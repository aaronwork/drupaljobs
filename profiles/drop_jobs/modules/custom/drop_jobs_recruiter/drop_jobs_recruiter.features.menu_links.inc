<?php
/**
 * @file
 * drop_jobs_recruiter.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function drop_jobs_recruiter_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-drop-jobs-admin:admin/drop-jobs/recruiters
  $menu_links['menu-drop-jobs-admin:admin/drop-jobs/recruiters'] = array(
    'menu_name' => 'menu-drop-jobs-admin',
    'link_path' => 'admin/drop-jobs/recruiters',
    'router_path' => 'admin',
    'link_title' => 'Recruiters',
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
    'weight' => '-47',
  );
  // Exported menu link: menu-drop-jobs-dashboard:dashboard/recruiter
  $menu_links['menu-drop-jobs-dashboard:dashboard/recruiter'] = array(
    'menu_name' => 'menu-drop-jobs-dashboard',
    'link_path' => 'dashboard/recruiter',
    'router_path' => 'dashboard/recruiter',
    'link_title' => 'Dashboard Home',
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
    'weight' => '-50',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard Home');
  t('Recruiters');


  return $menu_links;
}
