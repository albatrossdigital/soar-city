<?php
/**
 * @file
 * social_stream.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function social_stream_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function social_stream_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
