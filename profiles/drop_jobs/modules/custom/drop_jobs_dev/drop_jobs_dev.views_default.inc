<?php
/**
 * @file
 * drop_jobs_dev.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function drop_jobs_dev_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'drop_jobs_dev_export_node';
  $view->description = 'Views for exporting demo content for Migrate.';
  $view->tag = 'drop_jobs_dev';
  $view->base_table = 'node';
  $view->human_name = 'Drop Jobs Dev Export Node';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer drop_jobs';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Pages */
  $handler = $view->new_display('views_data_export', 'Pages', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'dummy_id';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
  );
  $handler->display->display_options['path'] = 'admin/drop-jobs/export/page';

  /* Display: Jobs */
  $handler = $view->new_display('views_data_export', 'Jobs', 'job');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Content: Attachments (field_job_attachments:fid) */
  $handler->display->display_options['relationships']['field_job_attachments_fid']['id'] = 'field_job_attachments_fid';
  $handler->display->display_options['relationships']['field_job_attachments_fid']['table'] = 'field_data_field_job_attachments';
  $handler->display->display_options['relationships']['field_job_attachments_fid']['field'] = 'field_job_attachments_fid';
  $handler->display->display_options['relationships']['field_job_attachments_fid']['label'] = 'File';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'dummy_id';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'author';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Occupational Field */
  $handler->display->display_options['fields']['field_job_field']['id'] = 'field_job_field';
  $handler->display->display_options['fields']['field_job_field']['table'] = 'field_data_field_job_field';
  $handler->display->display_options['fields']['field_job_field']['field'] = 'field_job_field';
  $handler->display->display_options['fields']['field_job_field']['label'] = 'field';
  $handler->display->display_options['fields']['field_job_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_field']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_job_field']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_job_field']['separator'] = ',';
  /* Field: Content: Fields of Study */
  $handler->display->display_options['fields']['field_job_study']['id'] = 'field_job_study';
  $handler->display->display_options['fields']['field_job_study']['table'] = 'field_data_field_job_study';
  $handler->display->display_options['fields']['field_job_study']['field'] = 'field_job_study';
  $handler->display->display_options['fields']['field_job_study']['label'] = 'study';
  $handler->display->display_options['fields']['field_job_study']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_study']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_job_study']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_job_study']['separator'] = ',';
  /* Field: Content: Emploment Type */
  $handler->display->display_options['fields']['field_job_type']['id'] = 'field_job_type';
  $handler->display->display_options['fields']['field_job_type']['table'] = 'field_data_field_job_type';
  $handler->display->display_options['fields']['field_job_type']['field'] = 'field_job_type';
  $handler->display->display_options['fields']['field_job_type']['label'] = 'type';
  $handler->display->display_options['fields']['field_job_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_job_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_job_type']['separator'] = ',';
  /* Field: Content: Salary */
  $handler->display->display_options['fields']['field_job_salary']['id'] = 'field_job_salary';
  $handler->display->display_options['fields']['field_job_salary']['table'] = 'field_data_field_job_salary';
  $handler->display->display_options['fields']['field_job_salary']['field'] = 'field_job_salary';
  $handler->display->display_options['fields']['field_job_salary']['label'] = 'salary';
  $handler->display->display_options['fields']['field_job_salary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_salary']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_job_salary']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Degree Level */
  $handler->display->display_options['fields']['field_job_degree_level']['id'] = 'field_job_degree_level';
  $handler->display->display_options['fields']['field_job_degree_level']['table'] = 'field_data_field_job_degree_level';
  $handler->display->display_options['fields']['field_job_degree_level']['field'] = 'field_job_degree_level';
  $handler->display->display_options['fields']['field_job_degree_level']['label'] = 'degree';
  $handler->display->display_options['fields']['field_job_degree_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_degree_level']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_job_degree_level']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_job_degree_level']['separator'] = ',';
  /* Field: Content: Years of Experience */
  $handler->display->display_options['fields']['field_job_experience']['id'] = 'field_job_experience';
  $handler->display->display_options['fields']['field_job_experience']['table'] = 'field_data_field_job_experience';
  $handler->display->display_options['fields']['field_job_experience']['field'] = 'field_job_experience';
  $handler->display->display_options['fields']['field_job_experience']['label'] = 'experience';
  $handler->display->display_options['fields']['field_job_experience']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_experience']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_job_experience']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_job_experience']['separator'] = ',';
  /* Field: Content: Required Languages */
  $handler->display->display_options['fields']['field_job_languages']['id'] = 'field_job_languages';
  $handler->display->display_options['fields']['field_job_languages']['table'] = 'field_data_field_job_languages';
  $handler->display->display_options['fields']['field_job_languages']['field'] = 'field_job_languages';
  $handler->display->display_options['fields']['field_job_languages']['label'] = 'languages';
  $handler->display->display_options['fields']['field_job_languages']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_languages']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_job_languages']['type'] = 'term_level_export';
  $handler->display->display_options['fields']['field_job_languages']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_job_languages']['separator'] = ',';
  /* Field: Content: Skills */
  $handler->display->display_options['fields']['field_job_skills']['id'] = 'field_job_skills';
  $handler->display->display_options['fields']['field_job_skills']['table'] = 'field_data_field_job_skills';
  $handler->display->display_options['fields']['field_job_skills']['field'] = 'field_job_skills';
  $handler->display->display_options['fields']['field_job_skills']['label'] = 'skills';
  $handler->display->display_options['fields']['field_job_skills']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_skills']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_job_skills']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_job_skills']['separator'] = '|';
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_job_organization']['id'] = 'field_job_organization';
  $handler->display->display_options['fields']['field_job_organization']['table'] = 'field_data_field_job_organization';
  $handler->display->display_options['fields']['field_job_organization']['field'] = 'field_job_organization';
  $handler->display->display_options['fields']['field_job_organization']['label'] = 'organization';
  $handler->display->display_options['fields']['field_job_organization']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_organization']['type'] = 'text_plain';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_job_address']['id'] = 'field_job_address';
  $handler->display->display_options['fields']['field_job_address']['table'] = 'field_data_field_job_address';
  $handler->display->display_options['fields']['field_job_address']['field'] = 'field_job_address';
  $handler->display->display_options['fields']['field_job_address']['label'] = 'country';
  $handler->display->display_options['fields']['field_job_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_job_address']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_job_address']['settings'] = array(
    'components' => array(
      'country' => 'country',
    ),
    'separator' => ', ',
  );
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_job_address_1']['id'] = 'field_job_address_1';
  $handler->display->display_options['fields']['field_job_address_1']['table'] = 'field_data_field_job_address';
  $handler->display->display_options['fields']['field_job_address_1']['field'] = 'field_job_address';
  $handler->display->display_options['fields']['field_job_address_1']['label'] = 'province';
  $handler->display->display_options['fields']['field_job_address_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_address_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_job_address_1']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_job_address_1']['settings'] = array(
    'components' => array(
      'administrative_area' => 'administrative_area',
    ),
    'separator' => ', ',
  );
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_job_address_2']['id'] = 'field_job_address_2';
  $handler->display->display_options['fields']['field_job_address_2']['table'] = 'field_data_field_job_address';
  $handler->display->display_options['fields']['field_job_address_2']['field'] = 'field_job_address';
  $handler->display->display_options['fields']['field_job_address_2']['label'] = 'city';
  $handler->display->display_options['fields']['field_job_address_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_address_2']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_job_address_2']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_job_address_2']['settings'] = array(
    'components' => array(
      'locality' => 'locality',
    ),
    'separator' => ', ',
  );
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_job_address_3']['id'] = 'field_job_address_3';
  $handler->display->display_options['fields']['field_job_address_3']['table'] = 'field_data_field_job_address';
  $handler->display->display_options['fields']['field_job_address_3']['field'] = 'field_job_address';
  $handler->display->display_options['fields']['field_job_address_3']['label'] = 'postal_code';
  $handler->display->display_options['fields']['field_job_address_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_address_3']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_job_address_3']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_job_address_3']['settings'] = array(
    'components' => array(
      'postal_code' => 'postal_code',
    ),
    'separator' => ', ',
  );
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_job_address_4']['id'] = 'field_job_address_4';
  $handler->display->display_options['fields']['field_job_address_4']['table'] = 'field_data_field_job_address';
  $handler->display->display_options['fields']['field_job_address_4']['field'] = 'field_job_address';
  $handler->display->display_options['fields']['field_job_address_4']['label'] = 'street';
  $handler->display->display_options['fields']['field_job_address_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_address_4']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_job_address_4']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_job_address_4']['settings'] = array(
    'components' => array(
      'thoroughfare' => 'thoroughfare',
    ),
    'separator' => ', ',
  );
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_job_address_5']['id'] = 'field_job_address_5';
  $handler->display->display_options['fields']['field_job_address_5']['table'] = 'field_data_field_job_address';
  $handler->display->display_options['fields']['field_job_address_5']['field'] = 'field_job_address';
  $handler->display->display_options['fields']['field_job_address_5']['label'] = 'premise';
  $handler->display->display_options['fields']['field_job_address_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_address_5']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_job_address_5']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_job_address_5']['settings'] = array(
    'components' => array(
      'premise' => 'premise',
    ),
    'separator' => ', ',
  );
  /* Field: Content: Accept Applications */
  $handler->display->display_options['fields']['field_job_applications']['id'] = 'field_job_applications';
  $handler->display->display_options['fields']['field_job_applications']['table'] = 'field_data_field_job_applications';
  $handler->display->display_options['fields']['field_job_applications']['field'] = 'field_job_applications';
  $handler->display->display_options['fields']['field_job_applications']['label'] = 'applications';
  $handler->display->display_options['fields']['field_job_applications']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_applications']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_job_applications']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_job_applications']['separator'] = ',';
  /* Field: Content: Job tags */
  $handler->display->display_options['fields']['field_job_tags']['id'] = 'field_job_tags';
  $handler->display->display_options['fields']['field_job_tags']['table'] = 'field_data_field_job_tags';
  $handler->display->display_options['fields']['field_job_tags']['field'] = 'field_job_tags';
  $handler->display->display_options['fields']['field_job_tags']['label'] = 'tags';
  $handler->display->display_options['fields']['field_job_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_job_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_job_tags']['separator'] = ',';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_job_url']['id'] = 'field_job_url';
  $handler->display->display_options['fields']['field_job_url']['table'] = 'field_data_field_job_url';
  $handler->display->display_options['fields']['field_job_url']['field'] = 'field_job_url';
  $handler->display->display_options['fields']['field_job_url']['label'] = 'url';
  $handler->display->display_options['fields']['field_job_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_job_url']['type'] = 'link_plain';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['relationship'] = 'field_job_attachments_fid';
  $handler->display->display_options['fields']['filename']['label'] = 'file';
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  /* Field: Content: Workflow State */
  $handler->display->display_options['fields']['field_job_workflow']['id'] = 'field_job_workflow';
  $handler->display->display_options['fields']['field_job_workflow']['table'] = 'field_data_field_job_workflow';
  $handler->display->display_options['fields']['field_job_workflow']['field'] = 'field_job_workflow';
  $handler->display->display_options['fields']['field_job_workflow']['label'] = 'workflow';
  $handler->display->display_options['fields']['field_job_workflow']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_workflow']['type'] = 'list_key';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job' => 'job',
  );
  $handler->display->display_options['path'] = 'admin/drop-jobs/export/job';

  /* Display: Organizations */
  $handler = $view->new_display('views_data_export', 'Organizations', 'organization');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Content: Image (field_image:fid) */
  $handler->display->display_options['relationships']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['relationships']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['relationships']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['relationships']['field_image_fid']['label'] = 'Logo';
  $handler->display->display_options['relationships']['field_image_fid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['relationship'] = 'field_image_fid';
  $handler->display->display_options['fields']['filename']['label'] = 'logo';
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'author';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Size */
  $handler->display->display_options['fields']['field_organization_size']['id'] = 'field_organization_size';
  $handler->display->display_options['fields']['field_organization_size']['table'] = 'field_data_field_organization_size';
  $handler->display->display_options['fields']['field_organization_size']['field'] = 'field_organization_size';
  $handler->display->display_options['fields']['field_organization_size']['label'] = 'size';
  $handler->display->display_options['fields']['field_organization_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_size']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['label'] = 'country';
  $handler->display->display_options['fields']['field_organization_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_organization_address']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_organization_address']['settings'] = array(
    'components' => array(
      'country' => 'country',
    ),
    'separator' => ', ',
  );
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_organization_address_1']['id'] = 'field_organization_address_1';
  $handler->display->display_options['fields']['field_organization_address_1']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_1']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_1']['label'] = 'province';
  $handler->display->display_options['fields']['field_organization_address_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_organization_address_1']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_organization_address_1']['settings'] = array(
    'components' => array(
      'administrative_area' => 'administrative_area',
    ),
    'separator' => ', ',
  );
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_organization_address_2']['id'] = 'field_organization_address_2';
  $handler->display->display_options['fields']['field_organization_address_2']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_2']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_2']['label'] = 'city';
  $handler->display->display_options['fields']['field_organization_address_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address_2']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_organization_address_2']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_organization_address_2']['settings'] = array(
    'components' => array(
      'locality' => 'locality',
    ),
    'separator' => ', ',
  );
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_organization_address_3']['id'] = 'field_organization_address_3';
  $handler->display->display_options['fields']['field_organization_address_3']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_3']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_3']['label'] = 'postal_code';
  $handler->display->display_options['fields']['field_organization_address_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address_3']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_organization_address_3']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_organization_address_3']['settings'] = array(
    'components' => array(
      'postal_code' => 'postal_code',
    ),
    'separator' => ', ',
  );
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_organization_address_4']['id'] = 'field_organization_address_4';
  $handler->display->display_options['fields']['field_organization_address_4']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_4']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_4']['label'] = 'street';
  $handler->display->display_options['fields']['field_organization_address_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address_4']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_organization_address_4']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_organization_address_4']['settings'] = array(
    'components' => array(
      'thoroughfare' => 'thoroughfare',
    ),
    'separator' => ', ',
  );
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_organization_address_5']['id'] = 'field_organization_address_5';
  $handler->display->display_options['fields']['field_organization_address_5']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_5']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_5']['label'] = 'premise';
  $handler->display->display_options['fields']['field_organization_address_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address_5']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_organization_address_5']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_organization_address_5']['settings'] = array(
    'components' => array(
      'premise' => 'premise',
    ),
    'separator' => ', ',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'description';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_organization_url']['id'] = 'field_organization_url';
  $handler->display->display_options['fields']['field_organization_url']['table'] = 'field_data_field_organization_url';
  $handler->display->display_options['fields']['field_organization_url']['field'] = 'field_organization_url';
  $handler->display->display_options['fields']['field_organization_url']['label'] = 'url';
  $handler->display->display_options['fields']['field_organization_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_organization_url']['type'] = 'link_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organization' => 'organization',
  );
  $handler->display->display_options['path'] = 'admin/drop-jobs/export/organization';
  $export['drop_jobs_dev_export_node'] = $view;

  $view = new view();
  $view->name = 'drop_jobs_dev_export_profile';
  $view->description = 'Views for exporting demo profiles for Migrate.';
  $view->tag = 'drop_jobs_dev';
  $view->base_table = 'profile';
  $view->human_name = 'Drop Jobs Dev Export Profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'candidate';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer drop_jobs';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['required'] = TRUE;
  /* Relationship: Profile: Phone Number (field_recruiter_phone) */
  $handler->display->display_options['relationships']['field_recruiter_phone_value']['id'] = 'field_recruiter_phone_value';
  $handler->display->display_options['relationships']['field_recruiter_phone_value']['table'] = 'field_data_field_recruiter_phone';
  $handler->display->display_options['relationships']['field_recruiter_phone_value']['field'] = 'field_recruiter_phone_value';
  $handler->display->display_options['relationships']['field_recruiter_phone_value']['label'] = 'Phone';
  $handler->display->display_options['relationships']['field_recruiter_phone_value']['delta'] = '-1';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'dummy_id';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'user';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_recruiter_first_name']['id'] = 'field_recruiter_first_name';
  $handler->display->display_options['fields']['field_recruiter_first_name']['table'] = 'field_data_field_recruiter_first_name';
  $handler->display->display_options['fields']['field_recruiter_first_name']['field'] = 'field_recruiter_first_name';
  $handler->display->display_options['fields']['field_recruiter_first_name']['relationship'] = 'field_contact_information_value';
  $handler->display->display_options['fields']['field_recruiter_first_name']['label'] = 'first_name';
  $handler->display->display_options['fields']['field_recruiter_first_name']['element_label_colon'] = FALSE;
  /* Field: Profile: Last Name */
  $handler->display->display_options['fields']['field_recruiter_last_name']['id'] = 'field_recruiter_last_name';
  $handler->display->display_options['fields']['field_recruiter_last_name']['table'] = 'field_data_field_recruiter_last_name';
  $handler->display->display_options['fields']['field_recruiter_last_name']['field'] = 'field_recruiter_last_name';
  $handler->display->display_options['fields']['field_recruiter_last_name']['relationship'] = 'field_contact_information_value';
  $handler->display->display_options['fields']['field_recruiter_last_name']['label'] = 'last_name';
  $handler->display->display_options['fields']['field_recruiter_last_name']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'user';

  /* Display: Recruiters */
  $handler = $view->new_display('views_data_export', 'Recruiters', 'recruiter');
  $handler->display->display_options['display_description'] = 'Exports recruiter base data to csv';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'recruiter';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['required'] = TRUE;
  /* Relationship: Profile: Photo (field_recruiter_photo:fid) */
  $handler->display->display_options['relationships']['field_recruiter_photo_fid']['id'] = 'field_recruiter_photo_fid';
  $handler->display->display_options['relationships']['field_recruiter_photo_fid']['table'] = 'field_data_field_recruiter_photo';
  $handler->display->display_options['relationships']['field_recruiter_photo_fid']['field'] = 'field_recruiter_photo_fid';
  $handler->display->display_options['relationships']['field_recruiter_photo_fid']['label'] = 'Photo';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'dummy_id';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'user';
  $handler->display->display_options['fields']['uid']['label'] = 'id';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'user';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_recruiter_first_name']['id'] = 'field_recruiter_first_name';
  $handler->display->display_options['fields']['field_recruiter_first_name']['table'] = 'field_data_field_recruiter_first_name';
  $handler->display->display_options['fields']['field_recruiter_first_name']['field'] = 'field_recruiter_first_name';
  $handler->display->display_options['fields']['field_recruiter_first_name']['relationship'] = 'field_contact_information_value';
  $handler->display->display_options['fields']['field_recruiter_first_name']['label'] = 'first_name';
  $handler->display->display_options['fields']['field_recruiter_first_name']['element_label_colon'] = FALSE;
  /* Field: Profile: Last Name */
  $handler->display->display_options['fields']['field_recruiter_last_name']['id'] = 'field_recruiter_last_name';
  $handler->display->display_options['fields']['field_recruiter_last_name']['table'] = 'field_data_field_recruiter_last_name';
  $handler->display->display_options['fields']['field_recruiter_last_name']['field'] = 'field_recruiter_last_name';
  $handler->display->display_options['fields']['field_recruiter_last_name']['relationship'] = 'field_contact_information_value';
  $handler->display->display_options['fields']['field_recruiter_last_name']['label'] = 'last_name';
  $handler->display->display_options['fields']['field_recruiter_last_name']['element_label_colon'] = FALSE;
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['relationship'] = 'field_recruiter_photo_fid';
  $handler->display->display_options['fields']['filename']['label'] = 'photo';
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  /* Field: Profile: Organization */
  $handler->display->display_options['fields']['field_recruiter_organization']['id'] = 'field_recruiter_organization';
  $handler->display->display_options['fields']['field_recruiter_organization']['table'] = 'field_data_field_recruiter_organization';
  $handler->display->display_options['fields']['field_recruiter_organization']['field'] = 'field_recruiter_organization';
  $handler->display->display_options['fields']['field_recruiter_organization']['label'] = 'organization';
  $handler->display->display_options['fields']['field_recruiter_organization']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_recruiter_organization']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recruiter' => 'recruiter',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    100482362 => '100482362',
  );
  $handler->display->display_options['path'] = 'admin/drop-jobs/export/recruiter';

  /* Display: Candidates */
  $handler = $view->new_display('views_data_export', 'Candidates', 'candidate');
  $handler->display->display_options['display_description'] = 'Exports candidate base data to csv';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'candidate';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = 'id';
  $handler->display->display_options['fields']['user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user']['separator'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'user';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Profile: Promoted */
  $handler->display->display_options['fields']['field_resume_promoted']['id'] = 'field_resume_promoted';
  $handler->display->display_options['fields']['field_resume_promoted']['table'] = 'field_data_field_resume_promoted';
  $handler->display->display_options['fields']['field_resume_promoted']['field'] = 'field_resume_promoted';
  $handler->display->display_options['fields']['field_resume_promoted']['label'] = 'promoted';
  $handler->display->display_options['fields']['field_resume_promoted']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_promoted']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_resume_promoted']['settings'] = array(
    'clickable' => 0,
    'display_type' => '0',
  );
  /* Field: Profile: Sticky */
  $handler->display->display_options['fields']['field_resume_sticky']['id'] = 'field_resume_sticky';
  $handler->display->display_options['fields']['field_resume_sticky']['table'] = 'field_data_field_resume_sticky';
  $handler->display->display_options['fields']['field_resume_sticky']['field'] = 'field_resume_sticky';
  $handler->display->display_options['fields']['field_resume_sticky']['label'] = 'sticky';
  $handler->display->display_options['fields']['field_resume_sticky']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_sticky']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_resume_sticky']['settings'] = array(
    'clickable' => 0,
    'display_type' => '0',
  );
  /* Field: Profile: Workflow State */
  $handler->display->display_options['fields']['field_resume_workflow']['id'] = 'field_resume_workflow';
  $handler->display->display_options['fields']['field_resume_workflow']['table'] = 'field_data_field_resume_workflow';
  $handler->display->display_options['fields']['field_resume_workflow']['field'] = 'field_resume_workflow';
  $handler->display->display_options['fields']['field_resume_workflow']['label'] = 'workflow';
  $handler->display->display_options['fields']['field_resume_workflow']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_workflow']['type'] = 'list_key';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resume' => 'resume',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    185431326 => '185431326',
  );
  $handler->display->display_options['path'] = 'admin/drop-jobs/export/candidate';

  /* Display: Candidates Personal */
  $handler = $view->new_display('views_data_export', 'Candidates Personal', 'candidate_personal');
  $handler->display->display_options['display_description'] = 'Exports candidate personal information data to csv';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'candidate_personal';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['required'] = TRUE;
  /* Relationship: Profile: Personal Information (field_resume_personal) */
  $handler->display->display_options['relationships']['field_resume_personal_value']['id'] = 'field_resume_personal_value';
  $handler->display->display_options['relationships']['field_resume_personal_value']['table'] = 'field_data_field_resume_personal';
  $handler->display->display_options['relationships']['field_resume_personal_value']['field'] = 'field_resume_personal_value';
  $handler->display->display_options['relationships']['field_resume_personal_value']['label'] = 'Personal Info';
  $handler->display->display_options['relationships']['field_resume_personal_value']['delta'] = '-1';
  /* Relationship: Field collection item: Photo (field_resume_photo:fid) */
  $handler->display->display_options['relationships']['field_resume_photo_fid']['id'] = 'field_resume_photo_fid';
  $handler->display->display_options['relationships']['field_resume_photo_fid']['table'] = 'field_data_field_resume_photo';
  $handler->display->display_options['relationships']['field_resume_photo_fid']['field'] = 'field_resume_photo_fid';
  $handler->display->display_options['relationships']['field_resume_photo_fid']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['relationships']['field_resume_photo_fid']['label'] = 'Photo';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'dummy_id';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Profile: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = 'id';
  $handler->display->display_options['fields']['user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user']['separator'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'user';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field collection item: Gender */
  $handler->display->display_options['fields']['field_resume_gender']['id'] = 'field_resume_gender';
  $handler->display->display_options['fields']['field_resume_gender']['table'] = 'field_data_field_resume_gender';
  $handler->display->display_options['fields']['field_resume_gender']['field'] = 'field_resume_gender';
  $handler->display->display_options['fields']['field_resume_gender']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['fields']['field_resume_gender']['label'] = 'gender';
  $handler->display->display_options['fields']['field_resume_gender']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_gender']['type'] = 'list_key';
  /* Field: Field collection item: Birthday */
  $handler->display->display_options['fields']['field_resume_birthday']['id'] = 'field_resume_birthday';
  $handler->display->display_options['fields']['field_resume_birthday']['table'] = 'field_data_field_resume_birthday';
  $handler->display->display_options['fields']['field_resume_birthday']['field'] = 'field_resume_birthday';
  $handler->display->display_options['fields']['field_resume_birthday']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['fields']['field_resume_birthday']['label'] = 'birthday';
  $handler->display->display_options['fields']['field_resume_birthday']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_birthday']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: Marital Status */
  $handler->display->display_options['fields']['field_resume_marital_status']['id'] = 'field_resume_marital_status';
  $handler->display->display_options['fields']['field_resume_marital_status']['table'] = 'field_data_field_resume_marital_status';
  $handler->display->display_options['fields']['field_resume_marital_status']['field'] = 'field_resume_marital_status';
  $handler->display->display_options['fields']['field_resume_marital_status']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['fields']['field_resume_marital_status']['label'] = 'marital';
  $handler->display->display_options['fields']['field_resume_marital_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_marital_status']['type'] = 'list_key';
  /* Field: Field collection item: Address */
  $handler->display->display_options['fields']['field_resume_address']['id'] = 'field_resume_address';
  $handler->display->display_options['fields']['field_resume_address']['table'] = 'field_data_field_resume_address';
  $handler->display->display_options['fields']['field_resume_address']['field'] = 'field_resume_address';
  $handler->display->display_options['fields']['field_resume_address']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['fields']['field_resume_address']['label'] = 'country';
  $handler->display->display_options['fields']['field_resume_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_resume_address']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_resume_address']['settings'] = array(
    'components' => array(
      'country' => 'country',
    ),
    'separator' => ', ',
  );
  /* Field: Field collection item: Address */
  $handler->display->display_options['fields']['field_resume_address_1']['id'] = 'field_resume_address_1';
  $handler->display->display_options['fields']['field_resume_address_1']['table'] = 'field_data_field_resume_address';
  $handler->display->display_options['fields']['field_resume_address_1']['field'] = 'field_resume_address';
  $handler->display->display_options['fields']['field_resume_address_1']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['fields']['field_resume_address_1']['label'] = 'province';
  $handler->display->display_options['fields']['field_resume_address_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_address_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_resume_address_1']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_resume_address_1']['settings'] = array(
    'components' => array(
      'administrative_area' => 'administrative_area',
    ),
    'separator' => ', ',
  );
  /* Field: Field collection item: Address */
  $handler->display->display_options['fields']['field_resume_address_2']['id'] = 'field_resume_address_2';
  $handler->display->display_options['fields']['field_resume_address_2']['table'] = 'field_data_field_resume_address';
  $handler->display->display_options['fields']['field_resume_address_2']['field'] = 'field_resume_address';
  $handler->display->display_options['fields']['field_resume_address_2']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['fields']['field_resume_address_2']['label'] = 'city';
  $handler->display->display_options['fields']['field_resume_address_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_address_2']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_resume_address_2']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_resume_address_2']['settings'] = array(
    'components' => array(
      'locality' => 'locality',
    ),
    'separator' => ', ',
  );
  /* Field: Field collection item: Address */
  $handler->display->display_options['fields']['field_resume_address_3']['id'] = 'field_resume_address_3';
  $handler->display->display_options['fields']['field_resume_address_3']['table'] = 'field_data_field_resume_address';
  $handler->display->display_options['fields']['field_resume_address_3']['field'] = 'field_resume_address';
  $handler->display->display_options['fields']['field_resume_address_3']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['fields']['field_resume_address_3']['label'] = 'postal_code';
  $handler->display->display_options['fields']['field_resume_address_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_address_3']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_resume_address_3']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_resume_address_3']['settings'] = array(
    'components' => array(
      'postal_code' => 'postal_code',
    ),
    'separator' => ', ',
  );
  /* Field: Field collection item: Address */
  $handler->display->display_options['fields']['field_resume_address_4']['id'] = 'field_resume_address_4';
  $handler->display->display_options['fields']['field_resume_address_4']['table'] = 'field_data_field_resume_address';
  $handler->display->display_options['fields']['field_resume_address_4']['field'] = 'field_resume_address';
  $handler->display->display_options['fields']['field_resume_address_4']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['fields']['field_resume_address_4']['label'] = 'street';
  $handler->display->display_options['fields']['field_resume_address_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_address_4']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_resume_address_4']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_resume_address_4']['settings'] = array(
    'components' => array(
      'thoroughfare' => 'thoroughfare',
    ),
    'separator' => ', ',
  );
  /* Field: Field collection item: Address */
  $handler->display->display_options['fields']['field_resume_address_5']['id'] = 'field_resume_address_5';
  $handler->display->display_options['fields']['field_resume_address_5']['table'] = 'field_data_field_resume_address';
  $handler->display->display_options['fields']['field_resume_address_5']['field'] = 'field_resume_address';
  $handler->display->display_options['fields']['field_resume_address_5']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['fields']['field_resume_address_5']['label'] = 'premise';
  $handler->display->display_options['fields']['field_resume_address_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_address_5']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_resume_address_5']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_resume_address_5']['settings'] = array(
    'components' => array(
      'premise' => 'premise',
    ),
    'separator' => ', ',
  );
  /* Field: Field collection item: Summary */
  $handler->display->display_options['fields']['field_resume_notes']['id'] = 'field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['table'] = 'field_data_field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['field'] = 'field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['fields']['field_resume_notes']['label'] = 'about';
  $handler->display->display_options['fields']['field_resume_notes']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_notes']['type'] = 'text_plain';
  /* Field: Field collection item: First Name */
  $handler->display->display_options['fields']['field_resume_first_name']['id'] = 'field_resume_first_name';
  $handler->display->display_options['fields']['field_resume_first_name']['table'] = 'field_data_field_resume_first_name';
  $handler->display->display_options['fields']['field_resume_first_name']['field'] = 'field_resume_first_name';
  $handler->display->display_options['fields']['field_resume_first_name']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['fields']['field_resume_first_name']['label'] = 'first_name';
  $handler->display->display_options['fields']['field_resume_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_first_name']['type'] = 'text_plain';
  /* Field: Field collection item: Last Name */
  $handler->display->display_options['fields']['field_resume_last_name']['id'] = 'field_resume_last_name';
  $handler->display->display_options['fields']['field_resume_last_name']['table'] = 'field_data_field_resume_last_name';
  $handler->display->display_options['fields']['field_resume_last_name']['field'] = 'field_resume_last_name';
  $handler->display->display_options['fields']['field_resume_last_name']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['fields']['field_resume_last_name']['label'] = 'last_name';
  $handler->display->display_options['fields']['field_resume_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_last_name']['type'] = 'text_plain';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['relationship'] = 'field_resume_photo_fid';
  $handler->display->display_options['fields']['filename']['label'] = 'photo';
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Salutation */
  $handler->display->display_options['fields']['field_resume_salutation']['id'] = 'field_resume_salutation';
  $handler->display->display_options['fields']['field_resume_salutation']['table'] = 'field_data_field_resume_salutation';
  $handler->display->display_options['fields']['field_resume_salutation']['field'] = 'field_resume_salutation';
  $handler->display->display_options['fields']['field_resume_salutation']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['fields']['field_resume_salutation']['label'] = 'salutation';
  $handler->display->display_options['fields']['field_resume_salutation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_salutation']['type'] = 'list_key';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resume' => 'resume',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    185431326 => '185431326',
  );
  $handler->display->display_options['path'] = 'admin/drop-jobs/export/candidate_personal';

  /* Display: Candidates Languages */
  $handler = $view->new_display('views_data_export', 'Candidates Languages', 'candidate_language');
  $handler->display->display_options['display_description'] = 'Exports candidate languages information data to csv';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'candidate_language';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['required'] = TRUE;
  /* Relationship: Profile: Languages (field_resume_languages) */
  $handler->display->display_options['relationships']['field_resume_languages_value']['id'] = 'field_resume_languages_value';
  $handler->display->display_options['relationships']['field_resume_languages_value']['table'] = 'field_data_field_resume_languages';
  $handler->display->display_options['relationships']['field_resume_languages_value']['field'] = 'field_resume_languages_value';
  $handler->display->display_options['relationships']['field_resume_languages_value']['label'] = 'Languages';
  $handler->display->display_options['relationships']['field_resume_languages_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'dummy_id';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Profile: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = 'id';
  $handler->display->display_options['fields']['user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user']['separator'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'user';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field collection item: Language */
  $handler->display->display_options['fields']['field_resume_language']['id'] = 'field_resume_language';
  $handler->display->display_options['fields']['field_resume_language']['table'] = 'field_data_field_resume_language';
  $handler->display->display_options['fields']['field_resume_language']['field'] = 'field_resume_language';
  $handler->display->display_options['fields']['field_resume_language']['relationship'] = 'field_resume_languages_value';
  $handler->display->display_options['fields']['field_resume_language']['label'] = 'languages';
  $handler->display->display_options['fields']['field_resume_language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_language']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_resume_language']['type'] = 'term_level_export';
  $handler->display->display_options['fields']['field_resume_language']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_resume_language']['separator'] = ',';
  /* Field: Field collection item: Summary */
  $handler->display->display_options['fields']['field_resume_notes']['id'] = 'field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['table'] = 'field_data_field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['field'] = 'field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['relationship'] = 'field_resume_languages_value';
  $handler->display->display_options['fields']['field_resume_notes']['label'] = 'notes';
  $handler->display->display_options['fields']['field_resume_notes']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_notes']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resume' => 'resume',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    185431326 => '185431326',
  );
  $handler->display->display_options['path'] = 'admin/drop-jobs/export/candidate_language';

  /* Display: Candidates Education */
  $handler = $view->new_display('views_data_export', 'Candidates Education', 'candidate_education');
  $handler->display->display_options['display_description'] = 'Exports candidate education information data to csv';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'candidate_education';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['required'] = TRUE;
  /* Relationship: Profile: Education (field_resume_education) */
  $handler->display->display_options['relationships']['field_resume_education_value']['id'] = 'field_resume_education_value';
  $handler->display->display_options['relationships']['field_resume_education_value']['table'] = 'field_data_field_resume_education';
  $handler->display->display_options['relationships']['field_resume_education_value']['field'] = 'field_resume_education_value';
  $handler->display->display_options['relationships']['field_resume_education_value']['label'] = 'Education';
  $handler->display->display_options['relationships']['field_resume_education_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'dummy_id';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Profile: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = 'id';
  $handler->display->display_options['fields']['user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user']['separator'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'user';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field collection item: Degree Level */
  $handler->display->display_options['fields']['field_resume_edu_level']['id'] = 'field_resume_edu_level';
  $handler->display->display_options['fields']['field_resume_edu_level']['table'] = 'field_data_field_resume_edu_level';
  $handler->display->display_options['fields']['field_resume_edu_level']['field'] = 'field_resume_edu_level';
  $handler->display->display_options['fields']['field_resume_edu_level']['relationship'] = 'field_resume_education_value';
  $handler->display->display_options['fields']['field_resume_edu_level']['label'] = 'degree';
  $handler->display->display_options['fields']['field_resume_edu_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_edu_level']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: Institution Name */
  $handler->display->display_options['fields']['field_resume_edu_name']['id'] = 'field_resume_edu_name';
  $handler->display->display_options['fields']['field_resume_edu_name']['table'] = 'field_data_field_resume_edu_name';
  $handler->display->display_options['fields']['field_resume_edu_name']['field'] = 'field_resume_edu_name';
  $handler->display->display_options['fields']['field_resume_edu_name']['relationship'] = 'field_resume_education_value';
  $handler->display->display_options['fields']['field_resume_edu_name']['label'] = 'institution';
  $handler->display->display_options['fields']['field_resume_edu_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_edu_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_resume_edu_name']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Field collection item: Field of Study */
  $handler->display->display_options['fields']['field_resume_edu_field']['id'] = 'field_resume_edu_field';
  $handler->display->display_options['fields']['field_resume_edu_field']['table'] = 'field_data_field_resume_edu_field';
  $handler->display->display_options['fields']['field_resume_edu_field']['field'] = 'field_resume_edu_field';
  $handler->display->display_options['fields']['field_resume_edu_field']['relationship'] = 'field_resume_education_value';
  $handler->display->display_options['fields']['field_resume_edu_field']['label'] = 'field';
  $handler->display->display_options['fields']['field_resume_edu_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_edu_field']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: Time Period */
  $handler->display->display_options['fields']['field_resume_edu_time']['id'] = 'field_resume_edu_time';
  $handler->display->display_options['fields']['field_resume_edu_time']['table'] = 'field_data_field_resume_edu_time';
  $handler->display->display_options['fields']['field_resume_edu_time']['field'] = 'field_resume_edu_time';
  $handler->display->display_options['fields']['field_resume_edu_time']['relationship'] = 'field_resume_education_value';
  $handler->display->display_options['fields']['field_resume_edu_time']['label'] = 'period';
  $handler->display->display_options['fields']['field_resume_edu_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_edu_time']['settings'] = array(
    'format_type' => 'export',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resume' => 'resume',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    185431326 => '185431326',
  );
  $handler->display->display_options['path'] = 'admin/drop-jobs/export/candidate_education';

  /* Display: Candidates Prefs */
  $handler = $view->new_display('views_data_export', 'Candidates Prefs', 'candidate_preferences');
  $handler->display->display_options['display_description'] = 'Exports candidate job preferences information data to csv';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'candidate_preferences';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['required'] = TRUE;
  /* Relationship: Profile: Job Preferences (field_resume_preferences) */
  $handler->display->display_options['relationships']['field_resume_preferences_value']['id'] = 'field_resume_preferences_value';
  $handler->display->display_options['relationships']['field_resume_preferences_value']['table'] = 'field_data_field_resume_preferences';
  $handler->display->display_options['relationships']['field_resume_preferences_value']['field'] = 'field_resume_preferences_value';
  $handler->display->display_options['relationships']['field_resume_preferences_value']['label'] = 'Job Preferences';
  $handler->display->display_options['relationships']['field_resume_preferences_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'dummy_id';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Profile: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = 'id';
  $handler->display->display_options['fields']['user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user']['separator'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'user';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field collection item: Desired Job Title */
  $handler->display->display_options['fields']['field_resume_pref_title']['id'] = 'field_resume_pref_title';
  $handler->display->display_options['fields']['field_resume_pref_title']['table'] = 'field_data_field_resume_pref_title';
  $handler->display->display_options['fields']['field_resume_pref_title']['field'] = 'field_resume_pref_title';
  $handler->display->display_options['fields']['field_resume_pref_title']['relationship'] = 'field_resume_preferences_value';
  $handler->display->display_options['fields']['field_resume_pref_title']['label'] = 'title';
  $handler->display->display_options['fields']['field_resume_pref_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_pref_title']['type'] = 'text_plain';
  /* Field: Field collection item: Desired Occupation */
  $handler->display->display_options['fields']['field_resume_pref_occupation']['id'] = 'field_resume_pref_occupation';
  $handler->display->display_options['fields']['field_resume_pref_occupation']['table'] = 'field_data_field_resume_pref_occupation';
  $handler->display->display_options['fields']['field_resume_pref_occupation']['field'] = 'field_resume_pref_occupation';
  $handler->display->display_options['fields']['field_resume_pref_occupation']['relationship'] = 'field_resume_preferences_value';
  $handler->display->display_options['fields']['field_resume_pref_occupation']['label'] = 'occupation';
  $handler->display->display_options['fields']['field_resume_pref_occupation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_pref_occupation']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: Desired Emploment Type */
  $handler->display->display_options['fields']['field_resume_pref_employment']['id'] = 'field_resume_pref_employment';
  $handler->display->display_options['fields']['field_resume_pref_employment']['table'] = 'field_data_field_resume_pref_employment';
  $handler->display->display_options['fields']['field_resume_pref_employment']['field'] = 'field_resume_pref_employment';
  $handler->display->display_options['fields']['field_resume_pref_employment']['relationship'] = 'field_resume_preferences_value';
  $handler->display->display_options['fields']['field_resume_pref_employment']['label'] = 'type';
  $handler->display->display_options['fields']['field_resume_pref_employment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_pref_employment']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_resume_pref_employment']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_resume_pref_employment']['separator'] = ',';
  /* Field: Field collection item: Available to Start */
  $handler->display->display_options['fields']['field_resume_pref_start']['id'] = 'field_resume_pref_start';
  $handler->display->display_options['fields']['field_resume_pref_start']['table'] = 'field_data_field_resume_pref_start';
  $handler->display->display_options['fields']['field_resume_pref_start']['field'] = 'field_resume_pref_start';
  $handler->display->display_options['fields']['field_resume_pref_start']['relationship'] = 'field_resume_preferences_value';
  $handler->display->display_options['fields']['field_resume_pref_start']['label'] = 'start';
  $handler->display->display_options['fields']['field_resume_pref_start']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_pref_start']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: Desired Salary */
  $handler->display->display_options['fields']['field_resume_pref_salary']['id'] = 'field_resume_pref_salary';
  $handler->display->display_options['fields']['field_resume_pref_salary']['table'] = 'field_data_field_resume_pref_salary';
  $handler->display->display_options['fields']['field_resume_pref_salary']['field'] = 'field_resume_pref_salary';
  $handler->display->display_options['fields']['field_resume_pref_salary']['relationship'] = 'field_resume_preferences_value';
  $handler->display->display_options['fields']['field_resume_pref_salary']['label'] = 'salary';
  $handler->display->display_options['fields']['field_resume_pref_salary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_pref_salary']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_resume_pref_salary']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Summary */
  $handler->display->display_options['fields']['field_resume_notes']['id'] = 'field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['table'] = 'field_data_field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['field'] = 'field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['relationship'] = 'field_resume_preferences_value';
  $handler->display->display_options['fields']['field_resume_notes']['label'] = 'notes';
  $handler->display->display_options['fields']['field_resume_notes']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_notes']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resume' => 'resume',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    185431326 => '185431326',
  );
  $handler->display->display_options['path'] = 'admin/drop-jobs/export/candidate_preferences';

  /* Display: Candidates Skills */
  $handler = $view->new_display('views_data_export', 'Candidates Skills', 'candidate_skills');
  $handler->display->display_options['display_description'] = 'Exports candidate skills information data to csv';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'candidate_skills';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['required'] = TRUE;
  /* Relationship: Profile: Skills (field_resume_skills) */
  $handler->display->display_options['relationships']['field_resume_skills_value']['id'] = 'field_resume_skills_value';
  $handler->display->display_options['relationships']['field_resume_skills_value']['table'] = 'field_data_field_resume_skills';
  $handler->display->display_options['relationships']['field_resume_skills_value']['field'] = 'field_resume_skills_value';
  $handler->display->display_options['relationships']['field_resume_skills_value']['label'] = 'Skills';
  $handler->display->display_options['relationships']['field_resume_skills_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'dummy_id';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Profile: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = 'id';
  $handler->display->display_options['fields']['user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user']['separator'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'user';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field collection item: Skill */
  $handler->display->display_options['fields']['field_resume_skills_level']['id'] = 'field_resume_skills_level';
  $handler->display->display_options['fields']['field_resume_skills_level']['table'] = 'field_data_field_resume_skills_level';
  $handler->display->display_options['fields']['field_resume_skills_level']['field'] = 'field_resume_skills_level';
  $handler->display->display_options['fields']['field_resume_skills_level']['relationship'] = 'field_resume_skills_value';
  $handler->display->display_options['fields']['field_resume_skills_level']['label'] = 'skill';
  $handler->display->display_options['fields']['field_resume_skills_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_skills_level']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_resume_skills_level']['type'] = 'term_level_export';
  $handler->display->display_options['fields']['field_resume_skills_level']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_resume_skills_level']['separator'] = ',';
  /* Field: Field collection item: Summary */
  $handler->display->display_options['fields']['field_resume_notes']['id'] = 'field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['table'] = 'field_data_field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['field'] = 'field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['relationship'] = 'field_resume_skills_value';
  $handler->display->display_options['fields']['field_resume_notes']['label'] = 'notes';
  $handler->display->display_options['fields']['field_resume_notes']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_notes']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resume' => 'resume',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    185431326 => '185431326',
  );
  $handler->display->display_options['path'] = 'admin/drop-jobs/export/candidate_skills';

  /* Display: Candidates Work */
  $handler = $view->new_display('views_data_export', 'Candidates Work', 'candidate_work');
  $handler->display->display_options['display_description'] = 'Exports candidate work experience information data to csv';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'views_data_export_1';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['required'] = TRUE;
  /* Relationship: Profile: Work Experience (field_resume_experience) */
  $handler->display->display_options['relationships']['field_resume_experience_value']['id'] = 'field_resume_experience_value';
  $handler->display->display_options['relationships']['field_resume_experience_value']['table'] = 'field_data_field_resume_experience';
  $handler->display->display_options['relationships']['field_resume_experience_value']['field'] = 'field_resume_experience_value';
  $handler->display->display_options['relationships']['field_resume_experience_value']['label'] = 'Work Experience';
  $handler->display->display_options['relationships']['field_resume_experience_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'dummy_id';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Profile: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = 'id';
  $handler->display->display_options['fields']['user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user']['separator'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'user';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field collection item: Job Title */
  $handler->display->display_options['fields']['field_resume_exp_title']['id'] = 'field_resume_exp_title';
  $handler->display->display_options['fields']['field_resume_exp_title']['table'] = 'field_data_field_resume_exp_title';
  $handler->display->display_options['fields']['field_resume_exp_title']['field'] = 'field_resume_exp_title';
  $handler->display->display_options['fields']['field_resume_exp_title']['relationship'] = 'field_resume_experience_value';
  $handler->display->display_options['fields']['field_resume_exp_title']['label'] = 'title';
  $handler->display->display_options['fields']['field_resume_exp_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_exp_title']['type'] = 'text_plain';
  /* Field: Field collection item: Company Name */
  $handler->display->display_options['fields']['field_resume_exp_company_name']['id'] = 'field_resume_exp_company_name';
  $handler->display->display_options['fields']['field_resume_exp_company_name']['table'] = 'field_data_field_resume_exp_company_name';
  $handler->display->display_options['fields']['field_resume_exp_company_name']['field'] = 'field_resume_exp_company_name';
  $handler->display->display_options['fields']['field_resume_exp_company_name']['relationship'] = 'field_resume_experience_value';
  $handler->display->display_options['fields']['field_resume_exp_company_name']['label'] = 'company_name';
  $handler->display->display_options['fields']['field_resume_exp_company_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_exp_company_name']['type'] = 'text_plain';
  /* Field: Field collection item: Company Link */
  $handler->display->display_options['fields']['field_resume_exp_company_url']['id'] = 'field_resume_exp_company_url';
  $handler->display->display_options['fields']['field_resume_exp_company_url']['table'] = 'field_data_field_resume_exp_company_url';
  $handler->display->display_options['fields']['field_resume_exp_company_url']['field'] = 'field_resume_exp_company_url';
  $handler->display->display_options['fields']['field_resume_exp_company_url']['relationship'] = 'field_resume_experience_value';
  $handler->display->display_options['fields']['field_resume_exp_company_url']['label'] = 'company_link';
  $handler->display->display_options['fields']['field_resume_exp_company_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_exp_company_url']['click_sort_column'] = 'url';
  /* Field: Field collection item: Occupational Field */
  $handler->display->display_options['fields']['field_resume_exp_field']['id'] = 'field_resume_exp_field';
  $handler->display->display_options['fields']['field_resume_exp_field']['table'] = 'field_data_field_resume_exp_field';
  $handler->display->display_options['fields']['field_resume_exp_field']['field'] = 'field_resume_exp_field';
  $handler->display->display_options['fields']['field_resume_exp_field']['relationship'] = 'field_resume_experience_value';
  $handler->display->display_options['fields']['field_resume_exp_field']['label'] = 'occupation';
  $handler->display->display_options['fields']['field_resume_exp_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_exp_field']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: Time Period */
  $handler->display->display_options['fields']['field_resume_exp_time']['id'] = 'field_resume_exp_time';
  $handler->display->display_options['fields']['field_resume_exp_time']['table'] = 'field_data_field_resume_exp_time';
  $handler->display->display_options['fields']['field_resume_exp_time']['field'] = 'field_resume_exp_time';
  $handler->display->display_options['fields']['field_resume_exp_time']['relationship'] = 'field_resume_experience_value';
  $handler->display->display_options['fields']['field_resume_exp_time']['label'] = 'period';
  $handler->display->display_options['fields']['field_resume_exp_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_exp_time']['settings'] = array(
    'format_type' => 'export',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: Employment Type */
  $handler->display->display_options['fields']['field_resume_exp_type']['id'] = 'field_resume_exp_type';
  $handler->display->display_options['fields']['field_resume_exp_type']['table'] = 'field_data_field_resume_exp_type';
  $handler->display->display_options['fields']['field_resume_exp_type']['field'] = 'field_resume_exp_type';
  $handler->display->display_options['fields']['field_resume_exp_type']['relationship'] = 'field_resume_experience_value';
  $handler->display->display_options['fields']['field_resume_exp_type']['label'] = 'type';
  $handler->display->display_options['fields']['field_resume_exp_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_exp_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: Summary */
  $handler->display->display_options['fields']['field_resume_notes']['id'] = 'field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['table'] = 'field_data_field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['field'] = 'field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['relationship'] = 'field_resume_experience_value';
  $handler->display->display_options['fields']['field_resume_notes']['label'] = 'notes';
  $handler->display->display_options['fields']['field_resume_notes']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_notes']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resume' => 'resume',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    185431326 => '185431326',
  );
  $handler->display->display_options['path'] = 'admin/drop-jobs/export/candidate_work';

  /* Display: Recruiters Phone */
  $handler = $view->new_display('views_data_export', 'Recruiters Phone', 'recruiter_phone');
  $handler->display->display_options['display_description'] = 'Exports recruiters phone information data to csv';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'views_data_export_1';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'dummy_id';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'user';
  $handler->display->display_options['fields']['uid']['label'] = 'id';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'user';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field collection item: Type */
  $handler->display->display_options['fields']['field_recruiter_phone_type']['id'] = 'field_recruiter_phone_type';
  $handler->display->display_options['fields']['field_recruiter_phone_type']['table'] = 'field_data_field_recruiter_phone_type';
  $handler->display->display_options['fields']['field_recruiter_phone_type']['field'] = 'field_recruiter_phone_type';
  $handler->display->display_options['fields']['field_recruiter_phone_type']['relationship'] = 'field_recruiter_phone_value';
  $handler->display->display_options['fields']['field_recruiter_phone_type']['label'] = 'phone_type';
  $handler->display->display_options['fields']['field_recruiter_phone_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_recruiter_phone_type']['type'] = 'list_key';
  /* Field: Field collection item: Number */
  $handler->display->display_options['fields']['field_recruiter_phone_number']['id'] = 'field_recruiter_phone_number';
  $handler->display->display_options['fields']['field_recruiter_phone_number']['table'] = 'field_data_field_recruiter_phone_number';
  $handler->display->display_options['fields']['field_recruiter_phone_number']['field'] = 'field_recruiter_phone_number';
  $handler->display->display_options['fields']['field_recruiter_phone_number']['relationship'] = 'field_recruiter_phone_value';
  $handler->display->display_options['fields']['field_recruiter_phone_number']['label'] = 'phone_number';
  $handler->display->display_options['fields']['field_recruiter_phone_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recruiter' => 'recruiter',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    100482362 => '100482362',
  );
  $handler->display->display_options['path'] = 'admin/drop-jobs/export/recruiter_phone';

  /* Display: Candidates Phone */
  $handler = $view->new_display('views_data_export', 'Candidates Phone', 'candidate_phone');
  $handler->display->display_options['display_description'] = 'Exports candidate phone information data to csv';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'recruiter_phone';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['required'] = TRUE;
  /* Relationship: Profile: Personal Information (field_resume_personal) */
  $handler->display->display_options['relationships']['field_resume_personal_value']['id'] = 'field_resume_personal_value';
  $handler->display->display_options['relationships']['field_resume_personal_value']['table'] = 'field_data_field_resume_personal';
  $handler->display->display_options['relationships']['field_resume_personal_value']['field'] = 'field_resume_personal_value';
  $handler->display->display_options['relationships']['field_resume_personal_value']['label'] = 'Personal Info';
  $handler->display->display_options['relationships']['field_resume_personal_value']['delta'] = '-1';
  /* Relationship: Field collection item: Phone Number (field_resume_phone) */
  $handler->display->display_options['relationships']['field_resume_phone_value']['id'] = 'field_resume_phone_value';
  $handler->display->display_options['relationships']['field_resume_phone_value']['table'] = 'field_data_field_resume_phone';
  $handler->display->display_options['relationships']['field_resume_phone_value']['field'] = 'field_resume_phone_value';
  $handler->display->display_options['relationships']['field_resume_phone_value']['relationship'] = 'field_resume_personal_value';
  $handler->display->display_options['relationships']['field_resume_phone_value']['label'] = 'Phone';
  $handler->display->display_options['relationships']['field_resume_phone_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'dummy_id';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Profile: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = 'id';
  $handler->display->display_options['fields']['user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user']['separator'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'user';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field collection item: Type */
  $handler->display->display_options['fields']['field_resume_phone_type']['id'] = 'field_resume_phone_type';
  $handler->display->display_options['fields']['field_resume_phone_type']['table'] = 'field_data_field_resume_phone_type';
  $handler->display->display_options['fields']['field_resume_phone_type']['field'] = 'field_resume_phone_type';
  $handler->display->display_options['fields']['field_resume_phone_type']['relationship'] = 'field_resume_phone_value';
  $handler->display->display_options['fields']['field_resume_phone_type']['label'] = 'phone_type';
  $handler->display->display_options['fields']['field_resume_phone_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_phone_type']['type'] = 'list_key';
  /* Field: Field collection item: Number */
  $handler->display->display_options['fields']['field_resume_phone_number']['id'] = 'field_resume_phone_number';
  $handler->display->display_options['fields']['field_resume_phone_number']['table'] = 'field_data_field_resume_phone_number';
  $handler->display->display_options['fields']['field_resume_phone_number']['field'] = 'field_resume_phone_number';
  $handler->display->display_options['fields']['field_resume_phone_number']['relationship'] = 'field_resume_phone_value';
  $handler->display->display_options['fields']['field_resume_phone_number']['label'] = 'phone_number';
  $handler->display->display_options['fields']['field_resume_phone_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resume_phone_number']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resume' => 'resume',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    185431326 => '185431326',
  );
  $handler->display->display_options['path'] = 'admin/drop-jobs/export/candidate_phone';
  $export['drop_jobs_dev_export_profile'] = $view;

  $view = new view();
  $view->name = 'drop_jobs_dev_export_user';
  $view->description = 'Views for exporting demo users for Migrate.';
  $view->tag = 'drop_jobs_dev';
  $view->base_table = 'users';
  $view->human_name = 'Drop Jobs Dev Export User';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer drop_jobs';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['label'] = 'role';
  $handler->display->display_options['fields']['rid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rid']['separator'] = ',';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = '!=';
  $handler->display->display_options['filters']['name']['value'] = 'admin';

  /* Display: Users */
  $handler = $view->new_display('views_data_export', 'Users', 'user');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/drop-jobs/export/user';
  $export['drop_jobs_dev_export_user'] = $view;

  return $export;
}
