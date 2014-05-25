<?php
/**
 * @file
 * drop_jobs_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drop_jobs_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: use advanced drop_jobs job search.
  $permissions['use advanced drop_jobs job search'] = array(
    'name' => 'use advanced drop_jobs job search',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate',
      2 => 'candidate admin',
      3 => 'content admin',
      4 => 'job admin',
      5 => 'organization admin',
      6 => 'recruiter admin',
    ),
    'module' => 'drop_jobs_search',
  );

  // Exported permission: use advanced drop_jobs resume search.
  $permissions['use advanced drop_jobs resume search'] = array(
    'name' => 'use advanced drop_jobs resume search',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'content admin',
      3 => 'job admin',
      4 => 'organization admin',
      5 => 'recruiter',
      6 => 'recruiter admin',
    ),
    'module' => 'drop_jobs_search',
  );

  // Exported permission: use drop_jobs job search.
  $permissions['use drop_jobs job search'] = array(
    'name' => 'use drop_jobs job search',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'drop_jobs_search',
  );

  // Exported permission: use drop_jobs resume search.
  $permissions['use drop_jobs resume search'] = array(
    'name' => 'use drop_jobs resume search',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'drop_jobs_search',
  );

  return $permissions;
}
