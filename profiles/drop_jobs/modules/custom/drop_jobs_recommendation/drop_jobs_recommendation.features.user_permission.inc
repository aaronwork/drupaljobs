<?php
/**
 * @file
 * drop_jobs_recommendation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drop_jobs_recommendation_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer drop_jobs recommendations.
  $permissions['administer drop_jobs recommendations'] = array(
    'name' => 'administer drop_jobs recommendations',
    'roles' => array(
      0 => 'administrator',
      1 => 'job admin',
      2 => 'candidate admin',
    ),
    'module' => 'drop_jobs_recommendation',
  );

  // Exported permission: delete own drop_jobs recommendations.
  $permissions['delete own drop_jobs recommendations'] = array(
    'name' => 'delete own drop_jobs recommendations',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate',
      2 => 'recruiter',
    ),
    'module' => 'drop_jobs_recommendation',
  );

  // Exported permission: view drop_jobs recommendations.
  $permissions['view drop_jobs recommendations'] = array(
    'name' => 'view drop_jobs recommendations',
    'roles' => array(
      0 => 'administrator',
      1 => 'candidate',
      2 => 'recruiter',
    ),
    'module' => 'drop_jobs_recommendation',
  );

  return $permissions;
}
