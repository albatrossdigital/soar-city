<?php
/**
 * @file
 * flight_city_311.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function flight_city_311_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function flight_city_311_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
