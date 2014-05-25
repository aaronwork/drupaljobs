<?php
/**
 * @file
 * drop_jobs_application.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drop_jobs_application_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function drop_jobs_application_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_drop_jobs_application_type().
 */
function drop_jobs_application_default_drop_jobs_application_type() {
  $items = array();
  $items['advanced'] = entity_import('drop_jobs_application_type', '{
    "type" : "advanced",
    "label" : "Advanced",
    "weight" : "0",
    "data" : null,
    "description" : "This is an advanced job application type. It has additional fields that can be used to create complex administrative workflows.",
    "rdf_mapping" : []
  }');
  $items['resume_required'] = entity_import('drop_jobs_application_type', '{
    "type" : "resume_required",
    "label" : "R\\u00e9sum\\u00e9 required",
    "weight" : "0",
    "data" : null,
    "description" : "A job application that requires the applicant to attach his r\\u00e9sum\\u00e9.",
    "rdf_mapping" : []
  }');
  $items['standard'] = entity_import('drop_jobs_application_type', '{
    "type" : "standard",
    "label" : "Standard",
    "weight" : "0",
    "data" : null,
    "description" : "This is the standard application type. It has no fields and should be adequate for most use-cases.",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_views_default_views_alter().
 */
function drop_jobs_application_views_default_views_alter(&$data) {
  if (isset($data['drop_jobs_job_admin'])) {
    $data['drop_jobs_job_admin']->display['default']->display_options['fields']['application_count'] = array(
      'id' => 'application_count',
      'table' => 'drop_jobs_application_statistics',
      'field' => 'application_count',
      'label' => 'Applications',
      'element_label_colon' => FALSE,
      'link' => 1,
    ); /* WAS: '' */
    $data['drop_jobs_job_admin']->display['default']->display_options['style_options']['columns']['application_count'] = 'application_count'; /* WAS: '' */
    $data['drop_jobs_job_admin']->display['default']->display_options['style_options']['info']['application_count'] = array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['drop_jobs_job_my_jobs'])) {
    $data['drop_jobs_job_my_jobs']->display['default']->display_options['fields']['application_count'] = array(
      'id' => 'application_count',
      'table' => 'drop_jobs_application_statistics',
      'field' => 'application_count',
      'element_label_colon' => FALSE,
      'link' => 1,
    ); /* WAS: '' */
    $data['drop_jobs_job_my_jobs']->display['default']->display_options['style_options']['columns']['application_count'] = 'application_count'; /* WAS: '' */
    $data['drop_jobs_job_my_jobs']->display['default']->display_options['style_options']['info']['application_count'] = array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ); /* WAS: '' */
  }
}

/**
 * Implements hook_default_rules_link().
 */
function drop_jobs_application_default_rules_link() {
  $items = array();
  $items['application_set_hidden'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Hide application",
      "link_type" : "javascript",
      "bundles" : [],
      "entity_link" : 1
    },
    "name" : "application_set_hidden",
    "label" : "Application set hidden",
    "path" : "application_set_hidden",
    "entity_type" : "drop_jobs_application",
    "rdf_mapping" : []
  }');
  $items['application_set_new'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Mark as new",
      "link_type" : "javascript",
      "bundles" : [],
      "entity_link" : 1
    },
    "name" : "application_set_new",
    "label" : "Application set new",
    "path" : "application_set_new",
    "entity_type" : "drop_jobs_application",
    "rdf_mapping" : []
  }');
  $items['application_set_read'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Mark as read",
      "link_type" : "javascript",
      "bundles" : [],
      "entity_link" : 1
    },
    "name" : "application_set_read",
    "label" : "Application set read",
    "path" : "application_set_read",
    "entity_type" : "drop_jobs_application",
    "rdf_mapping" : []
  }');
  $items['application_set_revoked'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Revoke application",
      "link_type" : "confirm",
      "bundles" : [],
      "entity_link" : 1,
      "confirm_question" : "Are you sure you want to revoke your application to this job?",
      "confirm_description" : "This action is irreversible."
    },
    "name" : "application_set_revoked",
    "label" : "Application set revoked",
    "path" : "application_set_revoked",
    "entity_type" : "drop_jobs_application",
    "rdf_mapping" : []
  }');
  return $items;
}
