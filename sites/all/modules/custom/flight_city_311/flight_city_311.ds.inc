<?php
/**
 * @file
 * flight_city_311.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function flight_city_311_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = '311_link';
  $ds_field->label = '311 Link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $ds_field->ui_limit = '311_category|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="https://baltimore.customerservicerequest.org/web_intake_balt/ServiceRequest.mvc/SRIntakeStep2/[term:field_311_code]" class="button">Create a new report</a>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['311_link'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function flight_city_311_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|311_category|default';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = '311_category';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'zf_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'description',
        2 => '311_link',
        3 => 'field_faqs',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'description' => 'ds_content',
      '311_link' => 'ds_content',
      'field_faqs' => 'ds_content',
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
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['taxonomy_term|311_category|default'] = $ds_layout;

  return $export;
}
