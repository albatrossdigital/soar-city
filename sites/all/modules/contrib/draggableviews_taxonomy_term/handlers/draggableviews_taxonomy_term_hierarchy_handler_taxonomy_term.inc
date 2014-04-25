<?php

/**
 * @file
 * Field API handler plugin.
 */

$plugin = array(
  'label' => 'Taxonomy term',
  'handler' => array(
    'class' => 'draggableviews_taxonomy_term_hierarchy_handler_taxonomy_term',
  ),
);

class draggableviews_taxonomy_term_hierarchy_handler_taxonomy_term extends draggableviews_hierarchy_handler {
  public function term_parent($tid) {
    $parent = db_select('taxonomy_term_hierarchy', 'h')
              ->fields('h', array('parent'))
              ->condition('tid', $tid, '=')
              ->range(0,1)
              ->execute()
              ->fetchField();
    return $parent;
  }

  public function term_depth($tid) {
    $parent = $this->term_parent($tid);
    if($parent == 0) {
      return 0;
    }else  {
      return 1+$this->term_depth($parent);
    }
  }
  
  public function get($field, $index) {
    $tid = $field->view->result[$index]->tid;
    $parent = $this->term_parent($tid);
    return $parent;
  }

  public function get_depth($field, $index) {
    $tid = $field->view->result[$index]->tid;
    $depth = $this->term_depth($tid);
    return $depth;
  }
  
  // Don't need to set value here as it is done in "weight" handler
  // draggableviews_handler in order to avoid doing multiple identical queries
  // to draggableviews_structure table.
  function set($form_state) {}
}