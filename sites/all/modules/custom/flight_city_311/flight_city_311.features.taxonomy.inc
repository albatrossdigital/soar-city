<?php
/**
 * @file
 * flight_city_311.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function flight_city_311_taxonomy_default_vocabularies() {
  return array(
    '311_category' => array(
      'name' => '311 Category',
      'machine_name' => '311_category',
      'description' => '',
      'hierarchy' => 2,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
