<?php
/**
 * @file
 * drop_jobs_application.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function drop_jobs_application_field_default_fields() {
  $fields = array();

  // Exported field: 'drop_jobs_application-advanced-field_application_workflow'.
  $fields['drop_jobs_application-advanced-field_application_workflow'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_application_workflow',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'rejected' => 'Rejected',
          'accepted' => 'Accepted',
          'followup' => 'Marked for follow up',
          'interview' => 'Called for interview',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'advanced',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '9',
        ),
      ),
      'entity_type' => 'drop_jobs_application',
      'field_name' => 'field_application_workflow',
      'label' => 'Workflow State',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
          'content_taxonomy_opt_groups' => FALSE,
        ),
        'type' => 'options_select',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'drop_jobs_application-resume_required-field_application_resume'.
  $fields['drop_jobs_application-resume_required-field_application_resume'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_application_resume',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'file',
      'settings' => array(
        'display_default' => 0,
        'display_field' => 0,
        'profile2_private' => FALSE,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'resume_required',
      'deleted' => '0',
      'description' => 'Please upload your résumé.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => '9',
        ),
      ),
      'entity_type' => 'drop_jobs_application',
      'field_name' => 'field_application_resume',
      'label' => 'Résumé',
      'required' => 1,
      'settings' => array(
        'description_field' => 0,
        'file_directory' => 'application_resumes',
        'file_extensions' => 'pdf doc docx odt',
        'max_filesize' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'file',
        'settings' => array(
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'node-job-field_job_applications'.
  $fields['node-job-field_job_applications'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_job_applications',
      'field_permissions' => array(
        'type' => '2',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 1,
            ),
          ),
          'sort' => array(
            'direction' => 'ASC',
            'property' => 'label',
            'type' => 'property',
          ),
          'target_bundles' => array(),
        ),
        'handler_submit' => 'Change handler',
        'profile2_private' => FALSE,
        'target_type' => 'drop_jobs_application_type',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'job',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'If you would like this job to accept applications, specify what kind of applications are allowed. Leave blank to accept no applications.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_job_applications',
      'label' => 'Accept Applications',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
          'content_taxonomy_opt_groups' => FALSE,
        ),
        'type' => 'options_select',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-job-field_job_notification'.
  $fields['node-job-field_job_notification'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_job_notification',
      'field_permissions' => array(
        'type' => '2',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'recruiter' => 'My email address',
          'organization' => 'My organization\'s email address',
          'email' => 'Custom email address',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'job',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Specify to which email addresses you would like to receive email notifications for applications to this job. You can configure the frequency of these emails in your dashboard.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_job_notification',
      'label' => 'Notification Preferences',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-job-field_job_notification_email'.
  $fields['node-job-field_job_notification_email'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_job_notification_email',
      'field_permissions' => array(
        'type' => '2',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'email',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'email',
    ),
    'field_instance' => array(
      'bundle' => 'job',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_job_notification_email',
      'label' => 'Notification Email',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'email',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'email_textfield',
        'weight' => '10',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Accept Applications');
  t('If you would like this job to accept applications, specify what kind of applications are allowed. Leave blank to accept no applications.');
  t('Notification Email');
  t('Notification Preferences');
  t('Please upload your résumé.');
  t('Résumé');
  t('Specify to which email addresses you would like to receive email notifications for applications to this job. You can configure the frequency of these emails in your dashboard.');
  t('Workflow State');

  return $fields;
}
