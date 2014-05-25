<?php
/**
 * @file
 * drop_jobs_application.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function drop_jobs_application_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: views_view
  $overrides["views_view.drop_jobs_job_admin.display|default|display_options|fields|application_count"] = array(
    'id' => 'application_count',
    'table' => 'drop_jobs_application_statistics',
    'field' => 'application_count',
    'label' => 'Applications',
    'element_label_colon' => FALSE,
    'link' => 1,
  );
  $overrides["views_view.drop_jobs_job_admin.display|default|display_options|style_options|columns|application_count"] = 'application_count';
  $overrides["views_view.drop_jobs_job_admin.display|default|display_options|style_options|info|application_count"] = array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  );
  $overrides["views_view.drop_jobs_job_my_jobs.display|default|display_options|fields|application_count"] = array(
    'id' => 'application_count',
    'table' => 'drop_jobs_application_statistics',
    'field' => 'application_count',
    'element_label_colon' => FALSE,
    'link' => 1,
  );
  $overrides["views_view.drop_jobs_job_my_jobs.display|default|display_options|style_options|columns|application_count"] = 'application_count';
  $overrides["views_view.drop_jobs_job_my_jobs.display|default|display_options|style_options|info|application_count"] = array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  );

 return $overrides;
}
