<?php
/**
 * @file
 * Drop Jobs Subscription views hooks.
 */

/**
 * Implements hook_views_data().
 */
function drop_jobs_subscription_views_data() {
  return array(
    'drop_jobs_subscription' => array(
      'table' => array(
        'group' => t('Drop Jobs Subscription'),
        'join' => array('#global' => array()),
      ),
      'trial' => array(
        'title' => t('Trial'),
        'help' => t('Provide text indicating whether the subscription plan is available for a free trial. Will return an empty string if the node is not of type subscription or does not have a free trial.'),
        'field' => array(
          'handler' => 'drop_jobs_subscription_handler_field_trial',
        ),
      ),
    ),
  );
}