<?php
/**
 * @file
 * drop_jobs_candidate.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drop_jobs_candidate_user_default_permissions() {
  $permissions = array();

  // Exported permission: access rules link resume_set_hidden.
  $permissions['access rules link resume_set_hidden'] = array(
    'name' => 'access rules link resume_set_hidden',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate',
      2 => 'candidate admin',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: access rules link resume_set_visible.
  $permissions['access rules link resume_set_visible'] = array(
    'name' => 'access rules link resume_set_visible',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate',
      2 => 'candidate admin',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: administer drop_jobs candidates.
  $permissions['administer drop_jobs candidates'] = array(
    'name' => 'administer drop_jobs candidates',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
    ),
    'module' => 'drop_jobs_candidate',
  );

  // Exported permission: create field_resume_promoted.
  $permissions['create field_resume_promoted'] = array(
    'name' => 'create field_resume_promoted',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_resume_sticky.
  $permissions['create field_resume_sticky'] = array(
    'name' => 'create field_resume_sticky',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_resume_workflow.
  $permissions['create field_resume_workflow'] = array(
    'name' => 'create field_resume_workflow',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit any resume profile.
  $permissions['edit any resume profile'] = array(
    'name' => 'edit any resume profile',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
    ),
    'module' => 'profile2',
  );

  // Exported permission: edit field_resume_promoted.
  $permissions['edit field_resume_promoted'] = array(
    'name' => 'edit field_resume_promoted',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_resume_sticky.
  $permissions['edit field_resume_sticky'] = array(
    'name' => 'edit field_resume_sticky',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_resume_workflow.
  $permissions['edit field_resume_workflow'] = array(
    'name' => 'edit field_resume_workflow',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_resume_promoted.
  $permissions['edit own field_resume_promoted'] = array(
    'name' => 'edit own field_resume_promoted',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_resume_sticky.
  $permissions['edit own field_resume_sticky'] = array(
    'name' => 'edit own field_resume_sticky',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_resume_workflow.
  $permissions['edit own field_resume_workflow'] = array(
    'name' => 'edit own field_resume_workflow',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own resume profile.
  $permissions['edit own resume profile'] = array(
    'name' => 'edit own resume profile',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate',
    ),
    'module' => 'profile2',
  );

  // Exported permission: flag favorite_resumes.
  $permissions['flag favorite_resumes'] = array(
    'name' => 'flag favorite_resumes',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'recruiter',
    ),
    'module' => 'flag',
  );

  // Exported permission: unflag favorite_resumes.
  $permissions['unflag favorite_resumes'] = array(
    'name' => 'unflag favorite_resumes',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
      2 => 'recruiter',
    ),
    'module' => 'flag',
  );

  // Exported permission: view any resume profile.
  $permissions['view any resume profile'] = array(
    'name' => 'view any resume profile',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  // Exported permission: view field_resume_promoted.
  $permissions['view field_resume_promoted'] = array(
    'name' => 'view field_resume_promoted',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_resume_sticky.
  $permissions['view field_resume_sticky'] = array(
    'name' => 'view field_resume_sticky',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_resume_workflow.
  $permissions['view field_resume_workflow'] = array(
    'name' => 'view field_resume_workflow',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_resume_promoted.
  $permissions['view own field_resume_promoted'] = array(
    'name' => 'view own field_resume_promoted',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_resume_sticky.
  $permissions['view own field_resume_sticky'] = array(
    'name' => 'view own field_resume_sticky',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_resume_workflow.
  $permissions['view own field_resume_workflow'] = array(
    'name' => 'view own field_resume_workflow',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own resume profile.
  $permissions['view own resume profile'] = array(
    'name' => 'view own resume profile',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate',
    ),
    'module' => 'profile2',
  );

  return $permissions;
}
