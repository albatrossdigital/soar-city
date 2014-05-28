<?php
/**
 * @file
 * baltimore_migrate.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function baltimore_migrate_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migrate_faq-link_5_text-array_filter';
  $feeds_tamper->importer = 'migrate_faq';
  $feeds_tamper->source = 'Link 5 text';
  $feeds_tamper->plugin_id = 'array_filter';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Filter empty items';
  $export['migrate_faq-link_5_text-array_filter'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migrate_faq-link_5_text-explode';
  $feeds_tamper->importer = 'migrate_faq';
  $feeds_tamper->source = 'Link 5 text';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Explode';
  $export['migrate_faq-link_5_text-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migrate_faq-link_5_text-rewrite';
  $feeds_tamper->importer = 'migrate_faq';
  $feeds_tamper->source = 'Link 5 text';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[link 1 text],[link 2 text],[link 3 text],[link 4 text],[link 5 text]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['migrate_faq-link_5_text-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migrate_faq-link_5_url-array_filter';
  $feeds_tamper->importer = 'migrate_faq';
  $feeds_tamper->source = 'Link 5 url';
  $feeds_tamper->plugin_id = 'array_filter';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Filter empty items';
  $export['migrate_faq-link_5_url-array_filter'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migrate_faq-link_5_url-explode';
  $feeds_tamper->importer = 'migrate_faq';
  $feeds_tamper->source = 'Link 5 url';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Explode';
  $export['migrate_faq-link_5_url-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migrate_faq-link_5_url-rewrite';
  $feeds_tamper->importer = 'migrate_faq';
  $feeds_tamper->source = 'Link 5 url';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[link 1 url],[link 2 url],[link 3 url],[link 4 url],[link 5 url]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['migrate_faq-link_5_url-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migrate_faq-sub_category-array_filter';
  $feeds_tamper->importer = 'migrate_faq';
  $feeds_tamper->source = 'Sub Category';
  $feeds_tamper->plugin_id = 'array_filter';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Filter empty items';
  $export['migrate_faq-sub_category-array_filter'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migrate_faq-sub_category-explode';
  $feeds_tamper->importer = 'migrate_faq';
  $feeds_tamper->source = 'Sub Category';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => 1,
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Explode';
  $export['migrate_faq-sub_category-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migrate_faq-sub_category-rewrite';
  $feeds_tamper->importer = 'migrate_faq';
  $feeds_tamper->source = 'Sub Category';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[sub category],[main category]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['migrate_faq-sub_category-rewrite'] = $feeds_tamper;

  return $export;
}
