<?php
/**
 * @file
 * social_stream.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function social_stream_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|social_stream|default';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'social_stream';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'social_stream' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'url' => 'js/json/social-stream-block/%',
        'type' => 'stream',
        'ft' => array(),
      ),
    ),
  );
  $export['bean|social_stream|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function social_stream_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|social_stream|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'social_stream';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'social_stream',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'social_stream' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['bean|social_stream|default'] = $ds_layout;

  return $export;
}
