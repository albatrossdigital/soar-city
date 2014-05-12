<?php
/**
 * @file
 * flight_city_workbench.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function flight_city_workbench_flag_default_flags() {
  $flags = array();
  // Exported flag: "Feature on main site".
  $flags['feature_main'] = array(
    'entity_type' => 'node',
    'title' => 'Feature on main site',
    'global' => 1,
    'types' => array(
      0 => 'entity',
      1 => 'faq',
      2 => 'organization',
      3 => 'page',
      4 => 'person',
      5 => 'program',
      6 => 'webform',
    ),
    'flag_short' => 'Feature on baltimorecity.gov',
    'flag_long' => 'Request that this item gets featured on the main website',
    'flag_message' => 'Your request has been submitted is pending approval',
    'unflag_short' => 'Remove request to feature on baltimorecity.gov',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
      'compact_teaser' => 0,
      'social' => 0,
      'social_big' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 1,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'flight_city_workbench',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Promote to main site".
  $flags['promote_main'] = array(
    'entity_type' => 'node',
    'title' => 'Promote to main site',
    'global' => 1,
    'types' => array(
      0 => 'event',
      1 => 'story',
    ),
    'flag_short' => 'Promote to baltimorecity.gov',
    'flag_long' => 'Request that this item is included on the main website',
    'flag_message' => 'Your request has been submitted is pending approval',
    'unflag_short' => 'Remove request to promote to baltimorecity.gov',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
      'compact_teaser' => 0,
      'social' => 0,
      'social_big' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 1,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'flight_city_workbench',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}
