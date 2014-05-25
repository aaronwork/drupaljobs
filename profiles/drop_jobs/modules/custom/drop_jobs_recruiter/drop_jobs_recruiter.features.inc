<?php
/**
 * @file
 * drop_jobs_recruiter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drop_jobs_recruiter_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function drop_jobs_recruiter_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_profile2_type().
 */
function drop_jobs_recruiter_default_profile2_type() {
  $items = array();
  $items['recruiter'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "recruiter",
    "label" : "Recruiter Profile",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1, "page_path" : "recruiter" },
    "rdf_mapping" : []
  }');
  return $items;
}
