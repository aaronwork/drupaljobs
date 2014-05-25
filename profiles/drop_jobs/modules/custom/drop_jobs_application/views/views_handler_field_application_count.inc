<?php
/**
 * @file
 * Views handlers for Job Applications.
 */

/**
 * A handler to provide a field with the number of applications this node has received.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_application_count extends views_handler_field_numeric {

  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
    $this->additional_fields['application_count'] = 'application_count';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link'] = TRUE;
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['link'] = array(
      '#type' => 'checkbox',
      '#title' => t("Display as link to node's applications page"),
      '#default_value' => $this->options['link'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $nid = $values->{$this->aliases['nid']};
    $count = $values->{$this->aliases['application_count']};

    if ($this->options['link']) {
      return l($count, "node/{$nid}/applications");
    }
    else {
      return $count;
    }
  }

  /**
   * Called to determine what to tell the clicksorter.
   */
  function click_sort($order) {
    if (isset($this->field_alias)) {
      // Since fields should always have themselves already added, just
      // add a sort on the field.
      $params = $this->options['group_type'] != 'group' ? array('function' => $this->options['group_type'])
          : array();
      $this->query->add_orderby(NULL, NULL, $order, 'application_count', $params);
    }
  }

}