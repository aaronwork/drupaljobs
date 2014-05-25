<?php
/**
 * @file
 * Users migration class for Drop Jobs Demo.
 */

/**
 * Class for migration users.
 */
class DropJobsUsers extends DropJobsMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Import users.');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'name' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationUser::getKeySchema()
    );

    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drop_jobs_demo') . '/import/user.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationUser();

    $this->addSimpleMappings(array('mail'));

    $this->addFieldMapping('name', 'name')
         ->dedupe('users', 'name');

    // Set the user's password to be the same as the username.
    $this->addFieldMapping('pass', 'name');

    $this->addFieldMapping('role_names', 'roles')
         ->separator(',');

    $this->addFieldMapping('status')
         ->defaultValue(1);

    $this->addUnmigratedDestinations(array(
      'created',
      'access',
      'login',
      'roles',
      'picture',
      'signature',
      'signature_format',
      'timezone',
      'language',
      'theme',
      'init',
      'data',
      'is_new',
      'path',
      'pathauto',
    ));
  }

  function csvcolumns() {
    return array(
      array('name', 'User name'),
      array('mail', 'User email'),
      array('roles', 'User roles'),
    );
  }
}