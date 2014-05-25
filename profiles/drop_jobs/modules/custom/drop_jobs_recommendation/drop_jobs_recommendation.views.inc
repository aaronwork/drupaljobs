<?php
/**
 * @file
 * Drop Jobs Recommendation views integration.
 */

class DropJobsRecommendationViewsController extends EntityDefaultViewsController {

  /**
   * Add extra fields to views_data().
   */
  public function views_data() {
    $data = parent::views_data();

    // Add a field to view the recommendation.
    $data['drop_jobs_recommendation']['view'] = array(
      'field' => array(
        'title' => t('Link'),
        'help' => t('Provide a simple link to view the recommendation.'),
        'handler' => 'views_handler_field_recommendation_view',
      ),
    );

    // Add a field to edit the recommendation.
    $data['drop_jobs_recommendation']['edit'] = array(
      'field' => array(
        'title' => t('Edit link'),
        'help' => t('Provide a simple link to edit the recommendation.'),
        'handler' => 'views_handler_field_recommendation_edit',
      ),
    );

    // Add a field to delete the recommendation.
    $data['drop_jobs_recommendation']['delete'] = array(
      'field' => array(
        'title' => t('Delete link'),
        'help' => t('Provide a simple link to delete the recommendation.'),
        'handler' => 'views_handler_field_recommendation_delete',
      ),
    );

    // Add a field for recommendation operations.
    $data['drop_jobs_recommendation']['operations'] = array(
      'field' => array(
        'title' => t('Operations'),
        'help' => t('Provide simple links to recommendation operations (view/edit/delete).'),
        'handler' => 'views_handler_field_recommendation_operations',
      ),
    );

    return $data;
  }

}