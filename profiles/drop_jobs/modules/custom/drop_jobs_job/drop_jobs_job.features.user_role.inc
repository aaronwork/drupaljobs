<?php
/**
 * @file
 * drop_jobs_job.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function drop_jobs_job_user_default_roles() {
  $roles = array();

  // Exported role: job admin.
  $roles['job admin'] = array(
    'name' => 'job admin',
    'weight' => '6',
    'machine_name' => 'job_admin',
  );

  return $roles;
}
