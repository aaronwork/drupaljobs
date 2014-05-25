<?php
/**
 * @file
 * drop_jobs_job.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drop_jobs_job_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
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
function drop_jobs_job_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function drop_jobs_job_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favorite Jobs".
  $flags['favorite_jobs'] = array(
    'entity_type' => 'node',
    'title' => 'Favorite Jobs',
    'global' => '0',
    'types' => array(
      0 => 'job',
    ),
    'errors' => array(),
    'flag_short' => 'Add to favorites',
    'flag_long' => 'Add this job to your favorite jobs list.',
    'flag_message' => '',
    'unflag_short' => 'Remove from favorites',
    'unflag_long' => 'Remove this job from your favorite jobs list.',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'drop_jobs_job',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function drop_jobs_job_node_info() {
  $items = array(
    'job' => array(
      'name' => t('Job'),
      'base' => 'node_content',
      'description' => t('Use <em>jobs</em> for job listings.'),
      'has_title' => '1',
      'title_label' => t('Job Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_rules_link().
 */
function drop_jobs_job_default_rules_link() {
  $items = array();
  $items['job_set_hidden'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Hide job",
      "link_type" : "token",
      "bundles" : { "job" : "job" },
      "entity_link" : 1
    },
    "name" : "job_set_hidden",
    "label" : "Job set hidden",
    "path" : "job_set_hidden",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['job_set_visible'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Show job",
      "link_type" : "token",
      "bundles" : { "job" : "job" },
      "entity_link" : 1
    },
    "name" : "job_set_visible",
    "label" : "Job set visible",
    "path" : "job_set_visible",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  return $items;
}
