<?php
/**
 * @file
 * drop_jobs_report.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function drop_jobs_report_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'drop_jobs_report_candidate';
  $view->description = 'Displays reports for candidates.';
  $view->tag = 'drop_jobs_report, drop_jobs_report_candidate';
  $view->base_table = 'profile';
  $view->human_name = 'Drop Jobs Report Candidate';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view drop_jobs reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['title'] = 'Registrations during the past 12 months.';
  $handler->display->display_options['style_options']['exclude_title'] = 1;
  $handler->display->display_options['style_options']['fields'] = array(
    'created_1' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
    'created' => array(
      'enabled' => 1,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => '',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'created_1',
    'invert' => 0,
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resume' => 'resume',
  );

  /* Display: Registrations */
  $handler = $view->new_display('block', 'Registrations', 'candidate_registration');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Candidate registrations';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Date created */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'profile';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = '';
  $handler->display->display_options['fields']['created_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_1']['custom_date_format'] = 'm/Y';
  /* Field: COUNT(Profile: Date created) */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'profile';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['group_type'] = 'count';
  $handler->display->display_options['fields']['created']['label'] = 'Count';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Profile: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'profile';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['block_description'] = 'Report: Candidate registrations';

  /* Display: Total */
  $handler = $view->new_display('block', 'Total', 'candidate_total');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Total number of registered candidates';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Profile: Profile ID) */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['group_type'] = 'count';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['pid']['format_plural'] = TRUE;
  $handler->display->display_options['fields']['pid']['format_plural_singular'] = '1 candidate';
  $handler->display->display_options['fields']['pid']['format_plural_plural'] = '@count candidates';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['block_description'] = 'Report: Candidate total';

  /* Display: States */
  $handler = $view->new_display('block', 'States', 'candidate_states');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Candidate résumé workflow states';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['title'] = 'Résumé states';
  $handler->display->display_options['style_options']['exclude_title'] = 1;
  $handler->display->display_options['style_options']['type'] = 'pie';
  $handler->display->display_options['style_options']['fields'] = array(
    'pid' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
    'field_resume_workflow' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => '',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_resume_workflow',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Profile: Profile ID) */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['group_type'] = 'count';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Profile: Workflow State */
  $handler->display->display_options['fields']['field_resume_workflow']['id'] = 'field_resume_workflow';
  $handler->display->display_options['fields']['field_resume_workflow']['table'] = 'field_data_field_resume_workflow';
  $handler->display->display_options['fields']['field_resume_workflow']['field'] = 'field_resume_workflow';
  $handler->display->display_options['fields']['field_resume_workflow']['label'] = '';
  $handler->display->display_options['fields']['field_resume_workflow']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Report: Résumé workflow states';
  $export['drop_jobs_report_candidate'] = $view;

  $view = new view();
  $view->name = 'drop_jobs_report_job';
  $view->description = 'Displays reports for jobs.';
  $view->tag = 'drop_jobs_report, drop_jobs_job';
  $view->base_table = 'node';
  $view->human_name = 'Drop Jobs Report Job';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view drop_jobs reports';
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
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job' => 'job',
  );

  /* Display: Postings */
  $handler = $view->new_display('block', 'Postings', 'job_postings');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Job postings';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['title'] = 'Job postings in the last 12 months';
  $handler->display->display_options['style_options']['exclude_title'] = 1;
  $handler->display->display_options['style_options']['fields'] = array(
    'created' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
    'nid' => array(
      'enabled' => 1,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => '',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'created',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/Y';
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Count';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Report: Job postings';

  /* Display: Total */
  $handler = $view->new_display('block', 'Total', 'job_total');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Total number of postedjobs';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['format_plural'] = TRUE;
  $handler->display->display_options['fields']['nid']['format_plural_singular'] = '1 job';
  $handler->display->display_options['fields']['nid']['format_plural_plural'] = '@count jobs';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['block_description'] = 'Report: Job total';

  /* Display: States */
  $handler = $view->new_display('block', 'States', 'job_states');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Job workflow states';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['title'] = 'Job workflow states';
  $handler->display->display_options['style_options']['exclude_title'] = 1;
  $handler->display->display_options['style_options']['type'] = 'pie';
  $handler->display->display_options['style_options']['fields'] = array(
    'nid' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
    'field_job_workflow' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => '',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_job_workflow',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Workflow State */
  $handler->display->display_options['fields']['field_job_workflow']['id'] = 'field_job_workflow';
  $handler->display->display_options['fields']['field_job_workflow']['table'] = 'field_data_field_job_workflow';
  $handler->display->display_options['fields']['field_job_workflow']['field'] = 'field_job_workflow';
  $handler->display->display_options['fields']['field_job_workflow']['label'] = '';
  $handler->display->display_options['fields']['field_job_workflow']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['block_description'] = 'Report: Job workflow states';
  $export['drop_jobs_report_job'] = $view;

  $view = new view();
  $view->name = 'drop_jobs_report_recruiter';
  $view->description = 'Displays reports for recruiters.';
  $view->tag = 'drop_jobs_report, drop_jobs_report_recruiter';
  $view->base_table = 'profile';
  $view->human_name = 'Drop Jobs Report Recruiter';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view drop_jobs reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['title'] = 'Registrations during the past 12 months.';
  $handler->display->display_options['style_options']['exclude_title'] = 1;
  $handler->display->display_options['style_options']['fields'] = array(
    'created_1' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
    'created' => array(
      'enabled' => 1,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => '',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'created_1',
    'invert' => 0,
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recruiter' => 'recruiter',
  );

  /* Display: Registrations */
  $handler = $view->new_display('block', 'Registrations', 'recruiter_registration');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recruiter registrations';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Date created */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'profile';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = '';
  $handler->display->display_options['fields']['created_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_1']['custom_date_format'] = 'm/Y';
  /* Field: COUNT(Profile: Date created) */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'profile';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['group_type'] = 'count';
  $handler->display->display_options['fields']['created']['label'] = 'Count';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Profile: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'profile';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['block_description'] = 'Report: Recruiter registrations';

  /* Display: Total */
  $handler = $view->new_display('block', 'Total', 'recruiter_total');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Total number of registered recruiters';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Profile: Profile ID) */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['group_type'] = 'count';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['pid']['format_plural'] = TRUE;
  $handler->display->display_options['fields']['pid']['format_plural_singular'] = '1 recruiter';
  $handler->display->display_options['fields']['pid']['format_plural_plural'] = '@count recruiters';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['block_description'] = 'Report: Recruiter total';
  $export['drop_jobs_report_recruiter'] = $view;

  return $export;
}
