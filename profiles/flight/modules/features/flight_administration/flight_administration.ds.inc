<?php
/**
 * @file
 * flight_administration.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function flight_administration_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'party|organisation|address_and_location';
  $ds_fieldsetting->entity_type = 'party';
  $ds_fieldsetting->bundle = 'organisation';
  $ds_fieldsetting->view_mode = 'address_and_location';
  $ds_fieldsetting->settings = array(
    'edit_party_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['party|organisation|address_and_location'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function flight_administration_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'edit_party_link';
  $ds_field->label = 'Edit party link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'party' => 'party',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
  if(user_access(\'edit parties\')) {
    print l(\'Edit\', \'party/\' . $entity->pid . \'/edit\');
  }
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['edit_party_link'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function flight_administration_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'party|organisation|address_and_location';
  $ds_layout->entity_type = 'party';
  $ds_layout->bundle = 'organisation';
  $ds_layout->view_mode = 'address_and_location';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_geofield',
        1 => 'edit_party_link',
      ),
      'right' => array(
        0 => 'field_name',
        1 => 'field_address',
      ),
    ),
    'fields' => array(
      'field_geofield' => 'left',
      'edit_party_link' => 'left',
      'field_name' => 'right',
      'field_address' => 'right',
    ),
    'classes' => array(
      'right' => array(
        'main-display' => 'main-display',
      ),
    ),
  );
  $export['party|organisation|address_and_location'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function flight_administration_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'address_and_location';
  $ds_view_mode->label = 'Address and Location';
  $ds_view_mode->entities = array(
    'party' => 'party',
  );
  $export['address_and_location'] = $ds_view_mode;

  return $export;
}
