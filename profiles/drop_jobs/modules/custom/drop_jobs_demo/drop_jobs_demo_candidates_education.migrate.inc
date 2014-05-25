<?php
/**
 * @file
 * Candidates Education Info migration class for Drop Jobs Demo.
 *
 * This is a separate migration because this particular field is a field
 * collection.
 */

/**
 * Class for importing field collection items from the education info bundle.
 */
class DropJobsCandidatesEducation extends DropJobsMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t("Import resume's education info field collection items.");
    $this->dependencies = array(
      'DropJobsCandidates',
      'DropJobsTermDegreeLevel',
      'DropJobsTermFieldsStudy',
    );

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
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drop_jobs_demo') . '/import/candidate_education.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationFieldCollection('field_resume_education', array(
      'host_entity_type' => 'profile2'
    ));

    $this->addFieldMapping('host_entity_id', 'id')
      ->sourceMigration('DropJobsCandidates');

    $this->addFieldMapping('field_resume_notes', 'notes');
    $this->addFieldMapping('field_resume_edu_level', 'degree')
      ->arguments(array('source_type' => 'tid'))
      ->sourceMigration('DropJobsTermDegreeLevel');
    $this->addFieldMapping('field_resume_edu_name', 'institution');
    $this->addFieldMapping('field_resume_edu_field', 'field')
      ->arguments(array('source_type' => 'tid'))
      ->sourceMigration('DropJobsTermFieldsStudy');
    $this->addFieldMapping('field_resume_edu_time', 'period');

    $this->addUnmigratedDestinations(array(
      'field_resume_edu_field:create_term',
      'field_resume_edu_field:ignore_case',
      'field_resume_edu_field:source_type',
      'field_resume_edu_name:language',
      'field_resume_notes:language',
      'field_resume_edu_level:source_type',
      'field_resume_edu_level:create_term',
      'field_resume_edu_level:ignore_case',
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
      array('degree', 'Candidate education degree level'),
      array('institution', 'Candidate education degree institution'),
      array('field', 'Candidate education field of study'),
      array('period', 'Candidate education time period'),
      array('notes', 'Candidate education notes'),
    );
  }

  function prepareRow($row) {
    parent::prepareRow($row);

    // Prepare date data.
    $this->_parseDate($row, 'period');

    return TRUE;
  }

}