<?php
/**
 * @file
 * Drop Jobs Application Rules integration.
 */

/**
 * Access callback.
 *
 * @see drop_jobs_application_rules_event_info()
 * @see drop_jobs_application_rules_action_info()
 */
function drop_jobs_application_rules_access($type, $name) {
  if ($type == 'event' || $type == 'condition') {
    return user_access('administer drop_jobs applications');
  }
}

/**
 * Implements hook_rules_event_info().
 *
 * Defines rules events.
 */
function drop_jobs_application_rules_event_info() {
  $events = array();

  // For the sake of convenience.
  $defaults = array(
    'group' => t('Drop Jobs Application'),
    'access callback' => 'drop_jobs_application_rules_access',
    'variables' => array(
      'application' => array(
        'label' => t('Application object'),
        'type' => 'drop_jobs_application',
        'skip save' => TRUE,
      ),
    ),
  );

  // Candidate applies to a Job.
  $events['drop_jobs_application_apply'] = array(
    'label' => t('Candidate applies to a Job.'),
    ) + $defaults;

  // Candidate removes Job application.
  $events['drop_jobs_application_revoke'] = array(
    'label' => t('Candidate removes a Job application.'),
    ) + $defaults;

  return $events;
}

/**
 * Implements hook_rules_condition_info().
 */
function drop_jobs_application_rules_condition_info() {
  $conditions = array();

  // For convenience.
  $defaults = array(
    'group' => t('Drop Jobs Application'),
  );

  $conditions['drop_jobs_application_applied'] = array(
    'label' => t('Check whether a candidate has already applied to a job'),
    'base' => 'drop_jobs_application_condition_applied',
    'parameter' => array(
      'job' => array(
        'label' => t('Job node'),
        'type' => 'node',
        'skip save' => TRUE,
      ),
      'user' => array(
        'label' => t('Candidate user'),
        'type' => 'user',
        'skip save' => TRUE,
      ),
    ),
    ) + $defaults;

  return $conditions;
}

/**
 * Implements hook_rules_action_info().
 */
function drop_jobs_application_rules_action_info() {
  $actions = array();

  // For convenience.
  $defaults = array(
    'group' => t('Drop Jobs Application'),
    'access callback' => 'drop_jobs_application_rules_access',
  );

  // Apply to job.
  $actions['drop_jobs_application_apply'] = array(
    'label' => t('Apply to a job.'),
    'base' => 'drop_jobs_application_action_apply',
    'parameter' => array(
      'job' => array(
        'label' => t('Job node'),
        'type' => 'node',
        'skip save' => TRUE,
      ),
      'user' => array(
        'label' => t('Candidate user'),
        'type' => 'user',
        'skip save' => TRUE,
      ),
    ),
    ) + $defaults;

  // Revoke job application.
  $actions['drop_jobs_application_revoke'] = array(
    'label' => t('Remove a job application'),
    'base' => 'drop_jobs_application_action_unapply',
    'parameter' => array(
      'application' => array(
        'label' => t('Job application object'),
        'type' => 'drop_jobs_application',
        'skip save' => TRUE,
      ),
    ),
    ) + $defaults;

  return $actions;
}

/**
 * Rules action callback.
 * Check whether a given candidate has already applied to a given job.
 */
function drop_jobs_application_condition_applied(stdClass $job, stdClass $user) {
  $applications = drop_jobs_application_load_by_user_and_node($user, $job);
  return !empty($applications);
}

/**
 * Rules action callback.
 * Make a given candidate apply to a given job.
 */
function drop_jobs_application_action_apply(stdClass $job, stdClass $user) {
  $values = array('user' => $user->uid, 'node' => $job->nid);
  $application = drop_jobs_application_create($values);
  return drop_jobs_application_save($application);
}

/**
 * Rules action callback.
 * Make a given candidate remove a job application.
 */
function drop_jobs_application_action_unapply(DropJobsApplication $application) {
  return drop_jobs_application_set_revoked($application);
}