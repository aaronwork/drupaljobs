<?php
/**
 * @file
 * drop_jobs_candidate.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function drop_jobs_candidate_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'drop_jobs_candidate';
  $view->description = 'Resume blocks';
  $view->tag = 'drop_jobs_candidate';
  $view->base_table = 'profile';
  $view->human_name = 'Drop Jobs Candidate';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'New Resumes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_resume_first_name' => 'field_resume_first_name',
    'field_resume_pref_title' => 'field_resume_pref_title',
  );
  $handler->display->display_options['row_options']['separator'] = '-';
  /* Relationship: Profile: Job Preferences (field_resume_preferences) */
  $handler->display->display_options['relationships']['field_resume_preferences_value']['id'] = 'field_resume_preferences_value';
  $handler->display->display_options['relationships']['field_resume_preferences_value']['table'] = 'field_data_field_resume_preferences';
  $handler->display->display_options['relationships']['field_resume_preferences_value']['field'] = 'field_resume_preferences_value';
  $handler->display->display_options['relationships']['field_resume_preferences_value']['label'] = 'Job Preferences';
  $handler->display->display_options['relationships']['field_resume_preferences_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_resume_preferences_value']['delta'] = '-1';
  /* Relationship: Profile: Personal Information (field_resume_personal) */
  $handler->display->display_options['relationships']['field_resume_personal_value']['id'] = 'field_resume_personal_value';
  $handler->display->display_options['relationships']['field_resume_personal_value']['table'] = 'field_data_field_resume_personal';
  $handler->display->display_options['relationships']['field_resume_personal_value']['field'] = 'field_resume_personal_value';
  $handler->display->display_options['relationships']['field_resume_personal_value']['label'] = 'Personal Information';
  $handler->display->display_options['relationships']['field_resume_personal_value']['delta'] = '-1';
  /* Field: Profile: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_profile2';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Field collection item: Desired Job Title */
  $handler->display->display_options['fields']['field_resume_pref_title']['id'] = 'field_resume_pref_title';
  $handler->display->display_options['fields']['field_resume_pref_title']['table'] = 'field_data_field_resume_pref_title';
  $handler->display->display_options['fields']['field_resume_pref_title']['field'] = 'field_resume_pref_title';
  $handler->display->display_options['fields']['field_resume_pref_title']['relationship'] = 'field_resume_preferences_value';
  $handler->display->display_options['fields']['field_resume_pref_title']['label'] = '';
  $handler->display->display_options['fields']['field_resume_pref_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_resume_pref_title']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['field_resume_pref_title']['element_label_colon'] = FALSE;
  /* Sort criterion: Profile: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'profile';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'day';
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resume' => 'resume',
  );
  /* Filter criterion: Profile: Workflow State (field_resume_workflow) */
  $handler->display->display_options['filters']['field_resume_workflow_value']['id'] = 'field_resume_workflow_value';
  $handler->display->display_options['filters']['field_resume_workflow_value']['table'] = 'field_data_field_resume_workflow';
  $handler->display->display_options['filters']['field_resume_workflow_value']['field'] = 'field_resume_workflow_value';
  $handler->display->display_options['filters']['field_resume_workflow_value']['value'] = array(
    'visible' => 'visible',
  );

  /* Display: New Resumes block */
  $handler = $view->new_display('block', 'New Resumes block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['block_description'] = 'New Resumes';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'field_resume_pref_title';
  $handler->display->display_options['row_options']['link_field'] = 'url';
  $handler->display->display_options['row_options']['description_field'] = 'field_resume_notes';
  $handler->display->display_options['row_options']['creator_field'] = 'variable';
  $handler->display->display_options['row_options']['date_field'] = 'created';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'url_1',
    'guid_field_is_permalink' => 1,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_profile2';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Field collection item: Desired Job Title */
  $handler->display->display_options['fields']['field_resume_pref_title']['id'] = 'field_resume_pref_title';
  $handler->display->display_options['fields']['field_resume_pref_title']['table'] = 'field_data_field_resume_pref_title';
  $handler->display->display_options['fields']['field_resume_pref_title']['field'] = 'field_resume_pref_title';
  $handler->display->display_options['fields']['field_resume_pref_title']['relationship'] = 'field_resume_preferences_value';
  $handler->display->display_options['fields']['field_resume_pref_title']['label'] = '';
  $handler->display->display_options['fields']['field_resume_pref_title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Summary */
  $handler->display->display_options['fields']['field_resume_notes']['id'] = 'field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['table'] = 'field_data_field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['field'] = 'field_resume_notes';
  $handler->display->display_options['fields']['field_resume_notes']['relationship'] = 'field_resume_preferences_value';
  $handler->display->display_options['fields']['field_resume_notes']['label'] = '';
  $handler->display->display_options['fields']['field_resume_notes']['element_label_colon'] = FALSE;
  /* Field: Profile: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'profile';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s O';
  /* Field: Profile: URL */
  $handler->display->display_options['fields']['url_1']['id'] = 'url_1';
  $handler->display->display_options['fields']['url_1']['table'] = 'views_entity_profile2';
  $handler->display->display_options['fields']['url_1']['field'] = 'url';
  $handler->display->display_options['fields']['url_1']['label'] = '';
  $handler->display->display_options['fields']['url_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url_1']['alter']['path'] = '[url_1]';
  $handler->display->display_options['fields']['url_1']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['url_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url_1']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url_1']['link_to_entity'] = 0;
  /* Field: Global: Variable */
  $handler->display->display_options['fields']['variable']['id'] = 'variable';
  $handler->display->display_options['fields']['variable']['table'] = 'views';
  $handler->display->display_options['fields']['variable']['field'] = 'variable';
  $handler->display->display_options['fields']['variable']['label'] = '';
  $handler->display->display_options['fields']['variable']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['variable']['variable_name'] = 'site_name';
  $handler->display->display_options['fields']['variable']['variable_default'] = 'Drop Jobs';
  $handler->display->display_options['path'] = 'resumes.xml';
  $export['drop_jobs_candidate'] = $view;

  $view = new view();
  $view->name = 'drop_jobs_candidate_admin';
  $view->description = 'Administration page for Candidates';
  $view->tag = 'drop_jobs_admin, drop_jobs_candidate';
  $view->base_table = 'profile';
  $view->human_name = 'Drop Jobs Candidate Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Candidates';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer drop_jobs candidates';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'full_name' => 'full_name',
    'mail' => 'mail',
    'changed' => 'changed',
    'field_resume_workflow' => 'field_resume_workflow',
    'field_resume_promoted' => 'field_resume_promoted',
    'field_resume_sticky' => 'field_resume_sticky',
    'status' => 'status',
    'view_user' => 'view_user',
    'edit_node' => 'edit_node',
    'cancel_node' => 'cancel_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'full_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_resume_workflow' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_resume_promoted' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_resume_sticky' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_user' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'cancel_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Add Candidate Link */
  $handler->display->display_options['header']['dj_add_candidate']['id'] = 'dj_add_candidate';
  $handler->display->display_options['header']['dj_add_candidate']['table'] = 'views';
  $handler->display->display_options['header']['dj_add_candidate']['field'] = 'dj_add_candidate';
  $handler->display->display_options['header']['dj_add_candidate']['empty'] = TRUE;
  /* Footer: Global: Back to top */
  $handler->display->display_options['footer']['dj_back']['id'] = 'dj_back';
  $handler->display->display_options['footer']['dj_back']['table'] = 'views';
  $handler->display->display_options['footer']['dj_back']['field'] = 'dj_back';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There are no candidates.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['required'] = TRUE;
  /* Relationship: Profile: Personal Information (field_resume_personal) */
  $handler->display->display_options['relationships']['field_resume_personal_value']['id'] = 'field_resume_personal_value';
  $handler->display->display_options['relationships']['field_resume_personal_value']['table'] = 'field_data_field_resume_personal';
  $handler->display->display_options['relationships']['field_resume_personal_value']['field'] = 'field_resume_personal_value';
  $handler->display->display_options['relationships']['field_resume_personal_value']['delta'] = '-1';
  /* Field: Bulk operations: Profile */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'profile';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'rules_component::rules_link_set_resume_set_hidden' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_link_set_resume_set_visible' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::drop_jobs_candidate_action_set_autohidden' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::drop_jobs_candidate_action_set_hidden' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::drop_jobs_candidate_action_set_visible' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Drop Jobs: Full name */
  $handler->display->display_options['fields']['full_name']['id'] = 'full_name';
  $handler->display->display_options['fields']['full_name']['table'] = 'drop_jobs_full_name';
  $handler->display->display_options['fields']['full_name']['field'] = 'full_name';
  $handler->display->display_options['fields']['full_name']['label'] = 'Name';
  $handler->display->display_options['fields']['full_name']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'user';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Profile: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'profile';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
  /* Field: Profile: Workflow State */
  $handler->display->display_options['fields']['field_resume_workflow']['id'] = 'field_resume_workflow';
  $handler->display->display_options['fields']['field_resume_workflow']['table'] = 'field_data_field_resume_workflow';
  $handler->display->display_options['fields']['field_resume_workflow']['field'] = 'field_resume_workflow';
  $handler->display->display_options['fields']['field_resume_workflow']['element_label_colon'] = FALSE;
  /* Field: Profile: Promoted */
  $handler->display->display_options['fields']['field_resume_promoted']['id'] = 'field_resume_promoted';
  $handler->display->display_options['fields']['field_resume_promoted']['table'] = 'field_data_field_resume_promoted';
  $handler->display->display_options['fields']['field_resume_promoted']['field'] = 'field_resume_promoted';
  $handler->display->display_options['fields']['field_resume_promoted']['element_label_colon'] = FALSE;
  /* Field: Profile: Sticky */
  $handler->display->display_options['fields']['field_resume_sticky']['id'] = 'field_resume_sticky';
  $handler->display->display_options['fields']['field_resume_sticky']['table'] = 'field_data_field_resume_sticky';
  $handler->display->display_options['fields']['field_resume_sticky']['field'] = 'field_resume_sticky';
  $handler->display->display_options['fields']['field_resume_sticky']['element_label_colon'] = FALSE;
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'user';
  $handler->display->display_options['fields']['status']['label'] = 'User Status';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'active-blocked';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['relationship'] = 'user';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_user']['text'] = 'view';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'user';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: User: Cancel link */
  $handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['table'] = 'users';
  $handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['relationship'] = 'user';
  $handler->display->display_options['fields']['cancel_node']['label'] = '';
  $handler->display->display_options['fields']['cancel_node']['element_label_colon'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resume' => 'resume',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Profile: Workflow State (field_resume_workflow) */
  $handler->display->display_options['filters']['field_resume_workflow_value']['id'] = 'field_resume_workflow_value';
  $handler->display->display_options['filters']['field_resume_workflow_value']['table'] = 'field_data_field_resume_workflow';
  $handler->display->display_options['filters']['field_resume_workflow_value']['field'] = 'field_resume_workflow_value';
  $handler->display->display_options['filters']['field_resume_workflow_value']['group'] = 1;
  $handler->display->display_options['filters']['field_resume_workflow_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_resume_workflow_value']['expose']['operator_id'] = 'field_resume_workflow_value_op';
  $handler->display->display_options['filters']['field_resume_workflow_value']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['field_resume_workflow_value']['expose']['operator'] = 'field_resume_workflow_value_op';
  $handler->display->display_options['filters']['field_resume_workflow_value']['expose']['identifier'] = 'field_resume_workflow_value';
  $handler->display->display_options['filters']['field_resume_workflow_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Profile: Promoted (field_resume_promoted) */
  $handler->display->display_options['filters']['field_resume_promoted_value']['id'] = 'field_resume_promoted_value';
  $handler->display->display_options['filters']['field_resume_promoted_value']['table'] = 'field_data_field_resume_promoted';
  $handler->display->display_options['filters']['field_resume_promoted_value']['field'] = 'field_resume_promoted_value';
  $handler->display->display_options['filters']['field_resume_promoted_value']['group'] = 1;
  $handler->display->display_options['filters']['field_resume_promoted_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_resume_promoted_value']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_resume_promoted_value']['expose']['label'] = 'Promoted';
  $handler->display->display_options['filters']['field_resume_promoted_value']['expose']['operator'] = 'field_resume_promoted_value_op';
  $handler->display->display_options['filters']['field_resume_promoted_value']['expose']['identifier'] = 'field_resume_promoted_value';
  $handler->display->display_options['filters']['field_resume_promoted_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Profile: Sticky (field_resume_sticky) */
  $handler->display->display_options['filters']['field_resume_sticky_value']['id'] = 'field_resume_sticky_value';
  $handler->display->display_options['filters']['field_resume_sticky_value']['table'] = 'field_data_field_resume_sticky';
  $handler->display->display_options['filters']['field_resume_sticky_value']['field'] = 'field_resume_sticky_value';
  $handler->display->display_options['filters']['field_resume_sticky_value']['group'] = 1;
  $handler->display->display_options['filters']['field_resume_sticky_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_resume_sticky_value']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_resume_sticky_value']['expose']['label'] = 'Sticky';
  $handler->display->display_options['filters']['field_resume_sticky_value']['expose']['operator'] = 'field_resume_sticky_value_op';
  $handler->display->display_options['filters']['field_resume_sticky_value']['expose']['identifier'] = 'field_resume_sticky_value';
  $handler->display->display_options['filters']['field_resume_sticky_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'user';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'User Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['relationship'] = 'user';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    7 => 0,
  );

  /* Display: Candidates Admin Page */
  $handler = $view->new_display('page', 'Candidates Admin Page', 'page');
  $handler->display->display_options['display_description'] = 'Administration page for Candidates';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/drop-jobs/candidates';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Candidates';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $export['drop_jobs_candidate_admin'] = $view;

  $view = new view();
  $view->name = 'drop_jobs_candidate_favorite';
  $view->description = 'Displays a list of a user\'s favorite candidates.';
  $view->tag = 'drop_jobs_candidate';
  $view->base_table = 'profile';
  $view->human_name = 'My favorite candidates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My favorite candidates';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'flag favorite_resumes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'url' => 'url',
    'label' => 'label',
    'timestamp' => 'timestamp',
    'created' => 'created',
    'ops' => 'ops',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'url' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'You have no favorite candidates.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Flags: favorite_resumes */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'profile';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'favorite_resumes';
  /* Field: Profile: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_profile2';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Profile: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'profile';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = 'Title';
  $handler->display->display_options['fields']['label']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['label']['alter']['link_class'] = 'action-view';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Flags: Flagged time */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Date Favorited';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Field: Profile: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'profile';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date Registered';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Operations';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resume' => 'resume',
  );

  /* Display: Favorite Resumes page */
  $handler = $view->new_display('page', 'Favorite Resumes page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'dashboard/recruiter/favorites';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Favorite candidates';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-drop-jobs-dashboard';
  $handler->display->display_options['menu']['context'] = 0;
  $export['drop_jobs_candidate_favorite'] = $view;

  return $export;
}
