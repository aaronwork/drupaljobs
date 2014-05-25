<?php
/**
 * @file
 * Definition of views_handler_drop_jobs_area_back.
 */

/**
 * Views area handler to display a simple "back to top" link.
 *
 * @ingroup views_area_handlers
 */
class views_handler_drop_jobs_area_back extends views_handler_area {

  function render() {
    if ($this->view->total_rows == 0 && !$this->options['empty']) {
      return;
    } else if ($this->view->total_rows > 10) {
      return '<a href="#" class="action-top" title="' . t('Back to Top') . '">' . t('Back to Top') . '</a>';
    }
  }

}
