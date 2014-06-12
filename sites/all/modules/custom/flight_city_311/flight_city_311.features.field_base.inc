<?php
/**
 * @file
 * flight_city_311.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function flight_city_311_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_311_code'
  $field_bases['field_311_code'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_311_code',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 55,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
