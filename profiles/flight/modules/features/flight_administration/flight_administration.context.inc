<?php
/**
 * @file
 * flight_administration.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function flight_administration_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'reach_dashboard';
  $context->description = 'Adds the default blocks to the dashboard';
  $context->tag = 'reach';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/dashboard' => 'admin/dashboard',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'flight_administration-create_new' => array(
          'module' => 'flight_administration',
          'delta' => 'create_new',
          'region' => 'dashboard_main',
          'weight' => '-10',
        ),
        'views-admin_content-block_1' => array(
          'module' => 'views',
          'delta' => 'admin_content-block_1',
          'region' => 'dashboard_main',
          'weight' => '-9',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'dashboard_sidebar',
          'weight' => '-37',
        ),
        'views-reach_actions_party-block_1' => array(
          'module' => 'views',
          'delta' => 'reach_actions_party-block_1',
          'region' => 'dashboard_sidebar',
          'weight' => '-36',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds the default blocks to the dashboard');
  t('reach');
  $export['reach_dashboard'] = $context;

  return $export;
}
