<?php
/**
 * @file
 * drop_jobs_demo.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function drop_jobs_demo_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_page';
  $strongarm->value = array(
    0 => 'main-menu',
    1 => 'menu-secondary-links',
  );
  $export['menu_options_page'] = $strongarm;

  return $export;
}
