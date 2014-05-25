<?php
/**
 * @file
 * drop_jobs_candidate.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function drop_jobs_candidate_user_default_roles() {
  $roles = array();

  // Exported role: candidate.
  $roles['candidate'] = array(
    'name' => 'candidate',
    'weight' => '3',
    'machine_name' => 'candidate',
  );

  // Exported role: candidate admin.
  $roles['candidate admin'] = array(
    'name' => 'candidate admin',
    'weight' => '8',
    'machine_name' => 'candidate_admin',
  );

  return $roles;
}
