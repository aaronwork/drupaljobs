<?php
/**
 * @file
 * Pages migration class for Drop Jobs Demo.
 */

/**
 * Class for importing basic pages.
 */
class DropJobsPages extends DropJobsMigration {

  public function __construct() {

    parent::__construct();
    $this->description = t('Import basic page nodes.');

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

    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drop_jobs_demo') . '/import/page.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('page', array('text_format' => 'full_html'));

    $this->addSimpleMappings(array('title', 'body'));

    $this->addFieldMapping('uid')->defaultValue(1);

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
    ));
  }

  function csvcolumns() {
    return array(
      array('dummy_id', 'Dummy PK'),
      array('title', 'Page title'),
      array('body', 'Page contents'),
    );
  }
}