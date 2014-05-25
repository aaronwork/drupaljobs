<?php
/**
 * @file
 * drop_jobs_subscription.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function drop_jobs_subscription_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-drop-jobs-admin:admin/content/subscription
  $menu_links['menu-drop-jobs-admin:admin/content/subscription'] = array(
    'menu_name' => 'menu-drop-jobs-admin',
    'link_path' => 'admin/content/subscription',
    'router_path' => 'admin/content/subscription',
    'link_title' => 'Subscriptions',
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
    'weight' => '-40',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Subscriptions');


  return $menu_links;
}
