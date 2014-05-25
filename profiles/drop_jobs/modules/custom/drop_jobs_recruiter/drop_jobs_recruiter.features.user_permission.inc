<?php
/**
 * @file
 * drop_jobs_recruiter.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drop_jobs_recruiter_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer drop_jobs recruiters.
  $permissions['administer drop_jobs recruiters'] = array(
    'name' => 'administer drop_jobs recruiters',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'drop_jobs_recruiter',
  );

  // Exported permission: create field_recruiter_first_name.
  $permissions['create field_recruiter_first_name'] = array(
    'name' => 'create field_recruiter_first_name',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_recruiter_last_name.
  $permissions['create field_recruiter_last_name'] = array(
    'name' => 'create field_recruiter_last_name',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_recruiter_organization.
  $permissions['create field_recruiter_organization'] = array(
    'name' => 'create field_recruiter_organization',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_recruiter_phone.
  $permissions['create field_recruiter_phone'] = array(
    'name' => 'create field_recruiter_phone',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_recruiter_photo.
  $permissions['create field_recruiter_photo'] = array(
    'name' => 'create field_recruiter_photo',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit any recruiter profile.
  $permissions['edit any recruiter profile'] = array(
    'name' => 'edit any recruiter profile',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'profile2',
  );

  // Exported permission: edit field_recruiter_first_name.
  $permissions['edit field_recruiter_first_name'] = array(
    'name' => 'edit field_recruiter_first_name',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_recruiter_last_name.
  $permissions['edit field_recruiter_last_name'] = array(
    'name' => 'edit field_recruiter_last_name',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_recruiter_organization.
  $permissions['edit field_recruiter_organization'] = array(
    'name' => 'edit field_recruiter_organization',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_recruiter_phone.
  $permissions['edit field_recruiter_phone'] = array(
    'name' => 'edit field_recruiter_phone',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_recruiter_photo.
  $permissions['edit field_recruiter_photo'] = array(
    'name' => 'edit field_recruiter_photo',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_recruiter_first_name.
  $permissions['edit own field_recruiter_first_name'] = array(
    'name' => 'edit own field_recruiter_first_name',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_recruiter_last_name.
  $permissions['edit own field_recruiter_last_name'] = array(
    'name' => 'edit own field_recruiter_last_name',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_recruiter_organization.
  $permissions['edit own field_recruiter_organization'] = array(
    'name' => 'edit own field_recruiter_organization',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_recruiter_phone.
  $permissions['edit own field_recruiter_phone'] = array(
    'name' => 'edit own field_recruiter_phone',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_recruiter_photo.
  $permissions['edit own field_recruiter_photo'] = array(
    'name' => 'edit own field_recruiter_photo',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own recruiter profile.
  $permissions['edit own recruiter profile'] = array(
    'name' => 'edit own recruiter profile',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'profile2',
  );

  // Exported permission: view any recruiter profile.
  $permissions['view any recruiter profile'] = array(
    'name' => 'view any recruiter profile',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'profile2',
  );

  // Exported permission: view field_recruiter_first_name.
  $permissions['view field_recruiter_first_name'] = array(
    'name' => 'view field_recruiter_first_name',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_recruiter_last_name.
  $permissions['view field_recruiter_last_name'] = array(
    'name' => 'view field_recruiter_last_name',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_recruiter_organization.
  $permissions['view field_recruiter_organization'] = array(
    'name' => 'view field_recruiter_organization',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_recruiter_phone.
  $permissions['view field_recruiter_phone'] = array(
    'name' => 'view field_recruiter_phone',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_recruiter_photo.
  $permissions['view field_recruiter_photo'] = array(
    'name' => 'view field_recruiter_photo',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_recruiter_first_name.
  $permissions['view own field_recruiter_first_name'] = array(
    'name' => 'view own field_recruiter_first_name',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_recruiter_last_name.
  $permissions['view own field_recruiter_last_name'] = array(
    'name' => 'view own field_recruiter_last_name',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_recruiter_organization.
  $permissions['view own field_recruiter_organization'] = array(
    'name' => 'view own field_recruiter_organization',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_recruiter_phone.
  $permissions['view own field_recruiter_phone'] = array(
    'name' => 'view own field_recruiter_phone',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_recruiter_photo.
  $permissions['view own field_recruiter_photo'] = array(
    'name' => 'view own field_recruiter_photo',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own recruiter profile.
  $permissions['view own recruiter profile'] = array(
    'name' => 'view own recruiter profile',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'profile2',
  );

  return $permissions;
}
