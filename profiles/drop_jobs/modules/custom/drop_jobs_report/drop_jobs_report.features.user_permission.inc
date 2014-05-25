<?php
/**
 * @file
 * drop_jobs_report.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drop_jobs_report_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer drop_jobs reports.
  $permissions['administer drop_jobs reports'] = array(
    'name' => 'administer drop_jobs reports',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'drop_jobs_report',
  );

  // Exported permission: view drop_jobs reports.
  $permissions['view drop_jobs reports'] = array(
    'name' => 'view drop_jobs reports',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'content admin',
      3 => 'job admin',
      4 => 'organization admin',
      5 => 'recruiter admin',
    ),
    'module' => 'drop_jobs_report',
  );

  return $permissions;
}
