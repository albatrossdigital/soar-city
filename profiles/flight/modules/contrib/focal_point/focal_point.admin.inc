<?php

/**
 * @file
 * Functionality needed by the focal point admin pages.
 */

/**
 * System form for focal point configuration settings.
 */
function focal_point_configuration_form($form, &$form_state) {
  if (module_exists('smartcrop')) {
    $form['focal_point_use_smart_crop'] = array(
      '#type' => 'checkbox',
      '#title' => 'Use smart crop to calculate the initial focal point',
      '#descrition' => t('This can slow down your site, especially if you are bulk uploading images.'),
      '#default_value' => variable_get('focal_point_use_smart_crop', '0'),
    );
  }

  $options = array(
    'image' => t('Standard image fields'),
    'media' => t('Media module image fields'),
  );
  $form['focal_point_enabled_for'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Enable focal point for the following:',
    '#options' => $options, // @todo: consider allowing this to be altered
    '#default_value' => variable_get('focal_point_enabled_for', array_keys($options)),
  );
  $form['focal_point_test_drive_link'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Take a test drive'), 'focal_point/test-drive'),
  );

  return system_settings_form($form);
}

/**
 * Form builder for the "test drive" page.
 */
function focal_point_test_drive_form($form, &$form_state) {
  $fid = variable_get('focal_point_test_drive_image', NULL);
  $file = !is_null($fid) ? file_load($fid) : NULL;
  $focal_point = variable_get('focal_point_test_drive_focal_point', FOCAL_POINT_DEFAULT);

  if (!empty($fid) && $file) {
    // Display the image and include the focal point indicator and field.
    $form['test_drive_image'] = array(
      '#theme_wrappers' => array('container'),
      'test_drive_indicator' => _focal_point_indicator('test-drive'),
      'test_drive_widget_image' => array(
        '#type' => 'markup',
        '#theme' => 'image_style',
        '#style_name' => 'focal_point_preview',
        '#path' => $file->uri,
      ),
      'focal_point_test_drive_focal_point' => _focal_point_field('test-drive', 0, $focal_point),
    );
  }

  $form['test_drive_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Set the focal point'),
  );

  $form['examples'] = _focal_point_preview($fid, $focal_point);
  $form['#submit'][] = 'focal_point_test_drive_form_submit';

  return $form;
}

/**
 * Form submit handler for focal_point_test_drive_form().
 *
 * @see focal_point_test_drive_form().
 */
function focal_point_test_drive_form_submit(&$form, &$form_state) {
  // Save the test drive focal point setting.
  if (isset($form_state['values']['focal_point_test_drive_focal_point'])) {
    $old_value = variable_get('focal_point_test_drive_focal_point', FOCAL_POINT_DEFAULT);
    if ($old_value !== $form_state['values']['focal_point_test_drive_focal_point']) {
      variable_set('focal_point_test_drive_focal_point', $form_state['values']['focal_point_test_drive_focal_point']);

      // Delete old derivative images since the focal point changed.
      $fid = variable_get('focal_point_test_drive_image', NULL);
      $file = !is_null($fid) ? file_load($fid) : NULL;
      if ($file) {
        image_path_flush($file->uri);
      }
    }
  }
}

/**
 * Page callback function to display a preview of derivative images for the
 * given file.
 *
 * @param int $fid
 *
 * @param string $focal_point
 *   (Optional) A string in the form 'left-percent-offset, top-percent-offset'.
 *   Leave this value empty to use the value stored in the database.
 *
 * @return array
 *
 * @see hook_focal_point_crop_data_alter().
 */
function focal_point_preview_page($fid, $focal_point = '') {
  $file = is_numeric($fid) ? file_load($fid) : NULL;

  if ($file && focal_point_validate($focal_point)) {
    // Get the render array for the preview.
    $output = _focal_point_preview($fid, $focal_point);

    // Clear the existing derivative images if they exist.
    image_path_flush($file->uri);
  }
  else {
    drupal_set_message(t('Invalid request. The preview images could not be displayed.'), 'error');
    $output = array();
  }

  return $output;
}
