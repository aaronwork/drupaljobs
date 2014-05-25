<?php
/**
 * @file
 * drop_jobs_demo.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function drop_jobs_demo_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drop_jobs_demo';
  $context->description = 'Demonstration content.';
  $context->tag = 'drop_jobs_demo';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~drop_jobs_admin' => '~drop_jobs_admin',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-secondary-links' => array(
          'module' => 'menu',
          'delta' => 'menu-secondary-links',
          'region' => 'footer_firstcolumn',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Demonstration content.');
  t('drop_jobs_demo');
  $export['drop_jobs_demo'] = $context;

  return $export;
}
