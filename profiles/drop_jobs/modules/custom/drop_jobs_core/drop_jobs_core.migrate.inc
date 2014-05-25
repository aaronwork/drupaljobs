<?php
/**
 * @file
 * Classes for Taxonomy term migrations.
 */

/**
 * Base class for all Drop Jobs taxonomy term migrations.
 */
class DropJobsTermMigration extends Migration {

  public function __construct($vocabulary, $module = 'drop_jobs_core') {
    parent::__construct();
    ini_set('auto_detect_line_endings', TRUE);
    $this->description = t('Import !vocab terms.', array('!vocab' => $vocabulary));

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'name' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceCSV(drupal_get_path('module', $module) . "/import/term_{$vocabulary}.csv", $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationTerm($vocabulary);

    $this->addSimpleMappings(array('name', 'parent_name'));

    $this->addUnmigratedDestinations(array(
      'description',
      'parent',
      'format',
      'weight',
      'path',
      'pathauto',
    ));
  }

  function csvcolumns() {
    return array(
      array('name', 'Term name'),
      array('parent_name', 'Term parent name'),
    );
  }

  public function processImport(array $options = array()) {
    parent::processImport($options = array());
    // Do not force menu rebuilding. Otherwise pathauto will try to rebuild
    // on each node_insert invocation.
    variable_set('menu_rebuild_needed', FALSE);
  }

}

/**
 * Class for migrating terms from the "Degree Level" vocabulary.
 */
class DropJobsTermDegreeLevel extends DropJobsTermMigration {

  public function __construct() {
    parent::__construct('degree_level');
  }
}

/**
 * Class for migrating terms from the "Employment Type" vocabulary.
 */
class DropJobsTermEmploymentType extends DropJobsTermMigration {

  public function __construct() {
    parent::__construct('employment_type');
  }
}

/**
 * Class for migrating terms from the "Fields of Study" vocabulary.
 */
class DropJobsTermFieldsStudy extends DropJobsTermMigration {

  public function __construct() {
    parent::__construct('fields_of_study');
  }
}

/**
 * Class for migrating terms from the "Languages" vocabulary.
 */
class DropJobsTermLanguages extends DropJobsTermMigration {

  public function __construct() {
    parent::__construct('languages');
  }
}

/**
 * Class for migrating terms from the "Occupational Fields" vocabulary.
 */
class DropJobsTermOccupationalFields extends DropJobsTermMigration {

  public function __construct() {
    parent::__construct('occupational_fields');
  }
}

/**
 * Class for migrating terms from the "Skills" vocabulary.
 */
class DropJobsTermSkills extends DropJobsTermMigration {

  public function __construct() {
    parent::__construct('skills');
  }
}
