<?php
/**
 * @file
 * drop_jobs_search.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function drop_jobs_search_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'jobs';
  $item->label = 'Jobs';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => 'Found [facetapi_results:result-count] job',
        'plural' => 1,
        'text_plural' => 'Found [facetapi_results:result-count] jobs',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'h3',
        'css' => 0,
        'classes' => '',
        'weight' => '-50',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '1',
    ),
  );
  $export['jobs'] = $item;

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'resumes';
  $item->label = 'Resumes';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => 'Found [facetapi_results:result-count] résumé',
        'plural' => 1,
        'text_plural' => 'Found [facetapi_results:result-count] résumés',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'h3',
        'css' => 0,
        'classes' => '',
        'weight' => '-50',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '1',
    ),
  );
  $export['resumes'] = $item;

  return $export;
}
