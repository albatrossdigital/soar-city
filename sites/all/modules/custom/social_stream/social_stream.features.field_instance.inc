<?php
/**
 * @file
 * social_stream.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function social_stream_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-social_stream-field_social_networks'
  $field_instances['bean-social_stream-field_social_networks'] = array(
    'bundle' => 'social_stream',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_social_networks',
    'label' => 'Social Networks',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Social Networks');

  return $field_instances;
}
