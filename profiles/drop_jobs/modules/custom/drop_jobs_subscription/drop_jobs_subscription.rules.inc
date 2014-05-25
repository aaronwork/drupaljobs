<?php
/**
 * @file
 * Drop Jobs Subscription Rules integration.
 */

/**
 * Implements hook_rules_event_info().
 *
 * Defines rules events.
 */
function drop_jobs_subscription_rules_event_info() {
  $events = array();

  // For the sake of convenience.
  $defaults = array(
    'group' => t('Drop Jobs Subscription'),
    'variables' => array(
      'subscription' => array(
        'label' => t('Subscription object'),
        'type' => 'node',
        'bundle' => 'subscription',
        'skip save' => TRUE,
      ),
    ),
  );

  // User subscribes to a subscription plan.
  $events['drop_jobs_subscription_subscribe'] = array(
    'label' => t('User subscribes to a plan'),
  ) + $defaults;

  // User renews a subscription plan.
  $events['drop_jobs_subscription_renew'] = array(
    'label' => t('User renews a subscription'),
  ) + $defaults;

  // User cancels a subscription plan.
  $events['drop_jobs_subscription_cancel'] = array(
    'label' => t('User cancels a subscription'),
  ) + $defaults;

  return $events;
}