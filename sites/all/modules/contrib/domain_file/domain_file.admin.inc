<?php

/**
 * FormAPI to set default domain settings for files.
 */
function domain_file_defaults_form($form, &$form_state) {
  $form = array();

  $options = array(DOMAIN_ALL => t('All domains'), DOMAIN_ACTIVE => t('Author\'s currently active domain'));
  foreach (domain_domains() as $key => $value) {
    $options[$value['machine_name']] = $value['sitename'];
  }

  foreach ($options as $key => $value) {
    $form['#file_defaults'][$key] = $value;
  }

  $default_values = domain_file_default_access_settings();
  $form['domain_file_defaults'] = array(
    '#type' => 'checkboxes',
    '#tree' => TRUE,
    '#options' => $options,
    '#default_value' => $default_values,
  );

  $form = system_settings_form($form);
  return $form;
}
