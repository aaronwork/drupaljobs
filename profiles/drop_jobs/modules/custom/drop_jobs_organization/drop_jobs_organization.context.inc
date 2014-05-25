<?php
/**
 * @file
 * drop_jobs_organization.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function drop_jobs_organization_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drop_jobs_dashboard_organization';
  $context->description = 'Organization Dashboard.';
  $context->tag = 'drop_jobs_organization';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dashboard/organization*' => 'dashboard/organization*',
        'node/*/edit' => 'node/*/edit',
      ),
    ),
    'user' => array(
      'values' => array(
        'organization' => 'organization',
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
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Organization Dashboard.');
  t('drop_jobs_organization');
  $export['drop_jobs_dashboard_organization'] = $context;

  return $export;
}
