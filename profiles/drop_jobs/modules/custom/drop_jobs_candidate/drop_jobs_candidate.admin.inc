<?php
/**
 * @file
 * Drop Jobs Candidate admin settings.
 */

/**
 * Form callback
 *
 * @see drop_jobs_candidate_menu().
 */
function drop_jobs_candidate_settings() {
  $form = array();

  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Candidate settings'),
    '#collapsible' => FALSE,
  );

  $form['wrapper']['drop_jobs_candidate_hide_incomplete'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide incomplete résumés'),
    '#description' => t("By default all résumés are displayed, unless they are explicitly set to hidden. If you check this option, you can ensure that Résumés that don't have a certain completeness percentage are automatically hidden."),
    '#default_value' => variable_get_value('drop_jobs_candidate_hide_incomplete'),
  );

  return system_settings_form($form);
}