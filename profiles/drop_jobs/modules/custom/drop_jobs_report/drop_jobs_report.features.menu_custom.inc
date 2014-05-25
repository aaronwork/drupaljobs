<?php
/**
 * @file
 * drop_jobs_report.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function drop_jobs_report_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-drop-jobs-reports.
  $menus['menu-drop-jobs-reports'] = array(
    'menu_name' => 'menu-drop-jobs-reports',
    'title' => 'Drop Jobs Reports',
    'description' => 'Drop Jobs Reports Dashboard links.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Drop Jobs Reports');
  t('Drop Jobs Reports Dashboard links.');


  return $menus;
}
