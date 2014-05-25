<?php
/**
 * @file
 * Drop Jobs Application settings and admin UI.
 */

/**
 * Form callback.
 *
 * @see drop_jobs_application_menu()
 */
function drop_jobs_application_settings($form, $form_state) {
  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Application settings'),
    '#collapsible' => FALSE,
  );

  $form['wrapper']['drop_jobs_application_anonymous'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display "Apply to job" link to anonymous users'),
    '#description' => t("Clicking on the link will send them to the login form and redirect them back once they've logged in. This can be an interesting way to increase candidate registrations."),
    '#default_value' => variable_get_value('drop_jobs_application_anonymous'),
  );

  $custom_text = variable_get_value('drop_jobs_application_text');
  $default_text = isset($custom_text['value']) ? $custom_text['value'] : '';

  $form['wrapper']['drop_jobs_application_text'] = array(
    '#type' => 'text_format',
    '#rows' => 4,
    '#title' => t('Display text on application forms'),
    '#description' => t('Optional. Enter some some custom text to display at the top of each job application form.'),
    '#default_value' => $default_text,
    '#format' => 'filtered_html',
  );

  return system_settings_form($form);
}

/**
 * Drop Jobs Application Type UI controller.
 */
class DropJobsApplicationTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage job applications, including fields.';
    return $items;
  }

}

/**
 * Form callback.
 * Generates the application type edit form.
 */
function drop_jobs_application_type_form($form, &$form_state, $application_type, $op = 'edit') {
  if ($op == 'clone') {
    $application_type->label .= ' (cloned)';
    $application_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $application_type->label,
    '#description' => t('The human-readable name of this application type.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($application_type->type) ? $application_type->type
        : '',
    '#maxlength' => 32,
    '#disabled' => $application_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'drop_jobs_application_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this application type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => isset($application_type->description) ? $application_type->description
        : '',
    '#description' => t('A brief description of this application type.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save application type'),
    '#weight' => 40,
  );

  if (!$application_type->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete application type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('drop_jobs_application_type_form_submit_delete')
    );
  }
  return $form;
}

/**
 * Submit callback.
 * Handles saving job application types.
 *
 * @see drop_jobs_application_type_form()
 */
function drop_jobs_application_type_form_submit(&$form, &$form_state) {
  $application_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  $application_type->save();
  $form_state['redirect'] = 'admin/structure/job_applications';
}

/**
 * Submit callback.
 * Handles deleting job application types.
 *
 * @see drop_jobs_application_type_form()
 */
function drop_jobs_application_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/job_applications/manage/' . $form_state['drop_jobs_application_type']->type . '/delete';
}

/**
 * Form callback.
 * Generates the application edit form.
 */
function drop_jobs_application_form($form, &$form_state, $application) {
  $form_state['application'] = $application;

  $options = array();
  foreach (drop_jobs_application_get_types() as $type => $object) {
    $options[$type] = $object->label;
  }

  $form['type'] = array(
    '#type' => 'select',
    '#title' => t('Application Type'),
    '#options' => $options,
    '#default_value' => $application->type,
  );

  $user = user_load($application->uid);

  $form['user'] = array(
    '#type' => 'textfield',
    '#title' => t('Candidate'),
    '#autocomplete_path' => 'user/autocomplete',
    '#default_value' => isset($user) ? $user->name : '',
  );

  $node = node_load($application->nid);

  $form['node'] = array(
    '#type' => 'textfield',
    '#title' => t('Job'),
    '#autocomplete_path' => 'jobs/autocomplete',
    '#default_value' => isset($node) ? "{$node->title} [nid:{$node->nid}]" : '',
  );

  $form['status'] = array(
    '#type' => 'select',
    '#title' => t('Status'),
    '#options' => drop_jobs_application_status_options_list(),
    '#default_value' => $application->status,
    '#weight' => 99,
  );

  field_attach_form('drop_jobs_application', $application, $form, $form_state);

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save application'),
    '#submit' => $submit + array('drop_jobs_application_form_submit'),
  );

  // Show Delete button if we edit application.
  $aid = entity_id('drop_jobs_application', $application);

  if (!empty($aid) && drop_jobs_application_access('edit', $application)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('drop_jobs_application_form_submit_delete'),
    );
  }

  return $form;
}

/**
 * Validatation callback.
 *
 * @see drop_jobs_application_form()
 */
function drop_jobs_application_form_validate(&$form, &$form_state) {
  // Make sure we have a valid user.
  if (!user_load_by_name($form_state['values']['user'])) {
    form_set_error('user', t('Invalid candidate.'));
  }

  // Make sure we have a valid type.
  if (!drop_jobs_application_get_types($form_state['values']['type'])) {
    form_set_error('type', t('Invalid application type.'));
  }

  // Make sure we have a valid job node.
  $matches = array();
  preg_match("/\[nid:([0-9])+\]/", $form_state['values']['node'], $matches);
  $matches = reset($matches);
  $pass = FALSE;
  if (!empty($matches)) {
    $matches = str_replace(array('[nid:', ']'), '', $matches);
    if (is_numeric($matches)) {
      if ($node = node_load($matches)) {
        if ($node->type === 'job') {
          $pass = TRUE;
          form_set_value($form['node'], $node->nid, $form_state);
        }
      }
    }
  }

  if ($pass !== TRUE) {
    form_set_error('node', t('Invalid job.'));
  }

  // Make sure we have a valid status.
  $options = drop_jobs_application_status_options_list();
  if (!array_key_exists($form_state['values']['status'], $options)) {
    form_set_error('status', t('Invalid application status.'));
  }
}

/**
 * Submit callback.
 * Saves an application.
 *
 * @see drop_jobs_application_form()
 */
function drop_jobs_application_form_submit(&$form, &$form_state) {
  $application = $form_state['application'];
  entity_form_submit_build_entity('drop_jobs_application', $application, $form, $form_state);
  drop_jobs_application_save($application);
  $application_uri = entity_uri('drop_jobs_application', $application);
  $form_state['redirect'] = $application_uri['path'];
  drupal_set_message(t('Application %title saved.', array('%title' => entity_label('drop_jobs_application', $application))));
}

/**
 * Submit callback.
 * Redirects to application delete confirmation form.
 *
 * @see drop_jobs_application_form()
 */
function drop_jobs_application_form_submit_delete($form, &$form_state) {
  $application = $form_state['application'];
  $application_uri = entity_uri('drop_jobs_application', $application);
  $form_state['redirect'] = $application_uri['path'] . '/delete';
}

/**
 * Form callback.
 * Displays application delete confirmation form.
 *
 * @see drop_jobs_application_menu()
 */
function drop_jobs_application_delete_form($form, &$form_state, $application) {
  $form_state['application'] = $application;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['aid'] = array('#type' => 'value', '#value' => entity_id('drop_jobs_application', $application));
  $application_uri = entity_uri('drop_jobs_application', $application);
  return confirm_form($form,
    t('Are you sure you want to delete application %title?', array('%title' => entity_label('drop_jobs_application', $application))),
    $application_uri['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Submit handler.
 * Deletes an application.
 *
 * @see drop_jobs_application_delete_form()
 */
function drop_jobs_application_delete_form_submit($form, &$form_state) {
  $application = $form_state['application'];
  drop_jobs_application_delete($application);
  drupal_set_message(t('Application %title deleted.', array('%title' => entity_label('drop_jobs_application', $application))));
  $form_state['redirect'] = '<front>';
}