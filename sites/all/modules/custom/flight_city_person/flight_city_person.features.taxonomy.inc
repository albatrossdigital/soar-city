<?php
/**
 * @file
 * flight_city_person.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function flight_city_person_taxonomy_default_vocabularies() {
  return array(
    'entity_' => array(
      'name' => 'Person Category',
      'machine_name' => 'entity_',
      'description' => 'Categoriazation for organization members',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
