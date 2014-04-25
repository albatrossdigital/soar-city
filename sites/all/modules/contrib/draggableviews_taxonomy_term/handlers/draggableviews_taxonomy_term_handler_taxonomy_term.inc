<?php

/**
 * @file
 * The taxonomy term weight handler plugin.
 */

$plugin = array(
  'label' => 'Taxonomy term',
  'handler' => array(
    'class' => 'draggableviews_taxonomy_term_handler_taxonomy_term',
  ),
);

class draggableviews_taxonomy_term_handler_taxonomy_term extends draggableviews_handler {
  public function get($field, $index) {
    $tid = $field->view->result[$index]->tid;
    $weight = db_select('taxonomy_term_data', 'd')
              ->fields('d', array('weight'))
              ->condition('tid', $tid, '=')
              ->range(0,1)
              ->execute()
              ->fetchField();
    return $weight;
  }
  
  function set($form_state) {
    foreach ($form_state['values']['draggableviews'] as $item) {
      // Make sure id is available.
      if (!isset($item['id'])) {
        continue;
      }
      $term = taxonomy_term_load($item['id']);
      if ($term->weight != $item['weight']) {
        $term->weight = $item['weight'];
        $term->parent = $item['parent'];
        taxonomy_term_save($term);
      }
    }
  }
}