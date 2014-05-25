<?php
/**
 * @file
 * drop_jobs_organization.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drop_jobs_organization_ctools_plugin_api() {
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
function drop_jobs_organization_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function drop_jobs_organization_node_info() {
  $items = array(
    'organization' => array(
      'name' => t('Organization'),
      'base' => 'node_content',
      'description' => t('Use <em>organizations</em> for companies which have job listings.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
