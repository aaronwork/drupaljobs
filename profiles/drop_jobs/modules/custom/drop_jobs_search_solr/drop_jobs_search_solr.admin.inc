<?php
/**
 * @file
 * Drop Jobs Solr Search settings and admin UI.
 */

/**
 * Form callback
 *
 * @see drop_jobs_search_solr_menu()
 */
function drop_jobs_search_solr_settings($form, $form_state) {
  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Solr Search settings'),
    '#collapsible' => FALSE,
  );

  $form['wrapper']['drop_jobs_search_solr_host'] = array(
    '#type' => 'textfield',
    '#title' => t('Solr host'),
    '#description' => t('Enter the absolute path to your Solr server host'),
    '#default_value' => variable_get_value('drop_jobs_search_solr_host'),
  );

  $form['wrapper']['drop_jobs_search_solr_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Solr port'),
    '#default_value' => variable_get_value('drop_jobs_search_solr_port'),
  );

  $form['wrapper']['drop_jobs_search_solr_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Solr path'),
    '#description' => t('Enter the path to your Solr server, relative to the host.'),
    '#default_value' => variable_get_value('drop_jobs_search_solr_path'),
  );

  return system_settings_form($form);
}
