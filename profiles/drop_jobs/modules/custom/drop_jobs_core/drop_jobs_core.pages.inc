<?php
/**
 * @file
 * Drop Jobs Core admin pages.
 */

/**
 * Page callback.
 * Displays the Welcome page for Drop Jobs.
 *
 * @see drop_jobs_core_menu()
 */
function drop_jobs_welcome_page() {
  $intro_text = '<p>' . t('!drop_jobs is a Drupal Distribution for creating job and résumé search websites.', array('!drop_jobs' => l(t('Drop Jobs'), 'http://drupal.org/project/drop_jobs', array('attributes' => array('target' => '_blank'))))) . '</p>';
  $intro_text .= '<p>' . t('Not sure how to get started? Try some of these suggestions:') . '</p>';

  $destination = drupal_get_destination();
  $steps = array();

  if (!module_exists('drop_jobs_demo')) {
    $steps[] = l(t('Enable Demonstration content'), 'admin/config/drop-jobs/demo/import', array('query' => $destination));
  }

  if (module_exists('drop_jobs_application') && !variable_get('file_private_path', NULL)) {
    $steps[] = l(t('Setup a private file system for users to upload their CVs when applying for jobs'), 'admin/config/media/file-system', array('query' => $destination));
  }

  $steps[] = l(t('Check out the Administrative Dashboard'), 'admin/drop-jobs', array('query' => $destination));
  $steps[] = l(t('Configure Drop Jobs'), 'admin/config/drop-jobs', array('query' => $destination));

  if (module_exists('drop_jobs_recommendation')) {
    $steps[] = l(t('Configure Job Recommendations'), 'admin/config/drop-jobs/recommendation', array('query' => $destination));
  }

  $steps[] = l(t('Check out your site Reports'), 'admin/reports/drop-jobs', array('query' => $destination));

  $intro_text .= theme('item_list', array('items' => $steps));
  $intro_text .= '<p>' . t('If you need any help please check out the official !group or use the !issue_tracker to open a support request.', array('!group' => l(t('group'), 'http://groups.drupal.org/drop-jobs-distribution', array('attributes' => array('target' => '_blank'))), '!issue_tracker' => l(t('issue tracker'), 'http://drupal.org/project/issues/drop_jobs', array('attributes' => array('target' => '_blank'))))) . '</p>';
  $intro_text .= '<p>' . t('We hope you have as much fun using Drop Jobs as we had building it!') . '</p>';

  return $intro_text;
}

/**
 * Page callback.
 * Displays Drop Jobs Admin Dashboard.
 *
 * @see drop_jobs_core_menu()
 * @see drop_jobs_core_menu_table()
 */
function drop_jobs_admin_dashboard() {
  $cols_per_row = variable_get_value('drop_jobs_dashboard_admin_cols');

  $classes = array(
    'admin/config/drop-jobs' => 'settings',
    'admin/reports/drop-jobs' => 'reports'
  );

  $exclude = array(
    'admin/drop-jobs',
    'user/logout',
  );

  return drop_jobs_core_menu_table('menu-drop-jobs-admin', $cols_per_row, NULL, $classes, $exclude);
}

/**
 * Page callback.
 *
 * Enables demo content module.
 *
 * @see drop_jobs_core_menu()
 */
function drop_jobs_core_demo_import() {
  module_enable(array('drop_jobs_demo'));

  // Find all available migrations.
  $migrations = migrate_migrations();
  foreach ($migrations as $machine_name => $migration) {
    if (strpos($machine_name, 'DropJobsTerm') === FALSE) {
      $operations[] = array('_drop_jobs_import', array($machine_name, t('Installing demo content.')));
    }
  }

  $batch = array(
    'title' => t('Install demo content'),
    'operations' => $operations,
    'finished' => 'drop_jobs_import_content_finished',
    'file' => drupal_get_path('profile', 'drop_jobs') . '/drop_jobs.install_callbacks.inc',
  );

  batch_set($batch);
  batch_process('admin/config/drop-jobs');
}

/**
 * Page callback.
 *
 * Removes demo content.
 *
 * @see drop_jobs_core_menu()
 */
function drop_jobs_core_demo_rollback() {
  // Find all available migrations.
  $migrations = migrate_migrations();
  foreach ($migrations as $machine_name => $migration) {
    if (strpos($machine_name, 'DropJobsTerm') === FALSE) {
      $operations[] = array('_drop_jobs_rollback', array($machine_name, t('Removing demo content.')));
    }
  }

  $batch = array(
    'title' => t('Remov demo content'),
    'operations' => $operations,
    'finished' => 'drop_jobs_rollback_content_finished',
    'file' => drupal_get_path('profile', 'drop_jobs') . '/drop_jobs.install_callbacks.inc',
  );

  batch_set($batch);
  batch_process('admin/config/drop-jobs/demo/disable');
}

/**
 * Page callback.
 *
 * Disables demo content module.
 *
 * @see drop_jobs_core_menu()
 */
function drop_jobs_core_demo_disable() {
  module_disable(array('drop_jobs_demo'));
  drupal_set_message(t('Demo content disabled'));
  drupal_goto('admin/config/drop-jobs');
}
