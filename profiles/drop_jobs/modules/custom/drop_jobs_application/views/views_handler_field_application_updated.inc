<?php
/**
 * @file
 * Views handlers for Job Applications.
 */

/**
 * Field handler to display the newer of last application / node updated.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_application_updated extends views_handler_field_date {
  function query() {
    $this->ensure_my_table();
    $this->node_table = $this->query->ensure_table('node', $this->relationship);
    $this->field_alias = $this->query->add_field(NULL, "GREATEST(" . $this->node_table . ".changed, " . $this->table_alias . ".last_application_timestamp)", $this->table_alias . '_' . $this->field);
  }
}
