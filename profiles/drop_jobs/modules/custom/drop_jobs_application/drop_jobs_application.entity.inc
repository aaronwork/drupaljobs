<?php
/**
 * @file
 * Drop Jobs Application entity class.
 */

/**
 * The class used for application entities.
 */
class DropJobsApplication extends Entity {

  /**
   * The application id.
   *
   * @var integer
   */
  public $aid;

  /**
   * The name of the application type.
   *
   * @var string
   */
  public $type;

  /**
   * The user id of the applicant.
   *
   * @var integer
   */
  public $uid;

  /**
   * The node id of the job.
   *
   * @var integer
   */
  public $nid;

  /**
   * The Unix timestamp when the application was created.
   *
   * @var integer
   */
  public $created;

  /**
   * The Unix timestamp when the application was most recently saved.
   *
   * @var integer
   */
  public $changed;

  /**
   * The application status.
   *
   * @var boolean
   */
  public $status;

  public function __construct($values = array()) {
    if (isset($values['user'])) {
      $this->setUser($values['user']);
      unset($values['user']);
    }
    if (isset($values['node'])) {
      $this->setNode($values['node']);
      unset($values['node']);
    }
    if (isset($values['type']) && is_object($values['type'])) {
      $values['type'] = $values['type']->type;
    }
    parent::__construct($values, 'drop_jobs_application');
  }

  /**
   * Returns the user owning this application.
   */
  public function user() {
    return user_load($this->uid);
  }

  /**
   * Returns the job node owning this application.
   */
  public function node() {
    return node_load($this->nid);
  }

  /**
   * Sets a new user owning this application.
   *
   * @param $account
   *   The user account object or the user account id (uid).
   */
  public function setUser($account) {
    $this->uid = is_object($account) ? $account->uid : $account;
  }

  /**
   * Sets a new job node this application.
   *
   * @param $node
   *   The job node object or the job node id (nid).
   */
  public function setNode($node) {
    $this->nid = is_object($node) ? $node->nid : $node;
  }

  /**
   * Returns the full url() for the application.
   */
  public function url() {
    $uri = $this->uri();
    return url($uri['path'], $uri);
  }

  /**
   * Returns the drupal path to this application.
   */
  public function path() {
    $uri = $this->uri();
    return $uri['path'];
  }

  protected function defaultUri() {
    return array(
      'path' => 'application/' . $this->aid,
    );
  }

  protected function defaultLabel() {
    $username = ($user = user_load($this->uid)) ? $user->name : 'username';
    $jobtitle = ($node = node_load($this->nid)) ? $node->title : 'job';
    return t('Application by @username to @job', array('@username' => $username, '@job' => $jobtitle));
  }

  public function save() {
    // Care about setting created and changed values. But do not automatically
    // set a created values for already existing applications.
    if (empty($this->created)) {
      $this->created = REQUEST_TIME;
    }
    $this->changed = REQUEST_TIME;

    if ($return = parent::save()) {
      // Update or set the static cache from drop_jobs_application_load_by_user().
      $cache = &drupal_static('drop_jobs_application_load_by_user', array());
      $cache[$this->uid][] = $this->aid;

      // Update or set the static cache from drop_jobs_application_load_by_node().
      $cache = &drupal_static('drop_jobs_application_load_by_node', array());
      $cache[$this->nid][] = $this->aid;

      // Update or set the static cache from drop_jobs_application_load_by_user_and_node().
      $cache = &drupal_static('drop_jobs_application_load_by_user_and_node', array());
      $cache["{$this->uid}_{$this->nid}"] = $this->aid;
    }

    return $return;
  }

}

/**
 * Use a separate class for application types so we can specify some defaults
 * modules may alter.
 */
class DropJobsApplicationType extends Entity {

  public $type;
  public $label;
  public $weight = 0;

  public function __construct($values = array()) {
    parent::__construct($values, 'drop_jobs_application_type');
  }

  /**
   * Returns whether the application type is locked, thus may not be deleted or renamed.
   *
   * Application types provided in code are automatically treated as locked, as well
   * as any fixed application type.
   */
  public function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }

}