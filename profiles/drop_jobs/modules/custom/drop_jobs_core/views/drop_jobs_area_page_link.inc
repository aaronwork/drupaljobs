<?php
/**
 * @file
 * Definition of views_handler_drop_jobs_area_page_link.
 */

/**
 * Views area handler to display a simple "add page" link.
 *
 * @ingroup views_area_handlers
 */
class views_handler_drop_jobs_area_page_link extends views_handler_area {

  function render() {
    if ($this->view->total_rows == 0 && !$this->options['empty']) {
      return;
    }
    else if (user_access('create page content')) {
      $options = array(
        'query' => drupal_get_destination(),
        'attributes' => array('class' => array('action-add')),
      );
      return l(t('Add page'), 'node/add/page', $options);
    }
  }

}
