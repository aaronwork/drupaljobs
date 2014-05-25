<?php
/**
 * @file
 * Organizations migration class for Drop Jobs Demo.
 */

/**
 * Class for importing organizations.
 */
class DropJobsOrganizations extends DropJobsMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Import organization nodes.');
    $this->dependencies = array(
      'DropJobsUsers',
      'DropJobsTermOrganizationSize',
      'DropJobsTermIndustries',
    );

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drop_jobs_demo') . '/import/organization.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('organization');

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'description');

    $this->addFieldMapping('field_organization_logo', 'logo');
    $this->addFieldMapping('field_organization_logo:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_organization_logo:source_dir')
      ->defaultValue(drupal_get_path('module', 'drop_jobs_demo') . '/import/images');

    $this->addFieldMapping('field_organization_size', 'size')
      ->arguments(array('source_type' => 'tid'))
      ->sourceMigration('DropJobsTermOrganizationSize');

    $this->addFieldMapping('field_organization_industry', 'industry')
      ->arguments(array('source_type' => 'tid'))
      ->sourceMigration('DropJobsTermIndustries');

    $this->addFieldMapping('field_organization_url', 'url');

    $this->addFieldMapping('uid', 'author')->defaultValue(1)->sourceMigration('DropJobsUsers');

    $arguments = array(
      'administrative_area' => array('source_field' => 'province'),
      'locality' => array('source_field' => 'city'),
      'postal_code' => array('source_field' => 'postal_code'),
      'thoroughfare' => array('source_field' => 'street'),
      'premise' => array('source_field' => 'premise'),
    );
    $this->addFieldMapping('field_organization_address', 'country')->arguments($arguments);

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
      'field_organization_logo:file_class',
      'field_organization_logo:language',
      'field_organization_logo:destination_dir',
      'field_organization_logo:destination_file',
      'field_organization_logo:preserve_files',
      'field_organization_logo:alt',
      'field_organization_logo:title',
      'field_organization_size:create_term',
      'field_organization_size:ignore_case',
      'field_organization_size:source_type',
      'field_organization_industry:create_term',
      'field_organization_industry:ignore_case',
      'field_organization_industry:source_type',
      'path',
      'comment',
      'pathauto',
      'field_organization_geofield',
      'field_organization_url:title',
      'field_organization_url:attributes',
      'field_organization_url:language',
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
      array('title', 'Organization name'),
      array('logo', 'Organization logo'),
      array('author', 'Organization author'),
      array('size', 'Organization size'),
      array('country', 'Organization address country'),
      array('province', 'Organization address province'),
      array('city', 'Organization address city'),
      array('postal_code', 'Organization address postal code'),
      array('street', 'Organization address street'),
      array('premise', 'Organization address premise'),
      array('description', 'Organization description'),
      array('industry', 'Organization industry'),
      array('url', 'Organization website'),
    );
  }

}