<?php
/**
 * @file
 * Recruiter migration class for Drop Jobs Demo.
 */

/**
 * Class for importing recruiter profiles.
 */
class DropJobsRecruiters extends DropJobsMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Import Recruiter profiles.');
    $this->dependencies = array('DropJobsUsers', 'DropJobsOrganizations');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationProfile2::getKeySchema()
    );

    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drop_jobs_demo') . '/import/recruiter.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationProfile2('recruiter');

    $this->addFieldMapping('uid', 'user')->defaultValue(1)->sourceMigration('DropJobsUsers');

    $this->addFieldMapping('field_recruiter_organization', 'organization')
      ->sourceMigration('DropJobsOrganizations');

    $this->addFieldMapping('field_recruiter_first_name', 'first_name');
    $this->addFieldMapping('field_recruiter_last_name', 'last_name');

    $this->addFieldMapping('field_recruiter_photo', 'photo');
    $this->addFieldMapping('field_recruiter_photo:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_recruiter_photo:source_dir')
      ->defaultValue(drupal_get_path('module', 'drop_jobs_demo') . '/import/images');

    $this->addUnmigratedDestinations(array(
      'revision_uid',
      'language',
      'field_recruiter_first_name:language',
      'field_recruiter_last_name:language',
      'field_recruiter_photo:file_class',
      'field_recruiter_photo:language',
      'field_recruiter_photo:destination_dir',
      'field_recruiter_photo:destination_file',
      'field_recruiter_photo:preserve_files',
      'field_recruiter_photo:alt',
      'field_recruiter_photo:title',
      'field_recruiter_phone',
    ));

    $this->addUnmigratedSources(array(
      'dummy_id',
      'id',
    ));
  }

  public function csvcolumns() {
    return array(
      array('dummy_id', 'Dummy id'),
      array('id', 'User id'),
      array('user', 'User name'),
      array('first_name', 'User first name'),
      array('last_name', 'User last name'),
      array('photo', 'User photo'),
      array('organization', 'User organization'),
    );
  }

  public function prepare($entity, $row) {
    // Manipulate created and updated dates so that we can have nice reports.
    static $step = 0;

    // 1 in 3 change to push back created date 1 month.
    if (mt_rand(0, 2) === 1) {
      ++$step;
    }

    if ($step > 0) {
      $date = strtotime("today - {$step} months");
      $entity->created = $date;
      $entity->changed = $date;
    }
  }

}