<?php
/**
 * @file
 * Drop Jobs Job Actions integration.
 */

/**
 * Implements hook_action_info().
 */
function drop_jobs_job_action_info() {
  return array(
    'drop_jobs_job_action_set_visible' => array(
      'label' => t('Set job workflow state to visible'),
      'type' => 'node',
      'configurable' => FALSE,
      'trigger' => array('any'),
      'behavior' => array('changes_property'),
    ),
    'drop_jobs_job_action_set_hidden' => array(
      'label' => t('Set job workflow state to hidden'),
      'type' => 'node',
      'configurable' => FALSE,
      'trigger' => array('any'),
      'behavior' => array('changes_property'),
    ),
    'drop_jobs_job_action_set_autohidden' => array(
      'label' => t('Set job workflow state to automatically hidden'),
      'type' => 'node',
      'configurable' => FALSE,
      'trigger' => array('any'),
      'behavior' => array('changes_property'),
    ),
  );
}

/**
 * Sets a job's workflow status to "Visible".
 *
 * @param stdClass
 *   An optional node object.
 * @param array
 *   Array with components:
 *   - 'nid': Node ID. Required if $node is not given.
 *
 * @ingroup actions
 */
function drop_jobs_job_action_set_visible($node = NULL, $context = array()) {
  if (!isset($node)) {
    if (!isset($context['nid'])) {
      return FALSE;
    }
    $node = node_load($context['nid']);
  }

  if (drop_jobs_job_set_visible($node) && variable_get('drop_jobs_log', FALSE)) {
    watchdog('drop_jobs_job', 'VBO - Set job: %job workflow state to "Visible"', array('%job' => $node->title), WATCHDOG_INFO);
  }
}

/**
 * Sets a job's workflow status to "Hidden".
 *
 * @param stdClass
 *   An optional node object.
 * @param array
 *   Array with components:
 *   - 'nid': Node ID. Required if $node is not given.
 *
 * @ingroup actions
 */
function drop_jobs_job_action_set_hidden($node = NULL, $context = array()) {
  if (!isset($node)) {
    if (!isset($context['nid'])) {
      return FALSE;
    }
    $node = node_load($context['nid']);
  }

  if (drop_jobs_job_set_hidden($node) && variable_get('drop_jobs_log', FALSE)) {
    watchdog('drop_jobs_job', 'VBO - Set job: %job workflow state to "Hidden"', array('%job' => $node->title), WATCHDOG_INFO);
  }
}

/**
 * Sets a job's workflow status to "Automatically Hidden".
 *
 * @param stdClass
 *   An optional node object.
 * @param array
 *   Array with components:
 *   - 'nid': Node ID. Required if $node is not given.
 *
 * @ingroup actions
 */
function drop_jobs_job_action_set_autohidden($node = NULL, $context = array()) {
  if (!isset($node)) {
    if (!isset($context['nid'])) {
      return FALSE;
    }
    $node = node_load($context['nid']);
  }

  if (drop_jobs_job_set_auto_hidden($node) && variable_get('drop_jobs_log', FALSE)) {
    watchdog('drop_jobs_job', 'VBO - Set job: %job workflow state to "Automatically Hidden"', array('%job' => $node->title), WATCHDOG_INFO);
  }
}
