<?php

/**
 * @file
 * Drop Jobs Application views integration.
 */
class DropJobsApplicationViewsController extends EntityDefaultViewsController {

  /**
   * Add extra fields to views_data().
   */
  public function views_data() {
    $data = parent::views_data();

    // Change the group.
    $data['field']['table']['group'] = t('Job Application');

    // Add a field to view the application's label.
    $data['drop_jobs_application']['label'] = array(
      'field' => array(
        'title' => t('Label'),
        'help' => t("The application's label."),
        'handler' => 'views_handler_field_application_label',
      ),
    );

    // Add a field to view the application.
    $data['drop_jobs_application']['view'] = array(
      'field' => array(
        'title' => t('Link'),
        'help' => t('Provide a simple link to view the application.'),
        'handler' => 'views_handler_field_application_view',
      ),
    );

    // Add a field to edit the application.
    $data['drop_jobs_application']['edit'] = array(
      'field' => array(
        'title' => t('Edit link'),
        'help' => t('Provide a simple link to edit the application.'),
        'handler' => 'views_handler_field_application_edit',
      ),
    );

    // Add a field to delete the application.
    $data['drop_jobs_application']['delete'] = array(
      'field' => array(
        'title' => t('Delete link'),
        'help' => t('Provide a simple link to delete the application.'),
        'handler' => 'views_handler_field_application_delete',
      ),
    );

    // Add a field for application operations.
    $data['drop_jobs_application']['operations'] = array(
      'field' => array(
        'title' => t('Operations'),
        'help' => t('Provide simple links to application operations (view/edit/delete).'),
        'handler' => 'views_handler_field_application_operations',
      ),
    );

    // ----------------------------------------------------------------------
    // drop_jobs_application_statistics table
    // define the group
    $data['drop_jobs_application_statistics']['table']['group'] = t('Drop Jobs Application');

    // joins
    $data['drop_jobs_application_statistics']['table']['join'] = array(
      //...to the node table
      'node' => array(
        'type' => 'INNER',
        'left_field' => 'nid',
        'field' => 'nid',
      ),
    );

    // last_application_timestamp
    $data['drop_jobs_application_statistics']['last_application_timestamp'] = array(
      'title' => t('Last application time'),
      'help' => t('Date and time of when the last application was posted.'),
      'field' => array(
        'handler' => 'views_handler_field_application_timestamp',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_date',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_date',
      ),
    );

    // last_application_name (author's name)
    $data['drop_jobs_application_statistics']['last_application_name'] = array(
      'title' => t("Last application author"),
      'help' => t('The name of the author of the last posted application.'),
      'field' => array(
        'handler' => 'views_handler_field_application_name',
        'click sortable' => TRUE,
        'no group by' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_application_name',
        'no group by' => TRUE,
      ),
    );

    // application_count
    $data['drop_jobs_application_statistics']['application_count'] = array(
      'title' => t('Application count'),
      'help' => t('Number of job applications this node has received.'),
      'field' => array(
        'handler' => 'views_handler_field_application_count',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument',
      ),
    );

    // last_application_timestamp
    $data['drop_jobs_application_statistics']['last_updated'] = array(
      'title' => t('Updated/applied date'),
      'help' => t('Date and time of when the application was last updated.'),
      'field' => array(
        'handler' => 'views_handler_field_application_updated',
        'click sortable' => TRUE,
        'no group by' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_application_updated',
        'no group by' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_application_updated',
      ),
    );

    // last_application_aid
    $data['drop_jobs_application_statistics']['last_application_aid'] = array(
      'title' => t('Last application AID'),
      'help' => t('Display the last application of a node'),
      'relationship' => array(
        'title' => t('Last application'),
        'help' => t('The last application of a node.'),
        'group' => t('application'),
        'base' => 'application',
        'base field' => 'aid',
        'handler' => 'views_handler_relationship',
        'label' => t('Last application'),
      ),
    );

    // last_application_uid
    $data['drop_jobs_application_statistics']['last_application_uid'] = array(
      'title' => t('Last application uid'),
      'help' => t('The User ID of the author of the last application of a node.'),
      'relationship' => array(
        'title' => t('Last application author'),
        'base' => 'users',
        'base field' => 'uid',
        'handler' => 'views_handler_relationship',
        'label' => t('Last application author'),
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
      'field' => array(
        'handler' => 'views_handler_filter_user_name',
      ),
    );

    return $data;
  }

}