<?php
/**
 * @file
 * Definition of drop_jobs_field_full_name.
 */

/**
 * A handler to provide a field with a user's full name.
 *
 * @ingroup views_field_handlers
 */
class drop_jobs_field_full_name extends views_handler_field {

  public function query() {
    // Don' do anything.
  }

  public function render($values) {
    if (isset($values->pid)) {
      if ($profile = profile2_load($values->pid)) {
        if ($profile_wrapper = entity_metadata_wrapper('profile2', $profile)) {
          if ($profile->type === 'resume') {
            if ($field_collection = $profile_wrapper->field_resume_personal->value()) {
              if ($fc_wrapper = entity_metadata_wrapper('field_collection_item', $field_collection)) {
                $first_name = $fc_wrapper->field_resume_first_name->value();
                $last_name = $fc_wrapper->field_resume_last_name->value();
              }
            }
          }
          else {
            $first_name = $profile_wrapper->field_recruiter_first_name->value();
            $last_name = $profile_wrapper->field_recruiter_last_name->value();
          }

          if (!empty($first_name) && !empty($last_name)) {
            return "{$first_name} {$last_name}";
          }
        }
      }
    }

    // Fallback to an empty string.
    return '';
  }

}
