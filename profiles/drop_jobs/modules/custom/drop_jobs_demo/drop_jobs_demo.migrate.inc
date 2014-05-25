<?php
/**
 * @file
 *  Base migration class for Drop Jobs Demo.
 */

/**
 * Common features for all the migrations.
 */
abstract class DropJobsMigration extends Migration {

  public function __construct() {
    parent::__construct();
    ini_set('auto_detect_line_endings', TRUE);
  }

  public function processImport(array $options = array()) {
    parent::processImport($options = array());
    // Do not force menu rebuilding. Otherwise pathauto will try to rebuild
    // on each node_insert invocation.
    variable_set('menu_rebuild_needed', FALSE);
  }

  /**
   * Helper function to parse Date fields.
   *
   * @param stdClass
   *   Object containing raw source data.
   */
  public function _parseDate(&$row, $field) {
    // Check for and add end date to time period.
    $period_temp = explode(' to ', $row->{$field});

    if (count($period_temp) === 2) {
      $date_data = array(
        'from' => (string) $period_temp[0],
        'to' => (string) $period_temp[1],
      );
      $row->{$field} = drupal_json_encode($date_data);
    }
  }

  /**
   * Helper function to parse Term Level fields.
   *
   * @param stdClass
   *   Object containing raw source data.
   * @param string
   *   The name of the field we are setting the value for.
   * @param string
   *   The vocabulary of the field we are looking up the tid.
   * @param string
   *   The separator used, in the case of multiple values.
   */
  public function _parseTermLevel(&$row, $field, $vocabulary, $separator = NULL) {
    $fields = array();
    $levels = array();

    if (!isset($separator)) {
      $temp = explode('|', $row->{$field});
      $term_name = array_shift($temp);
      $row->levels = array_shift($temp);

      // Find term tid from name.
      $term = taxonomy_get_term_by_name($term_name, $vocabulary);
      $term = reset($term);
      $row->{$field} = $term->tid;
    }
    else {
      $items = explode(',', $row->{$field});

      foreach ($items as $item) {
        $temp = explode('|', $item);
        $term_name = array_shift($temp);
        $levels[] = array_shift($temp);

        // Find term tid from name.
        $term = taxonomy_get_term_by_name($term_name, $vocabulary);
        $term = reset($term);
        $fields[] = $term->tid;
      }

      $row->{$field} = implode(',', $fields);
      $row->levels = implode(',', $levels);
    }
  }
}