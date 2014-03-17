<?php
/**
 * @file
 * Toolbar module integration.
 */

/**
 * Implements hook_admin_select_info() on behalf of toolbar.module.
 */
function navbar_admin_select_info() {
  $info = array();

  $info['navbar'] = array(
    'title' => t('Navbar module'),
    'access arguments' => array('access navbar'),
    'suppress callback' => 'admin_select_navbar_suppress',
  );

  return $info;
}

/**
 * Adds a suppress callback on behalf of toolbar.module.
 *
 * @see admin_select_page_alter()
 */
function admin_select_navbar_suppress($set = TRUE) {
  static $suppress = FALSE;
  if (!empty($set)) {
    $suppress = TRUE;
  }
  return $suppress;
}
