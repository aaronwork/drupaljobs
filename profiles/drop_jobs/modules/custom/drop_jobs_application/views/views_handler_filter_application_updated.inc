<?php
/**
 * @file
 * Views handlers for Job Applications.
 */

/**
 * Filter handler for the newer of last application / node updated
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_application_updated extends views_handler_filter_date {
  function query() {
    $this->ensure_my_table();
    $this->node_table = $this->query->ensure_table('node', $this->relationship);

    $field = "GREATEST(" . $this->node_table . ".changed, " . $this->table_alias . ".last_application_timestamp)";

    $info = $this->operators();
    if (!empty($info[$this->operator]['method'])) {
      $this->{$info[$this->operator]['method']}($field);
    }
  }
}
