<?php
/**
 * @file
 * drop_jobs_subscription.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drop_jobs_subscription_user_default_permissions() {
  $permissions = array();

  // Exported permission: create recruiter_basic subscription.
  $permissions['create recruiter_basic subscription'] = array(
    'name' => 'create recruiter_basic subscription',
    'roles' => array(
      0 => 'recruiter',
    ),
    'module' => 'subs',
  );

  // Exported permission: create recruiter_premium subscription.
  $permissions['create recruiter_premium subscription'] = array(
    'name' => 'create recruiter_premium subscription',
    'roles' => array(
      0 => 'recruiter',
    ),
    'module' => 'subs',
  );

  // Exported permission: create recruiter_standard subscription.
  $permissions['create recruiter_standard subscription'] = array(
    'name' => 'create recruiter_standard subscription',
    'roles' => array(
      0 => 'recruiter',
    ),
    'module' => 'subs',
  );

  // Exported permission: delete any recruiter_basic subscription.
  $permissions['delete any recruiter_basic subscription'] = array(
    'name' => 'delete any recruiter_basic subscription',
    'roles' => array(
      0 => 'recruiter admin',
    ),
    'module' => 'subs',
  );

  // Exported permission: delete any recruiter_premium subscription.
  $permissions['delete any recruiter_premium subscription'] = array(
    'name' => 'delete any recruiter_premium subscription',
    'roles' => array(
      0 => 'recruiter admin',
    ),
    'module' => 'subs',
  );

  // Exported permission: delete any recruiter_standard subscription.
  $permissions['delete any recruiter_standard subscription'] = array(
    'name' => 'delete any recruiter_standard subscription',
    'roles' => array(
      0 => 'recruiter admin',
    ),
    'module' => 'subs',
  );

  // Exported permission: delete own recruiter_basic subscription.
  $permissions['delete own recruiter_basic subscription'] = array(
    'name' => 'delete own recruiter_basic subscription',
    'roles' => array(
      0 => 'recruiter',
    ),
    'module' => 'subs',
  );

  // Exported permission: delete own recruiter_premium subscription.
  $permissions['delete own recruiter_premium subscription'] = array(
    'name' => 'delete own recruiter_premium subscription',
    'roles' => array(
      0 => 'recruiter',
    ),
    'module' => 'subs',
  );

  // Exported permission: delete own recruiter_standard subscription.
  $permissions['delete own recruiter_standard subscription'] = array(
    'name' => 'delete own recruiter_standard subscription',
    'roles' => array(
      0 => 'recruiter',
    ),
    'module' => 'subs',
  );

  // Exported permission: edit any recruiter_basic subscription.
  $permissions['edit any recruiter_basic subscription'] = array(
    'name' => 'edit any recruiter_basic subscription',
    'roles' => array(
      0 => 'recruiter admin',
    ),
    'module' => 'subs',
  );

  // Exported permission: edit any recruiter_premium subscription.
  $permissions['edit any recruiter_premium subscription'] = array(
    'name' => 'edit any recruiter_premium subscription',
    'roles' => array(
      0 => 'recruiter admin',
    ),
    'module' => 'subs',
  );

  // Exported permission: edit any recruiter_standard subscription.
  $permissions['edit any recruiter_standard subscription'] = array(
    'name' => 'edit any recruiter_standard subscription',
    'roles' => array(
      0 => 'recruiter admin',
    ),
    'module' => 'subs',
  );

  // Exported permission: edit own recruiter_basic subscription.
  $permissions['edit own recruiter_basic subscription'] = array(
    'name' => 'edit own recruiter_basic subscription',
    'roles' => array(
      0 => 'recruiter',
    ),
    'module' => 'subs',
  );

  // Exported permission: edit own recruiter_premium subscription.
  $permissions['edit own recruiter_premium subscription'] = array(
    'name' => 'edit own recruiter_premium subscription',
    'roles' => array(
      0 => 'recruiter',
    ),
    'module' => 'subs',
  );

  // Exported permission: edit own recruiter_standard subscription.
  $permissions['edit own recruiter_standard subscription'] = array(
    'name' => 'edit own recruiter_standard subscription',
    'roles' => array(
      0 => 'recruiter',
    ),
    'module' => 'subs',
  );

  // Exported permission: view any recruiter_basic subscription.
  $permissions['view any recruiter_basic subscription'] = array(
    'name' => 'view any recruiter_basic subscription',
    'roles' => array(
      0 => 'recruiter admin',
    ),
    'module' => 'subs',
  );

  // Exported permission: view any recruiter_premium subscription.
  $permissions['view any recruiter_premium subscription'] = array(
    'name' => 'view any recruiter_premium subscription',
    'roles' => array(
      0 => 'recruiter admin',
    ),
    'module' => 'subs',
  );

  // Exported permission: view any recruiter_standard subscription.
  $permissions['view any recruiter_standard subscription'] = array(
    'name' => 'view any recruiter_standard subscription',
    'roles' => array(
      0 => 'recruiter admin',
    ),
    'module' => 'subs',
  );

  // Exported permission: view own recruiter_basic subscription.
  $permissions['view own recruiter_basic subscription'] = array(
    'name' => 'view own recruiter_basic subscription',
    'roles' => array(
      0 => 'recruiter',
    ),
    'module' => 'subs',
  );

  // Exported permission: view own recruiter_premium subscription.
  $permissions['view own recruiter_premium subscription'] = array(
    'name' => 'view own recruiter_premium subscription',
    'roles' => array(
      0 => 'recruiter',
    ),
    'module' => 'subs',
  );

  // Exported permission: view own recruiter_standard subscription.
  $permissions['view own recruiter_standard subscription'] = array(
    'name' => 'view own recruiter_standard subscription',
    'roles' => array(
      0 => 'recruiter',
    ),
    'module' => 'subs',
  );

  return $permissions;
}
