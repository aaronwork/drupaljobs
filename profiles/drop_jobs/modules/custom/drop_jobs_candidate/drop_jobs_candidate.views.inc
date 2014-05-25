<?php
/**
 * @file
 * Drop Jobs Candidate Views hooks.
 */

/**
 * Implements hook_views_data_alter().
 */
function drop_jobs_candidate_views_data_alter(&$data) {
  $data['views']['dj_add_candidate'] = array(
    'title' => t('Add Candidate Link'),
    'help' => t('Displays a simple link to add a new candidate.'),
    'area' => array(
      'handler' => 'views_handler_drop_jobs_area_candidate_link',
    ),
  );
}
