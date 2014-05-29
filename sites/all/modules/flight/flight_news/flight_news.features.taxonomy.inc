<?php
/**
 * @file
 * flight_news.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function flight_news_taxonomy_default_vocabularies() {
  return array(
    'story_tag' => array(
      'name' => 'Story Tag',
      'machine_name' => 'story_tag',
      'description' => 'Story tags can be added by freetagging on the Story Edit page.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'story_type' => array(
      'name' => 'Story Type',
      'machine_name' => 'story_type',
      'description' => 'Used to create the different story formats',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
