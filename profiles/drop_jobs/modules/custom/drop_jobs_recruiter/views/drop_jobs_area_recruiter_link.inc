<?php
/**
 * @file
 * Definition of views_handler_drop_jobs_area_recruiter_link.
 */

/**
 * Views area handler to display a simple "add recruiter" link.
 *
 * @ingroup views_area_handlers
 */
class views_handler_drop_jobs_area_recruiter_link extends views_handler_area {

  function render() {
    if ($this->view->total_rows == 0 && !$this->options['empty']) {
      return;
    }
    else if (user_access('administer drop_jobs recruiters')) {
      $options = array(
        'query' => drupal_get_destination(),
        'attributes' => array('class' => array('action-add')),
      );
      return l(t('Add recruiter'), 'admin/people/create', $options);
    }
  }

}
