<?php
/**
 * @file
 * flight_city_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function flight_city_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_page';
  $context->description = '';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events' => 'events',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-calendar-block_3' => array(
          'module' => 'views',
          'delta' => 'calendar-block_3',
          'region' => 'content',
          'weight' => '-10',
          'title' => '<none>',
        ),
        'views-event_categories-block' => array(
          'module' => 'views',
          'delta' => 'event_categories-block',
          'region' => 'content',
          'weight' => '-9',
          'title' => '',
        ),
        'views-calendar-block_4' => array(
          'module' => 'views',
          'delta' => 'calendar-block_4',
          'region' => 'content',
          'weight' => '-8',
          'title' => '',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('page');
  $export['events_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_section';
  $context->description = '';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events' => 'events',
        'events/list' => 'events/list',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-calendar-list' => array(
          'module' => 'views',
          'delta' => '-exp-calendar-list',
          'region' => 'sidebar_first',
          'weight' => '-10',
          'title' => 'Find an Event',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('section');
  $export['events_section'] = $context;

  return $export;
}
