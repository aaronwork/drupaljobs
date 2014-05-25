<?php
/**
 * @file
 * Drop Jobs profile.
 */

/**
 * Set Drop Jobs as default install profile.
 *
 * Must use system as the hook module because drop_jobs is not active yet
 */
function system_form_install_select_profile_form_alter(&$form, $form_state) {
  foreach($form['profile'] as $key => $element) {
    $form['profile'][$key]['#value'] = 'drop_jobs';
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Alter the site configuration form.
 */
function drop_jobs_form_install_configure_form_alter(&$form, $form_state) {
  // Many modules set messages during installation that are very annoying.
  // Yeah, we're looking at you Date and iToggle.
  // Let's clear these messages to avoid the false impression that something
  // went wrong when it didn't.
  drupal_get_messages('status');
  drupal_get_messages('warning');

  // Warn about settings.php permissions risk
  $settings_dir = conf_path();
  $settings_file = $settings_dir . '/settings.php';
  // Check that $_POST is empty so we only show this message when the form is
  // first displayed, not on the next page after it is submitted. (We do not
  // want to repeat it multiple times because it is a general warning that is
  // not related to the rest of the installation process; it would also be
  // especially out of place on the last page of the installer, where it would
  // distract from the message that the Drupal installation has completed
  // successfully.)
  if (empty($_POST) && (!drupal_verify_install_file(DRUPAL_ROOT . '/' . $settings_file, FILE_EXIST | FILE_READABLE | FILE_NOT_WRITABLE) || !drupal_verify_install_file(DRUPAL_ROOT . '/' . $settings_dir, FILE_NOT_WRITABLE, 'dir'))) {
    drupal_set_message(st('All necessary changes to %dir and %file have been made, so you should remove write permissions to them now in order to avoid security risks. If you are unsure how to do so, consult the <a href="@handbook_url">online handbook</a>.', array('%dir' => $settings_dir, '%file' => $settings_file, '@handbook_url' => 'http://drupal.org/server-permissions')), 'warning');
  }

  // Pre-populate some fields.
  $form['site_information']['site_name']['#default_value'] = 'Drop Jobs'; // We don't use t() intentionally.
  $form['site_information']['site_mail']['#default_value'] = 'admin@' . $_SERVER['HTTP_HOST'];
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  // Don't site site maintenance email because it'll be set automatically once the site information email is set.

  // Add checkbox for example content.
  $form['drop_jobs'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#title' => t('Drop Jobs'),
  );

  $form['drop_jobs']['drop_jobs_demo_content'] = array(
    '#type' => 'checkbox',
    '#title' => t('Install demo content'),
    '#description' => t('Check this option to enable demonstration content for Drop Jobs to get your site up and running quickly.'),
    '#default_value' => TRUE,
  );

  // Add checkboxes for submodules.
  $form['drop_jobs']['drop_jobs_features'] = array(
    '#type' => 'fieldset',
    '#title' => t('Features'),
    '#description' => t('Enable additional Drop Jobs Features'),
    '#collapsible' => FALSE,
    '#tree' => TRUE,
  );

  // These get enabled by default.
  $enabled = array(
    'drop_jobs_report',
  );

  // These get excluded.
  $hidden = array(
    // Demo module gets its own separate option.
    'drop_jobs_demo',
    // It's best to only allow users to enable this one later to avoid
    // installation errors.
    'drop_jobs_search_solr',
  );

  // Add feature form items.
  foreach (drop_jobs_get_features() as $module => $info) {
    // Demo module gets special treatment.
    if (!in_array($module, $hidden)) {
      $form['drop_jobs']['drop_jobs_features'][$module] = array(
        '#type' => 'checkbox',
        '#title' => str_replace('Drop Jobs ', '', $info->info['name']),
        '#description' => $info->info['description'],
        '#default_value' => in_array($module, $enabled),
      );
    }
  }

  $form['#submit'][] = 'drop_jobs_install_configure_form_submit';
}

/**
 * Submit callback.
 *
 * Installs Drop Jobs demonstration content.
 */
function drop_jobs_install_configure_form_submit(&$form, &$form_state) {
  // Alias for convenience.
  $values =& $form_state['values'];

  // Enable additional modules.
  if ($values['drop_jobs_features']) {
    $modules = array();

    foreach ($values['drop_jobs_features'] as $module => $enabled) {
      if ($enabled) {
        $modules[] = $module;
      }
    }
  }

  // Set variable to enable additional modules.
  variable_set('drop_jobs_install_extra_modules', $modules);

  // Set variable to install or not demo content.
  variable_set('drop_jobs_install_demo_content', $values['drop_jobs_demo_content']);
}

/**
 * Implements hook_block_info().
 */
function drop_jobs_block_info() {
  return array(
    'powered-by' => array(
      'info' => t('Powered by Drop Jobs'),
      'weight' => '10',
      'cache' => DRUPAL_CACHE_GLOBAL,
    ),
  );
}

/**
 * Implements hook_block_view().
 */
function drop_jobs_block_view($delta = '') {
  if ($delta === 'powered-by') {
    return array(
      'subject' => NULL,
      'content' => '<span>' . t('Powered by <a href="@drop_jobs" target="_blank">Drop Jobs</a>, a <a href="@drupal" target="_blank">Drupal</a> distribution by <a href="@alex" target="_blank">Alex</a> and <a href="@friends" target="_blank">friends</a>.', array('@drop_jobs' => 'http://drupal.org/project/drop_jobs', '@drupal' => 'http://drupal.org', '@alex' => 'http://alexweber.com.br', '@friends' => 'http://groups.drupal.org/drop-jobs-distribution')) . '</span>',
    );
  }
}

/**
 * Returns an array of Drop Jobs modules (features) that are considered "core".
 *
 * @return array
 *   An array of the core modules' machine names.
 */
function drop_jobs_core_features() {
  return array(
    'drop_jobs_core',
    'drop_jobs_candidate',
    'drop_jobs_recruiter',
    'drop_jobs_job',
    'drop_jobs_organization',
    'drop_jobs_search',
  );
}

/**
 * Returns an array of Drop Jobs "Features" that can be turned on or off.
 * These are Drop Jobs submodules, excluding those considered to be "core"
 * by Drop Jobs or excluded by other modules.
 *
 * @return array
 *   An array of available modules, keyed by machine name.
 */
function drop_jobs_get_features() {
  $core_features = drop_jobs_core_features();

  // i18n module isn't technically core but it has dependencies outside of
  // Drop Jobs so we hide it here.
  $core_features[] = 'drop_jobs_i18n';

  // Build list of features.
  $features = array();

  foreach (system_rebuild_module_data() as $module => $info) {
    if (strpos($module, 'drop_jobs_') === 0 && !in_array($module, $core_features)) {
      $features[$module] = $info;
    }
  }

  return $features;
}

/**
 * Determine whether a user has a particular role.
 * If no user is specified we use the current user.
 *
 * @param mixed
 *   The role, can be either the numeric id or the machine name.
 * @param int
 *   The user, if none is specified checks against the current user.
 * @return boolean
 *   TRUE if the user has that role, FALSE otherwise.
 */
function drop_jobs_user_has_role($role, $uid = NULL) {
  $user = user_uid_optional_load($uid);

  // Make sure we have a valid user object.
  if (is_object($user) && isset($user->roles) && is_array($user->roles)) {
    return (is_numeric($role)) ? in_array($role, array_keys($user->roles)) : in_array($role, $user->roles);
  }

  return FALSE;
}
