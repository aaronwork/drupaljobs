<?php
/**
 * @file
 * drop_jobs_report.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function drop_jobs_report_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drop_jobs_report_candidate';
  $context->description = 'Candidates report pages.';
  $context->tag = 'drop_jobs_report';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/reports/drop-jobs/candidates*' => 'admin/reports/drop-jobs/candidates*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-95277571fd87debffe0c68effbb54be6' => array(
          'module' => 'views',
          'delta' => '95277571fd87debffe0c68effbb54be6',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-1f0dfd90a30acd004f5dba642364516b' => array(
          'module' => 'views',
          'delta' => '1f0dfd90a30acd004f5dba642364516b',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-462181b3e50bef3e0d658f08f6bedaaa' => array(
          'module' => 'views',
          'delta' => '462181b3e50bef3e0d658f08f6bedaaa',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Candidates report pages.');
  t('drop_jobs_report');
  $export['drop_jobs_report_candidate'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drop_jobs_report_job';
  $context->description = 'Jobs report pages.';
  $context->tag = 'drop_jobs_report';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/reports/drop-jobs/jobs*' => 'admin/reports/drop-jobs/jobs*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-drop_jobs_report_job-job_total' => array(
          'module' => 'views',
          'delta' => 'drop_jobs_report_job-job_total',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-7b0f999cedc70fbee3a2d73a74beab78' => array(
          'module' => 'views',
          'delta' => '7b0f999cedc70fbee3a2d73a74beab78',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-drop_jobs_report_job-job_states' => array(
          'module' => 'views',
          'delta' => 'drop_jobs_report_job-job_states',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Jobs report pages.');
  t('drop_jobs_report');
  $export['drop_jobs_report_job'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drop_jobs_report_recruiter';
  $context->description = 'Recruiters report pages.';
  $context->tag = 'drop_jobs_report';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/reports/drop-jobs/recruiters*' => 'admin/reports/drop-jobs/recruiters*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-4878362f64e183578234e7005b3113b5' => array(
          'module' => 'views',
          'delta' => '4878362f64e183578234e7005b3113b5',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-d42d26190875b701628592925df74748' => array(
          'module' => 'views',
          'delta' => 'd42d26190875b701628592925df74748',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Recruiters report pages.');
  t('drop_jobs_report');
  $export['drop_jobs_report_recruiter'] = $context;

  return $export;
}
