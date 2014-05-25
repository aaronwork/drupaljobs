<?php
/**
 * @file
 * Candidates Work Experience migration class for Drop Jobs Demo.
 *
 * This is a separate migration because this particular type is a type
 * collection.
 */

/**
 * Class for importing type collection items from the work experience bundle.
 */
class DropJobsCandidatesWork extends DropJobsMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t("Import resume's work experience type collection items.");
    $this->dependencies = array(
      'DropJobsCandidates',
      'DropJobsTermOccupationalFields',
      'DropJobsTermEmploymentType',
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
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drop_jobs_demo') . '/import/candidate_work.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationFieldCollection('field_resume_experience', array(
      'host_entity_type' => 'profile2'
    ));

    $this->addFieldMapping('host_entity_id', 'id')
      ->sourceMigration('DropJobsCandidates');

    $this->addFieldMapping('field_resume_exp_title', 'title');
    $this->addFieldMapping('field_resume_exp_company_name', 'company_name');
    $this->addFieldMapping('field_resume_exp_company_url', 'company_link');
    $this->addFieldMapping('field_resume_exp_field', 'occupation')
      ->arguments(array('source_type' => 'tid'))
      ->sourceMigration('DropJobsTermOccupationalFields');
    $this->addFieldMapping('field_resume_exp_time', 'period');
    $this->addFieldMapping('field_resume_exp_type', 'type')
      ->arguments(array('source_type' => 'tid'))
      ->sourceMigration('DropJobsTermEmploymentType');
    $this->addFieldMapping('field_resume_notes', 'notes');

    $this->addUnmigratedDestinations(array(
      'field_resume_exp_field:source_type',
      'field_resume_exp_field:create_term',
      'field_resume_exp_field:ignore_case',
      'field_resume_exp_type:source_type',
      'field_resume_exp_type:create_term',
      'field_resume_exp_type:ignore_case',
      'field_resume_exp_title:language',
      'field_resume_exp_company_name:language',
      'field_resume_notes:language',
      'field_resume_exp_company_url:title',
      'field_resume_exp_company_url:attributes',
      'field_resume_exp_company_url:language',
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
      array('title', 'Candidate experience job title'),
      array('company_name', 'Candidate experience job company name'),
      array('company_link', 'Candidate experience job company link'),
      array('occupation', 'Candidate experience job occupational type'),
      array('period', 'Candidate experience job period'),
      array('type', 'Candidate experience job employment type'),
      array('notes', 'Candidate experience notes'),
    );
  }

  function prepareRow($row) {
    parent::prepareRow($row);

    // Prepare date data.
    $this->_parseDate($row, 'period');

    return TRUE;
  }

}