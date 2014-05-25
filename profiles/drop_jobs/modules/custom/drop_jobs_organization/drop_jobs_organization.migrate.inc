<?php
/**
 * @file
 * Classes for Taxonomy term migrations for Drop Jobs Organization.
 */

/**
 * Class for migrating terms from the "Industries" vocabulary.
 */
class DropJobsTermIndustries extends DropJobsTermMigration {

  public function __construct() {
    parent::__construct('industries', 'drop_jobs_organization');
  }
}

/**
 * Class for migrating terms from the "Organization Size" vocabulary.
 */
class DropJobsTermOrganizationSize extends DropJobsTermMigration {

  public function __construct() {
    parent::__construct('organization_size', 'drop_jobs_organization');
  }
}
