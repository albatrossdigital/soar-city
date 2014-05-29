<?php
/**
 * @file
 * flight_city_organization.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function flight_city_organization_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'government';
  $context->description = '';
  $context->tag = 'citywide';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'organizations:page' => 'organizations:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-organizations-page' => array(
          'module' => 'views',
          'delta' => '-exp-organizations-page',
          'region' => 'sidebar_first',
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
  $export['government'] = $context;

  return $export;
}
