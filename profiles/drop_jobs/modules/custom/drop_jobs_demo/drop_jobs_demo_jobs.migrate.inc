<?php
/**
 * @file
 * Jobs migration class for Drop Jobs Demo.
 */

/**
 * Class for importing basic pages.
 */
class DropJobsJobs extends DropJobsMigration {

  public function __construct() {
//    $this->sourceFields['level'] = t('Term level, extracted in prepareRow()');

    parent::__construct();
    $this->description = t('Import job nodes.');
    $this->dependencies = array(
      'DropJobsUsers',
      'DropJobsTermOccupationalFields',
      'DropJobsTermEmploymentType',
      'DropJobsTermFieldsStudy',
      'DropJobsTermDegreeLevel',
      'DropJobsTermYearsExperience',
      'DropJobsTermSkills',
    );

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'dummy_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drop_jobs_demo') . '/import/job.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('job', array('text_format' => 'full_html'));

    $this->addSimpleMappings(array('title', 'body'));
    $this->addFieldMapping('field_job_organization', 'organization');
    $this->addFieldMapping('field_job_salary', 'salary');

    $this->addFieldMapping('field_job_field', 'field')
      ->arguments(array('source_type' => 'tid'))
      ->separator(',')
      ->sourceMigration('DropJobsTermOccupationalFields');

    $this->addFieldMapping('field_job_type', 'type')
      ->arguments(array('source_type' => 'tid'))
      ->separator(',')
      ->sourceMigration('DropJobsTermEmploymentType');

    $this->addFieldMapping('field_job_study', 'study')
      ->arguments(array('source_type' => 'tid'))
      ->separator(',')
      ->sourceMigration('DropJobsTermFieldsStudy');

    $this->addFieldMapping('field_job_degree_level', 'degree')
      ->arguments(array('source_type' => 'tid'))
      ->separator(',')
      ->sourceMigration('DropJobsTermDegreeLevel');

    $this->addFieldMapping('field_job_experience', 'experience')
      ->arguments(array('source_type' => 'tid'))
      ->sourceMigration('DropJobsTermYearsExperience');

    $this->addFieldMapping('field_job_skills', 'skills')
      ->arguments(array('source_type' => 'tid'))
      ->separator('|')
      ->sourceMigration('DropJobsTermSkills');

    $this->addFieldMapping('field_job_tags', 'tags')
      ->arguments(array(
        'create_term' => TRUE,
        'ignore_case' => TRUE
      ))
      ->separator(',');

    $arguments = array('source_type' => 'tid');
    $this->addFieldMapping('field_job_languages', 'languages')
      ->separator(',')
      ->arguments($arguments);
    $this->addFieldMapping('field_job_languages:level', 'levels')
      ->separator(',');

    $this->addFieldMapping('field_job_applications', 'applications')
      ->separator(',');

    $this->addFieldMapping('field_job_url', 'url');
    $this->addFieldMapping('field_job_workflow', 'workflow');

    $this->addFieldMapping('field_job_attachments', 'file');
    $this->addFieldMapping('field_job_attachments:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_job_attachments:source_dir')
      ->defaultValue(drupal_get_path('module', 'drop_jobs_demo') . '/import/files');

    $arguments = array(
      'administrative_area' => array('source_field' => 'province'),
      'locality' => array('source_field' => 'city'),
      'postal_code' => array('source_field' => 'postal_code'),
      'thoroughfare' => array('source_field' => 'street'),
      'premise' => array('source_field' => 'premise'),
    );
    $this->addFieldMapping('field_job_address', 'country')->arguments($arguments);

    $this->addFieldMapping('uid', 'author')
      ->sourceMigration('DropJobsUsers');

    $this->addUnmigratedDestinations(array(
      'created',
      'changed',
      'status',
      'promote',
      'sticky',
      'revision',
      'log',
      'language',
      'tnid',
      'translate',
      'revision_uid',
      'is_new',
      'body:summary',
      'body:format',
      'body:language',
      'path',
      'comment',
      'pathauto',
      'field_job_degree_level:create_term',
      'field_job_degree_level:source_type',
      'field_job_degree_level:ignore_case',
      'field_job_experience:source_type',
      'field_job_experience:create_term',
      'field_job_experience:ignore_case',
      'field_job_field:source_type',
      'field_job_field:create_term',
      'field_job_field:ignore_case',
      'field_job_skills:create_term',
      'field_job_skills:source_type',
      'field_job_skills:ignore_case',
      'field_job_study:create_term',
      'field_job_study:source_type',
      'field_job_study:ignore_case',
      'field_job_tags:source_type',
      'field_job_tags:create_term',
      'field_job_tags:ignore_case',
      'field_job_type:source_type',
      'field_job_type:create_term',
      'field_job_type:ignore_case',
      'field_job_organization:language',
      'favorite_jobs',
      'field_job_geofield',
      'field_job_attachments:file_class',
      'field_job_attachments:language',
      'field_job_attachments:destination_dir',
      'field_job_attachments:destination_file',
      'field_job_attachments:preserve_files',
      'field_job_attachments:description',
      'field_job_attachments:display',
      'field_job_notification',
      'field_job_notification_email',
      'field_job_url:title',
      'field_job_url:attributes',
      'field_job_url:language',
    ));

    $this->addUnmigratedSources(array(
      'province',
      'city',
      'postal_code',
      'street',
      'premise',
    ));
  }

  function csvcolumns() {
    return array(
      array('dummy_id', 'Dummy PK'),
      array('title', 'Job title'),
      array('author', 'Job author'),
      array('field', 'Job occupational field'),
      array('study', 'Job field of study'),
      array('type', 'Job type'),
      array('salary', 'Job salary'),
      array('degree', 'Job required degree level'),
      array('experience', 'Job required experience'),
      array('languages', 'Job required languages'),
      array('skills', 'Job required skills'),
      array('organization', 'Job organization'),
      array('country', 'Organization address country'),
      array('province', 'Organization address province'),
      array('city', 'Organization address city'),
      array('postal_code', 'Organization address postal code'),
      array('street', 'Organization address street'),
      array('premise', 'Organization address premise'),
      array('applications', 'Job accept applications'),
      array('tags', 'Job tags'),
      array('url', 'Job link'),
      array('file', 'Job attachment'),
      array('workflow', 'Job workflow state'),
      array('body', 'Job description'),
    );
  }

  function prepareRow($row) {
    parent::prepareRow($row);

    // Prepare required languages data.
    $this->_parseTermLevel($row, 'languages', 'languages', ',');

    // Find application type entity ids.
    if (module_exists('drop_jobs_application') && !empty($row->applications)) {
      $applications = array();
      $application_names = explode(',', $row->applications);
      foreach ($application_names as $name) {
        if (!empty($name)) {
          $application_id =
            db_select('drop_jobs_application_type', 'djat')
            ->fields('djat', array('id'))
            ->condition('label', $name, '=')
            ->execute()
            ->fetchField();

          if (!empty($application_id)) {
            $applications[] = $application_id;
          }
        }
      }

      if (!empty($applications)) {
        $row->applications = implode(',', $applications);
      }
      else {
        unset($row->applications);
      }
    }
    else {
      unset($row->applications);
    }

    return TRUE;
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