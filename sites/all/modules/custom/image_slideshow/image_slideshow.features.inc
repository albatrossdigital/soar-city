<?php
/**
 * @file
 * image_slideshow.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function image_slideshow_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function image_slideshow_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
