<?php
/**
 * @file
 * flight_city_entity.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function flight_city_entity_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|entity|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'entity';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_picture' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|entity|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function flight_city_entity_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|entity|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'entity';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'zf_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'body',
        1 => 'field_social_networks',
        2 => 'domain',
        3 => 'field_picture',
      ),
      'right' => array(
        4 => 'field_hours',
        5 => 'field_address',
        6 => 'field_location',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'field_social_networks' => 'left',
      'domain' => 'left',
      'field_picture' => 'left',
      'field_hours' => 'right',
      'field_address' => 'right',
      'field_location' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|entity|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|entity|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'entity';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'zf_3col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'body',
        3 => 'field_picture',
        5 => 'domain',
      ),
      'right' => array(
        1 => 'field_address',
      ),
      'middle' => array(
        2 => 'field_hours',
        4 => 'title',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'field_address' => 'right',
      'field_hours' => 'middle',
      'field_picture' => 'left',
      'title' => 'middle',
      'domain' => 'left',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|entity|teaser'] = $ds_layout;

  return $export;
}
