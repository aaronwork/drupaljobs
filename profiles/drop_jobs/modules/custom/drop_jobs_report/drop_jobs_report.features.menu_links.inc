<?php
/**
 * @file
 * drop_jobs_report.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function drop_jobs_report_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-drop-jobs-admin:admin/reports/drop-jobs
  $menu_links['menu-drop-jobs-admin:admin/reports/drop-jobs'] = array(
    'menu_name' => 'menu-drop-jobs-admin',
    'link_path' => 'admin/reports/drop-jobs',
    'router_path' => 'admin/reports/drop-jobs',
    'link_title' => 'Reports',
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
    'weight' => '-43',
  );
  // Exported menu link: menu-drop-jobs-reports:admin/reports/drop-jobs/candidates
  $menu_links['menu-drop-jobs-reports:admin/reports/drop-jobs/candidates'] = array(
    'menu_name' => 'menu-drop-jobs-reports',
    'link_path' => 'admin/reports/drop-jobs/candidates',
    'router_path' => 'admin/reports/drop-jobs/candidates',
    'link_title' => 'Candidates',
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
  // Exported menu link: menu-drop-jobs-reports:admin/reports/drop-jobs/jobs
  $menu_links['menu-drop-jobs-reports:admin/reports/drop-jobs/jobs'] = array(
    'menu_name' => 'menu-drop-jobs-reports',
    'link_path' => 'admin/reports/drop-jobs/jobs',
    'router_path' => 'admin/reports/drop-jobs/jobs',
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
    'weight' => '-48',
  );
  // Exported menu link: menu-drop-jobs-reports:admin/reports/drop-jobs/recruiters
  $menu_links['menu-drop-jobs-reports:admin/reports/drop-jobs/recruiters'] = array(
    'menu_name' => 'menu-drop-jobs-reports',
    'link_path' => 'admin/reports/drop-jobs/recruiters',
    'router_path' => 'admin/reports/drop-jobs/recruiters',
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
    'weight' => '-49',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Candidates');
  t('Jobs');
  t('Recruiters');
  t('Reports');


  return $menu_links;
}
