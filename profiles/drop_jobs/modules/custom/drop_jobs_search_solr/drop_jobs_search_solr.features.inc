<?php
/**
 * @file
 * drop_jobs_search_solr.features.inc
 */

/**
 * Implements hook_default_search_api_server().
 */
function drop_jobs_search_solr_default_search_api_server() {
  $items = array();
  $items['solr_server'] = entity_import('search_api_server', '{
    "name" : "Solr Server",
    "machine_name" : "solr_server",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "host" : "' . variable_get_value('drop_jobs_search_solr_host') . '",
      "port" : "' . variable_get_value('drop_jobs_search_solr_port') . '",
      "path" : "\\/' . variable_get_value('drop_jobs_search_solr_path') . '",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "http_method" : "POST"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
