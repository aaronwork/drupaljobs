<?php
/**
 * @file
 * Views handlers for Job Recommendations.
 */

/**
 * A handler to provide a field with a link to view the recommendation.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_recommendation_view extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['rid'] = 'rid';
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
    $rid = $values->{$this->aliases['rid']};
    $entity = drop_jobs_recommendation_load($rid);

    if (!drop_jobs_recommendation_access('view', $entity)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $entity_uri = entity_uri('drop_jobs_recommendation', $entity);
    return l($text, reset($entity_uri));
  }

}

/**
 * A handler to provide a field with a link to edit the recommendation.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_recommendation_edit extends views_handler_field_recommendation_view {

  function render($values) {
    $rid = $values->{$this->aliases['rid']};
    $entity = drop_jobs_recommendation_load($rid);

    if (!drop_jobs_recommendation_access('edit', $entity)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $entity_uri = entity_uri('drop_jobs_recommendation', $entity);
    return l($text, reset($entity_uri) . '/edit');
  }

}

/**
 * A handler to provide a field with a link to delete the recommendation.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_recommendation_delete extends views_handler_field_recommendation_view {

  function render($values) {
    $rid = $values->{$this->aliases['rid']};
    $entity = drop_jobs_recommendation_load($rid);

    if (!drop_jobs_recommendation_access('delete', $entity)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $entity_uri = entity_uri('drop_jobs_recommendation', $entity);
    return l($text, reset($entity_uri) . '/delete');
  }

}

/**
 * A handler to provide a field with operations links for the recommendation.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_recommendation_operations extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['rid'] = 'rid';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $rid = $values->{$this->aliases['rid']};
    $destination = drupal_get_destination();
    $operations = array();

    // Load the recommendation entity.
    $entity = drop_jobs_recommendation_load($rid);
    $entity_uri = entity_uri('drop_jobs_recommendation', $entity);

    // Add view link if user has view permsission.
    if (drop_jobs_recommendation_access('view', $entity)) {
      $operations['view'] = array(
        'title' => t('view'),
        'href' => reset($entity_uri),
        'destination' => $destination,
      );
    }

    // Add view link if user has edit permsission.
    if (drop_jobs_recommendation_access('edit', $entity)) {
      $operations['edit'] = array(
        'title' => t('edit'),
        'href' => reset($entity_uri) . '/edit',
        'destination' => $destination,
      );
    }

    // Add view link if user has delete permsission.
    if (drop_jobs_recommendation_access('delete', $entity)) {
      $operations['delete'] = array(
        'title' => t('delete'),
        'href' => reset($entity_uri) . '/delete',
        'destination' => $destination,
      );
    }

    return array(
      '#theme' => 'links__drop_jobs_recommendation_operations',
      '#links' => $operations,
      '#attributes' => array('class' => array('links', 'inline')),
    );
  }

}