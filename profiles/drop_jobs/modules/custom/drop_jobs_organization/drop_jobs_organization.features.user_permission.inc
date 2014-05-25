<?php
/**
 * @file
 * drop_jobs_organization.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drop_jobs_organization_user_default_permissions() {
  $permissions = array();

  // Exported permission: add terms in 10.
  $permissions['add terms in 10'] = array(
    'name' => 'add terms in 10',
    'roles' => array(
      0 => 'administrator',
      1 => 'organization admin',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: add terms in 11.
  $permissions['add terms in 11'] = array(
    'name' => 'add terms in 11',
    'roles' => array(
      0 => 'administrator',
      1 => 'organization admin',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: administer drop_jobs organizations.
  $permissions['administer drop_jobs organizations'] = array(
    'name' => 'administer drop_jobs organizations',
    'roles' => array(
      0 => 'administrator',
      1 => 'organization admin',
    ),
    'module' => 'drop_jobs_organization',
  );

  // Exported permission: create organization content.
  $permissions['create organization content'] = array(
    'name' => 'create organization content',
    'roles' => array(
      0 => 'administrator',
      1 => 'organization admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any organization content.
  $permissions['delete any organization content'] = array(
    'name' => 'delete any organization content',
    'roles' => array(
      0 => 'administrator',
      1 => 'organization admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own organization content.
  $permissions['delete own organization content'] = array(
    'name' => 'delete own organization content',
    'roles' => array(
      0 => 'administrator',
      1 => 'organization',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 10.
  $permissions['delete terms in 10'] = array(
    'name' => 'delete terms in 10',
    'roles' => array(
      0 => 'administrator',
      1 => 'organization admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 11.
  $permissions['delete terms in 11'] = array(
    'name' => 'delete terms in 11',
    'roles' => array(
      0 => 'administrator',
      1 => 'organization admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any organization content.
  $permissions['edit any organization content'] = array(
    'name' => 'edit any organization content',
    'roles' => array(
      0 => 'administrator',
      1 => 'organization admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own organization content.
  $permissions['edit own organization content'] = array(
    'name' => 'edit own organization content',
    'roles' => array(
      0 => 'administrator',
      1 => 'organization',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 10.
  $permissions['edit terms in 10'] = array(
    'name' => 'edit terms in 10',
    'roles' => array(
      0 => 'administrator',
      1 => 'organization admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 11.
  $permissions['edit terms in 11'] = array(
    'name' => 'edit terms in 11',
    'roles' => array(
      0 => 'administrator',
      1 => 'organization admin',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
