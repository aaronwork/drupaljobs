<?php
/**
 * @file
 * drop_jobs_candidate.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function drop_jobs_candidate_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_resume_flags|profile2|resume|form';
  $field_group->group_name = 'group_resume_flags';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'resume';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional settings',
    'weight' => '9',
    'children' => array(
      0 => 'field_resume_promoted',
      1 => 'field_resume_sticky',
      2 => 'field_resume_visible',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Additional settings',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_resume_flags|profile2|resume|form'] = $field_group;

  return $export;
}
