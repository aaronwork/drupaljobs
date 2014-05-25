<?php
/**
 * @file
 * drop_jobs_recruiter.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function drop_jobs_recruiter_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pcp_profile2_recruiter_hide_block_on_complete';
  $strongarm->value = 1;
  $export['pcp_profile2_recruiter_hide_block_on_complete'] = $strongarm;

  return $export;
}
