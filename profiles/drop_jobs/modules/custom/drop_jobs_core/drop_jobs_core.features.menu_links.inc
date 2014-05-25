<?php
/**
 * @file
 * drop_jobs_core.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function drop_jobs_core_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-drop-jobs-admin:admin/config/drop-jobs
  $menu_links['menu-drop-jobs-admin:admin/config/drop-jobs'] = array(
    'menu_name' => 'menu-drop-jobs-admin',
    'link_path' => 'admin/config/drop-jobs',
    'router_path' => 'admin/config/drop-jobs',
    'link_title' => 'Settings',
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
    'weight' => '-41',
  );
  // Exported menu link: menu-drop-jobs-admin:admin/drop-jobs
  $menu_links['menu-drop-jobs-admin:admin/drop-jobs'] = array(
    'menu_name' => 'menu-drop-jobs-admin',
    'link_path' => 'admin/drop-jobs',
    'router_path' => 'admin/drop-jobs',
    'link_title' => 'Admin Home',
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
  // Exported menu link: menu-drop-jobs-admin:admin/drop-jobs/pages
  $menu_links['menu-drop-jobs-admin:admin/drop-jobs/pages'] = array(
    'menu_name' => 'menu-drop-jobs-admin',
    'link_path' => 'admin/drop-jobs/pages',
    'router_path' => 'admin/drop-jobs/pages',
    'link_title' => 'Pages',
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
    'weight' => '-44',
  );
  // Exported menu link: menu-drop-jobs-admin:user/logout
  $menu_links['menu-drop-jobs-admin:user/logout'] = array(
    'menu_name' => 'menu-drop-jobs-admin',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Logout',
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
    'weight' => '-39',
  );
  // Exported menu link: menu-drop-jobs-dashboard:user/logout
  $menu_links['menu-drop-jobs-dashboard:user/logout'] = array(
    'menu_name' => 'menu-drop-jobs-dashboard',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Logout',
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
    'weight' => '50',
  );
  // Exported menu link: user-menu:admin/drop-jobs
  $menu_links['user-menu:admin/drop-jobs'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'admin/drop-jobs',
    'router_path' => 'admin/drop-jobs',
    'link_title' => 'Drop Jobs Admin',
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
  t('Admin Home');
  t('Drop Jobs Admin');
  t('Logout');
  t('Pages');
  t('Settings');


  return $menu_links;
}
