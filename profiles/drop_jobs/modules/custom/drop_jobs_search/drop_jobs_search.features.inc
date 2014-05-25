<?php
/**
 * @file
 * drop_jobs_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drop_jobs_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function drop_jobs_search_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function drop_jobs_search_default_search_api_index() {
  $items = array();
  $items['job_index'] = entity_import('search_api_index', '{
    "name" : "Job Index",
    "machine_name" : "job_index",
    "description" : "Index job nodes.",
    "server" : "db_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "type" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "promote" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_job_degree_level" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_job_experience" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_job_field" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_job_organization" : { "type" : "string" },
        "field_job_salary" : { "type" : "decimal" },
        "field_job_skills" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_job_study" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_job_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_job_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_job_workflow" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "search_api_viewed" : { "type" : "text" },
        "search_api_aggregation_1" : { "type" : "text" },
        "field_job_address:country" : { "type" : "string" },
        "field_job_address:administrative_area" : { "type" : "string" },
        "field_job_address:locality" : { "type" : "string" },
        "field_job_degree_level:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_job_experience:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_job_field:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_job_skills:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_job_study:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_job_tags:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_job_type:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "default" : "0", "bundles" : { "job" : "job" } }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "-49", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "-48", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-47", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "-46", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "-45",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Job Location",
                "type" : "fulltext",
                "fields" : [
                  "field_job_address:country",
                  "field_job_address:administrative_area",
                  "field_job_address:locality"
                ],
                "description" : "A Fulltext aggregation of the following fields: Address \\u00bb Country, Address \\u00bb Administrative area (i.e. State \\/ Province), Address \\u00bb Locality (i.e. City)."
              }
            }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "-44", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_viewed" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "search_api_viewed" : true },
            "title" : 0,
            "alt" : 0,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "search_api_viewed" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['resume_index'] = entity_import('search_api_index', '{
    "name" : "Resume Index",
    "machine_name" : "resume_index",
    "description" : "Index resume profiles.",
    "server" : "db_server",
    "item_type" : "profile2",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "type" : { "type" : "string", "entity_type" : "profile2_type" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "user" : { "type" : "integer", "entity_type" : "user" },
        "field_resume_promoted" : { "type" : "boolean" },
        "field_resume_sticky" : { "type" : "boolean" },
        "field_resume_workflow" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "search_api_viewed" : { "type" : "text" },
        "field_resume_education:field_resume_edu_field" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_resume_education:field_resume_edu_level" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_resume_education:field_resume_edu_name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_resume_experience:field_resume_exp_company_name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_resume_experience:field_resume_exp_field" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_resume_experience:field_resume_exp_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_resume_preferences:field_resume_pref_employment" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_resume_preferences:field_resume_pref_occupation" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_resume_preferences:field_resume_pref_title" : { "type" : "text" },
        "field_resume_education:field_resume_edu_field:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_resume_education:field_resume_edu_level:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_resume_languages:field_resume_language:term" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_resume_preferences:field_resume_pref_employment:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_resume_preferences:field_resume_pref_occupation:parents_all" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_resume_skills:field_resume_skills_level:term:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "resume" : "resume" } }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "account" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_viewed" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "search_api_viewed" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "search_api_viewed" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function drop_jobs_search_default_search_api_server() {
  $items = array();
  $items['db_server'] = entity_import('search_api_server', '{
    "name" : "Database Server",
    "machine_name" : "db_server",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "indexes" : {
        "job_index" : {
          "type" : {
            "table" : "search_api_db_job_index_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_job_index_status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "promote" : {
            "table" : "search_api_db_job_index_promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "sticky" : {
            "table" : "search_api_db_job_index_sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_job_index_created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_job_index_changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_job_index_author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_job_degree_level" : {
            "table" : "search_api_db_job_index_field_job_degree_level",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_job_experience" : {
            "table" : "search_api_db_job_index_field_job_experience",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_job_field" : {
            "table" : "search_api_db_job_index_field_job_field",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_job_organization" : {
            "table" : "search_api_db_job_index_field_job_organization",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_job_salary" : {
            "table" : "search_api_db_job_index_field_job_salary",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "field_job_skills" : {
            "table" : "search_api_db_job_index_field_job_skills",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_job_study" : {
            "table" : "search_api_db_job_index_field_job_study",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_job_tags" : {
            "table" : "search_api_db_job_index_field_job_tags",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_job_type" : {
            "table" : "search_api_db_job_index_field_job_type",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_job_workflow" : {
            "table" : "search_api_db_job_index_field_job_workflow",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_job_index_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_viewed" : {
            "table" : "search_api_db_job_index_search_api_viewed",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_aggregation_1" : {
            "table" : "search_api_db_job_index_search_api_aggregation_1",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_job_address:country" : {
            "table" : "search_api_db_job_index_field_job_address_country",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_job_address:administrative_area" : {
            "table" : "search_api_db_job_index_field_job_address_administrative_area",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_job_address:locality" : {
            "table" : "search_api_db_job_index_field_job_address_locality",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_job_degree_level:parents_all" : {
            "table" : "search_api_db_job_index_field_job_degree_level_parents_all",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_job_experience:parents_all" : {
            "table" : "search_api_db_job_index_field_job_experience_parents_all",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_job_field:parents_all" : {
            "table" : "search_api_db_job_index_field_job_field_parents_all",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_job_skills:parents_all" : {
            "table" : "search_api_db_job_index_field_job_skills_parents_all",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_job_study:parents_all" : {
            "table" : "search_api_db_job_index_field_job_study_parents_all",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_job_tags:parents_all" : {
            "table" : "search_api_db_job_index_field_job_tags_parents_all",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_job_type:parents_all" : {
            "table" : "search_api_db_job_index_field_job_type_parents_all",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          }
        },
        "resume_index" : {
          "type" : {
            "table" : "search_api_db_resume_index_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_resume_index_created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_resume_index_changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "user" : {
            "table" : "search_api_db_resume_index_user",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_resume_promoted" : {
            "table" : "search_api_db_resume_index_field_resume_promoted",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "field_resume_sticky" : {
            "table" : "search_api_db_resume_index_field_resume_sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "field_resume_workflow" : {
            "table" : "search_api_db_resume_index_field_resume_workflow",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_resume_index_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_viewed" : {
            "table" : "search_api_db_resume_index_search_api_viewed",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_resume_education:field_resume_edu_field" : {
            "table" : "search_api_db_resume_index_field_resume_education_field_resume_",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_resume_education:field_resume_edu_level" : {
            "table" : "search_api_db_resume_index_field_resume_education_field_resum_1",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_resume_education:field_resume_edu_name" : {
            "table" : "search_api_db_resume_index_field_resume_education_field_resum_2",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_resume_experience:field_resume_exp_company_name" : {
            "table" : "search_api_db_resume_index_field_resume_experience_field_resume",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_resume_experience:field_resume_exp_field" : {
            "table" : "search_api_db_resume_index_field_resume_experience_field_resu_1",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_resume_experience:field_resume_exp_type" : {
            "table" : "search_api_db_resume_index_field_resume_experience_field_resu_2",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_resume_preferences:field_resume_pref_employment" : {
            "table" : "search_api_db_resume_index_field_resume_preferences_field_resum",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_resume_preferences:field_resume_pref_occupation" : {
            "table" : "search_api_db_resume_index_field_resume_preferences_field_res_1",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_resume_preferences:field_resume_pref_title" : {
            "table" : "search_api_db_resume_index_field_resume_preferences_field_res_2",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_resume_education:field_resume_edu_field:parents_all" : {
            "table" : "search_api_db_resume_index_field_resume_education_field_resum_3",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_resume_education:field_resume_edu_level:parents_all" : {
            "table" : "search_api_db_resume_index_field_resume_education_field_resum_4",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_resume_languages:field_resume_language:term" : {
            "table" : "search_api_db_resume_index_field_resume_languages_field_resume_",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_resume_preferences:field_resume_pref_employment:parents_all" : {
            "table" : "search_api_db_resume_index_field_resume_preferences_field_res_3",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_resume_preferences:field_resume_pref_occupation:parents_all" : {
            "table" : "search_api_db_resume_index_field_resume_preferences_field_res_4",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_resume_skills:field_resume_skills_level:term:parents_all" : {
            "table" : "search_api_db_resume_index_field_resume_skills_field_resume_ski",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
