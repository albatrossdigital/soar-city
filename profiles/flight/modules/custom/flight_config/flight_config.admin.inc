<?php

/**
 * @file
 * Functionality and helper functions for CAPTCHA administration.
 */


/**
 * Form builder function for the general configuration
 */
function flight_config_admin_settings() {

  $form['domain_path'] = array(
    '#type' => 'fieldset',
    '#title' => t('Domain path'),
  );
  $options = array();
  foreach(node_type_get_types() as $type) {
    $options[$type->type] = $type->name;
  }
  $form['domain_path']['domain_paths'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types to force domain_path pathauto'),
    '#description' => t('Check the content types that should force domain_path usage when pathauto is enabled. This allows you to use the /about path multiple times, for instance.'),
    '#options' => $options,
    '#default_value' => variable_get('flight_config_domain_paths', array()), 
  );

  // Submit button.
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Submission function for captcha_admin_settings form.
 */
function flight_config_admin_settings_submit($form, &$form_state) {
  variable_set('flight_config_domain_paths', $form_state['values']['domain_paths']);
  drupal_set_message(t('Your settings have been saved.'), 'status');
}


