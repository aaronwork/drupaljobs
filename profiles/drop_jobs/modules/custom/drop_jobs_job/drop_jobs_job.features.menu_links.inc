<?php
/**
 * @file
 * drop_jobs_job.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function drop_jobs_job_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-drop-jobs-admin:admin/drop-jobs/jobs
  $menu_links['menu-drop-jobs-admin:admin/drop-jobs/jobs'] = array(
    'menu_name' => 'menu-drop-jobs-admin',
    'link_path' => 'admin/drop-jobs/jobs',
    'router_path' => 'admin/drop-jobs',
    'link_title' => 'Jobs',
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
    'weight' => '-46',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Jobs');


  return $menu_links;
}
