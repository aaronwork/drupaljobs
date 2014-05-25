<?php
/**
 * @file
 * drop_jobs_job.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function drop_jobs_job_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_additional|node|job|form';
  $field_group->group_name = 'group_job_additional';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Information',
    'weight' => '5',
    'children' => array(
      0 => 'field_job_attachments',
      1 => 'field_job_tags',
      2 => 'field_job_url',
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
  $export['group_job_additional|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_basic|node|job|default';
  $field_group->group_name = 'group_job_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_job_field',
      1 => 'field_job_salary',
      2 => 'field_job_study',
      3 => 'field_job_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Basic Information',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_job_basic|node|job|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_basic|node|job|form';
  $field_group->group_name = 'group_job_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_job_field',
      1 => 'field_job_salary',
      2 => 'field_job_study',
      3 => 'field_job_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Basic Information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_job_basic|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_location|node|job|default';
  $field_group->group_name = 'group_job_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Work location',
    'weight' => '5',
    'children' => array(
      0 => 'field_job_address',
      1 => 'field_job_organization',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Work location',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_job_location|node|job|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_location|node|job|form';
  $field_group->group_name = 'group_job_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Work location',
    'weight' => '3',
    'children' => array(
      0 => 'field_job_address',
      1 => 'field_job_geofield',
      2 => 'field_job_organization',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Work location',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_job_location|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_requirements|node|job|default';
  $field_group->group_name = 'group_job_requirements';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Requirements',
    'weight' => '4',
    'children' => array(
      0 => 'field_job_degree_level',
      1 => 'field_job_experience',
      2 => 'field_job_languages',
      3 => 'field_job_skills',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Requirements',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_job_requirements|node|job|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_requirements|node|job|form';
  $field_group->group_name = 'group_job_requirements';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Requirements',
    'weight' => '2',
    'children' => array(
      0 => 'field_job_degree_level',
      1 => 'field_job_experience',
      2 => 'field_job_languages',
      3 => 'field_job_skills',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Requirements',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_job_requirements|node|job|form'] = $field_group;

  return $export;
}
