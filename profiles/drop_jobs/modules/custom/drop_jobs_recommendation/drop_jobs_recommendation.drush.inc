<?php
/**
 * @file
 * Drop Jobs Recommendation Drush integration.
 */

/**
 * Implements hook_drush_command().
 */
function drop_jobs_recommendation_drush_command() {
  return array(
    // Utility commands.
    'drop-jobs-recommendation-cron' => array(
      'description' => 'Execute drop_jobs_recommendation cron script.',
    ),
    'drop-jobs-recommendation-load' => array(
      'description' => 'Load and view a recommendation',
      'aliases' => array('drop_jobs_recommendation-view'),
      'arguments' => array(
        'id' => "The recommendation's id.",
        'full' => "true/false. Whether to load the full recommendation object. Defaults to false.",
      ),
    ),
    'drop-jobs-recommendation-delete' => array(
      'description' => 'Delete a recommendation',
      'aliases' => array('drop-jobs-recommendation-del'),
      'arguments' => array(
        'id' => "The recommendation's id.",
      ),
    ),
  );
}

/**
 * Implements hook_drush_help().
 */
function drop_jobs_recommendation_drush_help($section) {
  switch ($section) {
    case 'drush:drop_jobs_recommendation-cron':
      return dt("Execute drop_jobs_recommendation cron script. Use this to execute the drop_jobs_recommendation cron script independently from Drupal's cron.");
    case 'drush:drop_jobs_recommendation-load':
      return dt('Load and view a recommendation.');
    case 'drush:drop_jobs_recommendation-delete':
      return dt('Delete a recommendation.');
  }
}

########################
### Utility Commands ###
########################

/**
 * Drush command.
 * Execute recommendation cron script.
 *
 * @see drop_jobs_recommendation_drush_command()
 */
function drush_drop_jobs_recommendation_cron() {
  drop_jobs_recommendation_cron();
  drush_print(dt('Drop Jobs Recommendation cron executed!'));
}

/**
 * Drush command.
 * Load and view a recommendation.
 *
 * @param int
 *   The recommendation's id.
 * @param boolean
 *   Whether to load the full recommendation object.
 */
function drush_drop_jobs_recommendation_load($id, $full = FALSE) {
  if ($recommendation = drop_jobs_recommendation_load($id)) {
    if (!$full) {
      $dummy = new stdClass;

      foreach ($recommendation as $property => $value) {
        $dummy->$property = $value;
      }

      $recommendation = $dummy;
    }
    drush_print(dt('Recommendation loaded successfully!') . "\n");
    print_r($recommendation);
    drush_print("\n");
  }
  else {
    drush_print(dt('Failed to load the recommendation. Invalid recommendation id.'));
  }
}

/**
 * Drush command.
 * Delete a recommendation.
 *
 * @param int
 *   The recommendation's id.
 */
function drush_drop_jobs_recommendation_delete($id) {
  if ($recommendation = drop_jobs_recommendation_load($id)) {
    if (drush_confirm(dt('Are you sure you want to delete this recommendation?'))) {
      drop_jobs_recommendation_delete($recommendation);
      drush_print(dt('Recommendation deleted successfully!'));
    }
  }
  else {
    drush_print(dt('Failed to load the recommendation. Invalid recommendation id.'));
  }
}