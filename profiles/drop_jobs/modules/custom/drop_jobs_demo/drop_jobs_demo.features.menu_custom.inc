<?php
/**
 * @file
 * drop_jobs_demo.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function drop_jobs_demo_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-secondary-links.
  $menus['menu-secondary-links'] = array(
    'menu_name' => 'menu-secondary-links',
    'title' => 'Secondary Links',
    'description' => 'Auxiliary menu',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Auxiliary menu');
  t('Secondary Links');


  return $menus;
}
