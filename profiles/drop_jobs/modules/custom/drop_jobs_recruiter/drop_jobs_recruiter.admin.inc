<?php

/**
 * @file
 * Drop Jobs Recruiter admin settings.
 */

/**
 * Form callback
 *
 * @see drop_jobs_recruiter_menu().
 */
function drop_jobs_recruiter_settings() {
  $form = array();

  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Recruiter settings'),
    '#collapsible' => FALSE,
  );

  return system_settings_form($form);
}