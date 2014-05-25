<?php
/**
 * @file
 * Views handlers for Drop Jobs Subscription.
 */

/**
 * A handler to provide a subscription trial field.
 *
 * @ingroup views_field_handlers
 */
class drop_jobs_subscription_handler_field_trial extends views_handler_field {
  function query() {
    // Do nothing, as this handler does not need to do anything to the query itself.
  }

  /**
   * Render the trigger field and its linked popup information.
   */
  function render($values) {
    // Find out the subscription plans for which we have free trials.
    $plans = drop_jobs_subscription_plans();
    return array_key_exists($values->nid, $plans) ? '<strong>' . t('Eligible for Free Trial!') . '</strong>' : '';
  }
}