<?php
/**
 * @file
 * flight_city_organization.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function flight_city_organization_taxonomy_default_vocabularies() {
  return array(
    'organization_category' => array(
      'name' => 'Entity Category',
      'machine_name' => 'organization_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
