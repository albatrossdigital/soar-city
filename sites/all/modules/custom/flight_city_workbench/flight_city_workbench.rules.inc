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
  return $items;
}


function flight_city_workbench_approvers($node, $rid){
  $keys = array_keys($node->workbench_access);
  $uids = workbench_access_get_section_users_by_account('taxonomy', $keys[0], array($rid));
  $approvers = array();
  foreach($uids as $uid => $name){
    $approvers[] = user_load($uid);
  }
  return array('approvers' => $approvers);
}