<?php
/**
 * @file
 * Drop Jobs Job pages.
 */

/**
 * Ajax callback.
 * Autocompletes job titles.
 *
 * @param $string
 *  The text entered in the input field.
 * @see drop_jobs_job_menu()
 */
function drop_jobs_job_autocomplete($string) {
  $matches = array();

  $query = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('n.status', 1, '=')
    ->condition('n.type', 'job', '=')
    ->condition('n.title', '%' . db_like($string) . '%', 'LIKE')
    ->range(0, 20);

  $return = $query->execute();

  foreach ($return as $row) {
    $matches["{$row->title} [nid:{$row->nid}]"] = check_plain($row->title);
  }

  drupal_json_output($matches);
}