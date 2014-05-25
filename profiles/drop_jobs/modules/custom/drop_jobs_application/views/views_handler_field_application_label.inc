<?php
/**
 * @file
 * Views handlers for Job Applications.
 */

/**
 * A handler to provide a field with the job application's label.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_application_label extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['aid'] = 'aid';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link'] = FALSE;
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['link'] = array(
      '#type' => 'checkbox',
      '#title' => t('Link to application'),
      '#default_value' => $this->options['link'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $aid = $values->{$this->aliases['aid']};
    $entity = entity_load('drop_jobs_application', $aid);
    $text = entity_label('drop_jobs_application', $entity);

    if ($this->options['link']) {
      $entity_uri = entity_uri('drop_jobs_application', $entity);
      return l($text, reset($entity_uri));
    }
    else {
      return $text;
    }
  }

}