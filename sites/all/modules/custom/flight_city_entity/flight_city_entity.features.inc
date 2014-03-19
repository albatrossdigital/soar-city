<?php
/**
 * @file
 * flight_city_entity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function flight_city_entity_ctools_plugin_api($module = NULL, $api = NULL) {
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
function flight_city_entity_node_info() {
  $items = array(
    'entity' => array(
      'name' => t('Entity'),
      'base' => 'node_content',
      'description' => t('Entites are for departments, agencies or subsites and contain basic contact and social media information.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
