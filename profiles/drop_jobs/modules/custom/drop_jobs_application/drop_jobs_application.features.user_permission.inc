<?php
/**
 * @file
 * drop_jobs_application.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drop_jobs_application_user_default_permissions() {
  $permissions = array();

  // Exported permission: access rules link application_set_hidden.
  $permissions['access rules link application_set_hidden'] = array(
    'name' => 'access rules link application_set_hidden',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
      2 => 'recruiter',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: access rules link application_set_new.
  $permissions['access rules link application_set_new'] = array(
    'name' => 'access rules link application_set_new',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
      2 => 'recruiter',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: access rules link application_set_read.
  $permissions['access rules link application_set_read'] = array(
    'name' => 'access rules link application_set_read',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
      2 => 'recruiter',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: access rules link application_set_revoked.
  $permissions['access rules link application_set_revoked'] = array(
    'name' => 'access rules link application_set_revoked',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate',
      2 => 'job admin',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: administer drop_jobs applications.
  $permissions['administer drop_jobs applications'] = array(
    'name' => 'administer drop_jobs applications',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
    ),
    'module' => 'drop_jobs_application',
  );

  // Exported permission: create drop_jobs applications.
  $permissions['create drop_jobs applications'] = array(
    'name' => 'create drop_jobs applications',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate',
    ),
    'module' => 'drop_jobs_application',
  );

  // Exported permission: create field_job_applications.
  $permissions['create field_job_applications'] = array(
    'name' => 'create field_job_applications',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_job_notification.
  $permissions['create field_job_notification'] = array(
    'name' => 'create field_job_notification',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_job_notification_email.
  $permissions['create field_job_notification_email'] = array(
    'name' => 'create field_job_notification_email',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_job_applications.
  $permissions['edit field_job_applications'] = array(
    'name' => 'edit field_job_applications',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_job_notification.
  $permissions['edit field_job_notification'] = array(
    'name' => 'edit field_job_notification',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_job_notification_email.
  $permissions['edit field_job_notification_email'] = array(
    'name' => 'edit field_job_notification_email',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_job_applications.
  $permissions['edit own field_job_applications'] = array(
    'name' => 'edit own field_job_applications',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_job_notification.
  $permissions['edit own field_job_notification'] = array(
    'name' => 'edit own field_job_notification',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_job_notification_email.
  $permissions['edit own field_job_notification_email'] = array(
    'name' => 'edit own field_job_notification_email',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_job_applications.
  $permissions['view field_job_applications'] = array(
    'name' => 'view field_job_applications',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_job_notification.
  $permissions['view field_job_notification'] = array(
    'name' => 'view field_job_notification',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_job_notification_email.
  $permissions['view field_job_notification_email'] = array(
    'name' => 'view field_job_notification_email',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_job_applications.
  $permissions['view own field_job_applications'] = array(
    'name' => 'view own field_job_applications',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_job_notification.
  $permissions['view own field_job_notification'] = array(
    'name' => 'view own field_job_notification',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_job_notification_email.
  $permissions['view own field_job_notification_email'] = array(
    'name' => 'view own field_job_notification_email',
    'roles' => array(
      0 => 'administrator',
      1 => 'recruiter',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
