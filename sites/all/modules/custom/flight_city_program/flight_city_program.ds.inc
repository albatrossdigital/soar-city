<?php
/**
 * @file
 * flight_city_program.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function flight_city_program_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|program|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'program';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_picture' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_media' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|program|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function flight_city_program_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|program|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'program';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_picture',
        2 => 'field_media',
        3 => 'field_attachment',
        4 => 'domain',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_picture' => 'ds_content',
      'field_media' => 'ds_content',
      'field_attachment' => 'ds_content',
      'domain' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|program|default'] = $ds_layout;

  return $export;
}
