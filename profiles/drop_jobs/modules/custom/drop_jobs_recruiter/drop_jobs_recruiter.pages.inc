<?php
/**
 * @file
 * Drop Jobs Recruiter pages.
 */

/**
 * Page callback.
 *
 * Dislays recruiter dashboard.
 *
 * @see drop_jobs_recruiter_menu()
 * @see drop_jobs_core_menu_table()
 */
function drop_jobs_recruiter_dashboard() {
  $cols_per_row = variable_get_value('drop_jobs_dashboard_user_cols');

  $classes = array(
    'dashboard/recruiter/profile' => 'recruiter',
  );

  $exclude = array(
    'dashboard/recruiter',
    'user/logout',
  );

  return drop_jobs_core_menu_table('menu-drop-jobs-dashboard', $cols_per_row, NULL, $classes, $exclude, TRUE);
}

/**
 * Form callback.
 *
 * Displays recruiter dashboard settings form.
 *
 * @see drop_jobs_recruiter_menu()
 */
function drop_jobs_recruiter_preferences($form, $form_state) {
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
 * Displays recruiter profile in dashboard context.
 *
 * @see drop_jobs_recruiter_menu()
 */
function drop_jobs_recruiter_profile() {
  $account = user_uid_optional_load();

  if ($profile = reset(profile2_load_by_user($account->uid))) {
    if ($profile->type === 'recruiter') {
      drupal_set_title('My recruiter profile');
      return profile2_view($profile);
    }
  }

  return drupal_not_found();
}

/**
 * Page callback.
 *
 * Redirects a recruiter to his edit profile form.
 *
 * @see drop_jobs_recruiter_menu()
 */
function drop_jobs_recruiter_profile_edit() {
  $account = user_uid_optional_load();

  if ($profile = reset(profile2_load_by_user($account->uid))) {
    if ($profile->type === 'recruiter') {
      drupal_goto("recruiter/{$account->uid}/edit");
    }
  }
}
