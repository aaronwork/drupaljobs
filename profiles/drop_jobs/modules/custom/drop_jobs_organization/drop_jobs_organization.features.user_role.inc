<?php
/**
 * @file
 * drop_jobs_organization.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function drop_jobs_organization_user_default_roles() {
  $roles = array();

  // Exported role: organization.
  $roles['organization'] = array(
    'name' => 'organization',
    'weight' => '5',
    'machine_name' => 'organization',
  );

  // Exported role: organization admin.
  $roles['organization admin'] = array(
    'name' => 'organization admin',
    'weight' => '9',
    'machine_name' => 'organization_admin',
  );

  return $roles;
}
