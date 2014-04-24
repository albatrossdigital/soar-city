<?php

/**
 * Implements template_preprocess_html().
 *
 */
function flight_city_preprocess_html(&$vars) {

  // Need legacy support for IE downgrade to Foundation 2 or use JS file below
  drupal_add_js('//use.typekit.net/tyn0pry.js', array(
    'type' => 'external',
    'scope' => 'header',
    'weight' => 0,
  ));
  drupal_add_js('try{Typekit.load();}catch(e){}', array(
    'type' => 'inline',
    'scope' => 'header',
    'weight' => 1,
  ));
}

/**
 * Implements template_preprocess_page
 *
 */
function flight_city_preprocess_page(&$vars) {
  // Set section title explicitly
  if(!isset($vars['section_title'])) {
    $vars['section_title'] = FALSE;
  }

  // Set section title explicitly
  if(!isset($vars['entity_title'])) {
    $vars['entity_title'] = $vars['site_name'];
  }

  // Convenience variables
  if (!empty($vars['page']['sidebar_first'])){
    $left = $vars['page']['sidebar_first'];
  }

  if (!empty($vars['page']['sidebar_second'])) {
    $right = $vars['page']['sidebar_second'];
  }

  // Dynamic sidebars
  if (!empty($left) && !empty($right)) {
    $vars['main_grid'] = 'medium-6 medium-push-3';
    $vars['sidebar_first_grid'] = 'medium-3 medium-pull-6';
    $vars['sidebar_sec_grid'] = 'medium-3';
  } elseif (empty($left) && !empty($right)) {
    $vars['main_grid'] = 'medium-9';
    $vars['sidebar_first_grid'] = '';
    $vars['sidebar_sec_grid'] = 'medium-3';
  } elseif (!empty($left) && empty($right)) {
    $vars['main_grid'] = 'medium-9 medium-push-3';
    $vars['sidebar_first_grid'] = 'medium-3 medium-pull-9';
    $vars['sidebar_sec_grid'] = '';
  } else {
    $vars['main_grid'] = 'medium-12';
    $vars['sidebar_first_grid'] = '';
    $vars['sidebar_sec_grid'] = '';
  }
}

/**
 * Implements template_preprocess_node
 *
 */
//function flight_city_preprocess_node(&$variables) {
//}

/**
 * Implements hook_preprocess_block()
 */
//function flight_city_preprocess_block(&$variables) {
//  // Add wrapping div with global class to all block content sections.
//  $variables['content_attributes_array']['class'][] = 'block-content';
//
//  // Convenience variable for classes based on block ID
//  $block_id = $variables['block']->module . '-' . $variables['block']->delta;
//
//  // Add classes based on a specific block
//  switch ($block_id) {
//    // System Navigation block
//    case 'system-navigation':
//      // Custom class for entire block
//      $variables['classes_array'][] = 'system-nav';
//      // Custom class for block title
//      $variables['title_attributes_array']['class'][] = 'system-nav-title';
//      // Wrapping div with custom class for block content
//      $variables['content_attributes_array']['class'] = 'system-nav-content';
//      break;
//
//    // User Login block
//    case 'user-login':
//      // Hide title
//      $variables['title_attributes_array']['class'][] = 'element-invisible';
//      break;
//
//    // Example of adding Foundation classes
//    case 'block-foo': // Target the block ID
//      // Set grid column or mobile classes or anything else you want.
//      $variables['classes_array'][] = 'six columns';
//      break;
//  }
//
//  // Add template suggestions for blocks from specific modules.
//  switch($variables['elements']['#block']->module) {
//    case 'menu':
//      $variables['theme_hook_suggestions'][] = 'block__nav';
//    break;
//  }
//}

//function flight_city_preprocess_views_view(&$variables) {
//}

/**
 * Implements template_preprocess_panels_pane().
 *
 */
//function flight_city_preprocess_panels_pane(&$variables) {
//}

/**
 * Implements template_preprocess_views_views_fields().
 *
 */
//function flight_city_preprocess_views_view_fields(&$variables) {
//}

/**
 * Implements theme_form_element_label()
 * Use foundation tooltips
 */
//function flight_city_form_element_label($variables) {
//  if (!empty($variables['element']['#title'])) {
//    $variables['element']['#title'] = '<span class="secondary label">' . $variables['element']['#title'] . '</span>';
//  }
//  if (!empty($variables['element']['#description'])) {
//    $variables['element']['#description'] = ' <span data-tooltip="top" class="has-tip tip-top" data-width="250" title="' . $variables['element']['#description'] . '">' . t('More information?') . '</span>';
//  }
//  return theme_form_element_label($variables);
//}

/**
 * Implements hook_preprocess_button().
 */
//function flight_city_preprocess_button(&$variables) {
//  $variables['element']['#attributes']['class'][] = 'button';
//  if (isset($variables['element']['#parents'][0]) && $variables['element']['#parents'][0] == 'submit') {
//    $variables['element']['#attributes']['class'][] = 'secondary';
//  }
//}

/**
 * Implements hook_form_alter()
 * Example of using foundation sexy buttons
 */
function flight_city_form_alter(&$form, &$form_state, $form_id) {
  // Sexy submit buttons
  if (!empty($form['actions']) && !empty($form['actions']['submit'])) {
    $classes = array('primary', 'button');
    $form['actions']['submit']['#attributes']['class'] = $classes;
  }
}

/**
 * Implements hook_form_FORM_ID_alter()
 * Example of using foundation sexy buttons on comment form
 */
//function flight_city_form_comment_form_alter(&$form, &$form_state) {
  // Sexy preview buttons
//  $classes = (is_array($form['actions']['preview']['#attributes']['class']))
//    ? $form['actions']['preview']['#attributes']['class']
//    : array();
//  $classes = array_merge($classes, array('secondary', 'button', 'radius'));
//  $form['actions']['preview']['#attributes']['class'] = $classes;
//}


/**
 * Implements template_preprocess_panels_pane().
 */
// function zurb_foundation_preprocess_panels_pane(&$variables) {
// }

/**
* Implements template_preprocess_views_views_fields().
*/
/* Delete me to enable
function THEMENAME_preprocess_views_view_fields(&$variables) {
 if ($variables['view']->name == 'nodequeue_1') {

   // Check if we have both an image and a summary
   if (isset($variables['fields']['field_image'])) {

     // If a combined field has been created, unset it and just show image
     if (isset($variables['fields']['nothing'])) {
       unset($variables['fields']['nothing']);
     }

   } elseif (isset($variables['fields']['title'])) {
     unset ($variables['fields']['title']);
   }

   // Always unset the separate summary if set
   if (isset($variables['fields']['field_summary'])) {
     unset($variables['fields']['field_summary']);
   }
 }
}

// */

/**
 * Implements hook_css_alter().
 */
//function flight_city_css_alter(&$css) {
//  // Always remove base theme CSS.
//  $theme_path = drupal_get_path('theme', 'zurb_foundation');
//
//  foreach($css as $path => $values) {
//    if(strpos($path, $theme_path) === 0) {
//      unset($css[$path]);
//    }
//  }
//}

/**
 * Implements hook_js_alter().
 */
//function flight_city_js_alter(&$js) {
//  // Always remove base theme JS.
//  $theme_path = drupal_get_path('theme', 'zurb_foundation');
//
//  foreach($js as $path => $values) {
//    if(strpos($path, $theme_path) === 0) {
//      unset($js[$path]);
//    }
//  }
//}
