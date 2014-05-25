<?php
/**
 * @file
 * Drop Jobs Recruiter Views hooks.
 */

/**
 * Implements hook_views_data_alter().
 */
function drop_jobs_recruiter_views_data_alter(&$data) {
  $data['views']['dj_add_recruiter'] = array(
    'title' => t('Add Recruiter Link'),
    'help' => t('Displays a simple link to add a new recruiter.'),
    'area' => array(
      'handler' => 'views_handler_drop_jobs_area_recruiter_link',
    ),
  );
}