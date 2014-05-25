<?php
/**
 * @file
 * Drop Jobs Recommendation entity class.
 */

/**
 * Job Recommendation entity class.
 */
class DropJobsRecommendation extends Entity {

  /**
   * The recommendation id.
   *
   * @var integer
   */
  public $rid;

  /**
   * The job node id.
   *
   * @var integer
   */
  public $nid;

  /**
   * The user id.
   *
   * @var integer
   */
  public $uid;

  /**
   * The Unix timestamp when the recommendation was made.
   *
   * @var integer
   */
  public $created;

  /**
   * Returns the full url() for the subscription.
   */
  public function url() {
    $uri = $this->uri();
    return url($uri['path'], $uri);
  }

  /**
   * Returns the drupal path to this subscription.
   */
  public function path() {
    $uri = $this->uri();
    return $uri['path'];
  }

  protected function defaultUri() {
    return array(
      'path' => 'recommendation/' . $this->rid,
    );
  }

  protected function defaultLabel() {
    $username = isset($this->uid) ? user_load($this->uid)->name : 'username';
    $jobtitle = isset($this->nid) ? node_load($this->nid)->title : 'jobtitle';
    return t('Recommend @job to @username', array('@job' => $jobtitle, '@username' => $username));
  }

  public function save() {
    // Care about setting created values. But do not automatically
    // set a created values for already existing recommendations.
    if (empty($this->created)) {
      $this->created = REQUEST_TIME;
    }

    if ($return = parent::save()) {
      // Update or set the static cache from drop_jobs_recommendation_load_by_user().
      $cache = &drupal_static('drop_jobs_recommendation_load_by_user', array());
      $cache[$this->uid][] = $this->rid;
    }

    return $return;
  }

}