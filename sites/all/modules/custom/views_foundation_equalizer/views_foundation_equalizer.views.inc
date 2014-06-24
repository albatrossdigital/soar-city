<?php

/**
 * @file
 * Provide the Foundation plugins definition.
 */

/**
 * Implements hook_views_plugins().
 */
function views_foundation_equalizer_views_plugins() {
  $path = drupal_get_path('module', 'views_foundation_equalizer');

  return array(
    'style' => array(
      'views_foundation_equalizer' => array(
        'title' => t('Foundation Equalizer'),
        'help' => t('Displays Content in unformatter Foundation Eqaulizer support.'),
        'handler' => 'views_foundation_equalizer_plugin_style_equalizer',
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'uses row class' => TRUE,
        'uses grouping' => TRUE,
        'type' => 'normal',
        'theme' => 'views_foundation_equalizer',
        'theme path' => $path . '/theme',
        'theme file' => 'views_foundation_equalizer.theme.inc',
      ),
    ),
  );
}
