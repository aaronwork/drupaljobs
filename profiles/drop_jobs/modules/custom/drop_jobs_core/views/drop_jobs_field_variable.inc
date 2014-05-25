<?php
/**
 * @file
 * Definition of drop_jobs_field_full_name.
 */

/**
 * A handler to provide a field with any variable's value.
 *
 * @ingroup views_field_handlers
 */
class drop_jobs_field_variable extends views_handler_field {

  public function query() {
    // Don' do anything.
  }

  public function render($values) {
    return variable_get($this->options['variable_name'], $this->options['variable_default']);
  }

  /**
   * Field options.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['variable_name'] = array('default' => '');
    $options['variable_default'] = array('default' => '');
    return $options;
  }

  /**
   * Field options form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['variable_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Variable name'),
      '#description' => t('Enter the variable name to use.'),
      '#default_value' => $this->options['variable_name'],
    );

    $form['variable_default'] = array(
      '#type' => 'textfield',
      '#title' => t('Default value'),
      '#description' => t('Enter the default value to use if the variable is empty.'),
      '#default_value' => $this->options['variable_default'],
    );
  }

}
