<?php
/**
 * @file
 * Toolbar module integration.
 */

/**
 * Implements hook_admin_select_info() on behalf of toolbar.module.
 */
function toolbar_admin_select_info() {
  $info = array();

  $info['toolbar'] = array(
    'title' => t('Toolbar module'),
    'access arguments' => array('access toolbar'),
    'suppress callback' => 'admin_select_toolbar_suppress',
  );

  return $info;
}

/**
 * Adds a suppress callback on behalf of toolbar.module.
 *
 * @see admin_select_page_alter()
 */
function admin_select_toolbar_suppress($set = TRUE) {
  static $suppress = FALSE;
  if (!empty($set)) {
    $suppress = TRUE;
  }
  return $suppress;
}
