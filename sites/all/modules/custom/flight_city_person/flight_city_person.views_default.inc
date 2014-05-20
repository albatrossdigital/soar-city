<?php
/**
 * @file
 * flight_city_person.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function flight_city_person_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'people';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'People';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'People';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_person_category',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Category (field_person_category) */
  $handler->display->display_options['relationships']['field_person_category_tid']['id'] = 'field_person_category_tid';
  $handler->display->display_options['relationships']['field_person_category_tid']['table'] = 'field_data_field_person_category';
  $handler->display->display_options['relationships']['field_person_category_tid']['field'] = 'field_person_category_tid';
  $handler->display->display_options['relationships']['field_person_category_tid']['label'] = 'Category';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_person_category']['id'] = 'field_person_category';
  $handler->display->display_options['fields']['field_person_category']['table'] = 'field_data_field_person_category';
  $handler->display->display_options['fields']['field_person_category']['field'] = 'field_person_category';
  $handler->display->display_options['fields']['field_person_category']['label'] = '';
  $handler->display->display_options['fields']['field_person_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_person_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_person_category']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Rendered Node */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_person_category_tid';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Contextual filter: Content: Category (field_person_category) */
  $handler->display->display_options['arguments']['field_person_category_tid']['id'] = 'field_person_category_tid';
  $handler->display->display_options['arguments']['field_person_category_tid']['table'] = 'field_data_field_person_category';
  $handler->display->display_options['arguments']['field_person_category_tid']['field'] = 'field_person_category_tid';
  $handler->display->display_options['arguments']['field_person_category_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_person_category_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_person_category_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_person_category_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_person_category_tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['field_person_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_person_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_person_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_person_category_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_person_category_tid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_person_category_tid']['validate_options']['code'] = 'if (empty($argument)) {
  return FALSE;
}
$arguments = explode(\'+\', check_plain(str_replace(\'-\', \' \', $argument)));
$handler->value = $arguments;
$handler->validated_title = ucwords($arguments[0]);
$handler->operator = \'or\';
foreach ($handler->value as $term_name) {
  foreach (taxonomy_get_term_by_name($term_name) as $term) {
    if ($term && (empty($vocabularies) || isset($vocabularies[$term->vocabulary_machine_name]))) {
      $tids[] = $term->tid;
      $term_names[] = $term->name;
      $this->argument->argument = implode(\'+\', $tids);
    }
  }
}
return TRUE;';
  $handler->display->display_options['arguments']['field_person_category_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Domain Access: Domain ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'domain_access';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'current_domain';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'numeric';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'people/%';

  /* Display: Page with no grouping */
  $handler = $view->new_display('page', 'Page with no grouping', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'people-list/%';
  $export['people'] = $view;

  return $export;
}
