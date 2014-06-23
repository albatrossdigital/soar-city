<?php
/**
 * @file
 * baltimore_govdelivery.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function baltimore_govdelivery_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'govdelivery_subscribe_link';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Govdelivery Subscribe Link';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<a href="/subscribe" title="Subscribe to our mailing list with GovDelivery">Subscribe <i class="fa-envelope-o icon-right"></i></a>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Field collection item: Entity with the Social Networks (field_social_networks) */
  $handler->display->display_options['relationships']['field_social_networks_node']['id'] = 'field_social_networks_node';
  $handler->display->display_options['relationships']['field_social_networks_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_social_networks_node']['field'] = 'field_social_networks_node';
  $handler->display->display_options['relationships']['field_social_networks_node']['required'] = TRUE;
  /* Field: Field collection item: Account URL */
  $handler->display->display_options['fields']['field_social_network_account']['id'] = 'field_social_network_account';
  $handler->display->display_options['fields']['field_social_network_account']['table'] = 'field_data_field_social_network_account';
  $handler->display->display_options['fields']['field_social_network_account']['field'] = 'field_social_network_account';
  $handler->display->display_options['fields']['field_social_network_account']['label'] = '';
  $handler->display->display_options['fields']['field_social_network_account']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_social_network_account']['alter']['text'] = 'Subscribe <i class="fa-envelope-o icon-right"></i>';
  $handler->display->display_options['fields']['field_social_network_account']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_social_network_account']['alter']['path'] = 'subscribe/[field_social_network_account]';
  $handler->display->display_options['fields']['field_social_network_account']['alter']['alt'] = 'Subscribe to our mailing list with GovDelivery';
  $handler->display->display_options['fields']['field_social_network_account']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Field collection item: Network (field_social_network_type) */
  $handler->display->display_options['filters']['field_social_network_type_value']['id'] = 'field_social_network_type_value';
  $handler->display->display_options['filters']['field_social_network_type_value']['table'] = 'field_data_field_social_network_type';
  $handler->display->display_options['filters']['field_social_network_type_value']['field'] = 'field_social_network_type_value';
  $handler->display->display_options['filters']['field_social_network_type_value']['value'] = array(
    'govdelivery' => 'govdelivery',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['govdelivery_subscribe_link'] = $view;

  return $export;
}
