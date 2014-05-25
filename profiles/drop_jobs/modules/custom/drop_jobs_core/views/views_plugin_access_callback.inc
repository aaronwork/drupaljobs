<?php
/**
 * @file
 * Definition of views_plugin_access_callback.
 */

/**
 * Access plugin that provides callback-based access control.
 *
 * @ingroup views_access_plugins
 */
class views_plugin_access_callback extends views_plugin_access {
  function access($account) {
    return $this->options['callback']($account);
  }

  function get_access_callback() {
    return array($this->options['callback']);
  }

  function summary_title() {
    $count = count($this->options['callback']);
    if ($count < 1) {
      return t('No callback selected');
    }
    else {
      return check_plain($this->options['callback']);
    }
  }


  function option_definition() {
    $options = parent::option_definition();
    $options['callback'] = array('default' => array());

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['callback'] = array(
      '#type' => 'textfield',
      '#title' => t('Callback'),
      '#default_value' => $this->options['callback'],
      '#description' => t("Use the following callback to check for access."),
    );
  }

  function options_validate(&$form, &$form_state) {
    if (!function_exists($form_state['values']['access_options']['callback'])) {
      form_error($form['callback'], t('You must select valid callback.'));
    }
  }
}
