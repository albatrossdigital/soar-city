<?php
/**
 * @file
 * flight_address_helper.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function flight_address_helper_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'flight_helper_addresses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Flight Helper Addresses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'columns medium-4';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Address - Full name */
  $handler->display->display_options['fields']['field_address_name_line']['id'] = 'field_address_name_line';
  $handler->display->display_options['fields']['field_address_name_line']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_name_line']['field'] = 'field_address_name_line';
  $handler->display->display_options['fields']['field_address_name_line']['label'] = '';
  $handler->display->display_options['fields']['field_address_name_line']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_address_name_line']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Address - Full name */
  $handler->display->display_options['filters']['field_address_name_line']['id'] = 'field_address_name_line';
  $handler->display->display_options['filters']['field_address_name_line']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_name_line']['field'] = 'field_address_name_line';
  $handler->display->display_options['filters']['field_address_name_line']['operator'] = 'word';
  $handler->display->display_options['filters']['field_address_name_line']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_address_name_line']['expose']['operator_id'] = 'field_address_name_line_op';
  $handler->display->display_options['filters']['field_address_name_line']['expose']['label'] = 'Address - Full name';
  $handler->display->display_options['filters']['field_address_name_line']['expose']['operator'] = 'field_address_name_line_op';
  $handler->display->display_options['filters']['field_address_name_line']['expose']['identifier'] = 'field_address_name_line';
  $handler->display->display_options['filters']['field_address_name_line']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_address_name_line']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_address_name_line']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_address_name_line']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_address_name_line']['expose']['autocomplete_field'] = 'field_address_name_line';
  $handler->display->display_options['filters']['field_address_name_line']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_address_name_line']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_address_name_line']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Address - Full name */
  $handler->display->display_options['filters']['field_address_name_line_1']['id'] = 'field_address_name_line_1';
  $handler->display->display_options['filters']['field_address_name_line_1']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_name_line_1']['field'] = 'field_address_name_line';
  $handler->display->display_options['filters']['field_address_name_line_1']['operator'] = 'not empty';

  /* Display: List View */
  $handler = $view->new_display('entityreference', 'List View', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_address' => 'field_address',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'components' => array(
      'name_line' => 'name_line',
    ),
    'separator' => ', ',
  );
  $handler->display->display_options['fields']['field_address']['group_column'] = 'name_line';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Address - Full name */
  $handler->display->display_options['filters']['field_address_name_line_1']['id'] = 'field_address_name_line_1';
  $handler->display->display_options['filters']['field_address_name_line_1']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_name_line_1']['field'] = 'field_address_name_line';
  $handler->display->display_options['filters']['field_address_name_line_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_address_name_line_1']['expose']['operator_id'] = 'field_address_name_line_1_op';
  $handler->display->display_options['filters']['field_address_name_line_1']['expose']['label'] = 'Address - Full name';
  $handler->display->display_options['filters']['field_address_name_line_1']['expose']['operator'] = 'field_address_name_line_1_op';
  $handler->display->display_options['filters']['field_address_name_line_1']['expose']['identifier'] = 'field_address_name_line_1';
  $handler->display->display_options['filters']['field_address_name_line_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_address_name_line_1']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_address_name_line_1']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_address_name_line_1']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_address_name_line_1']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_address_name_line_1']['expose']['autocomplete_dependent'] = 0;

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $export['flight_helper_addresses'] = $view;

  return $export;
}
