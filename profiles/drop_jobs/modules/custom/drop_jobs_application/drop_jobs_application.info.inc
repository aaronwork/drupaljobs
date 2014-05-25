<?php
/**
 * @file
 * Drop Jobs Application Entity metadata integration.
 */

/**
 * Extend the defaults.
 */
class DropJobsApplicationMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['type'] = array(
      'type' => 'drop_jobs_application_type',
      'setter permission' => 'administer drop_jobs applications',
      'required' => TRUE,
      'description' => t('The application type.'),
    ) + $properties['type'];

    // Replace uid property with our candidate property.
    unset($properties['uid']);
    $properties['candidate'] = array(
      'label' => t("Candidate"),
      'type' => 'user',
      'description' => t("The unique ID of the candidate user."),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer drop_jobs applications',
      'required' => TRUE,
      'schema field' => 'uid',
    );

    // Replace nid property with out job property.
    unset($properties['nid']);
    $properties['job'] = array(
      'label' => t("Job"),
      'type' => 'node',
      'description' => t("The unique ID of the job node."),
      'schema field' => 'nid',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer drop_jobs applications',
      'required' => TRUE,
    );

    // Override created property info.
    $properties['created']['type'] = 'date';
    $properties['created']['description'] = t("The date the application was posted.");
    $properties['created']['setter permission'] = 'administer drop_jobs applications';

    // Override changed property info.
    $properties['changed']['type'] = 'date';
    $properties['changed']['description'] = t("The date the application was most recently updated.");

    // Override status property info.
    $properties['status']['description'] = t("The application's status.");
    $properties['status']['options list'] = 'drop_jobs_application_status_options_list';
    $properties['status']['access callback'] = 'administer drop_jobs applications';
    $properties['status']['setter callback'] = 'entity_property_verbatim_set';

    return $info;
  }
}
