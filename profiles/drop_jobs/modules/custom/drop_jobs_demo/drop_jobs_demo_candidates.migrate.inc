<?php
/**
 * @file
 * Candidates migration class for Drop Jobs Demo.
 */

/**
 * Class for importing recruiter profiles.
 */
class DropJobsCandidates extends DropJobsMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Import Candidate resumes.');
    $this->softDependencies = array('DropJobsUsers');

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

    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drop_jobs_demo') . '/import/candidate.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationProfile2('resume');

    $this->addFieldMapping('uid', 'user')->defaultValue(1)->sourceMigration('DropJobsUsers');

    $this->addFieldMapping('field_resume_promoted', 'promoted');
    $this->addFieldMapping('field_resume_sticky', 'sticky');
    $this->addFieldMapping('field_resume_workflow', 'workflow');

    $this->addUnmigratedDestinations(array(
      'revision_uid',
      'language',
      'field_resume_attachments',
      'field_resume_attachments:file_class',
      'field_resume_attachments:language',
      'field_resume_attachments:destination_dir',
      'field_resume_attachments:destination_file',
      'field_resume_attachments:file_replace',
      'field_resume_attachments:preserve_files',
      'field_resume_attachments:source_dir',
      'field_resume_attachments:description',
      'field_resume_attachments:display',
      // These are ignored for now because we must first migrate this Profile
      // entity and then the Field Collection Items.
      'field_resume_personal',
      'field_resume_languages',
      'field_resume_education',
      'field_resume_preferences',
      'field_resume_skills',
      'field_resume_experience',
    ));

    $this->addUnmigratedSources(array(
      'id',
    ));
  }

  public function csvcolumns() {
    return array(
      array('id', 'User id'),
      array('user', 'User name'),
      array('promoted', 'Resume promoted flag'),
      array('sticky', 'Resume sticky flag'),
      array('workflow', 'Resume workflow state'),
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