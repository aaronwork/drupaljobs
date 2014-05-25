<?php
/**
 * @file
 * drop_jobs_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function drop_jobs_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'drop_jobs_search_jobs';
  $view->description = 'Job search pages.';
  $view->tag = 'drop_jobs_search';
  $view->base_table = 'search_api_index_job_index';
  $view->human_name = 'Drop Jobs Search Jobs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Job Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'use drop_jobs job search';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'There are no jobs matching the selected filters at the moment.';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_job_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Indexed Node: Sticky in lists */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'search_api_index_job_index';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Indexed Node: Promoted to frontpage */
  $handler->display->display_options['sorts']['promote']['id'] = 'promote';
  $handler->display->display_options['sorts']['promote']['table'] = 'search_api_index_job_index';
  $handler->display->display_options['sorts']['promote']['field'] = 'promote';
  $handler->display->display_options['sorts']['promote']['order'] = 'DESC';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_job_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Sort criterion: Indexed Node: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_job_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_job_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_job_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job' => 'job',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Node: Workflow State */
  $handler->display->display_options['filters']['field_job_workflow']['id'] = 'field_job_workflow';
  $handler->display->display_options['filters']['field_job_workflow']['table'] = 'search_api_index_job_index';
  $handler->display->display_options['filters']['field_job_workflow']['field'] = 'field_job_workflow';
  $handler->display->display_options['filters']['field_job_workflow']['value'] = array(
    'visible' => 'visible',
  );
  $handler->display->display_options['filters']['field_job_workflow']['group'] = 1;
  /* Filter criterion: Indexed Node: Entity HTML output */
  $handler->display->display_options['filters']['search_api_viewed']['id'] = 'search_api_viewed';
  $handler->display->display_options['filters']['search_api_viewed']['table'] = 'search_api_index_job_index';
  $handler->display->display_options['filters']['search_api_viewed']['field'] = 'search_api_viewed';
  $handler->display->display_options['filters']['search_api_viewed']['group'] = 1;
  $handler->display->display_options['filters']['search_api_viewed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_viewed']['expose']['operator_id'] = 'search_api_viewed_op';
  $handler->display->display_options['filters']['search_api_viewed']['expose']['label'] = 'What?';
  $handler->display->display_options['filters']['search_api_viewed']['expose']['operator'] = 'search_api_viewed_op';
  $handler->display->display_options['filters']['search_api_viewed']['expose']['identifier'] = 'search_api_viewed';
  $handler->display->display_options['filters']['search_api_viewed']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Indexed Node: Job Location */
  $handler->display->display_options['filters']['search_api_aggregation_1']['id'] = 'search_api_aggregation_1';
  $handler->display->display_options['filters']['search_api_aggregation_1']['table'] = 'search_api_index_job_index';
  $handler->display->display_options['filters']['search_api_aggregation_1']['field'] = 'search_api_aggregation_1';
  $handler->display->display_options['filters']['search_api_aggregation_1']['group'] = 1;
  $handler->display->display_options['filters']['search_api_aggregation_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['operator_id'] = 'search_api_aggregation_1_op';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['label'] = 'Where?';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['operator'] = 'search_api_aggregation_1_op';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['identifier'] = 'search_api_aggregation_1';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'search/jobs';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Job Search';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['drop_jobs_search_jobs'] = $view;

  $view = new view();
  $view->name = 'drop_jobs_search_resume';
  $view->description = 'Resume search pages.';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_resume_index';
  $view->human_name = 'Drop Jobs Search Resume';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Résumé search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'use drop_jobs resume search';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'There are no résumés matching the selected filters at the moment.';
  /* Field: Indexed Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'search_api_index_resume_index';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  /* Sort criterion: Indexed Profile: Sticky */
  $handler->display->display_options['sorts']['field_resume_sticky']['id'] = 'field_resume_sticky';
  $handler->display->display_options['sorts']['field_resume_sticky']['table'] = 'search_api_index_resume_index';
  $handler->display->display_options['sorts']['field_resume_sticky']['field'] = 'field_resume_sticky';
  $handler->display->display_options['sorts']['field_resume_sticky']['order'] = 'DESC';
  /* Sort criterion: Indexed Profile: Promoted */
  $handler->display->display_options['sorts']['field_resume_promoted']['id'] = 'field_resume_promoted';
  $handler->display->display_options['sorts']['field_resume_promoted']['table'] = 'search_api_index_resume_index';
  $handler->display->display_options['sorts']['field_resume_promoted']['field'] = 'field_resume_promoted';
  $handler->display->display_options['sorts']['field_resume_promoted']['order'] = 'DESC';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_resume_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Sort criterion: Indexed Profile: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_resume_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Indexed Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_resume_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resume' => 'resume',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Profile: Workflow State */
  $handler->display->display_options['filters']['field_resume_workflow']['id'] = 'field_resume_workflow';
  $handler->display->display_options['filters']['field_resume_workflow']['table'] = 'search_api_index_resume_index';
  $handler->display->display_options['filters']['field_resume_workflow']['field'] = 'field_resume_workflow';
  $handler->display->display_options['filters']['field_resume_workflow']['value'] = array(
    'visible' => 'visible',
  );
  $handler->display->display_options['filters']['field_resume_workflow']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_resume_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'What?';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'search/resume';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Résumé Search';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['drop_jobs_search_resume'] = $view;

  return $export;
}
