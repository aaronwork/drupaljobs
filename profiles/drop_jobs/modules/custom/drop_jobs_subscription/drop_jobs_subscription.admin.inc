<?php
/**
 * @file
 * Drop Jobs Subscription admin settings.
 */

/**
 * Form callback
 *
 * @see drop_jobs_subscription_menu().
 */
function drop_jobs_subscription_settings() {
  $form = array();

  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Subscription settings'),
    '#collapsible' => FALSE,
  );

  $form['wrapper']['trial'] = array(
    '#type' => 'fieldset',
    '#title' => t('Trial settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $drop_jobs_subscription_trial = variable_get_value('drop_jobs_subscription_trial');

  $form['wrapper']['trial']['drop_jobs_subscription_trial'] = array(
    '#title' => t('Enable free trials'),
    '#type' => 'checkbox',
    '#description' => t('Check this option to enable free trials for your subscriptions.'),
    '#default_value' => $drop_jobs_subscription_trial,
  );

  $form['wrapper']['trial']['trial_container'] = array(
    '#type' => 'container',
    '#states' => array(
      'invisible' => array(
        'input[name="drop_jobs_subscription_trial"]' => array('checked' => FALSE),
      ),
    ),
  );

  $form['wrapper']['trial']['trial_container']['drop_jobs_subscription_trial_length'] = array(
    '#title' => t('Trial length'),
    '#type' => 'textfield',
    '#description' => t('How long the free trial lasts, in days.'),
    '#default_value' => variable_get_value('drop_jobs_subscription_trial_length'),
    '#size' => 2,
  );

  $options = array();

  foreach (subs_get_types() as $type) {
    $options[$type->id] = $type->label;
  }

  $form['wrapper']['trial']['trial_container']['drop_jobs_subscription_trial_plans'] = array(
    '#title' => t('Enabled plans'),
    '#type' => 'checkboxes',
    '#description' => t('What plans are enabled for the free trial.'),
    '#options' => $options,
    '#default_value' => variable_get_value('drop_jobs_subscription_trial_plans'),
  );

  $form['wrapper']['workflow'] = array(
    '#type' => 'fieldset',
    '#title' => t('Workflow settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

//  $form['wrapper']['workflow']['drop_jobs_subscription_restrict_subs'] = array(
//    '#type' => 'checkbox',
//    '#title' => t('Only allow recruiters to subscribe to a plan when their profile is complete'),
//    '#default_value' => variable_get_value('drop_jobs_subscription_restrict_subs'),
//  );

  $form['wrapper']['workflow']['drop_jobs_subscription_restrict_jobs'] = array(
    '#type' => 'checkbox',
    '#title' => t('Only allow recruiters with active subscriptions to create jobs'),
    '#default_value' => variable_get_value('drop_jobs_subscription_restrict_jobs'),
  );

  $form['wrapper']['workflow']['drop_jobs_subscription_restrict_jobs_plans'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Subscription plans'),
    '#description' => t('Recruiters must have an active subscription of one of the following types in order to create jobs.'),
    '#options' => $options,
    '#default_value' => variable_get_value('drop_jobs_subscription_restrict_jobs_plans'),
    '#states' => array(
      'visible' => array(
        'input[name="drop_jobs_subscription_restrict_jobs"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['wrapper']['links'] = array(
    '#type' => 'fieldset',
    '#title' => t('Links'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $links = array();
  $destination = drupal_get_destination();

  $links['subs'] = array(
    'title' => t('Subs module settings'),
    'href' => 'admin/config/workflow/subs',
    'query' => $destination,
  );

  $form['wrapper']['links']['subs'] = array(
    '#theme' => 'links',
    '#links' => $links,
    '#attributes' => array('class' => array('links', 'inline')),
  );

  return system_settings_form($form);
}

/**
 * Validate callback
 *
 * @see drop_jobs_subscription_settings().
 */
function drop_jobs_subscription_settings_validate($form, &$form_state) {
  if (!is_numeric($form_state['values']['drop_jobs_subscription_trial_length'])) {
    form_set_error($form_state['values']['drop_jobs_subscription_trial_length'], t('Subscription trial length must be numeric.'));
  }
  else if (!$form_state['values']['drop_jobs_subscription_trial_length'] > 0) {
    form_set_error($form_state['values']['drop_jobs_subscription_trial_length'], t('Subscription trial length must be greater than 0.'));
  }
}