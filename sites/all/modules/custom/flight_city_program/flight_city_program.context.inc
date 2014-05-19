<?php
/**
 * @file
 * flight_city_program.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function flight_city_program_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'programs_page';
  $context->description = '';
  $context->tag = 'page';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'programs:page' => 'programs:page',
      ),
    ),
  );
  $context->reactions = array(
    'theme' => array(
      'title' => 'What we do',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('page');
  $export['programs_page'] = $context;

  return $export;
}
