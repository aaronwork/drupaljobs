<?php
/**
 * @file
 * drop_jobs_job.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function drop_jobs_job_taxonomy_default_vocabularies() {
  return array(
    'job_tags' => array(
      'name' => 'Job Tags',
      'machine_name' => 'job_tags',
      'description' => 'Use tags to group jobs on similar topics into categories.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-10',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'years_of_experience' => array(
      'name' => 'Years of Experience',
      'machine_name' => 'years_of_experience',
      'description' => 'Job Years of Experience',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
