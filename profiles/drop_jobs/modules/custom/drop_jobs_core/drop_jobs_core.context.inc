<?php
/**
 * @file
 * drop_jobs_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function drop_jobs_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drop_jobs_admin';
  $context->description = 'Administration pages.';
  $context->tag = 'drop_jobs_core';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin*' => 'admin*',
        'node/*/*' => 'node/*/*',
        'devel*' => 'devel*',
        'help*' => 'help*',
        'taxonomy/term/*/*' => 'taxonomy/term/*/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'content admin' => 'content admin',
        'job admin' => 'job admin',
        'organization admin' => 'organization admin',
        'recruiter admin' => 'recruiter admin',
        'candidate admin' => 'candidate admin',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-drop-jobs-admin' => array(
          'module' => 'menu',
          'delta' => 'menu-drop-jobs-admin',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Administration pages.');
  t('drop_jobs_core');
  $export['drop_jobs_admin'] = $context;

  return $export;
}
