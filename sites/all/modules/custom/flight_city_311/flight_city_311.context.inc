<?php
/**
 * @file
 * flight_city_311.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function flight_city_311_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '311_home';
  $context->description = '';
  $context->tag = 'citywide';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        '311_home:page' => '311_home:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-311_home-page' => array(
          'module' => 'views',
          'delta' => '-exp-311_home-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
          'title' => '',
        ),
        'views-311_home-block_1' => array(
          'module' => 'views',
          'delta' => '311_home-block_1',
          'region' => 'triptych_first',
          'weight' => '-10',
          'title' => 'Popular Service Requests',
        ),
        'flight_city_311-search' => array(
          'module' => 'flight_city_311',
          'delta' => 'search',
          'region' => 'triptych_middle',
          'weight' => '-10',
          'title' => '',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('citywide');
  $export['311_home'] = $context;

  return $export;
}
