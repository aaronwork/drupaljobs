<?php
/**
 * @file
 * Candidates Personal Info migration class for Drop Jobs Demo.
 *
 * This is a separate migration because this particular field is a field
 * collection.
 */

/**
 * Class for importing field collection items from the personal info bundle.
 */
class DropJobsCandidatesPersonal extends DropJobsMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t("Import resume's personal info field collection items.");
    $this->dependencies = array('DropJobsCandidates');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    // We use the same CSV as from the candidate resume migration.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drop_jobs_demo') . '/import/candidate_personal.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationFieldCollection('field_resume_personal', array(
      'host_entity_type' => 'profile2'
    ));

    $this->addFieldMapping('host_entity_id', 'id')
      ->sourceMigration('DropJobsCandidates');

    $arguments = array(
      'administrative_area' => array('source_field' => 'province'),
      'locality' => array('source_field' => 'city'),
      'postal_code' => array('source_field' => 'postal_code'),
      'thoroughfare' => array('source_field' => 'street'),
      'premise' => array('source_field' => 'premise'),
    );
    $this->addFieldMapping('field_resume_address', 'country')->arguments($arguments);

    $this->addFieldMapping('field_resume_gender', 'gender');
    $this->addFieldMapping('field_resume_marital_status', 'marital');
    $this->addFieldMapping('field_resume_birthday', 'birthday');
    $this->addFieldMapping('field_resume_notes', 'about');

    $this->addFieldMapping('field_resume_photo', 'photo');
    $this->addFieldMapping('field_resume_photo:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_resume_photo:source_dir')
      ->defaultValue(drupal_get_path('module', 'drop_jobs_demo') . '/import/images');

    $this->addFieldMapping('field_resume_first_name', 'first_name');
    $this->addFieldMapping('field_resume_last_name', 'last_name');
    $this->addFieldMapping('field_resume_salutation', 'salutation');

    $this->addUnmigratedDestinations(array(
      'field_resume_notes:language',
      'field_resume_first_name:language',
      'field_resume_last_name:language',
      'field_resume_photo:file_class',
      'field_resume_photo:language',
      'field_resume_photo:destination_dir',
      'field_resume_photo:destination_file',
      'field_resume_photo:preserve_files',
      'field_resume_photo:alt',
      'field_resume_photo:title',
      // This is computed automatically.
      'field_resume_geofield',
      // This is ignored for now because we must first migrate this profile
      // before migrating this field which is a field collection item.
      'field_resume_phone',
    ));

    $this->addUnmigratedSources(array(
      'dummy_id',
      'user',
      'province',
      'city',
      'postal_code',
      'street',
      'premise',
    ));
  }

  public function csvcolumns() {
    return array(
      array('dummy_id', 'Dummy id'),
      array('id', 'User id'),
      array('user', 'User name'),
      array('gender', 'Candidate gender'),
      array('birthday', 'Candidate birthday'),
      array('marital', 'Candidate marital status'),
      array('country', 'Organization address country'),
      array('province', 'Organization address province'),
      array('city', 'Organization address city'),
      array('postal_code', 'Organization address postal code'),
      array('street', 'Organization address street'),
      array('premise', 'Organization address premise'),
      array('about', 'Candidate about'),
      array('first_name', 'User first name'),
      array('last_name', 'User last name'),
      array('photo', 'User photo'),
      array('salutation', 'User salutation'),
    );
  }
}