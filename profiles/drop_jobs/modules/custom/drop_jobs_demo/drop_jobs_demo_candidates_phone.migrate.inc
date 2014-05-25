<?php
/**
 * @file
 * Candidates Phone number migration class for Drop Jobs Demo.
 *
 * This is a separate migration because this particular field is a field
 * collection inside another field collection belonging to the Resume.
 */

/**
 * Class for importing field collection items from the contact info bundle.
 */
class DropJobsCandidatesPhone extends DropJobsMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t("Import resume's phone number field collection items.");
    $this->dependencies = array('DropJobsCandidatesPersonal', 'DropJobsCandidates');

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
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drop_jobs_demo') . '/import/candidate_phone.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationFieldCollection('field_resume_phone', array(
      'host_entity_type' => 'field_collection_item'
    ));

    $this->addFieldMapping('host_entity_id', 'id')
      ->sourceMigration('DropJobsCandidatesPersonal');

    $this->addFieldMapping('field_resume_phone_number', 'phone_number');
    $this->addFieldMapping('field_resume_phone_type', 'phone_type');

    $this->addUnmigratedDestinations(array(
      'field_resume_phone_number:language',
    ));

    $this->addUnmigratedSources(array(
      'user',
    ));
  }

  public function csvcolumns() {
    return array(
      array('dummy_id', 'Dummy id'),
      array('id', 'User id'),
      array('user', 'User name'),
      array('phone_type', 'User phone type'),
      array('phone_number', 'User phone number'),
    );
  }

}