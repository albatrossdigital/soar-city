<?php
/**
 * @file
 * image_slideshow.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function image_slideshow_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'images';
  $queue->label = 'Images';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'file';
  $queue->settings = array(
    'target_bundles' => array(
      'image' => 'image',
    ),
    'min_size' => '0',
    'max_size' => '0',
  );
  $export['images'] = $queue;

  return $export;
}
