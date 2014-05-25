<?php
/**
 * @file
 * Views handlers for Job Applications.
 */

/**
 * A handler to provide a field with a link to view the job application.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_application_view extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['aid'] = 'aid';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $aid = $values->{$this->aliases['aid']};
    $entity = drop_jobs_application_load($aid);

    if (!drop_jobs_application_access('view', $entity)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $entity_uri = entity_uri('drop_jobs_application', $entity);
    return l($text, reset($entity_uri));
  }

}

/**
 * A handler to provide a field with a link to edit the job application.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_application_edit extends views_handler_field_application_view {

  function render($values) {
    $aid = $values->{$this->aliases['aid']};
    $entity = drop_jobs_application_load($aid);

    if (!drop_jobs_application_access('view', $entity)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $entity_uri = entity_uri('drop_jobs_application', $entity);
    return l($text, reset($entity_uri) . '/edit', array('query' => array('destination' => drupal_get_destination())));
  }

}

/**
 * A handler to provide a field with a link to delete the job application.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_application_delete extends views_handler_field_application_view {

  function render($values) {
    $aid = $values->{$this->aliases['aid']};
    $entity = drop_jobs_application_load($aid);

    if (!drop_jobs_application_access('view', $entity)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $entity_uri = entity_uri('drop_jobs_application', $entity);
    return l($text, reset($entity_uri) . '/delete', array('query' => array('destination' => drupal_get_destination())));
  }

}

class views_handler_field_application_operations extends views_handler_field_application_view {

  function construct() {
    parent::construct();
    $this->additional_fields['aid'] = 'aid';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $aid = $values->{$this->aliases['aid']};
    $destination = drupal_get_destination();
    $operations = array();

    // Load the application entity.
    $entity = drop_jobs_application_load($aid);
    $entity_uri = entity_uri('drop_jobs_application', $entity);

    // Add view link if user has permsission.
    if (drop_jobs_application_access('view', $entity)) {
      $operations['view'] = array(
        'title' => t('view'),
        'href' => reset($entity_uri),
        'destination' => $destination,
      );
    }

    // Add edit link if user has permsission.
    if (drop_jobs_application_access('edit', $entity)) {
      $operations['edit'] = array(
        'title' => t('edit'),
        'href' => reset($entity_uri) . '/edit',
        'query' => $destination,
      );
    }

    // Add delete link if user has permsission.
    if (drop_jobs_application_access('delete', $entity)) {
      $operations['delete'] = array(
        'title' => t('delete'),
        'href' => reset($entity_uri) . '/delete',
        'query' => $destination,
      );
    }

    return array(
      '#theme' => 'links__drop_jobs_application_operations',
      '#links' => $operations,
      '#attributes' => array('class' => array('links', 'inline')),
    );
  }

}