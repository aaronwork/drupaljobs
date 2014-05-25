<?php
/**
 * @file
 * drop_jobs_core.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function drop_jobs_core_taxonomy_default_vocabularies() {
  return array(
    'degree_level' => array(
      'name' => 'Degree Level',
      'machine_name' => 'degree_level',
      'description' => 'Education degree level.',
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
    'employment_type' => array(
      'name' => 'Emploment Type',
      'machine_name' => 'employment_type',
      'description' => 'Employment types',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-8',
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
    'fields_of_study' => array(
      'name' => 'Fields of Study',
      'machine_name' => 'fields_of_study',
      'description' => 'Fields of Study',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-2',
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
    'languages' => array(
      'name' => 'Languages',
      'machine_name' => 'languages',
      'description' => 'Spoken Languages',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-1',
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
    'occupational_fields' => array(
      'name' => 'Occupational Fields',
      'machine_name' => 'occupational_fields',
      'description' => 'Occupational Fields',
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
    'skills' => array(
      'name' => 'Skills',
      'machine_name' => 'skills',
      'description' => 'Job and Resume skills',
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
