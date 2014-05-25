<?php
/**
 * @file
 * Recruiter Phone number migration class for Drop Jobs Demo.
 *
 * This is a separate migration because this particular field is a field
 * collection belonging to the Recruiter profile.
 */

/**
 * Class for importing field collection items from the contact info bundle.
 */
class DropJobsRecruitersPhone extends DropJobsMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t("Import recruiter profiles' phone number field collection items.");
    $this->dependencies = array('DropJobsRecruiters');

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

    // We use the same CSV as from the recruiter profile migration.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drop_jobs_demo') . '/import/recruiter_phone.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationFieldCollection('field_recruiter_phone', array(
      'host_entity_type' => 'profile2'
    ));

    $this->addFieldMapping('host_entity_id', 'id')
      ->sourceMigration('DropJobsRecruiters');

    $this->addFieldMapping('field_recruiter_phone_number', 'phone_number');
    $this->addFieldMapping('field_recruiter_phone_type', 'phone_type');

    $this->addUnmigratedDestinations(array(
      'field_recruiter_phone_number:language',
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