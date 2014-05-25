<?php
/**
 * @file
 * Drop Jobs Candidate Rules integration.
 */

/**
 * Access callback.
 *
 * @see drop_jobs_candidate_rules_event_info()
 * @see drop_jobs_candidate_rules_action_info()
 */
function drop_jobs_candidate_rules_access($type, $name) {
  if ($type === 'event' || $type === 'condition') {
    return user_access('administer drop_jobs candidates');
  }
}

/**
 * Implements hook_rules_event_info().
 *
 * Defines rules events.
 */
function drop_jobs_candidate_rules_event_info() {
  $events = array();

  // For the sake of convenience.
  $defaults = array(
    'group' => t('Drop Jobs Candidate'),
    'access callback' => 'drop_jobs_candidate_rules_access',
    'variables' => array(
      'profile' => array(
        'label' => t('Resume profile object'),
        'type' => 'profile2',
        'skip save' => TRUE,
      ),
    ),
  );

  // Candidate résumé becomes complete.
  $events['drop_jobs_candidate_complete'] = array(
    'label' => t('Candidate completes his résumé.'),
    ) + $defaults;

  // Candidate résumé becomes incomplete.
  $events['drop_jobs_candidate_incomplete'] = array(
    'label' => t('Candidate un-completes his résumé.'),
    ) + $defaults;

  // Candidate résumé becomes visible.
  $events['drop_jobs_candidate_visible'] = array(
    'label' => t('Résumé set to visible.'),
    ) + $defaults;

  // Candidate résumé becomes hidden.
  $events['drop_jobs_candidate_hidden'] = array(
    'label' => t('Résumé set to hidden.'),
    ) + $defaults;

  // Candidate résumé becomes automatically hidden.
  $events['drop_jobs_candidate_auto_hidden'] = array(
    'label' => t('Résumé set to hidden.'),
    ) + $defaults;

  return $events;
}

/**
 * Implements hook_rules_condition_info().
 */
function drop_jobs_candidate_rules_condition_info() {
  $conditions = array();

  // For convenience.
  $defaults = array(
    'group' => t('Drop Jobs Candidate'),
    'parameter' => array(
      'profile' => array(
        'label' => t('Resume profile object'),
        'type' => 'profile2',
        'skip save' => TRUE,
      ),
    ),
  );

  $conditions['drop_jobs_candidate_visible'] = array(
    'label' => t("Check whether a given candidate's résumé is visible"),
    'base' => 'drop_jobs_candidate_condition_visible',
    ) + $defaults;

  $conditions['drop_jobs_candidate_hidden'] = array(
    'label' => t("Check whether a given candidate's résumé is hidden"),
    'base' => 'drop_jobs_candidate_condition_hidden',
    ) + $defaults;

  $conditions['drop_jobs_candidate_auto_hidden'] = array(
    'label' => t("Check whether a given candidate's résumé is automatically hidden"),
    'base' => 'drop_jobs_candidate_condition_auto_hidden',
    ) + $defaults;

  return $conditions;
}

/**
 * Implements hook_rules_action_info().
 */
function drop_jobs_candidate_rules_action_info() {
  $actions = array();

  // For convenience.
  $defaults = array(
    'group' => t('Drop Jobs Candidate'),
    'access callback' => 'drop_jobs_candidate_rules_access',
    'parameter' => array(
      'profile' => array(
        'type' => 'profile2',
        'label' => t('Profile object'),
        'save' => FALSE,
      ),
    ),
  );

  // Show a resume.
  $actions['drop_jobs_candidate_visible'] = array(
    'label' => t('Mark a résumé as visible'),
    'base' => 'drop_jobs_resume_action_visible',
    ) + $defaults;

  // Hide a resume.
  $actions['drop_jobs_candidate_hidden'] = array(
    'label' => t('Mark a résumé as hidden'),
    'base' => 'drop_jobs_resume_action_hidden',
    ) + $defaults;

  // Auto hide a resume.
  $actions['drop_jobs_candidate_hidden'] = array(
    'label' => t('Mark a résumé as automatically hidden'),
    'base' => 'drop_jobs_resume_action_auto_hidden',
    ) + $defaults;

  return $actions;
}

/**
 * Rules condition callback.
 *
 * Checks whether a given résumé is visible.
 *
 * @see drop_jobs_candidate_rules_condition_info()
 */
function drop_jobs_candidate_condition_visible(Profile $profile) {
  return drop_jobs_candidate_is_visible($profile);
}

/**
 * Rules condition callback.
 *
 * Checks whether a given résumé is visible.
 *
 * @see drop_jobs_candidate_rules_condition_info()
 */
function drop_jobs_candidate_condition_hidden(Profile $profile) {
  return drop_jobs_candidate_is_hidden($profile);
}

/**
 * Rules condition callback.
 *
 * Checks whether a given résumé is automatically hidden.
 *
 * @see drop_jobs_candidate_rules_condition_info()
 */
function drop_jobs_candidate_condition_auto_hidden(Profile $profile) {
  return drop_jobs_candidate_is_auto_hidden($profile);
}

/**
 * Rules action callback.
 *
 * Marks a given résumé as visible.
 *
 * @see drop_jobs_candidate_rules_action_info()
 */
function drop_jobs_resume_action_visible(Profile $profile) {
  return drop_jobs_candidate_set_visible($profile);
}

/**
 * Rules action callback.
 *
 * Marks a given résumé as hidden.
 *
 * @see drop_jobs_candidate_rules_action_info()
 */
function drop_jobs_resume_action_hidden(Profile $profile) {
  return drop_jobs_candidate_set_hidden($profile);
}

/**
 * Rules action callback.
 *
 * Marks a given résumé as automatically hidden.
 *
 * @see drop_jobs_candidate_rules_action_info()
 */
function drop_jobs_resume_action_auto_hidden(Profile $profile) {
  return drop_jobs_candidate_set_auto_hidden($profile);
}
