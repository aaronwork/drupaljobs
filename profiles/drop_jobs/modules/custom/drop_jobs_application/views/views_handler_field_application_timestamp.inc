<?php
/**
 * @file
 * Views handlers for Job Applications.
 */

/**
 * Field handler to display the timestamp of an application with the count of applications.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_application_timestamp extends views_handler_field_date {
  function construct() {
    parent::construct();
    $this->additional_fields['application_count'] = 'application_count';
  }

  function render($values) {
    $application_count = $this->get_value($values, 'application_count');
    if (empty($this->options['empty_zero']) || $application_count) {
      return parent::render($values);
    }
    else {
      return NULL;
    }
  }
}
