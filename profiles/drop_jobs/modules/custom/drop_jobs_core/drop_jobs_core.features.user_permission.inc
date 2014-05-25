<?php
/**
 * @file
 * drop_jobs_core.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drop_jobs_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: access draggableviews.
  $permissions['access draggableviews'] = array(
    'name' => 'access draggableviews',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'content admin',
      3 => 'job admin',
      4 => 'organization admin',
      5 => 'recruiter admin',
    ),
    'module' => 'draggableviews',
  );

  // Exported permission: access drop_jobs user dashboard.
  $permissions['access drop_jobs user dashboard'] = array(
    'name' => 'access drop_jobs user dashboard',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate',
      2 => 'organization',
      3 => 'recruiter',
    ),
    'module' => 'drop_jobs_core',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'content admin',
      3 => 'job admin',
      4 => 'organization admin',
      5 => 'recruiter admin',
    ),
    'module' => 'user',
  );

  // Exported permission: add terms in 3.
  $permissions['add terms in 3'] = array(
    'name' => 'add terms in 3',
    'roles' => array(
      0 => 'administrator',
      1 => 'content admin',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: add terms in 4.
  $permissions['add terms in 4'] = array(
    'name' => 'add terms in 4',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: add terms in 5.
  $permissions['add terms in 5'] = array(
    'name' => 'add terms in 5',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: add terms in 6.
  $permissions['add terms in 6'] = array(
    'name' => 'add terms in 6',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: add terms in 7.
  $permissions['add terms in 7'] = array(
    'name' => 'add terms in 7',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: add terms in 8.
  $permissions['add terms in 8'] = array(
    'name' => 'add terms in 8',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: add terms in 9.
  $permissions['add terms in 9'] = array(
    'name' => 'add terms in 9',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: administer drop_jobs.
  $permissions['administer drop_jobs'] = array(
    'name' => 'administer drop_jobs',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'drop_jobs_core',
  );

  // Exported permission: delete terms in 3.
  $permissions['delete terms in 3'] = array(
    'name' => 'delete terms in 3',
    'roles' => array(
      0 => 'administrator',
      1 => 'content admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 4.
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 5.
  $permissions['delete terms in 5'] = array(
    'name' => 'delete terms in 5',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 6.
  $permissions['delete terms in 6'] = array(
    'name' => 'delete terms in 6',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 7.
  $permissions['delete terms in 7'] = array(
    'name' => 'delete terms in 7',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 8.
  $permissions['delete terms in 8'] = array(
    'name' => 'delete terms in 8',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 9.
  $permissions['delete terms in 9'] = array(
    'name' => 'delete terms in 9',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 3.
  $permissions['edit terms in 3'] = array(
    'name' => 'edit terms in 3',
    'roles' => array(
      0 => 'administrator',
      1 => 'content admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 4.
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 5.
  $permissions['edit terms in 5'] = array(
    'name' => 'edit terms in 5',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 6.
  $permissions['edit terms in 6'] = array(
    'name' => 'edit terms in 6',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 7.
  $permissions['edit terms in 7'] = array(
    'name' => 'edit terms in 7',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 8.
  $permissions['edit terms in 8'] = array(
    'name' => 'edit terms in 8',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 9.
  $permissions['edit terms in 9'] = array(
    'name' => 'edit terms in 9',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'job admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: use itoggle.
  $permissions['use itoggle'] = array(
    'name' => 'use itoggle',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'content admin',
      3 => 'job admin',
      4 => 'organization admin',
      5 => 'recruiter admin',
    ),
    'module' => 'itoggle',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'system',
  );

  return $permissions;
}
