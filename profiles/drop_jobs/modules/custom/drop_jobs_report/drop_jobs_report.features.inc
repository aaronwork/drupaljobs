<?php
/**
 * @file
 * drop_jobs_report.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drop_jobs_report_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function drop_jobs_report_views_api() {
  return array("version" => "3.0");
}
