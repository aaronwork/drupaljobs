<?php
/**
 * @file
 * drop_jobs_candidate.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function drop_jobs_candidate_default_rules_configuration() {
  $items = array();
  $items['rules_auto_hide_resumes'] = entity_import('rules_config', '{ "rules_auto_hide_resumes" : {
      "LABEL" : "Auto Hide Resumes",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "drop_jobs_candidate" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_update" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "185431326" : "185431326" } }
          }
        },
        { "user_is_blocked" : { "account" : [ "account" ] } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "account:profile-resume:field-resume-workflow" ],
            "value" : "auto_hidden"
          }
        }
      ]
    }
  }');
  $items['rules_create_candidate_resume'] = entity_import('rules_config', '{ "rules_create_candidate_resume" : {
      "LABEL" : "Create Candidate R\\u00e9sum\\u00e9",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "drop_jobs", "drop_jobs_candidate" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_insert", "user_update" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "185431326" : "185431326" } }
          }
        },
        { "data_is_empty" : { "data" : [ "account:profile-resume" ] } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "profile2",
              "param_type" : "resume",
              "param_user" : [ "account" ]
            },
            "PROVIDE" : { "entity_created" : { "resume" : "Candidate Resume" } }
          }
        },
        { "entity_save" : { "data" : [ "resume" ], "immediate" : 1 } }
      ]
    }
  }');
  $items['rules_link_condition_resume_set_hidden'] = entity_import('rules_config', '{ "rules_link_condition_resume_set_hidden" : {
      "LABEL" : "Rules link: Resume set hidden condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "profile2" : { "label" : "profile2", "type" : "profile2" } },
      "AND" : [
        { "data_is" : { "data" : [ "profile2:type" ], "value" : "resume" } },
        { "data_is" : { "data" : [ "profile2:field-resume-workflow" ], "value" : "visible" } },
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "30037204" : "30037204", "99206295" : "99206295" } },
                "operation" : "OR"
              }
            },
            { "AND" : [
                { "data_is" : { "data" : [ "site:current-user" ], "value" : [ "profile2:user" ] } },
                { "user_has_role" : {
                    "account" : [ "site:current-user" ],
                    "roles" : { "value" : { "185431326" : "185431326" } }
                  }
                }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_link_condition_resume_set_visible'] = entity_import('rules_config', '{ "rules_link_condition_resume_set_visible" : {
      "LABEL" : "Rules link: Resume set visible condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "profile2" : { "label" : "profile2", "type" : "profile2" } },
      "AND" : [
        { "data_is" : { "data" : [ "profile2:type" ], "value" : "resume" } },
        { "data_is" : {
            "data" : [ "profile2:field-resume-workflow" ],
            "op" : "IN",
            "value" : { "value" : { "hidden" : "hidden" } }
          }
        },
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "30037204" : "30037204", "215224363" : "215224363" } },
                "operation" : "OR"
              }
            },
            { "AND" : [
                { "data_is" : { "data" : [ "site:current-user" ], "value" : [ "profile2:user" ] } },
                { "user_has_role" : {
                    "account" : [ "site:current-user" ],
                    "roles" : { "value" : { "185431326" : "185431326" } }
                  }
                }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_link_set_resume_set_hidden'] = entity_import('rules_config', '{ "rules_link_set_resume_set_hidden" : {
      "LABEL" : "Rules link: Resume set hidden rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "profile2" : { "label" : "profile2", "type" : "profile2" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [ { "data_is" : { "data" : [ "profile2:type" ], "value" : "resume" } } ],
            "DO" : [
              { "data_set" : { "data" : [ "profile2:field-resume-workflow" ], "value" : "hidden" } }
            ],
            "LABEL" : "Resume set hidden"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_resume_set_visible'] = entity_import('rules_config', '{ "rules_link_set_resume_set_visible" : {
      "LABEL" : "Rules link: Resume set visible rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "profile2" : { "label" : "profile2", "type" : "profile2" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [ { "data_is" : { "data" : [ "profile2:type" ], "value" : "resume" } } ],
            "DO" : [
              { "data_set" : { "data" : [ "profile2:field-resume-workflow" ], "value" : "visible" } },
              { "drupal_message" : { "message" : "Your r\\u00e9sum\\u00e9 is now visible!", "repeat" : 0 } }
            ],
            "LABEL" : "Resume set visible"
          }
        }
      ]
    }
  }');
  $items['rules_register_as_candidate'] = entity_import('rules_config', '{ "rules_register_as_candidate" : {
      "LABEL" : "Register as Candidate",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-5",
      "TAGS" : [ "drop_jobs", "drop_jobs_candidate" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_insert" ],
      "IF" : [
        { "data_is" : { "data" : [ "site:current-page:path" ], "value" : "user\\/register" } }
      ],
      "DO" : [
        { "user_add_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "185431326" : "185431326" } }
          }
        }
      ]
    }
  }');
  $items['rules_resume_label'] = entity_import('rules_config', '{ "rules_resume_label" : {
      "LABEL" : "Resume Label",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "drop_jobs_candidate" ],
      "REQUIRES" : [ "rules", "profile2" ],
      "ON" : [ "profile2_update" ],
      "IF" : [
        { "data_is" : { "data" : [ "profile2:type" ], "value" : "resume" } },
        { "NOT data_is_empty" : { "data" : [ "profile2:field-resume-preferences" ] } },
        { "NOT data_is" : {
            "data" : [ "profile2:label" ],
            "value" : [ "profile2:field-resume-preferences:field-resume-pref-title" ]
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "profile2:label" ],
            "value" : [ "profile2:field-resume-preferences:field-resume-pref-title" ]
          }
        }
      ]
    }
  }');
  return $items;
}
