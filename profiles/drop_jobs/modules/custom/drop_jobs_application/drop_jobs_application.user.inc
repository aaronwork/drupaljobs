<?php
/**
 * @file
 * Drop Jobs Application user preferences forms.
 */

/**
 * Form callback.
 *
 * Displays user email preferences form.
 *
 * @see drop_jobs_application_menu()
 */
function drop_jobs_application_email_settings($form, $form_state) {
  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Email notifications'),
    '#collapsible' => FALSE,
  );

  // Get user id.
  $account = user_uid_optional_load();
  $uid = $account->uid;

  // Email frequency.
  $default = user_variable_get('drop_jobs_application_email_frequency', FALSE, $uid);
  $form['wrapper']['frequency'] = array(
    '#title' => t('Email frequency'),
    '#description' => t('Configure how often you would like to receive emails for applications to your jobs.'),
    '#type' => 'select',
    '#options' => array(
      DROP_JOBS_APPLICATION_EMAIL_NONE => t('Never'),
      DROP_JOBS_APPLICATION_EMAIL_ALL => t('For every application'),
      DROP_JOBS_APPLICATION_EMAIL_DAILY => t('Daily Digest'),
      DROP_JOBS_APPLICATION_EMAIL_WEEKLY => t('Weekly Digest'),
    ),
    '#default_value' => ($default === FALSE) ? DROP_JOBS_APPLICATION_EMAIL_DAILY : $default,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Submit callback.
 *
 * @see drop_jobs_application_email_settings()
 */
function drop_jobs_application_email_settings_submit(&$form, &$form_state) {
  // Get user id.
  $account = user_uid_optional_load();
  $uid = $account->uid;

  // Alias for convenience.
  $values =& $form_state['values'];

  // Save settings.
  user_variable_set('drop_jobs_application_email_frequency', $values['frequency'], FALSE, $uid);

  drupal_set_message(t('Email notification preferences saved.'));
}