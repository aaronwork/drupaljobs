<?php
/**
 * @file
 * Drop Jobs Application pages.
 */

/**
 * Application view callback.
 * Displays an application entity.
 *
 * @see drop_jobs_application_menu()
 */
function drop_jobs_application_view($application) {
  drupal_set_title(entity_label('drop_jobs_application', $application));
  return entity_view('drop_jobs_application', array(entity_id('drop_jobs_application', $application) => $application), 'full');
}

/**
 * Form callback.
 *
 * Shows a confirmation form for applying to a job.
 *
 * @see drop_jobs_application_menu()
 */
function drop_jobs_application_form_apply($form, $form_state, $nid) {
  // Redirect anonymous users to registration page.
  // This is necessary because we can deliberately let anonymous users see the
  // "Apply to job" link but will sneakily redirect to user/register. Muahahaha.
  if (user_is_anonymous()) {
    drupal_goto('user/register', array('query' => array('destination' => 'node/' . $nid . '/apply')));
  }

  // Load allowed application type for this job.
  $application_type = drop_jobs_application_allowed($nid);
  $node = node_load($nid);

  // Build application form.
  $form = array();

  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid,
  );

  $form['type'] = array(
    '#type' => 'hidden',
    '#value' => $application_type,
  );

  $custom_text = variable_get_value('drop_jobs_application_text');
  if (isset($custom_text['value']) && !empty($custom_text['value'])) {
    $form['custom_text'] = array(
      '#markup' => $custom_text['value'],
    );
  }

  $application = entity_create('drop_jobs_application', array('type' => $application_type));
  field_attach_form('drop_jobs_application', $application, $form, $form_state);

  $form['#validate'][] = 'drop_jobs_application_form_apply_validate_apply';
  $form['#submit'][] = 'drop_jobs_application_form_apply_submit_apply';

  return confirm_form($form, t('Apply to job %title?', array('%title' => $node->title)), 'node/' . $nid, '', t('Apply'), t('Cancel'));
}

/**
 * Validation callback.
 *
 * @see drop_jobs_application_form_apply()
 */
function drop_jobs_application_form_apply_validate_apply($form, &$form_state) {
  // Make sure a valid job is selected.
  if (!is_numeric($form_state['values']['nid'])) {
    form_set_error($form['nid'], t('Invalid job.'));
  }

  // Make sure a valid application type is selected.
  $allowed = drop_jobs_application_allowed($form_state['values']['nid']);
  if ($allowed !== $form_state['values']['type']) {
    form_set_error($form['type'], t('Invalid application type.'));
  }
}

/**
 * Submit callback.
 *
 * @see drop_jobs_application_form_apply().
 */
function drop_jobs_application_form_apply_submit_apply($form, &$form_state) {
  $nid = $form_state['values']['nid'];
  $type = $form_state['values']['type'];
  $account = user_uid_optional_load();
  $node = node_load($nid);

  // Prepare values for creating new application.
  $values = array(
    'user' => $account,
    'node' => $nid,
    'type' => $type,
    'status' => DROP_JOBS_APPLICATION_NEW
  );
  $application = drop_jobs_application_create($values);

  // Attach extra submitted values to application.
  entity_form_submit_build_entity('drop_jobs_application', $application, $form, $form_state);

  if (drop_jobs_application_save($application)) {
    // Invoke rules event.
    // This is done here instead of on the entity-level because an application
    // entity can technically be edited and saved after being created.
    rules_invoke_event('drop_jobs_application_apply', $application);

    if (variable_get_value('drop_jobs_log')) {
      watchdog('drop_jobs_application', 'User: %user applied to job: %job', array('%user' => $account->name, '%job' => $node->title), WATCHDOG_INFO);
    }

    drupal_set_message(t('You have successfully applied to the job: @name!', array('@name' => $node->title)));
    drupal_goto('node/' . $nid);
  }

  watchdog('drop_jobs_application', 'Error for user: %user applying to job: %job', array('%user' => $account->name, '%job' => $node->title), WATCHDOG_ERROR);
  drupal_set_message(t('An error ocurred when applying to this job, please contact the site administrators.'), 'error');
}

/**
 * Form callback.
 *
 * Shows a confirmation form for unapplying to a job.
 *
 * @see drop_jobs_application_menu().
 */
function drop_jobs_application_form_unapply($form, $form_state, $nid) {
  $form = array();

  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid,
  );

  $form['confirm'] = array(
    '#type' => 'checkbox',
    '#title' => t('Confirm application removal'),
    '#description' => t('Check the above box to confirm your application removal'),
    '#default_value' => FALSE,
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit')
  );

  return $form;
}

/**
 * Validate callback.
 *
 * @see drop_jobs_application_form_unapply().
 */
function drop_jobs_application_form_unapply_validate($form, &$form_state) {
  if (!is_numeric($form_state['values']['nid'])) {
    form_set_error($form_state['values']['nid'], t('Invalid job.'));
  }
}

/**
 * Submit callback.
 *
 * @see drop_jobs_application_form_apply().
 */
function drop_jobs_application_form_unapply_submit($form, &$form_state) {
  $nid = $form_state['values']['nid'];
  $account = user_uid_optional_load();
  $node = node_load($nid);

  if ($application = drop_jobs_application_load_by_user_and_node($account, $nid)) {
    if (drop_jobs_application_set_revoked($application)) {
      // Invoke rules event.
      rules_invoke_event('drop_jobs_application_revoke', $application);

      if (variable_get_value('drop_jobs_log')) {
        watchdog('drop_jobs_application', 'User: %user removed application to job: %job', array('%user' => $account->name, '%job' => $node->title), WATCHDOG_INFO);
      }

      drupal_set_message(t('You have successfully removed your job application!'));
      drupal_goto('node/' . $nid);
    }
  }

  drupal_set_message(t('An error ocurred when removing your job application, please contact the site administrators.'), 'error');
  watchdog('drop_jobs_application', 'Error for user: %user removing application to job: %job', array('%user' => $account->name, '%job' => $node->title), WATCHDOG_ERROR);
}
