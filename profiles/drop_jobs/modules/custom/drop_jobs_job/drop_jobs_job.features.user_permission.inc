<?php
/**
 * @file
 * drop_jobs_job.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drop_jobs_job_user_default_permissions() {
  $permissions = array();

  // Exported permission: access rules link job_set_hidden.
  $permissions['access rules link job_set_hidden'] = array(
    'name' => 'access rules link job_set_hidden',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: access rules link job_set_visible.
  $permissions['access rules link job_set_visible'] = array(
    'name' => 'access rules link job_set_visible',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: add terms in 1.
  $permissions['add terms in 1'] = array(
    'name' => 'add terms in 1',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: add terms in 2.
  $permissions['add terms in 2'] = array(
    'name' => 'add terms in 2',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: administer drop_jobs jobs.
  $permissions['administer drop_jobs jobs'] = array(
    'name' => 'administer drop_jobs jobs',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'drop_jobs_job',
  );

  // Exported permission: create field_job_workflow.
  $permissions['create field_job_workflow'] = array(
    'name' => 'create field_job_workflow',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create job content.
  $permissions['create job content'] = array(
    'name' => 'create job content',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any job content.
  $permissions['delete any job content'] = array(
    'name' => 'delete any job content',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own job content.
  $permissions['delete own job content'] = array(
    'name' => 'delete own job content',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 1.
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 2.
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any job content.
  $permissions['edit any job content'] = array(
    'name' => 'edit any job content',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit field_job_workflow.
  $permissions['edit field_job_workflow'] = array(
    'name' => 'edit field_job_workflow',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_job_workflow.
  $permissions['edit own field_job_workflow'] = array(
    'name' => 'edit own field_job_workflow',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own job content.
  $permissions['edit own job content'] = array(
    'name' => 'edit own job content',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 1.
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 2.
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: flag favorite_jobs.
  $permissions['flag favorite_jobs'] = array(
    'name' => 'flag favorite_jobs',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate',
    ),
    'module' => 'flag',
  );

  // Exported permission: unflag favorite_jobs.
  $permissions['unflag favorite_jobs'] = array(
    'name' => 'unflag favorite_jobs',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate',
    ),
    'module' => 'flag',
  );

  // Exported permission: view field_job_workflow.
  $permissions['view field_job_workflow'] = array(
    'name' => 'view field_job_workflow',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_job_workflow.
  $permissions['view own field_job_workflow'] = array(
    'name' => 'view own field_job_workflow',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
