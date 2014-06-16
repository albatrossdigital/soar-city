<?php
/**
 * @file
 * social_stream.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function social_stream_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'social_stream';
  $bean_type->label = 'Social stream';
  $bean_type->options = '';
  $bean_type->description = 'Adds a social stream box to a page.';
  $export['social_stream'] = $bean_type;

  return $export;
}
