<?php
/**
 * @file
 * balt_apachesolr.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function balt_apachesolr_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'Nutch Server';
  $environment->url = 'http://192.241.220.139:8090/solr-nutch2';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_direct_commit' => 0,
    'apachesolr_index_last' => array(
      'node' => array(
        'last_changed' => '1401143505',
        'last_entity_id' => '222',
      ),
      'taxonomy_term' => array(
        'last_changed' => '1401143505',
        'last_entity_id' => '124',
      ),
    ),
    'apachesolr_index_updated' => 1401143521,
    'apachesolr_last_optimize' => 1401142135,
    'apachesolr_read_only' => '0',
    'apachesolr_search_facet_pages' => '',
    'apachesolr_soft_commit' => 0,
    'multisitesearch' => 1,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'entity',
      1 => 'event',
      2 => 'faq',
      3 => 'organization',
      4 => 'page',
      5 => 'person',
      6 => 'program',
      7 => 'story',
      8 => 'webform',
    ),
    'taxonomy_term' => array(
      0 => '311_category',
      1 => 'event_category',
      2 => 'faq_category',
      3 => 'faq_tags',
      4 => 'organization_category',
      5 => 'payment_type',
      6 => 'story_type',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
