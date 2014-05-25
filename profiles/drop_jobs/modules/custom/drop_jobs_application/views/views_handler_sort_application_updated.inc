<?php
/**
 * @file
 * Views handlers for Job Applications.
 */

/**
 * Sort handler for the newer of last application / node updated.
 *
 * @ingroup views_sort_handlers
 */
class views_handler_sort_application_updated extends views_handler_sort_date {
  function query() {
    $this->ensure_my_table();
    $this->node_table = $this->query->ensure_table('node', $this->relationship);
    $this->field_alias = $this->query->add_orderby(NULL, "GREATEST(" . $this->node_table . ".changed, " . $this->table_alias . ".last_application_timestamp)", $this->options['order'], $this->table_alias . '_' . $this->field);
  }
}
