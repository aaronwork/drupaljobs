<?php
/**
 * @file
 * Drop Jobs Recommendation metadata controller class.
 */

class DropJobsRecommendationMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    // Replace nid property with an entity relationship.
    $properties['nid'] = array(
      'label' => t('Job'),
      'type' => 'node',
      'description' => t('The unique ID of the job.'),
      'required' => TRUE,
      'schema field' => 'nid',
    );

    // Replace uid property with an entity relationship.
    $properties['uid'] = array(
      'label' => t('User'),
      'type' => 'user',
      'description' => t('The unique ID of the user.'),
      'required' => TRUE,
      'schema field' => 'uid',
    );

    // Complement created property info.
    $properties['created']['type'] = 'date';
    $properties['created']['description'] = t('The date the recommendation was made.');
    $properties['created']['setter permission'] = 'administer drop_jobs recommendations';

    return $info;
  }
}