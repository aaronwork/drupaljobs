<?php
/**
 * @file
 * Drop Jobs Recommendation admin settings.
 */

/**
 * Form callback
 *
 * @see drop_jobs_recommendation_menu().
 */
function drop_jobs_recommendation_settings() {
  $form = array();

  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Recommendation settings'),
    '#collapsible' => FALSE,
  );

  $form['wrapper']['candidate'] = array(
    '#type' => 'fieldset',
    '#title' => t('Candidate settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['wrapper']['candidate']['drop_jobs_recommendation_candidate_enable'] = array(
    '#title' => t('Recommend jobs for candidates'),
    '#type' => 'checkbox',
    '#default_value' => variable_get_value('drop_jobs_recommendation_candidate_enable'),
  );

  if (module_exists('drop_jobs_subscription')) {
    $options = array();

    foreach (subs_get_types() as $type) {
      $options[$type->id] = $type->label;
    }

    $form['wrapper']['candidate']['drop_jobs_recommendation_candidate_subs'] = array(
      '#title' => t('Only for candidates with active subscriptions'),
      '#type' => 'checkbox',
      '#default_value' => variable_get_value('drop_jobs_recommendation_candidate_subs'),
      '#states' => array(
        'visible' => array(
          'input[name="drop_jobs_recommendation_candidate_enable"]' => array('checked' => TRUE),
        ),
      ),
    );

    $form['wrapper']['candidate']['drop_jobs_recommendation_candidate_subs_plans'] = array(
      '#title' => t('Enabled plans'),
      '#type' => 'checkboxes',
      '#description' => t('What plans are enabled for recommendations.'),
      '#options' => $options,
      '#default_value' => variable_get_value('drop_jobs_recommendation_candidate_subs_plans'),
      '#states' => array(
        'visible' => array(
          'input[name="drop_jobs_recommendation_candidate_subs"]' => array('checked' => TRUE),
        ),
      ),
    );
  }

  $form['wrapper']['job'] = array(
    '#type' => 'fieldset',
    '#title' => t('Job settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['wrapper']['job']['drop_jobs_recommendation_job_enable'] = array(
    '#title' => t('Recommend candidates for jobs'),
    '#type' => 'checkbox',
    '#default_value' => variable_get_value('drop_jobs_recommendation_job_enable'),
  );

  if (module_exists('drop_jobs_subscription')) {
    $form['wrapper']['job']['drop_jobs_recommendation_job_subs'] = array(
      '#title' => t("Only for jobs who's authors have active subscriptions"),
      '#type' => 'checkbox',
      '#default_value' => variable_get_value('drop_jobs_recommendation_job_subs'),
      '#states' => array(
        'visible' => array(
          'input[name="drop_jobs_recommendation_job_enable"]' => array('checked' => TRUE),
        ),
      ),
    );

    $form['wrapper']['job']['drop_jobs_recommendation_job_subs_plans'] = array(
      '#title' => t('Enabled plans'),
      '#type' => 'checkboxes',
      '#description' => t('What plans are enabled for recommendations.'),
      '#options' => $options,
      '#default_value' => variable_get_value('drop_jobs_recommendation_job_subs_plans'),
      '#states' => array(
        'visible' => array(
          'input[name="drop_jobs_recommendation_job_subs"]' => array('checked' => TRUE),
        ),
      ),
    );
  }

  $form['wrapper']['drop_jobs_recommendation_bias'] = array(
    '#type' => 'fieldset',
    '#title' => t('Field Bias'),
    '#description' => t('These are the fields in common between jobs and candidate resumes. Change the bias to make certain fields more relevant than others.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $job_fields = drop_jobs_recommendation_entity_get_fields('node', 'job');

  foreach (drop_jobs_recommendation_map() as $job_field => $resume_field) {
    $form['wrapper']['drop_jobs_recommendation_bias']["djrb_{$job_field}"] = array(
      '#title' => $job_field === 'title' ? t('Job Title') : $job_fields[$job_field]['label'],
      '#type' => 'textfield',
      '#size' => 4,
      '#default_value' => variable_get("djrb_{$job_field}", 1),
    );
  }

  return system_settings_form($form);
}

/**
 * Form callback.
 * Generates the recommendation form.
 */
function drop_jobs_recommendation_form($form, &$form_state, $recommendation) {
  $form_state['recommendation'] = $recommendation;
  $admin = user_access('administer drop_jobs recommendations');

  // Only show job and user fields if user has permission.
  if ($admin) {
    if (isset($recommendation->nid)) {
      $node = node_load($recommendation->nid);
    }

    $form['nid'] = array(
      '#type' => 'textfield',
      '#title' => t('Job'),
      '#autocomplete_path' => 'jobs/autocomplete',
      '#default_value' => isset($node) ? "{$node->title} [nid:{$node->nid}]" : '',
      '#required' => TRUE,
    );

    if (isset($recommendation->uid)) {
      $user = user_load($recommendation->uid);
    }

    $form['uid'] = array(
      '#type' => 'textfield',
      '#title' => t('User'),
      '#autocomplete_path' => 'user/autocomplete',
      '#default_value' => isset($user) ? $user->name : '',
      '#required' => TRUE,
    );
  }

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save recommendation'),
    '#submit' => $submit + array('drop_jobs_recommendation_form_submit'),
  );

  // Display delete button if we're editing the recommendation and have
  // permission.
  if (!empty($aid) && drop_jobs_recommendation_access('edit', $recommendation)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#limit_validation_errors' => array(),
      '#submit' => array('drop_jobs_recommendation_form_submit_delete'),
    );
  }

  return $form;
}

/**
 * Validatation callback.
 *
 * @see drop_jobs_recommendation_form()
 */
function drop_jobs_recommendation_form_validate(&$form, &$form_state) {
  // Make sure we have a valid user.
  if (!$user = user_load_by_name($form_state['values']['uid'])) {
    form_set_error('uid', t('Invalid candidate.'));
  } else {
    form_set_value($form['uid'], $user->uid, $form_state);
  }

  // Make sure we have a valid job node.
  $matches = array();
  preg_match("/\[nid:([0-9])+\]/", $form_state['values']['nid'], $matches);
  $matches = reset($matches);
  $pass = FALSE;
  if (!empty($matches)) {
    $matches = str_replace(array('[nid:', ']'), '', $matches);
    if (is_numeric($matches)) {
      if ($node = node_load($matches)) {
        if ($node->type === 'job') {
          $pass = TRUE;
          form_set_value($form['nid'], $node->nid, $form_state);
        }
      }
    }
  }

  if ($pass !== TRUE) {
    form_set_error('nid', t('Invalid job.'));
  }
}

/**
 * Submit callback.
 * Saves a recommendation.
 *
 * @see drop_jobs_recommendation_form()
 */
function drop_jobs_recommendation_form_submit(&$form, &$form_state) {
  $recommendation = $form_state['recommendation'];

  // Build entity.
  entity_form_submit_build_entity('drop_jobs_recommendation', $recommendation, $form, $form_state);

  // Save entity.
  drop_jobs_recommendation_save($recommendation);

  // Redirect.
  $recommendation_uri = entity_uri('drop_jobs_recommendation', $recommendation);
  $form_state['redirect'] = $recommendation_uri['path'];

  // Success message.
  drupal_set_message(t('%title saved.', array('%title' => entity_label('drop_jobs_recommendation', $recommendation))));
}

/**
 * Submit callback.
 * Redirects to recommendation delete confirmation form.
 *
 * @see drop_jobs_recommendation_form()
 */
function drop_jobs_recommendation_form_submit_delete($form, &$form_state) {
  $recommendation = $form_state['recommendation'];
  $recommendation_uri = entity_uri('drop_jobs_recommendation', $recommendation);
  $form_state['redirect'] = $recommendation_uri['path'] . '/delete';
}

/**
 * Form callback.
 * Displays recommendation delete confirmation form.
 *
 * @see drop_jobs_recommendation_menu()
 */
function drop_jobs_recommendation_delete_form($form, &$form_state, $recommendation) {
  $form_state['recommendation'] = $recommendation;

  // Always provide entity id in the same form key as in the entity edit form.
  $form['rid'] = array('#type' => 'value', '#value' => entity_id('drop_jobs_recommendation', $recommendation));
  $recommendation_uri = entity_uri('drop_jobs_recommendation', $recommendation);
  return confirm_form($form, t('Are you sure you want to delete %title?', array('%title' => entity_label('drop_jobs_recommendation', $recommendation))), $recommendation_uri['path'], t('This action cannot be undone.'), t('Delete'), t('Cancel'));
}

/**
 * Submit handler.
 * Deletes a recommendation.
 *
 * @see drop_jobs_recommendation_delete_form()
 */
function drop_jobs_recommendation_delete_form_submit($form, &$form_state) {
  $recommendation = $form_state['recommendation'];

  // Delete recommendation.
  drop_jobs_recommendation_delete($recommendation);

  // Redirect to front page.
  $form_state['redirect'] = '<front>';

  // Success message.
  drupal_set_message(t('%title deleted.', array('%title' => entity_label('drop_jobs_recommendation', $recommendation))));
}