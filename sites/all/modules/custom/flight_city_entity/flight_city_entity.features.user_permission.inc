<?php
/**
 * @file
 * flight_city_entity.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function flight_city_entity_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create entity content'.
  $permissions['create entity content'] = array(
    'name' => 'create entity content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any entity content'.
  $permissions['delete any entity content'] = array(
    'name' => 'delete any entity content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own entity content'.
  $permissions['delete own entity content'] = array(
    'name' => 'delete own entity content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any entity content'.
  $permissions['edit any entity content'] = array(
    'name' => 'edit any entity content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own entity content'.
  $permissions['edit own entity content'] = array(
    'name' => 'edit own entity content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'update entity content on assigned domains'.
  $permissions['update entity content on assigned domains'] = array(
    'name' => 'update entity content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  return $permissions;
}
