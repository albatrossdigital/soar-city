<?php
/**
 * @file
 * flight_events.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function flight_events_taxonomy_default_vocabularies() {
  return array(
    'event_category' => array(
      'name' => 'Event Category',
      'machine_name' => 'event_category',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
