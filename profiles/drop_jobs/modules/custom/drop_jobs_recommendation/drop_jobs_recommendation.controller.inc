<?php
/**
 * @file
 * Drop Jobs Recommendation entity controllers.
 */

/**
 * Job Recommendation entity controller class.
 */
class DropJobsRecommendationController extends EntityAPIController {

  /**
   * Add properties as pseudo-fields.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    // Make user themed like a default field.
    $user = user_load($entity->uid);
    $content['uid'] = array(
      '#theme' => 'field',
      '#title' => t('User'),
      '#access' => TRUE,
      '#label_display' => 'inline',
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#entity_type' => 'drop_jobs_recommendation',
      '#bundle' => 'drop_jobs_recommendation',
      '#items' => array(array('value' => $entity->uid)),
      '#formatter' => 'text_default',
      0 => array('#markup' => l($user->name, 'user/' . $entity->uid)),
    );

    // Make job themed like a default field.
    $node = node_load($entity->nid);
    $content['nid'] = array(
      '#theme' => 'field',
      '#title' => t('Job'),
      '#access' => TRUE,
      '#label_display' => 'inline',
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#entity_type' => 'drop_jobs_recommendation',
      '#bundle' => 'drop_jobs_recommendation',
      '#items' => array(array('value' => $entity->nid)),
      '#formatter' => 'text_default',
      0 => array('#markup' => l($node->title, 'node/' . $entity->nid)),
    );

    // Make created themed like a default field.
    $content['created'] = array(
      '#theme' => 'field',
      '#title' => t('Created'),
      '#access' => TRUE,
      '#label_display' => 'inline',
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#entity_type' => 'drop_jobs_recommendation',
      '#bundle' => 'drop_jobs_recommendation',
      '#items' => array(array('value' => $entity->created)),
      '#formatter' => 'text_default',
      0 => array('#markup' => format_date($entity->created, 'medium')),
    );

    // Add action buttons.
    $actions = array();


    // Apply to Job.
    if (module_exists('drop_jobs_application') && user_access('create drop_jobs applications')) {
      $actions['apply'] = array(
        'title' => t('Apply to Job'),
        'href' => "node/{$entity->nid}/apply",
        'attributes' => array('class' => array('action-apply')),
      );
    }

    // View Job.
    $actions['view'] = array(
      'title' => t('View Job Details'),
      'href' => "node/{$entity->nid}",
      'attributes' => array('class' => array('action-view')),
    );

    // Delete Recommendation.
    if (drop_jobs_recommendation_access('delete', $entity)) {
      $actions['delete'] = array(
      'title' => t('Delete Recommendation'),
      'href' => "node/{$entity->nid}/delete",
      'attributes' => array('class' => array('action-delete')),
      );
    }

    $content['action-links'] = array(
      '#theme' => 'links',
      '#links' => $actions,
    );

    return parent::buildContent($entity, $view_mode, $langcode, $content);
  }

}