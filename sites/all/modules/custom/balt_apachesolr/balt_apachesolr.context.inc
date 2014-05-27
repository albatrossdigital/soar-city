<?php
/**
 * @file
 * balt_apachesolr.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function balt_apachesolr_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site_search';
  $context->description = '';
  $context->tag = 'search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/site*' => 'search/site*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-G204zHQGfJYp1enBsKh3tOl0048pbF8M' => array(
          'module' => 'facetapi',
          'delta' => 'G204zHQGfJYp1enBsKh3tOl0048pbF8M',
          'region' => 'highlighted',
          'weight' => '-9',
          'title' => '<none>',
        ),
        'current_search-standard' => array(
          'module' => 'current_search',
          'delta' => 'standard',
          'region' => 'content',
          'weight' => '-10',
          'title' => '<none>',
        ),
        'facetapi-l4sZw7Q80g30SKRgKU7fmNvAAxFK1ehn' => array(
          'module' => 'facetapi',
          'delta' => 'l4sZw7Q80g30SKRgKU7fmNvAAxFK1ehn',
          'region' => 'sidebar_first',
          'weight' => '-10',
          'title' => 'Filter Results',
        ),
      ),
    ),
    'theme' => array(
      'title' => 'Your Search',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => 'no-page-title',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('search');
  $export['site_search'] = $context;

  return $export;
}
