<?php
/**
 * @file
 * flight_city_faq.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function flight_city_faq_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|faq|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'faq';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h6',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|faq|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|faq_category|teaser';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'faq_category';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'faq_subcategories' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:1:{s:9:"arguments";a:1:{s:19:"term_node_tid_depth";s:0:"";}}s:4:"type";s:11:"views_panes";s:7:"subtype";s:25:"faq_category-panel_pane_1";}',
        'load_terms' => 1,
        'ft' => array(),
      ),
    ),
    'term_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['taxonomy_term|faq_category|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function flight_city_faq_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'faq_subcategories';
  $ds_field->label = 'FAQ Subcategories';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $ds_field->ui_limit = 'faq_category|*';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['faq_subcategories'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function flight_city_faq_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|faq|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'faq';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'zf_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'domain',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
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
  $export['node|faq|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|faq|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'faq';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'zf_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
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
  $export['node|faq|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|faq_category|default';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'faq_category';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'zf_2col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'left' => array(
        'columns' => 'columns',
        'medium-3' => 'medium-3',
      ),
      'right' => array(
        'columns' => 'columns',
        'medium-9' => 'medium-9',
      ),
    ),
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
  $export['taxonomy_term|faq_category|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|faq_category|full';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'faq_category';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'zf_1col';
  $ds_layout->settings = array(
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
  $export['taxonomy_term|faq_category|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|faq_category|teaser';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'faq_category';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'zf_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'term_icon',
      ),
      'right' => array(
        1 => 'title',
        2 => 'faq_subcategories',
      ),
    ),
    'fields' => array(
      'term_icon' => 'left',
      'title' => 'right',
      'faq_subcategories' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'row' => 'row',
      ),
      'left' => array(
        'columns' => 'columns',
        'medium-3' => 'medium-3',
      ),
      'right' => array(
        'columns' => 'columns',
        'medium-9' => 'medium-9',
      ),
    ),
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
  $export['taxonomy_term|faq_category|teaser'] = $ds_layout;

  return $export;
}
