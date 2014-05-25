<?php
/**
 * @file
 * Drop Jobs Candidate Actions integration.
 */

/**
 * Implements hook_action_info().
 */
function drop_jobs_candidate_action_info() {
  return array(
    'drop_jobs_candidate_action_set_visible' => array(
      'label' => t('Set résumé workflow state to visible'),
      'type' => 'profile2',
      'configurable' => FALSE,
      'trigger' => array('any'),
      'behavior' => array('changes_property'),
    ),
    'drop_jobs_candidate_action_set_hidden' => array(
      'label' => t('Set résumé workflow state to hidden'),
      'type' => 'profile2',
      'configurable' => FALSE,
      'trigger' => array('any'),
      'behavior' => array('changes_property'),
    ),
    'drop_jobs_candidate_action_set_autohidden' => array(
      'label' => t('Set résumé workflow state to automatically hidden'),
      'type' => 'profile2',
      'configurable' => FALSE,
      'trigger' => array('any'),
      'behavior' => array('changes_property'),
    ),
  );
}

/**
 * Sets a résumé's workflow status to "Visible".
 *
 * @param Profile
 *   An optional Profile object.
 * @param array
 *   Array with components:
 *   - 'pid': Profile ID. Required if $profile is not given.
 *
 * @ingroup actions
 */
function drop_jobs_candidate_action_set_visible($profile = NULL, $context = array()) {
  if (!isset($profile)) {
    if (!isset($context['pid'])) {
      return FALSE;
    }
    $profile = profile2_load($context['pid']);
  }

  if ($profile instanceof Profile) {
    if (drop_jobs_candidate_set_visible($profile) && variable_get('drop_jobs_log', FALSE)) {
      watchdog('drop_jobs_candidate', 'VBO - Set résumé: %resume workflow state to "Visible"', array('%resume' => $profile->label), WATCHDOG_INFO);
    }
  }
}

/**
 * Sets a résumé's workflow status to "Hidden".
 *
 * @param Profile
 *   An optional Profile object.
 * @param array
 *   Array with components:
 *   - 'pid': Profile ID. Required if $profile is not given.
 *
 * @ingroup actions
 */
function drop_jobs_candidate_action_set_hidden($profile = NULL, $context = array()) {
  if (!isset($profile)) {
    if (!isset($context['pid'])) {
      return FALSE;
    }
    $profile = profile2_load($context['pid']);
  }

  if ($profile instanceof Profile) {
    if (drop_jobs_candidate_set_hidden($profile) && variable_get('drop_jobs_log', FALSE)) {
      watchdog('drop_jobs_candidate', 'VBO - Set résumé: %resume workflow state to "Hidden"', array('%resume' => $profile->label), WATCHDOG_INFO);
    }
  }
}

/**
 * Sets a résumé's workflow status to "Automatically Hidden".
 *
 * @param Profile
 *   An optional Profile object.
 * @param array
 *   Array with components:
 *   - 'pid': Profile ID. Required if $profile is not given.
 *
 * @ingroup actions
 */
function drop_jobs_candidate_action_set_autohidden($profile = NULL, $context = array()) {
  if (!isset($profile)) {
    if (!isset($context['pid'])) {
      return FALSE;
    }
    $profile = profile2_load($context['pid']);
  }

  if ($profile instanceof Profile) {
    if (drop_jobs_candidate_set_auto_hidden($profile) && variable_get('drop_jobs_log', FALSE)) {
      watchdog('drop_jobs_candidate', 'VBO - Set résumé: %resume workflow state to "Automatically Hidden"', array('%resume' => $profile->label), WATCHDOG_INFO);
    }
  }
}
