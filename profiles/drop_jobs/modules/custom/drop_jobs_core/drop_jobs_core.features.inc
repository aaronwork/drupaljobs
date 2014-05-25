<?php
/**
 * @file
 * drop_jobs_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drop_jobs_core_ctools_plugin_api() {
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
function drop_jobs_core_views_api() {
  return array("version" => "3.0");
}
