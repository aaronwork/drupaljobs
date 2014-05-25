<?php
/**
 * @file
 * drop_jobs_dev.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drop_jobs_dev_user_default_permissions() {
  $permissions = array();

  // Exported permission: use add another.
  $permissions['use add another'] = array(
    'name' => 'use add another',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'content admin',
      3 => 'job admin',
      4 => 'organization admin',
      5 => 'recruiter admin',
    ),
    'module' => 'addanother',
  );

  return $permissions;
}
