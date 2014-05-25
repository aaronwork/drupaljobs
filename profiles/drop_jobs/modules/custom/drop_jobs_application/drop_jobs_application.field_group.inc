<?php
/**
 * @file
 * drop_jobs_application.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function drop_jobs_application_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_applications|node|job|form';
  $field_group->group_name = 'group_job_applications';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Applications',
    'weight' => '6',
    'children' => array(
      0 => 'field_job_applications',
      1 => 'field_job_notification',
      2 => 'field_job_notification_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_job_applications|node|job|form'] = $field_group;

  return $export;
}
