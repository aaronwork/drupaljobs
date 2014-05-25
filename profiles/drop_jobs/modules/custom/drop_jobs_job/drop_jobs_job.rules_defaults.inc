<?php
/**
 * @file
 * drop_jobs_job.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function drop_jobs_job_default_rules_configuration() {
  $items = array();
  $items['rules_link_condition_job_set_hidden'] = entity_import('rules_config', '{ "rules_link_condition_job_set_hidden" : {
      "LABEL" : "Rules link: Job unpublish condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "job" : "job" } } } },
        { "data_is" : { "data" : [ "node:field-job-workflow" ], "value" : "visible" } },
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "30037204" : "30037204", "139881272" : "139881272" } },
                "operation" : "OR"
              }
            },
            { "AND" : [
                { "data_is" : { "data" : [ "node:author" ], "value" : [ "site:current-user" ] } },
                { "user_has_role" : {
                    "account" : [ "site:current-user" ],
                    "roles" : { "value" : { "100482362" : "100482362" } }
                  }
                }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_link_condition_job_set_visible'] = entity_import('rules_config', '{ "rules_link_condition_job_set_visible" : {
      "LABEL" : "Rules link: Job publish condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "job" : "job" } } } },
        { "NOT data_is" : { "data" : [ "node:field-job-workflow" ], "value" : "visible" } },
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "30037204" : "30037204", "139881272" : "139881272" } },
                "operation" : "OR"
              }
            },
            { "AND" : [
                { "data_is" : { "data" : [ "node:author" ], "value" : [ "site:current-user" ] } },
                { "user_has_role" : {
                    "account" : [ "site:current-user" ],
                    "roles" : { "value" : { "100482362" : "100482362" } }
                  }
                }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_link_set_job_set_hidden'] = entity_import('rules_config', '{ "rules_link_set_job_set_hidden" : {
      "LABEL" : "Rules link: Job unpublish rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "job" : "job" } } } }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-job-workflow" ], "value" : "hidden" } },
              { "drupal_message" : { "message" : "Unpublished job [node:title]!", "repeat" : 0 } }
            ],
            "LABEL" : "Job set hidden"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_job_set_visible'] = entity_import('rules_config', '{ "rules_link_set_job_set_visible" : {
      "LABEL" : "Rules link: Job publish rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "job" : "job" } } } }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-job-workflow" ], "value" : "visible" } },
              { "drupal_message" : { "message" : "Published job [node:title]!", "repeat" : 0 } }
            ],
            "LABEL" : "Job set visible"
          }
        }
      ]
    }
  }');
  $items['rules_auto_hide_jobs'] = entity_import('rules_config', '{ "rules_auto_hide_jobs" : {
      "LABEL" : "Auto Hide Jobs",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "drop_jobs_job" ],
      "REQUIRES" : [ "rules", "drop_jobs_job" ],
      "ON" : [ "user_update" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "100482362" : "100482362" } }
          }
        },
        { "user_is_blocked" : { "account" : [ "account" ] } }
      ],
      "DO" : [
        { "drop_jobs_job_auto_hide_by_user" : { "account" : [ "account" ] } }
      ]
    }
  }');
  return $items;
}
