<?php
/**
 * @file
 * drop_jobs_core.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function drop_jobs_core_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-drop-jobs-admin.
  $menus['menu-drop-jobs-admin'] = array(
    'menu_name' => 'menu-drop-jobs-admin',
    'title' => 'Drop Jobs Admin',
    'description' => 'Drop Jobs Administration Dashboard links.',
  );
  // Exported menu: menu-drop-jobs-dashboard.
  $menus['menu-drop-jobs-dashboard'] = array(
    'menu_name' => 'menu-drop-jobs-dashboard',
    'title' => 'Drop Jobs Dashboard',
    'description' => 'Drop Jobs User Dashboard links.',
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Drop Jobs Admin');
  t('Drop Jobs Administration Dashboard links.');
  t('Drop Jobs Dashboard');
  t('Drop Jobs User Dashboard links.');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('User menu');


  return $menus;
}
