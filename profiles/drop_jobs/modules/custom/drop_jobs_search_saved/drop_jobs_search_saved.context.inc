<?php
/**
 * @file
 * drop_jobs_search_saved.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function drop_jobs_search_saved_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drop_jobs_search_job_saved';
  $context->description = 'Displays the saved job searches block.';
  $context->tag = 'drop_jobs_search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'drop_jobs_search_jobs:page' => 'drop_jobs_search_jobs:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search_api_saved_searches-job_index' => array(
          'module' => 'search_api_saved_searches',
          'delta' => 'job_index',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Displays the saved job searches block.');
  t('drop_jobs_search');
  $export['drop_jobs_search_job_saved'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drop_jobs_search_resume_saved';
  $context->description = 'Displays the saved resume searches block.';
  $context->tag = 'drop_jobs_search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'drop_jobs_search_resume' => 'drop_jobs_search_resume',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search_api_saved_searches-resume_index' => array(
          'module' => 'search_api_saved_searches',
          'delta' => 'resume_index',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Displays the saved resume searches block.');
  t('drop_jobs_search');
  $export['drop_jobs_search_resume_saved'] = $context;

  return $export;
}
