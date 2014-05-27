<?php
/**
 * @file
 * baltimore_migrate.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function baltimore_migrate_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'migrate_users';
  $feeds_importer->config = array(
    'name' => 'Migrate: Users',
    'description' => 'Imports users from a csv spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          6 => '6',
          8 => 0,
          5 => 0,
          7 => 0,
          3 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Email address',
            'target' => 'mail',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Email address',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'First Name',
            'target' => 'field_user_firstname',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Last Name',
            'target' => 'field_user_lastname',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Title',
            'target' => 'field_user_title',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['migrate_users'] = $feeds_importer;

  return $export;
}
