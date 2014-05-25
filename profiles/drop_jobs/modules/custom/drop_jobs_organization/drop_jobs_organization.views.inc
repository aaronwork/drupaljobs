<?php
/**
 * @file
 * Drop Jobs Organization Views hooks.
 */

/**
 * Implements hook_views_data_alter().
 */
function drop_jobs_organization_views_data_alter(&$data) {
  $data['views']['dj_add_organization'] = array(
    'title' => t('Add Organization Link'),
    'help' => t('Displays a simple link to add a new organization.'),
    'area' => array(
      'handler' => 'views_handler_drop_jobs_area_organization_link',
    ),
  );
}