<?php
/**
 * @file
 * Drop Jobs Application Migrate destination class.
 */

/**
 * Destination class implementing migration into nodes.
 */
class MigrateDestinationDropJobsApplication extends MigrateDestinationEntity {

  var $entity_type = 'drop_jobs_application';
  var $entity_info = NULL;
  var $entity_key = NULL;

  static public function getKeySchema() {
    $key = 'aid'; // Hard coded since $this->entity_key not in object context.
    return array(
      $key => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
    );
  }

  /**
   * Basic initialization
   *
   * @param string $bundle
   *  A.k.a. the application type.
   * @param array $options
   *  Options applied to applications.
   */
  public function __construct($bundle, array $options = array()) {
    parent::__construct($this->entity_type, $bundle, $options);
    $this->entity_info = entity_get_info('drop_jobs_application');
    $this->entity_key = $this->entity_info['entity keys']['id'];
  }

  /**
   * Returns a list of fields available to be mapped for the application type (bundle)
   *
   * @return array
   *  Keys: machine names of the fields (to be passed to addFieldMapping)
   *  Values: Human-friendly descriptions of the fields.
   */
  public function fields() {
    $fields = array();
    $type = ucfirst($this->entity_type) . ': ';
    // First the core properties
    $fields[$this->entity_key] = $type . t('Existing application ID');
    $fields['uid'] = $type . t('Authored by (uid)');
    $fields['nid'] = $type . t('Applied to (nid)');
    $fields['created'] = $type . t('Created timestamp');
    $fields['changed'] = $type . t('Modified timestamp');
    $fields['status'] = $type . t('Published');

    // Then add in anything provided by handlers
    $fields += migrate_handler_invoke_all('Entity', 'fields', $this->entityType, $this->bundle);
    $fields += migrate_handler_invoke_all('DropJobsApplication', 'fields', $this->entityType, $this->bundle);

    return $fields;
  }

  /**
   * Delete a batch of applications at once.
   *
   * @param $ids
   *  Array of application IDs to be deleted.
   */
  public function bulkRollback(array $ids) {
    migrate_instrument_start('drop_jobs_application_delete_multiple');
    $this->prepareRollback($ids);
    entity_delete_multiple($this->entity_type, $ids);
    $this->completeRollback($ids);
    migrate_instrument_stop('drop_jobs_application_delete_multiple');
  }

  /**
   * Import a single entity.
   *
   * @param $entity
   *  Entity object to build. Prefilled with any fields mapped in the Migration.
   * @param $row
   *  Raw source data object - passed through to prepare/complete handlers.
   * @return array
   *  Array of key fields of the entity that was saved if
   *  successful. FALSE on failure.
   */
  public function import(stdClass $entity, stdClass $row) {
    $migration = Migration::currentMigration();
    $type = $this->entity_info['entity keys']['bundle'];
    $entity->$type = $this->bundle;
    list($id, $vid, $bundle) = entity_extract_ids($this->entity_type, $entity);

    // Updating previously-migrated content?
    if (isset($row->migrate_map_destid1)) {
      // Make sure is_new is off
      $entity->is_new = FALSE;
      if (!empty($id)) {
        if ($id != $row->migrate_map_destid1) {
          throw new MigrateException(t("Incoming id !id and map destination id !destid1 don't match",
            array('!id' => $id, '!destid1' => $row->migrate_map_destid1)));
        }
      }
      else {
        $entity->{$this->entity_key} = $row->migrate_map_destid1;
      }
    }
    if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
      if (empty($id)) {
        throw new MigrateException(t('System-of-record is DESTINATION, but no destination id provided'));
      }
      $old_entity = entity_load_single($this->entity_type, $id);
      if (!isset($entity->created)) {
        $entity->created = $old_entity->created;
      }
      if (!isset($entity->uid)) {
        $entity->uid = $old_entity->uid;
      }
    }

    // Invoke migration prepare handlers
    $this->prepare($entity, $row);

    // Trying to update an existing entity
    if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
      // Incoming data overrides existing data.
      foreach ($entity as $field => $value) {
        $old_entity->$field = $value;
      }
      // Use the loaded entity from now on.
      $entity = $old_entity;
    }
    else {
      // Create a full application class.
      $entity = entity_create($this->entity_type, (array) $entity);
    }

    if (empty($id) && !(isset($entity->is_new) && $entity->is_new)) {
      $updating = TRUE;
    }
    else {
      $updating = FALSE;
    }

    migrate_instrument_start('entity_save');
    entity_save($this->entity_type, $entity);
    migrate_instrument_stop('entity_save');

    list($id, $vid, $bundle) = entity_extract_ids($this->entity_type, $entity);

    if (isset($id)) {
      if ($updating) {
        $this->numUpdated++;
      }
      else {
        $this->numCreated++;
      }

      $return = array($id);
    }
    else {
      $return = FALSE;
    }

    $this->complete($entity, $row);
    return $return;
  }
}
