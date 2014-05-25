<?php
/**
 * @file
 * Drop Jobs Organization pages.
 */

/**
 * Page callback.
 *
 * Dislays organization dashboard.
 *
 * @see drop_jobs_organization_menu()
 * @see drop_jobs_core_menu_table()
 */
function drop_jobs_organization_dashboard() {
  $cols_per_row = variable_get_value('drop_jobs_dashboard_user_cols');

  $classes = array(
    'dashboard/organization/page' => 'organization',
  );

  $exclude = array(
    'dashboard/organization',
    'user/logout',
  );

  return drop_jobs_core_menu_table('menu-drop-jobs-dashboard', $cols_per_row, NULL, $classes, $exclude, TRUE);
}

/**
 * Form callback.
 *
 * Displays organization dashboard settings form.
 *
 * @see drop_jobs_organization_menu()
 */
function drop_jobs_organization_preferences($form, $form_state) {
  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Global Preferences'),
    '#collapsible' => FALSE,
  );

  return $form;
}

/**
 * Page callback.
 *
 * Displays organization profile in dashboard context.
 *
 * @see drop_jobs_organization_menu()
 */
function drop_jobs_organization_profile() {
  $account = user_uid_optional_load();

  if ($node = drop_jobs_organization_find_by_user($account->uid)) {
    drupal_set_title('My organization');
    return node_view($node);
  }

  return drupal_not_found();
}

/**
 * Page callback.
 *
 * Redirects a organization to his edit profile form.
 *
 * @see drop_jobs_organization_menu()
 */
function drop_jobs_organization_profile_edit() {
  $account = user_uid_optional_load();

  if ($node = drop_jobs_organization_find_by_user($account->uid)) {
    drupal_goto("node/{$node->nid}/edit");
  }
}
