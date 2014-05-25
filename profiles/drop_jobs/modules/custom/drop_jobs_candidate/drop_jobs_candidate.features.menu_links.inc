<?php
/**
 * @file
 * drop_jobs_candidate.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function drop_jobs_candidate_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-drop-jobs-admin:admin/drop-jobs/candidates
  $menu_links['menu-drop-jobs-admin:admin/drop-jobs/candidates'] = array(
    'menu_name' => 'menu-drop-jobs-admin',
    'link_path' => 'admin/drop-jobs/candidates',
    'router_path' => 'admin/drop-jobs',
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
    'weight' => '-48',
  );
  // Exported menu link: menu-drop-jobs-dashboard:dashboard/candidate
  $menu_links['menu-drop-jobs-dashboard:dashboard/candidate'] = array(
    'menu_name' => 'menu-drop-jobs-dashboard',
    'link_path' => 'dashboard/candidate',
    'router_path' => 'dashboard/candidate',
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
  t('Candidates');
  t('Dashboard Home');


  return $menu_links;
}
