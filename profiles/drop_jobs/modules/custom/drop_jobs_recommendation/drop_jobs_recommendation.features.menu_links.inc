<?php
/**
 * @file
 * drop_jobs_recommendation.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function drop_jobs_recommendation_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-drop-jobs-admin:admin/drop-jobs/recommendations
  $menu_links['menu-drop-jobs-admin:admin/drop-jobs/recommendations'] = array(
    'menu_name' => 'menu-drop-jobs-admin',
    'link_path' => 'admin/drop-jobs/recommendations',
    'router_path' => 'admin/drop-jobs/recommendations',
    'link_title' => 'Recommendations',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-42',
  );
  // Exported menu link: menu-drop-jobs-dashboard:dashboard/job-recommendations
  $menu_links['menu-drop-jobs-dashboard:dashboard/job-recommendations'] = array(
    'menu_name' => 'menu-drop-jobs-dashboard',
    'link_path' => 'dashboard/job-recommendations',
    'router_path' => 'dashboard/job-recommendations',
    'link_title' => 'Job recommendations',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Job recommendations');
  t('Recommendations');


  return $menu_links;
}
