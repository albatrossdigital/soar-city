<?php
/**
 * @file
 * baltimore_migrate.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function baltimore_migrate_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
