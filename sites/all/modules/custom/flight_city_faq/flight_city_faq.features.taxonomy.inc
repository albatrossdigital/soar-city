<?php
/**
 * @file
 * flight_city_faq.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function flight_city_faq_taxonomy_default_vocabularies() {
  return array(
    'faq_category' => array(
      'name' => 'FAQ Category',
      'machine_name' => 'faq_category',
      'description' => 'Used to organize FAQs',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'faq_tags' => array(
      'name' => 'FAQ Tags',
      'machine_name' => 'faq_tags',
      'description' => 'Used to organize FAQs',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
