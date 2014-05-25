<?php
/**
 * @file
 * drop_jobs_candidate.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function drop_jobs_candidate_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drop_jobs_dashboard_candidate';
  $context->description = 'Candidate Dashboard.';
  $context->tag = 'drop_jobs_candidate';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dashboard/candidate*' => 'dashboard/candidate*',
        'resume/*/edit' => 'resume/*/edit',
      ),
    ),
    'user' => array(
      'values' => array(
        'candidate' => 'candidate',
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
        'pcp-pcp_profile2_resume' => array(
          'module' => 'pcp',
          'delta' => 'pcp_profile2_resume',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Candidate Dashboard.');
  t('drop_jobs_candidate');
  $export['drop_jobs_dashboard_candidate'] = $context;

  return $export;
}
