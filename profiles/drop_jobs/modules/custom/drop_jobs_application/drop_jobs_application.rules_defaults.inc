<?php
/**
 * @file
 * drop_jobs_application.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function drop_jobs_application_default_rules_configuration() {
  $items = array();
  $items['rules_link_condition__cloned'] = entity_import('rules_config', '{ "rules_link_condition__cloned" : {
      "LABEL" : "Rules link: Application set hidden (cloned) condition",
      "PLUGIN" : "and",
      "USES VARIABLES" : { "drop_jobs_application" : { "type" : "drop_jobs_application", "label" : "drop_jobs_application" } },
      "AND" : []
    }
  }');
  $items['rules_link_condition_application_set_hidden'] = entity_import('rules_config', '{ "rules_link_condition_application_set_hidden" : {
      "LABEL" : "Rules link: Application set hidden condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "drop_jobs_application" : { "label" : "drop_jobs_application", "type" : "drop_jobs_application" } },
      "AND" : [
        { "data_is" : {
            "data" : [ "drop-jobs-application:status" ],
            "op" : "IN",
            "value" : { "value" : [ "0", "1" ] }
          }
        },
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "30037204" : "30037204", "139881272" : "139881272" } },
                "operation" : "OR"
              }
            },
            { "AND" : [
                { "user_has_role" : {
                    "account" : [ "site:current-user" ],
                    "roles" : { "value" : { "100482362" : "100482362" } }
                  }
                },
                { "data_is" : {
                    "data" : [ "drop-jobs-application:job:author" ],
                    "value" : [ "site:current-user" ]
                  }
                }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_link_condition_application_set_new'] = entity_import('rules_config', '{ "rules_link_condition_application_set_new" : {
      "LABEL" : "Rules link: Application set new condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "drop_jobs_application" : { "label" : "drop_jobs_application", "type" : "drop_jobs_application" } },
      "AND" : [
        { "data_is" : {
            "data" : [ "drop-jobs-application:status" ],
            "op" : "IN",
            "value" : { "value" : { "1" : "1", "2" : "2" } }
          }
        },
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "30037204" : "30037204", "139881272" : "139881272" } },
                "operation" : "OR"
              }
            },
            { "AND" : [
                { "user_has_role" : {
                    "account" : [ "site:current-user" ],
                    "roles" : { "value" : { "100482362" : "100482362" } }
                  }
                },
                { "data_is" : {
                    "data" : [ "drop-jobs-application:job:author" ],
                    "value" : [ "site:current-user" ]
                  }
                }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_link_condition_application_set_read'] = entity_import('rules_config', '{ "rules_link_condition_application_set_read" : {
      "LABEL" : "Rules link: Application set read condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "drop_jobs_application" : { "label" : "drop_jobs_application", "type" : "drop_jobs_application" } },
      "AND" : [
        { "data_is" : {
            "data" : [ "drop-jobs-application:status" ],
            "op" : "IN",
            "value" : { "value" : { "0" : "0", "2" : "2" } }
          }
        },
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "30037204" : "30037204", "139881272" : "139881272" } },
                "operation" : "OR"
              }
            },
            { "AND" : [
                { "user_has_role" : {
                    "account" : [ "site:current-user" ],
                    "roles" : { "value" : { "100482362" : "100482362" } }
                  }
                },
                { "data_is" : {
                    "data" : [ "drop-jobs-application:job:author" ],
                    "value" : [ "site:current-user" ]
                  }
                }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_link_condition_application_set_revoked'] = entity_import('rules_config', '{ "rules_link_condition_application_set_revoked" : {
      "LABEL" : "Rules link: Resume set revoked condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "drop_jobs_application" : { "label" : "drop_jobs_application", "type" : "drop_jobs_application" } },
      "AND" : [
        { "NOT data_is" : { "data" : [ "drop-jobs-application:status" ], "value" : "3" } },
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "30037204" : "30037204", "139881272" : "139881272" } },
                "operation" : "OR"
              }
            },
            { "AND" : [
                { "user_has_role" : {
                    "account" : [ "site:current-user" ],
                    "roles" : { "value" : { "185431326" : "185431326" } }
                  }
                },
                { "data_is" : {
                    "data" : [ "drop-jobs-application:candidate" ],
                    "value" : [ "site:current-user" ]
                  }
                }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_link_set_application_set_hidden'] = entity_import('rules_config', '{ "rules_link_set_application_set_hidden" : {
      "LABEL" : "Rules link: Application set hidden rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "drop_jobs_application" : { "type" : "drop_jobs_application", "label" : "drop_jobs_application" } },
      "RULES" : [
        { "RULE" : {
            "DO" : [
              { "data_set" : { "data" : [ "drop-jobs-application:status" ], "value" : "2" } }
            ],
            "LABEL" : "Application set hidden"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_application_set_new'] = entity_import('rules_config', '{ "rules_link_set_application_set_new" : {
      "LABEL" : "Rules link: Application set new rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "drop_jobs_application" : { "type" : "drop_jobs_application", "label" : "drop_jobs_application" } },
      "RULES" : [
        { "RULE" : {
            "DO" : [
              { "data_set" : { "data" : [ "drop-jobs-application:status" ], "value" : "0" } }
            ],
            "LABEL" : "Application set new"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_application_set_read'] = entity_import('rules_config', '{ "rules_link_set_application_set_read" : {
      "LABEL" : "Rules link: Application set read rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "drop_jobs_application" : { "type" : "drop_jobs_application", "label" : "drop_jobs_application" } },
      "RULES" : [
        { "RULE" : {
            "DO" : [
              { "data_set" : { "data" : [ "drop-jobs-application:status" ], "value" : "1" } }
            ],
            "LABEL" : "Application set read"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_application_set_revoked'] = entity_import('rules_config', '{ "rules_link_set_application_set_revoked" : {
      "LABEL" : "Rules link: Resume set revoked rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "drop_jobs_application" : { "type" : "drop_jobs_application", "label" : "drop_jobs_application" } },
      "RULES" : [
        { "RULE" : {
            "DO" : [
              { "data_set" : { "data" : [ "drop-jobs-application:status" ], "value" : "3" } }
            ],
            "LABEL" : "Application set revoked"
          }
        }
      ]
    }
  }');
  return $items;
}
