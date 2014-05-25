<?php
/**
 * @file
 * Drop Jobs Application Actions integration.
 */

/**
 * Implements hook_action_info().
 */
function drop_jobs_application_action_info() {
  return array(
    'drop_jobs_application_action_set_new' => array(
      'label' => t('Mark as new'),
      'type' => 'drop_jobs_application',
      'configurable' => FALSE,
      'trigger' => array('any'),
      'behavior' => array('changes_property'),
    ),
    'drop_jobs_application_action_set_read' => array(
      'label' => t('Mark as read'),
      'type' => 'drop_jobs_application',
      'configurable' => FALSE,
      'trigger' => array('any'),
      'behavior' => array('changes_property'),
    ),
    'drop_jobs_application_action_set_hidden' => array(
      'label' => t('Mark as hidden'),
      'type' => 'drop_jobs_application',
      'configurable' => FALSE,
      'trigger' => array('any'),
      'behavior' => array('changes_property'),
    ),
    'drop_jobs_application_action_set_revoked' => array(
      'label' => t('Mark as revoked'),
      'type' => 'drop_jobs_application',
      'configurable' => FALSE,
      'trigger' => array('any'),
      'behavior' => array('changes_property'),
    ),
  );
}

/**
 * Sets an applications status to "new".
 *
 * @param $application
 *   An optional application object.
 * @param array $context
 *   Array with components:
 *   - 'aid': Application ID. Required if $application is not given.
 *
 * @ingroup actions
 */
function drop_jobs_application_action_set_new($application = NULL, $context = array()) {
  if (!isset($application)) {
    if (!isset($context['aid'])) {
      return FALSE;
    }
    $application = drop_jobs_application_load($context['aid']);
  }

  if ($application instanceof DropJobsApplication) {
    $application->status = DROP_JOBS_APPLICATION_NEW;

    if (drop_jobs_application_save($application) && variable_get('drop_jobs_log', FALSE)) {
      $subject = entity_label('drop_jobs_application', $application);
      watchdog('drop_jobs_application', 'VBO - Marked application: %subject as "new"', array('%subject' => $subject), WATCHDOG_INFO);
    }
  }
}

/**
 * Sets an applications status to "read".
 *
 * @param $application
 *   An optional application object.
 * @param array $context
 *   Array with components:
 *   - 'aid': Application ID. Required if $application is not given.
 *
 * @ingroup actions
 */
function drop_jobs_application_action_set_read($application = NULL, $context = array()) {
  if (!isset($application)) {
    if (!isset($context['aid'])) {
      return FALSE;
    }
    $application = drop_jobs_application_load($context['aid']);
  }

  if ($application instanceof DropJobsApplication) {
    $application->status = DROP_JOBS_APPLICATION_READ;

    if (drop_jobs_application_save($application) && variable_get('drop_jobs_log', FALSE)) {
      $subject = entity_label('drop_jobs_application', $application);
      watchdog('drop_jobs_application', 'VBO - Marked application: %subject as "read"', array('%subject' => $subject), WATCHDOG_INFO);
    }
  }
}

/**
 * Sets an applications status to "hidden".
 *
 * @param $application
 *   An optional application object.
 * @param array $context
 *   Array with components:
 *   - 'aid': Application ID. Required if $application is not given.
 *
 * @ingroup actions
 */
function drop_jobs_application_action_set_hidden($application = NULL, $context = array()) {
  if (!isset($application)) {
    if (!isset($context['aid'])) {
      return FALSE;
    }
    $application = drop_jobs_application_load($context['aid']);
  }

  if ($application instanceof DropJobsApplication) {
    $application->status = DROP_JOBS_APPLICATION_HIDDEN;

    if (drop_jobs_application_save($application) && variable_get('drop_jobs_log', FALSE)) {
      $subject = entity_label('drop_jobs_application', $application);
      watchdog('drop_jobs_application', 'VBO - Marked application: %subject as "hidden"', array('%subject' => $subject), WATCHDOG_INFO);
    }
  }
}

/**
 * Sets an applications status to "revoked".
 *
 * @param $application
 *   An optional application object.
 * @param array $context
 *   Array with components:
 *   - 'aid': Application ID. Required if $application is not given.
 *
 * @ingroup actions
 */
function drop_jobs_application_action_set_revoked($application = NULL, $context = array()) {
  if (!isset($application)) {
    if (!isset($context['aid'])) {
      return FALSE;
    }
    $application = drop_jobs_application_load($context['aid']);
  }

  if ($application instanceof DropJobsApplication) {
    $application->status = DROP_JOBS_APPLICATION_REVOKED;

    if (drop_jobs_application_save($application) && variable_get('drop_jobs_log', FALSE)) {
      $subject = entity_label('drop_jobs_application', $application);
      watchdog('drop_jobs_application', 'VBO - Marked application: %subject as "revoked"', array('%subject' => $subject), WATCHDOG_INFO);
    }
  }
}
