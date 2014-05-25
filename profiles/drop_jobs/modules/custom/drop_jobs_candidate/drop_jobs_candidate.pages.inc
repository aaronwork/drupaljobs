<?php
/**
 * @file
 * Drop Jobs Candidate pages.
 */

/**
 * Page callback.
 *
 * Dislays candidate dashboard.
 *
 * @see drop_jobs_candidate_menu()
 * @see drop_jobs_core_menu_table()
 */
function drop_jobs_candidate_dashboard() {
  $cols_per_row = variable_get_value('drop_jobs_dashboard_user_cols');

  $classes = array(
    'dashboard/candidate/resume' => 'resume',
  );

  $exclude = array(
    'dashboard/candidate',
    'user/logout',
  );

  return drop_jobs_core_menu_table('menu-drop-jobs-dashboard', $cols_per_row, NULL, $classes, $exclude, TRUE);
}

/**
 * Form callback.
 *
 * Displays candidate dashboard settings form.
 *
 * @see drop_jobs_candidate_menu()
 */
function drop_jobs_candidate_preferences($form, $form_state) {
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
 * Displays candidate profile in dashboard context.
 *
 * @see drop_jobs_candidate_menu()
 */
function drop_jobs_candidate_profile() {
  $account = user_uid_optional_load();

  if ($profile = reset(profile2_load_by_user($account->uid))) {
    if ($profile->type === 'resume') {
      drupal_set_title('My résumé');
      return profile2_view($profile);
    }
  }

  return drupal_not_found();
}

/**
 * Page callback.
 *
 * Redirects a candidate to his edit profile form.
 *
 * @see drop_jobs_candidate_menu()
 */
function drop_jobs_candidate_profile_edit() {
  $account = user_uid_optional_load();

  if ($profile = reset(profile2_load_by_user($account->uid))) {
    if ($profile->type === 'resume') {
      drupal_goto("resume/{$account->uid}/edit");
    }
  }
}
