<?php
/**
 * @file Drop Jobs Report admin settings form.
 */

/**
 * Form callback.
 * Report settings form.
 *
 * @see drop_jobs_report_menu().
 */
function drop_jobs_report_settings() {
  $form = array();

  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Report settings'),
    '#collapsible' => FALSE,
  );

  $form['wrapper']['drop_jobs_report_items_per_row'] = array(
    '#title' => t('Items per row'),
    '#description' => t('How many links appear in each row in the Drop Jobs Report Dashboard. Note that setting this to very high values will likely break the page layout.'),
    '#type' => 'textfield',
    '#size' => 2,
    '#default_value' => variable_get_value('drop_jobs_report_items_per_row'),
  );

  return system_settings_form($form);
}