<?php
/**
 * Implements hook_rules_action_info().
 */
function flight_city_workbench_rules_action_info() {
  $items = array();
  $items['flight_city_workbench_approvers'] = array(
    'label' => t('Get approvers'),
    'group' => t('Flight Workbench'),
    'parameter' => array(
      'node' => array('type' => 'node', 'label' => t('Node')),
      'rid' => array('type' => 'integer', 'label' => t('Role rid')),
    ),
    'provides' => array(
      'approvers' => array('type' => 'list<user>', 'label' => t('List of approvers')),
    ),
  );
  $items['flight_city_workbench_moderation_load_current_revision'] = array(
    'label' => t("Load current node revision"),
    'group' => t("Flight Workbench"),
    'base' => 'flight_city_workbench_moderation_load_current_revision_rules_action',

    'parameter' => array(
      'node' => array(
        'type' => 'node',
        'label' => t("Content"),
      ),
    ),
    'provides' => array(
      'node_revision' => array(
        'type' => 'node',
        'label' => t("Current node revision"),
      ),
      'revision_author' => array(
        'type' => 'user',
        'label' => t("Current node revision author"),
      ),
    ),
  );
  return $items;
}

  


/**
 * Action: Loads the current node revision.
 *
 * $param $node
 *   A node object
 *
 * @return
 *   A loaded node revision.
 */
function flight_city_workbench_moderation_load_current_revision_rules_action($node) {
  $node_revision = workbench_moderation_node_current_load($node);
  $revision_author = user_load($node_revision->workbench_moderation['current']->uid);
  dpm($node_revision);
  dpm($node);
  return array(
    'node' => $node, 
    'node_revision' => $node_revision, 
    'revision_author' => $revision_author
  );
}


/**
 * Action: Gets the approvers that should receive an email for a given post.
 *
 * @return
 *   A loaded node revision.
 */
function flight_city_workbench_approvers($node, $rid){
  $keys = array_keys($node->workbench_access);
  $uids = workbench_access_get_section_users_by_account('taxonomy', $keys[0], array($rid));
  $approvers = array();
  foreach($uids as $uid => $name){
    $approvers[] = user_load($uid);
  }
  if (empty($approvers)) {
    $view = flight_config_view_data('flight_workbench_users');
    foreach($view as $row){
      $approvers[] = user_load($row->uid);
    }
  }
  return array('approvers' => $approvers);
}