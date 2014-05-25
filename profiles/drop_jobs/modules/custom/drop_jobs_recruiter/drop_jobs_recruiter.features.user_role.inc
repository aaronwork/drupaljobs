<?php
/**
 * @file
 * drop_jobs_recruiter.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function drop_jobs_recruiter_user_default_roles() {
  $roles = array();

  // Exported role: recruiter.
  $roles['recruiter'] = array(
    'name' => 'recruiter',
    'weight' => '4',
    'machine_name' => 'recruiter',
  );

  // Exported role: recruiter admin.
  $roles['recruiter admin'] = array(
    'name' => 'recruiter admin',
    'weight' => '10',
    'machine_name' => 'recruiter_admin',
  );

  return $roles;
}
