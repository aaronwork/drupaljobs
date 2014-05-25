<?php
/**
 * @file
 * Drop Jobs Application entity controller.
 */

/**
 * Drop Jobs Application Controller.
 */
class DropJobsApplicationController extends EntityAPIController {

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $return = parent::save($entity, $transaction);
    _drop_jobs_application_update_statistics($entity->nid);
    return $return;
  }

  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    $return = parent::delete($ids, $transaction);

    $entities = $this->load($ids);
    $ids = array_keys($entities);
    _drop_jobs_application_update_statistics($ids);

    return $return;
  }

  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    // Make type themed like a default field.
    $content['type'] = array(
      '#theme' => 'field',
      '#title' => t('Application Type'),
      '#access' => TRUE,
      '#label_display' => 'inline',
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#entity_type' => 'drop_jobs_application',
      '#bundle' => 'drop_jobs_application',
      '#items' => array(array('value' => $entity->type)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $entity->type),
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
      '#entity_type' => 'drop_jobs_application',
      '#bundle' => 'drop_jobs_application',
      '#items' => array(array('value' => $entity->created)),
      '#formatter' => 'text_default',
      0 => array('#markup' => format_date($entity->created, 'medium')),
    );

    // Make user themed like a default field.
    $user = user_load($entity->uid);
    $content['uid'] = array(
      '#theme' => 'field',
      '#title' => t('Candidate'),
      '#access' => TRUE,
      '#label_display' => 'inline',
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#entity_type' => 'drop_jobs_application',
      '#bundle' => 'drop_jobs_application',
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
      '#entity_type' => 'drop_jobs_application',
      '#bundle' => 'drop_jobs_application',
      '#items' => array(array('value' => $entity->nid)),
      '#formatter' => 'text_default',
      0 => array('#markup' => l($node->title, 'node/' . $entity->nid)),
    );

    // Make status themed like a default field.
    $status_options = drop_jobs_application_status_options_list();
    $status = $status_options[$entity->status];
    $content['status'] = array(
      '#theme' => 'field',
      '#title' => t('Status'),
      '#access' => TRUE,
      '#label_display' => 'inline',
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#entity_type' => 'drop_jobs_application',
      '#bundle' => 'drop_jobs_application',
      '#items' => array(array('value' => $entity->status)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $status),
    );

    return parent::buildContent($entity, $view_mode, $langcode, $content);
  }

}