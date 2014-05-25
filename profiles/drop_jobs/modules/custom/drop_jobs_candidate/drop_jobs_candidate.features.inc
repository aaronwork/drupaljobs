<?php
/**
 * @file
 * drop_jobs_candidate.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drop_jobs_candidate_ctools_plugin_api() {
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
function drop_jobs_candidate_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function drop_jobs_candidate_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favorite Resumes".
  $flags['favorite_resumes'] = array(
    'entity_type' => 'profile2',
    'title' => 'Favorite Resumes',
    'global' => '0',
    'types' => array(
      0 => 'resume',
    ),
    'errors' => array(),
    'flag_short' => 'Add to favorites',
    'flag_long' => 'Add this resume to your favorites.',
    'flag_message' => '',
    'unflag_short' => 'Remove from favorites',
    'unflag_long' => 'Remove this resume from your favorites.',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'page' => 'page',
      'account' => 0,
      'diff_standard' => 0,
      'teaser' => 0,
      'token' => 0,
    ),
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'drop_jobs_candidate',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function drop_jobs_candidate_image_default_styles() {
  $styles = array();

  // Exported image style: resume_teaser.
  $styles['resume_teaser'] = array(
    'name' => 'resume_teaser',
    'effects' => array(
      1 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => '90',
          'height' => '90',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_profile2_type().
 */
function drop_jobs_candidate_default_profile2_type() {
  $items = array();
  $items['resume'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "resume",
    "label" : "R\\u00e9sum\\u00e9",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1, "page_path" : "resume" },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_rules_link().
 */
function drop_jobs_candidate_default_rules_link() {
  $items = array();
  $items['resume_set_hidden'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Hide r\\u00e9sum\\u00e9",
      "link_type" : "confirm",
      "bundles" : { "resume" : "resume" },
      "entity_link" : 1,
      "confirm_question" : "Are you sure you want to hide your r\\u00e9sum\\u00e9?",
      "confirm_description" : "Hiding your r\\u00e9sum\\u00e9 will exclude you from appearing in search results. You can always change this later."
    },
    "name" : "resume_set_hidden",
    "label" : "Resume set hidden",
    "path" : "resume_set_hidden",
    "entity_type" : "profile2",
    "rdf_mapping" : []
  }');
  $items['resume_set_visible'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Show r\\u00e9sum\\u00e9",
      "link_type" : "token",
      "bundles" : { "resume" : "resume" },
      "entity_link" : 1
    },
    "name" : "resume_set_visible",
    "label" : "Resume set visible",
    "path" : "resume_set_visible",
    "entity_type" : "profile2",
    "rdf_mapping" : []
  }');
  return $items;
}
