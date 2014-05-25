<?php
/**
 * @file
 * Candidates Preferences Info migration class for Drop Jobs Demo.
 *
 * This is a separate migration because this particular field is a field
 * collection.
 */

/**
 * Class for importing field collection items from the prefs info bundle.
 */
class DropJobsCandidatesPreferences extends DropJobsMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t("Import resume's job prefereces info field collection items.");
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

    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drop_jobs_demo') . '/import/candidate_preferences.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationFieldCollection('field_resume_preferences', array(
      'host_entity_type' => 'profile2'
    ));

    $this->addFieldMapping('host_entity_id', 'id')
      ->sourceMigration('DropJobsCandidates');

    $this->addFieldMapping('field_resume_pref_title', 'title');

    $this->addFieldMapping('field_resume_notes', 'notes');

    $this->addFieldMapping('field_resume_pref_occupation', 'occupation')
      ->arguments(array('source_type' => 'tid'))
      ->separator(',')
      ->sourceMigration('DropJobsTermOccupationalFields');

    $this->addFieldMapping('field_resume_pref_employment', 'type')
      ->arguments(array('source_type' => 'tid'))
      ->separator(',')
      ->sourceMigration('DropJobsTermEmploymentType');

    $this->addFieldMapping('field_resume_pref_start', 'start');
    $this->addFieldMapping('field_resume_pref_salary', 'salary');

    $this->addUnmigratedDestinations(array(
      'field_resume_notes:language',
      'field_resume_pref_title:language',
      'field_resume_pref_occupation:source_type',
      'field_resume_pref_occupation:create_term',
      'field_resume_pref_occupation:ignore_case',
      'field_resume_pref_employment:source_type',
      'field_resume_pref_employment:create_term',
      'field_resume_pref_employment:ignore_case',
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
      array('title', 'Candidate job prefs job title'),
      array('occupation', 'Candidate job prefs occupation'),
      array('type', 'Candidate job prefs job type'),
      array('start', 'Candidate job prefs start date'),
      array('salary', 'Candidate job prefs salary'),
      array('notes', 'Candidate job prefs summary'),
    );
  }

}
