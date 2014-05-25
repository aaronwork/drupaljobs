<?php
/**
 * @file
 * drop_jobs_recruiter.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function drop_jobs_recruiter_default_rules_configuration() {
  $items = array();
  $items['rules_create_recruiter_profile'] = entity_import('rules_config', '{ "rules_create_recruiter_profile" : {
      "LABEL" : "Create Recruiter Profile",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "drop_jobs", "drop_jobs_recruiter" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_insert", "user_update" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "100482362" : "100482362" } }
          }
        },
        { "data_is_empty" : { "data" : [ "account:profile-recruiter" ] } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "profile2",
              "param_type" : "recruiter",
              "param_user" : [ "account" ]
            },
            "PROVIDE" : { "entity_created" : { "recruiter" : "Recruiter Profile" } }
          }
        },
        { "entity_save" : { "data" : [ "recruiter" ], "immediate" : 1 } }
      ]
    }
  }');
  $items['rules_recruiter_label'] = entity_import('rules_config', '{ "rules_recruiter_label" : {
      "LABEL" : "Recruiter Label",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "drop_jobs_recruiter" ],
      "REQUIRES" : [ "rules", "profile2" ],
      "ON" : [ "profile2_update" ],
      "IF" : [
        { "data_is" : { "data" : [ "profile2:type" ], "value" : "recruiter" } },
        { "NOT data_is_empty" : { "data" : [ "profile2:field-recruiter-first-name" ] } },
        { "NOT data_is_empty" : { "data" : [ "profile2:field-recruiter-last-name" ] } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "profile2:label" ],
            "value" : "[profile2:field-recruiter-first-name] [profile2:field-recruiter-last-name]"
          }
        }
      ]
    }
  }');
  $items['rules_register_as_recruiter'] = entity_import('rules_config', '{ "rules_register_as_recruiter" : {
      "LABEL" : "Register as Recruiter",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-5",
      "TAGS" : [ "drop_jobs", "drop_jobs_recruiter" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_insert" ],
      "IF" : [
        { "data_is" : {
            "data" : [ "site:current-page:path" ],
            "value" : "user\\/register\\/recruiter"
          }
        }
      ],
      "DO" : [
        { "user_add_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "100482362" : "100482362" } }
          }
        }
      ]
    }
  }');
  return $items;
}
