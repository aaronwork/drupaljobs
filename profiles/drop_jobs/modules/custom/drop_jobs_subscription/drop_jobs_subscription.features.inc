<?php
/**
 * @file
 * drop_jobs_subscription.features.inc
 */

/**
 * Implements hook_views_api().
 */
function drop_jobs_subscription_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_subs_type().
 */
function drop_jobs_subscription_default_subs_type() {
  $items = array();
  $items['recruiter_basic'] = entity_import('subs_type', '{
    "name" : "recruiter_basic",
    "label" : "Recruiter Basic",
    "weight" : "0",
    "data" : null,
    "description" : "Entry-level subscription.",
    "length" : "2592000",
    "grace" : "432000",
    "default_status" : "0",
    "jobs" : "5",
    "contacts" : "5",
    "searches" : "5",
    "rdf_mapping" : []
  }');
  $items['recruiter_premium'] = entity_import('subs_type', '{
    "name" : "recruiter_premium",
    "label" : "Recruiter Premium",
    "weight" : "0",
    "data" : null,
    "description" : "Serious users only.",
    "length" : "2592000",
    "grace" : "432000",
    "default_status" : "0",
    "jobs" : "0",
    "contacts" : "0",
    "searches" : "0",
    "rdf_mapping" : []
  }');
  $items['recruiter_standard'] = entity_import('subs_type', '{
    "name" : "recruiter_standard",
    "label" : "Recruiter Standard",
    "weight" : "0",
    "data" : null,
    "description" : "Standard subsciption - great value!",
    "length" : "2592000",
    "grace" : "432000",
    "default_status" : "0",
    "jobs" : "10",
    "contacts" : "10",
    "searches" : "10",
    "rdf_mapping" : []
  }');
  return $items;
}
