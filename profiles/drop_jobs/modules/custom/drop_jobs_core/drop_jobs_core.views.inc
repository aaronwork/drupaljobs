<?php
/**
 * @file
 * Drop Jobs Core Views hooks.
 */

/**
 * Implements hook_views_data().
 */
function drop_jobs_core_views_data() {
  $data = array(
    'drop_jobs_full_name' => array(
      'table' => array(
        'group' => t('Drop Jobs'),
        'join' => array(
          'profile' => array(
            'type' => 'INNER',
            'left_field' => 'pid',
            'field' => 'pid',
          ),
        ),
      ),
      'full_name' => array(
        'title' => t('Full name'),
        'help' => t("Displays the user's full name."),
        'field' => array(
          'handler' => 'drop_jobs_field_full_name',
          'click sortable' => FALSE,
        ),
      ),
    ),
  );

  return $data;
}

/**
 * Implements hook_views_plugins().
 */
function drop_jobs_core_views_plugins() {
  $plugins = array(
    'access' => array(
      'callback' => array(
        'title' => t('Callback'),
        'help' => t('Access will be granted based on a callback.'),
        'handler' => 'views_plugin_access_callback',
        'uses options' => TRUE,
        'help topic' => 'access-callback',
      ),
    ),
  );

  return $plugins;
}

/**
 * Implements hook_views_data_alter().
 */
function drop_jobs_core_views_data_alter(&$data) {
  // Add page link.
  $data['views']['dj_add_page'] = array(
    'title' => t('Add Page Link'),
    'help' => t('Displays a simple link to add a new page.'),
    'area' => array(
      'handler' => 'views_handler_drop_jobs_area_page_link',
    ),
  );

  // Back to top link.
  $data['views']['dj_back'] = array(
    'title' => t('Back to top'),
    'help' => t('Displays a simple link to go back to the top of the page.'),
    'area' => array(
      'handler' => 'views_handler_drop_jobs_area_back',
    ),
  );

  // Variable value field.
  $data['views']['variable'] = array(
    'title' => t('Variable'),
    'help' => t('Displays the value of a Drupal variable.'),
    'field' => array(
      'handler' => 'drop_jobs_field_variable',
    ),
  );
}