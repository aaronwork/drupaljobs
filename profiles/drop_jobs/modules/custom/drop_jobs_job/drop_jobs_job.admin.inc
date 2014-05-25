<?php
/**
 * @file
 * Drop Jobs Job admin settings.
 */

/**
 * Form callback
 *
 * @see drop_jobs_job_menu().
 */
function drop_jobs_job_settings() {
  $form = array();

  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Job settings'),
    '#collapsible' => FALSE,
  );

  return system_settings_form($form);
}
