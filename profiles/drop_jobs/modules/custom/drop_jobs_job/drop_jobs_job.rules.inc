<?php
/**
 * @file
 * Drop Jobs Job Rules integration.
 */


/**
 * Access callback.
 *
 * @see drop_jobs_job_rules_event_info()
 * @see drop_jobs_job_rules_action_info()
 */
function drop_jobs_job_rules_access($type, $name) {
  if ($type === 'event' || $type === 'condition') {
    return user_access('administer drop_jobs jobs');
  }
}

/**
 * Implements hook_rules_event_info().
 *
 * Defines rules events.
 */
function drop_jobs_job_rules_event_info() {
  $events = array();

  // For the sake of convenience.
  $defaults = array(
    'group' => t('Drop Jobs Job'),
    'access callback' => 'drop_jobs_job_rules_access',
    'variables' => array(
      'job' => array(
        'label' => t('Job node object'),
        'type' => 'node',
        'skip save' => TRUE,
      ),
    ),
  );

  // Job becomes visible.
  $events['drop_jobs_job_visible'] = array(
    'label' => t('Job set to visible.'),
    ) + $defaults;

  // Job becomes hidden.
  $events['drop_jobs_job_hidden'] = array(
    'label' => t('Job set to hidden.'),
    ) + $defaults;

  // Job becomes automatically hidden.
  $events['drop_jobs_job_auto_hidden'] = array(
    'label' => t('Job set to hidden.'),
    ) + $defaults;

  return $events;
}

/**
 * Implements hook_rules_condition_info().
 */
function drop_jobs_job_rules_condition_info() {
  $conditions = array();

  // For convenience.
  $defaults = array(
    'group' => t('Drop Jobs Job'),
    'parameter' => array(
      'job' => array(
        'label' => t('Job node object'),
        'type' => 'node',
        'skip save' => TRUE,
      ),
    ),
  );

  $conditions['drop_jobs_job_visible'] = array(
    'label' => t("Check whether a given job is visible"),
    'base' => 'drop_jobs_job_condition_visible',
    ) + $defaults;

  $conditions['drop_jobs_job_hidden'] = array(
    'label' => t("Check whether a given job is hidden"),
    'base' => 'drop_jobs_job_condition_hidden',
    ) + $defaults;

  $conditions['drop_jobs_job_auto_hidden'] = array(
    'label' => t("Check whether a given job is automatically hidden"),
    'base' => 'drop_jobs_job_condition_auto_hidden',
    ) + $defaults;

  return $conditions;
}

/**
 * Implements hook_rules_action_info().
 */
function drop_jobs_job_rules_action_info() {
  $actions = array();

  // For convenience.
  $defaults = array(
    'group' => t('Drop Jobs Job'),
    'access callback' => 'drop_jobs_job_rules_access',
    'parameter' => array(
      'job' => array(
        'type' => 'node',
        'label' => t('Job node object'),
        'save' => FALSE,
      ),
    ),
  );

  // Show a job.
  $actions['drop_jobs_job_visible'] = array(
    'label' => t('Mark a job as visible'),
    'base' => 'drop_jobs_job_action_visible',
    ) + $defaults;

  // Hide a job.
  $actions['drop_jobs_job_hidden'] = array(
    'label' => t('Mark a job as hidden'),
    'base' => 'drop_jobs_job_action_hidden',
    ) + $defaults;

  // Auto hide a job.
  $actions['drop_jobs_job_hidden'] = array(
    'label' => t('Mark a job as automatically hidden'),
    'base' => 'drop_jobs_job_action_auto_hidden',
    ) + $defaults;

  // This rule receives a user account as a param.
  // Automatically hide a user's jobs.
  $actions['drop_jobs_job_auto_hide_by_user'] = array(
    'group' => t('Drop Jobs Job'),
    'parameter' => array(
      'account' => array(
        'type' => 'user',
        'label' => t('Recruiter user account'),
        'save' => FALSE,
      ),
    ),
    'label' => t("Automatically hide a user's jobs"),
    'base' => 'drop_jobs_job_action_auto_hide_by_user',
  );

  return $actions;
}

/**
 * Rules condition callback.
 *
 * Checks whether a given job is visible.
 *
 * @see drop_jobs_job_rules_condition_info()
 */
function drop_jobs_job_condition_visible($job) {
  return drop_jobs_job_is_visible($job);
}

/**
 * Rules condition callback.
 *
 * Checks whether a given job is visible.
 *
 * @see drop_jobs_job_rules_condition_info()
 */
function drop_jobs_job_condition_hidden($job) {
  return drop_jobs_job_is_hidden($job);
}

/**
 * Rules condition callback.
 *
 * Checks whether a given job is automatically hidden.
 *
 * @see drop_jobs_job_rules_condition_info()
 */
function drop_jobs_job_condition_auto_hidden($job) {
  return drop_jobs_job_is_auto_hidden($job);
}

/**
 * Rules action callback.
 *
 * Marks a given job as visible.
 *
 * @see drop_jobs_job_rules_action_info()
 */
function drop_jobs_job_action_visible($job) {
  return drop_jobs_job_set_visible($job);
}

/**
 * Rules action callback.
 *
 * Marks a given job as hidden.
 *
 * @see drop_jobs_job_rules_action_info()
 */
function drop_jobs_job_action_hidden($job) {
  return drop_jobs_job_set_hidden($job);
}

/**
 * Rules action callback.
 *
 * Marks a given job as automatically hidden.
 *
 * @see drop_jobs_job_rules_action_info()
 */
function drop_jobs_job_action_auto_hidden($job) {
  return drop_jobs_job_set_auto_hidden($job);
}

/**
 * Rules action callback.
 *
 * Sets all of a user's jobs workflow statuses to "automatically hidden".
 *
 * @see drop_jobs_job_rules_action_info()
 */
function drop_jobs_job_action_auto_hide_by_user(stdClass $user) {
  foreach (drop_jobs_job_find_by_user($user->uid) as $nid) {
    drop_jobs_job_set_auto_hidden($nid);
  }
}
