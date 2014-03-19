<?php
/**
 * @file
 * flight_city_program.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function flight_city_program_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function flight_city_program_node_info() {
  $items = array(
    'program' => array(
      'name' => t('Program'),
      'base' => 'node_content',
      'description' => t('Programs belong to Entities and may contain sub pages, stories and events.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
