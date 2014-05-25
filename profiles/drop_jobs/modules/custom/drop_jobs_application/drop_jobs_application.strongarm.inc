<?php
/**
 * @file
 * drop_jobs_application.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function drop_jobs_application_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_drop_jobs_application__advanced';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'type' => array(
          'weight' => '-5',
        ),
        'created' => array(
          'weight' => '-4',
        ),
        'uid' => array(
          'weight' => '-3',
        ),
        'nid' => array(
          'weight' => '-2',
        ),
        'status' => array(
          'weight' => '-1',
        ),
      ),
      'display' => array(
        'type' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
        ),
        'created' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'uid' => array(
          'default' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
        ),
        'nid' => array(
          'default' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
        ),
        'status' => array(
          'default' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
        ),
        'rules_links_application_set_hidden' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'rules_links_application_set_new' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'rules_links_application_set_read' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'rules_links_application_set_revoked' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_drop_jobs_application__advanced'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_drop_jobs_application__resume_required';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'type' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
        ),
        'created' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'uid' => array(
          'default' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
        ),
        'nid' => array(
          'default' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
        ),
        'status' => array(
          'default' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
        ),
        'rules_links_application_set_hidden' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'rules_links_application_set_new' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'rules_links_application_set_read' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'rules_links_application_set_revoked' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_drop_jobs_application__resume_required'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_drop_jobs_application__standard';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'type' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
        ),
        'created' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'uid' => array(
          'default' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
        ),
        'nid' => array(
          'default' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
        ),
        'status' => array(
          'default' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
        ),
        'rules_links_application_set_hidden' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'rules_links_application_set_new' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'rules_links_application_set_read' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'rules_links_application_set_revoked' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_drop_jobs_application__standard'] = $strongarm;

  return $export;
}
