<?php

/**
 * @file
 * Functionality and helper functions for CAPTCHA administration.
 */


/**
 * Form builder function for the general configuration
 */
function flight_city_workbench_admin_settings() {
  $content_types = array();
  foreach(node_type_get_types() as $type) {
    $content_types[$type->type] = $type->name;
  }

  $form['domain_path'] = array(
    '#type' => 'fieldset',
    '#title' => t('Domain path'),
  );
  $form['domain_path']['domain_path_bundles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types to force domain_path pathauto'),
    '#description' => t('Check the content types that should force domain_path usage when pathauto is enabled. This allows you to use the /about path multiple times, for instance.'),
    '#options' => $content_types,
    '#default_value' => variable_get('flight_city_workbench_domain_paths', array()), 
  );

  $form['promote'] = array(
    '#type' => 'fieldset',
    '#title' => t('Promote to citywide site'),
  );
  $form['promote_nodes']['promote_bundles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types that can be promoted'),
    '#description' => t('Check the content types that can be promoted to the home page.  All other content types that can be flagged to be promoted will just send send an email informing the super editor that this content should be featured in a home page block.'),
    '#options' => $content_types,
    '#default_value' => variable_get('flight_city_workbench_domain_paths', array()), 
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
function flight_city_workbench_admin_settings_submit($form, &$form_state) {
  variable_set('flight_city_workbench_domain_path_bundles', $form_state['values']['domain_path_bundles']);
  drupal_set_message(t('Your settings have been saved.'), 'status');
}


