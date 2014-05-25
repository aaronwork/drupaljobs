<?php
/**
 * @file
 * Candidates Language Info migration class for Drop Jobs Demo.
 *
 * This is a separate migration because this particular field is a field
 * collection.
 */

/**
 * Class for importing field collection items from the language info bundle.
 */
class DropJobsCandidatesLanguage extends DropJobsMigration {

  public function __construct() {
//    $this->sourceFields['level'] = t('Term level, extracted in prepareRow()');

    parent::__construct();
    $this->description = t("Import resume's language info field collection items.");
    $this->dependencies = array('DropJobsCandidates');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'dummy_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    // We use the same CSV as from the candidate resume migration.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drop_jobs_demo') . '/import/candidate_language.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationFieldCollection('field_resume_languages', array(
      'host_entity_type' => 'profile2'
    ));

    $this->addFieldMapping('host_entity_id', 'id')
      ->sourceMigration('DropJobsCandidates');

    $this->addFieldMapping('field_resume_notes', 'notes');

    $arguments = array('source_type' => 'tid');
    $this->addFieldMapping('field_resume_language', 'languages')
      ->separator(',')
      ->arguments($arguments);
    $this->addFieldMapping('field_resume_language:level', 'levels')
      ->separator(',');

    $this->addUnmigratedDestinations(array(
      'field_resume_notes:language',
    ));

    $this->addUnmigratedSources(array(
      'user',
    ));
  }

  public function csvcolumns() {
    return array(
      array('dummy_id', 'Dummy item id'),
      array('id', 'User id'),
      array('user', 'User name'),
      array('languages', 'Resume language'),
      array('notes', 'Resume language notes'),
    );
  }

  function prepareRow($row) {
    parent::prepareRow($row);

    // Prepare languages data.
    $this->_parseTermLevel($row, 'languages', 'languages', ',');

    return TRUE;
  }
}