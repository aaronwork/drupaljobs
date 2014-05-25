<?php
/**
 * @file
 * Drop Jobs Dev Drush integration.
 */

/**
 * Implements hook_drush_command().
 */
function drop_jobs_dev_drush_command() {
  return array(
    'drop-jobs-dev-reset' => array(
      'description' => 'Erase the entire Drupal database.',
      'aliases' => array('dev-reset'),
    ),
  );
}

/**
 * Implements hook_drush_help().
 */
function drop_jobs_dev_drush_help($section) {
  switch ($section) {
    case 'drush:drop_jobs_dev-reset':
      return dt('Erase the entire Drupal database.');
  }
}

/**
 * Drush command.
 * Execute dev cron script.
 *
 * @see drop_jobs_dev_drush_command()
 */
function drush_drop_jobs_dev_reset() {
  // @TODO drush confirm.
  $result = db_query("SHOW tables");
  $result->execute();
  $results = $result->fetchAll();
  $tables = array();

  foreach ($results as $table) {
    $tables[] = reset($table);
  }

  db_query('DROP TABLE ' . implode(', ', $tables));
  drush_print(dt('All tables deleted!'));
}