<?php
/**
 * @file
 * drop_jobs_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function drop_jobs_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drop_jobs_search_job';
  $context->description = 'Job search pages.';
  $context->tag = 'drop_jobs_search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'drop_jobs_search_jobs' => 'drop_jobs_search_jobs',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-ZsVIMdA6PRShtc1bF3nImuMZpT0wjftf' => array(
          'module' => 'facetapi',
          'delta' => 'ZsVIMdA6PRShtc1bF3nImuMZpT0wjftf',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-9PWgflD6G2ttZkP0vEDB9x799JeZnShr' => array(
          'module' => 'facetapi',
          'delta' => '9PWgflD6G2ttZkP0vEDB9x799JeZnShr',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-bs7Je7MVyzAoLVHZETZhHz1t0dTl3S9Q' => array(
          'module' => 'facetapi',
          'delta' => 'bs7Je7MVyzAoLVHZETZhHz1t0dTl3S9Q',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-yfKXu9TiqmC57xTbt5sJFAUVYcjHBBRa' => array(
          'module' => 'facetapi',
          'delta' => 'yfKXu9TiqmC57xTbt5sJFAUVYcjHBBRa',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-3r1a4x24SvTETJp9q6LfV4J1jioL4yIh' => array(
          'module' => 'facetapi',
          'delta' => '3r1a4x24SvTETJp9q6LfV4J1jioL4yIh',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-Q69AqI52uBh6sZa8CFAFd4yxXY5Cskq7' => array(
          'module' => 'facetapi',
          'delta' => 'Q69AqI52uBh6sZa8CFAFd4yxXY5Cskq7',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-jaHaeHelyaknczEHysUQre1yxE5Drzt1' => array(
          'module' => 'facetapi',
          'delta' => 'jaHaeHelyaknczEHysUQre1yxE5Drzt1',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-divtS05mL9idE06lwMGv0QhgCVGxsgx6' => array(
          'module' => 'facetapi',
          'delta' => 'divtS05mL9idE06lwMGv0QhgCVGxsgx6',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-q29aExfsFLNQiqAOeYEx8tE6W5YyGTe9' => array(
          'module' => 'facetapi',
          'delta' => 'q29aExfsFLNQiqAOeYEx8tE6W5YyGTe9',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-123ZakQutnazp9Q5VV4dGfR2iZyGNkFi' => array(
          'module' => 'facetapi',
          'delta' => '123ZakQutnazp9Q5VV4dGfR2iZyGNkFi',
          'region' => 'sidebar_first',
          'weight' => '-1',
        ),
        'facetapi-2qCcJM3Q1Sx3mJAXmtIknJ8oQxoxhPBl' => array(
          'module' => 'facetapi',
          'delta' => '2qCcJM3Q1Sx3mJAXmtIknJ8oQxoxhPBl',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'current_search-jobs' => array(
          'module' => 'current_search',
          'delta' => 'jobs',
          'region' => 'sidebar_second',
          'weight' => '-37',
        ),
        'views-drop_jobs_jobs-block' => array(
          'module' => 'views',
          'delta' => 'drop_jobs_jobs-block',
          'region' => 'sidebar_second',
          'weight' => '-35',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Job search pages.');
  t('drop_jobs_search');
  $export['drop_jobs_search_job'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drop_jobs_search_job_block';
  $context->description = 'Displays the exposed job search block.';
  $context->tag = 'drop_jobs_search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'views' => array(
      'values' => array(
        'drop_jobs_search_jobs:page' => 'drop_jobs_search_jobs:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-drop_jobs_search_jobs-page' => array(
          'module' => 'views',
          'delta' => '-exp-drop_jobs_search_jobs-page',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Displays the exposed job search block.');
  t('drop_jobs_search');
  $export['drop_jobs_search_job_block'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drop_jobs_search_resume';
  $context->description = 'Resume search';
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
        'facetapi-QVr3vh71QW7vKN1AmGOAqdHQYbvgY2jy' => array(
          'module' => 'facetapi',
          'delta' => 'QVr3vh71QW7vKN1AmGOAqdHQYbvgY2jy',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-zilceZy87CaK1HqL8X10Bdd2KoDyzqOL' => array(
          'module' => 'facetapi',
          'delta' => 'zilceZy87CaK1HqL8X10Bdd2KoDyzqOL',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-sQOtLjusI0qrFGplfscICm92Rc2Z3w1Q' => array(
          'module' => 'facetapi',
          'delta' => 'sQOtLjusI0qrFGplfscICm92Rc2Z3w1Q',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-DwMg1ya2tzPyeKnmaQRnAr4hpnyXOawd' => array(
          'module' => 'facetapi',
          'delta' => 'DwMg1ya2tzPyeKnmaQRnAr4hpnyXOawd',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-JBOkbNYTr4PeL7SNr0FlESVEYN7DWyXJ' => array(
          'module' => 'facetapi',
          'delta' => 'JBOkbNYTr4PeL7SNr0FlESVEYN7DWyXJ',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-kkvvp9qhmr4J0IppgNaWPVr0s3psv8tT' => array(
          'module' => 'facetapi',
          'delta' => 'kkvvp9qhmr4J0IppgNaWPVr0s3psv8tT',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-0bVzrZRr0XoZzKtk2GfmB0otXckq5uTX' => array(
          'module' => 'facetapi',
          'delta' => '0bVzrZRr0XoZzKtk2GfmB0otXckq5uTX',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'current_search-resumes' => array(
          'module' => 'current_search',
          'delta' => 'resumes',
          'region' => 'sidebar_second',
          'weight' => '-37',
        ),
        'views-drop_jobs_candidate-block' => array(
          'module' => 'views',
          'delta' => 'drop_jobs_candidate-block',
          'region' => 'sidebar_second',
          'weight' => '-35',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Resume search');
  t('drop_jobs_search');
  $export['drop_jobs_search_resume'] = $context;

  return $export;
}
