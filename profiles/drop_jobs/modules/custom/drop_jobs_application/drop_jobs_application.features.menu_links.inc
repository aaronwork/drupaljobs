<?php
/**
 * @file
 * drop_jobs_application.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function drop_jobs_application_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-drop-jobs-admin:admin/drop-jobs/applications
  $menu_links['menu-drop-jobs-admin:admin/drop-jobs/applications'] = array(
    'menu_name' => 'menu-drop-jobs-admin',
    'link_path' => 'admin/drop-jobs/applications',
    'router_path' => 'admin/drop-jobs/applications',
    'link_title' => 'Applications',
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
    'weight' => '-49',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Applications');


  return $menu_links;
}
