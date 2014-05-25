<?php
/**
 * @file
 * drop_jobs_search_saved.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drop_jobs_search_saved_user_default_permissions() {
  $permissions = array();

  // Exported permission: use search_api_saved_searches.
  $permissions['use search_api_saved_searches'] = array(
    'name' => 'use search_api_saved_searches',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'search_api_saved_searches',
  );

  return $permissions;
}
