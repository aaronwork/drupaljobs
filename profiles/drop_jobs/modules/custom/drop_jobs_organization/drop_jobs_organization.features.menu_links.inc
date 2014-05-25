<?php
/**
 * @file
 * drop_jobs_organization.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function drop_jobs_organization_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-drop-jobs-admin:admin/drop-jobs/organizations
  $menu_links['menu-drop-jobs-admin:admin/drop-jobs/organizations'] = array(
    'menu_name' => 'menu-drop-jobs-admin',
    'link_path' => 'admin/drop-jobs/organizations',
    'router_path' => 'admin/drop-jobs/organizations',
    'link_title' => 'Organizations',
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
    'weight' => '-45',
  );
  // Exported menu link: menu-drop-jobs-dashboard:dashboard/organization
  $menu_links['menu-drop-jobs-dashboard:dashboard/organization'] = array(
    'menu_name' => 'menu-drop-jobs-dashboard',
    'link_path' => 'dashboard/organization',
    'router_path' => 'dashboard/organization',
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
  t('Organizations');


  return $menu_links;
}
