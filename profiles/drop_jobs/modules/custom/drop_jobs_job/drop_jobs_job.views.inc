<?php
/**
 * @file
 * Drop Jobs Job Views hooks.
 */

/**
 * Implements hook_views_data_alter().
 */
function drop_jobs_job_views_data_alter(&$data) {
  $data['views']['dj_add_job'] = array(
    'title' => t('Add Job Link'),
    'help' => t('Displays a simple link to add a new job.'),
    'area' => array(
      'handler' => 'views_handler_drop_jobs_area_job_link',
    ),
  );
}