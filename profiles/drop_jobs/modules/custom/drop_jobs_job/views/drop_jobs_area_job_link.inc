<?php
/**
 * @file
 * Definition of views_handler_drop_jobs_area_job_link.
 */

/**
 * Views area handler to display a simple "add job" link.
 *
 * @ingroup views_area_handlers
 */
class views_handler_drop_jobs_area_job_link extends views_handler_area {

  function render() {
    if ($this->view->total_rows == 0 && !$this->options['empty']) {
      return;
    }

    $options = array(
      'query' => drupal_get_destination(),
      'attributes' => array('class' => array('action-add')),
    );
    return l(t('Add job'), 'node/add/job', $options);
  }

}
