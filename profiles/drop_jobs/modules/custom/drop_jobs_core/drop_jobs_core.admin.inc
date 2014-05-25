<?php
/**
 * @file
 * Drop Jobs Core admin settings.
 */

/**
 * Form callback.
 * General settings form.
 *
 * @see drop_jobs_core_menu()
 */
function drop_jobs_core_settings() {
  $form = array();

  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Global settings'),
    '#collapsible' => FALSE,
  );

  $form['wrapper']['misc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Misc'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $form['wrapper']['misc']['drop_jobs_welcome_page'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display welcome page'),
    '#description' => t('Since any user can access the "Welcome to Drop Jobs" page, you might want to disable it eventually.'),
    '#default_value' => variable_get_value('drop_jobs_welcome_page'),
  );

  $form['wrapper']['misc']['drop_jobs_log'] = array(
    '#type' => 'checkbox',
    '#title' => t('Development mode'),
    '#description' => t('Development mode logs more watchdog entries such as debug statments whereas production will only log errors.'),
    '#default_value' => variable_get_value('drop_jobs_log'),
  );

  $form['wrapper']['features'] = array(
    '#type' => 'fieldset',
    '#title' => t('Features'),
    '#description' => t('Enable or disable additional Drop Jobs Features.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  // Add feature form items.
  foreach (drop_jobs_get_features() as $module => $info) {
    $form['wrapper']['features'][$module] = array(
      '#type' => 'checkbox',
      '#title' => str_replace('Drop Jobs ', '', $info->info['name']),
      '#description' => $info->info['description'],
      '#default_value' => $info->status,
      '#disabled' => drop_jobs_core_feature_required($module),
    );
  }

  $form['wrapper']['dashboard'] = array(
    '#type' => 'fieldset',
    '#title' => t('Dashboards'),
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
  );

  $form['wrapper']['dashboard']['drop_jobs_dashboard_admin_cols'] = array(
    '#title' => t('Admin Dashboard - Items per row'),
    '#description' => t('How many links appear in each row in the Drop Jobs Administration Dashboard. Note that setting this to very high values will likely break the page layout.'),
    '#type' => 'textfield',
    '#size' => 2,
    '#default_value' => variable_get_value('drop_jobs_dashboard_admin_cols'),
  );

  $form['wrapper']['dashboard']['drop_jobs_dashboard_user_cols'] = array(
    '#title' => t('User Dashboard - Items per row'),
    '#description' => t('How many links appear in each row in the Drop Jobs User Dashboard. Note that setting this to very high values will likely break the page layout.'),
    '#type' => 'textfield',
    '#size' => 2,
    '#default_value' => variable_get_value('drop_jobs_dashboard_user_cols'),
  );

  $form['wrapper']['links'] = array(
    '#type' => 'fieldset',
    '#title' => t('Links'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $links = array();
  $destination = drupal_get_destination();

  $links['site_information'] = array(
    'title' => t('Site information'),
    'href' => 'admin/config/system/site-information',
    'query' => $destination,
  );

  $form['wrapper']['links']['links'] = array(
    '#theme' => 'links',
    '#links' => $links,
    '#attributes' => array('class' => array('links', 'inline')),
  );

  $form['#submit'][] = 'drop_jobs_core_settings_submit';

  return system_settings_form($form);
}

/**
 * Submit callback.
 *
 * @see drop_jobs_core_settings()
 */
function drop_jobs_core_settings_submit(&$form, &$form_state) {
  // If we disabled the welcome page, make sure its not still the frontpage.
  if (!$form_state['values']['misc']['drop_jobs_welcome_page']) {
    $front_page = variable_get('site_frontpage');
    // If it is the frontpage, change the frontpage to the default "node".
    if ($front_page === 'welcome-to-drop-jobs') {
      variable_set('site_frontpage', 'node');
    }
  }

  // Set welcome page variable manually. For whatever reason it's not getting
  // automagically set as expected.
  variable_set('drop_jobs_welcome_page', $form_state['values']['misc']['drop_jobs_welcome_page']);

  // Since this form deals with enabling and disabling features as well as the
  // welcome page, a menu rebuild will likely be needed. Let's keep things
  // simple and always set it to true.
  variable_set('menu_rebuild_needed', TRUE);

  // Blank slate for dealing with enabling/disabling features.
  $enable = array();
  $disable = array();

  $demo_action = NULL;

  // Enable/disable Drop Jobs Features.
  foreach ($form_state['values']['features'] as $module => $state) {
    // Modules to enable.
    if ($state == 1 && !module_exists($module)) {
      if ($module === 'drop_jobs_demo') {
        $demo_action = 'enable';
      }
      else {
        $enable[] = $module;
      }
    }

    // Modules to disable.
    if ($state == 0 && module_exists($module)) {
      if ($module === 'drop_jobs_demo') {
        $demo_action = 'disable';
      }
      else {
        $disable[] = $module;
      }
    }

    // Enable modules.
    if (!empty($enable)) {
      module_enable($enable, TRUE);
    }

    // Disable modules.
    if (!empty($disable)) {
      module_disable($disable, TRUE);
    }
  }

  // Demo module gets treated differently.
  if ($demo_action === 'enable') {
    drupal_goto('admin/config/drop-jobs/demo/import');
  }
  else if ($demo_action === 'disable') {
    drupal_goto('admin/config/drop-jobs/demo/rollback');
  }
}

/**
 * Validation callback.
 *
 * @see drop_jobs_core_settings()
 */
function drop_jobs_core_settings_validate($form, &$form_state) {
  if (!is_numeric($form_state['values']['drop_jobs_dashboard_admin_cols'])) {
    form_set_error($form_state['values']['drop_jobs_dashboard_admin_cols'], t('Items per row must be numeric.'));
  }
  else if (!$form_state['values']['drop_jobs_dashboard_admin_cols'] > 0) {
    form_set_error($form_state['values']['drop_jobs_dashboard_admin_cols'], t('Items per row must be greater than 0.'));
  }

  if (!is_numeric($form_state['values']['drop_jobs_dashboard_user_cols'])) {
    form_set_error($form_state['values']['drop_jobs_dashboard_user_cols'], t('Items per row must be numeric.'));
  }
  else if (!$form_state['values']['drop_jobs_dashboard_user_cols'] > 0) {
    form_set_error($form_state['values']['drop_jobs_dashboard_user_cols'], t('Items per row must be greater than 0.'));
  }
}
