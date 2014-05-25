<?php
/**
 * @file
 * Classes for Taxonomy term migrations for Drop Jobs Job.
 */

/**
 * Class for migrating terms from the "Years of Experience" vocabulary.
 */
class DropJobsTermYearsExperience extends DropJobsTermMigration {

  public function __construct() {
    parent::__construct('years_of_experience', 'drop_jobs_job');
  }
}