<?php
/**
 * @file
 * drop_jobs_recruiter.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function drop_jobs_recruiter_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drop_jobs_dashboard_recruiter';
  $context->description = 'Recruiter Dashboard.';
  $context->tag = 'drop_jobs_recruiter';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dashboard/recruiter*' => 'dashboard/recruiter*',
        'recruiter/*/edit' => 'recruiter/*/edit',
      ),
    ),
    'user' => array(
      'values' => array(
        'recruiter' => 'recruiter',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-drop-jobs-dashboard' => array(
          'module' => 'menu',
          'delta' => 'menu-drop-jobs-dashboard',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'pcp-pcp_profile2_recruiter' => array(
          'module' => 'pcp',
          'delta' => 'pcp_profile2_recruiter',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Recruiter Dashboard.');
  t('drop_jobs_recruiter');
  $export['drop_jobs_dashboard_recruiter'] = $context;

  return $export;
}
