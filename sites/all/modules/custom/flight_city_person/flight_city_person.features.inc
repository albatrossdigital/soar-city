<?php
/**
 * @file
 * flight_city_person.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function flight_city_person_ctools_plugin_api($module = NULL, $api = NULL) {
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
 * Implements hook_views_api().
 */
function flight_city_person_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function flight_city_person_node_info() {
  $items = array(
    'person' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => t('People are used for staff member listings'),
      'has_title' => '1',
      'title_label' => t('Full name'),
      'help' => '',
    ),
  );
  return $items;
}
