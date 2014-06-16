<?php
/**
 * @file
 * social_stream.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function social_stream_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'social_stream_networks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Social stream networks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Field collection item: Entity with the Social Networks (field_social_networks) */
  $handler->display->display_options['relationships']['field_social_networks_node']['id'] = 'field_social_networks_node';
  $handler->display->display_options['relationships']['field_social_networks_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_social_networks_node']['field'] = 'field_social_networks_node';
  /* Relationship: Field collection item: Entity with the Social Networks (field_social_networks) */
  $handler->display->display_options['relationships']['field_social_networks_bean']['id'] = 'field_social_networks_bean';
  $handler->display->display_options['relationships']['field_social_networks_bean']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_social_networks_bean']['field'] = 'field_social_networks_bean';
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['label'] = 'id';
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Field: Field collection item: Account URL */
  $handler->display->display_options['fields']['field_social_network_account']['id'] = 'field_social_network_account';
  $handler->display->display_options['fields']['field_social_network_account']['table'] = 'field_data_field_social_network_account';
  $handler->display->display_options['fields']['field_social_network_account']['field'] = 'field_social_network_account';
  $handler->display->display_options['fields']['field_social_network_account']['label'] = 'url';
  /* Field: Field collection item: Network */
  $handler->display->display_options['fields']['field_social_network_type']['id'] = 'field_social_network_type';
  $handler->display->display_options['fields']['field_social_network_type']['table'] = 'field_data_field_social_network_type';
  $handler->display->display_options['fields']['field_social_network_type']['field'] = 'field_social_network_type';
  $handler->display->display_options['fields']['field_social_network_type']['label'] = 'network';
  $handler->display->display_options['fields']['field_social_network_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_social_network_type']['alter']['text'] = '[field_social_network_type-value]';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_social_networks_node';
  $handler->display->display_options['fields']['title']['label'] = 'name';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_social_networks_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Domain Access: Domain ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'domain_access';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'field_social_networks_node';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'current_domain';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Field collection item: Account URL (field_social_network_account) */
  $handler->display->display_options['filters']['field_social_network_account_value']['id'] = 'field_social_network_account_value';
  $handler->display->display_options['filters']['field_social_network_account_value']['table'] = 'field_data_field_social_network_account';
  $handler->display->display_options['filters']['field_social_network_account_value']['field'] = 'field_social_network_account_value';
  $handler->display->display_options['filters']['field_social_network_account_value']['operator'] = 'not empty';
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_social_networks' => 'field_social_networks',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_json';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'js/json/social-stream';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_json';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field collection item: Entity with the Social Networks (field_social_networks) */
  $handler->display->display_options['relationships']['field_social_networks_bean']['id'] = 'field_social_networks_bean';
  $handler->display->display_options['relationships']['field_social_networks_bean']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_social_networks_bean']['field'] = 'field_social_networks_bean';
  $handler->display->display_options['relationships']['field_social_networks_bean']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Block: Internal, numeric block ID */
  $handler->display->display_options['arguments']['bid']['id'] = 'bid';
  $handler->display->display_options['arguments']['bid']['table'] = 'bean';
  $handler->display->display_options['arguments']['bid']['field'] = 'bid';
  $handler->display->display_options['arguments']['bid']['relationship'] = 'field_social_networks_bean';
  $handler->display->display_options['arguments']['bid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['bid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['bid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['bid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['bid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Domain Access: Domain ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'domain_access';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'field_social_networks_node';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'current_domain';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'js/json/social-stream-block';
  $export['social_stream_networks'] = $view;

  return $export;
}
