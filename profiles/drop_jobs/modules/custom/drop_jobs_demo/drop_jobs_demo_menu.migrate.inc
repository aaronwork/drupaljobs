<?php
/**
 * @file
 * Drop Jobs Demo Menu migration class for menu links.
 */

/**
 * Class for importing menu links.
 */
class DropJobsMenuLinks extends DropJobsMigration {

  public function __construct() {
//    $this->sourceFields['path'] = t('Menu path, extracted from database.');

    parent::__construct();
    $this->description = t('Import menu links.');
    $this->dependencies = array('DropJobsPages');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'dummy_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationMenuLinks::getKeySchema()
    );

    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drop_jobs_demo') . '/import/page.csv', DropJobsPages::csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationMenuLinks();

    // Defaults.
    $this->addFieldMapping('menu_name')->defaultValue('menu-secondary-links');
    $this->addFieldMapping('plid')->defaultValue(0);
    $this->addFieldMapping('router_path')->defaultValue('node/%');
    $this->addFieldMapping('link_title', 'title');
    $this->addFieldMapping('module')->defaultValue('menu');
    $this->addFieldMapping('hidden')->defaultValue(0);
    $this->addFieldMapping('external')->defaultValue(0);
    $this->addFieldMapping('has_children')->defaultValue(0);
    $this->addFieldMapping('expanded')->defaultValue(0);
    $this->addFieldMapping('depth')->defaultValue(1);
    $this->addFieldMapping('customized')->defaultValue(1);
    $this->addFieldMapping('weight')->defaultValue(0);

    $this->addFieldMapping('link_path', 'path');

    $this->addUnmigratedDestinations(array(
      'options',
      'p1',
      'p2',
      'p3',
      'p4',
      'p5',
      'p6',
      'p7',
      'p8',
      'p9',
      'updated',
    ));

    $this->addUnmigratedSources(array(
      'body',
    ));
  }

  function prepareRow($row) {
    parent::prepareRow($row);

    // Find node id from title.
    $nid =
      db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'page', '=')
      ->condition('title', $row->title, '=')
      ->execute()
      ->fetchField();

    if ($nid) {
      $row->path = "node/{$nid}";
    }
  }

}