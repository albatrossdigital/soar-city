<?php

/**
 * Implements template_preprocess_html().
 *
 */
function flight_city_preprocess_html(&$vars) {

  // Need legacy support for IE downgrade to Foundation 2 or use JS file below
  /*drupal_add_js('//use.typekit.net/tyn0pry.js', array(
    'type' => 'external',
    'scope' => 'header',
    'weight' => 0,
  ));
  drupal_add_js('try{Typekit.load();}catch(e){}', array(
    'type' => 'inline',
    'scope' => 'header',
    'weight' => 1,
  ));*/
  drupal_add_js(drupal_get_path('theme', 'flight_city') . '/js/vendor/rem.js', array(
    'type' => 'file',
    'scope' => 'footer'
  ));
}


/**
 * Implements template_preprocess_page
 *
 */
function _flight_city_active_menu_parent() {
  // using active menu
  $trail = menu_get_active_trail();
  //we're on a child
  if(isset($trail[1])) {
    if($trail[1]['menu_name'] == 'main-menu') {
      return $trail[1]['link_title'];
    }
  }
  return FALSE;
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
    $current_domain = domain_get_domain();
    // Main top level domain
    if($current_domain['is_default']) {

      // If there is an override use it
      if($vars['section_title']) {
        $vars['entity_title'] = $vars['section_title'];
        $vars['section_title'] = FALSE;
      }
      // else use menu item if available
      else {
        $vars['entity_title'] = ($menu_title = _flight_city_active_menu_parent())
         ? $menu_title : FALSE;
      }
    }
    // Nothing set, so set to site name
    if(empty($vars['entity_title'])) {
      $vars['entity_title'] = $vars['site_name'];
    }
  }

  // Set logo to link default
  // @TODO be smarter about this
  //$default_domain = domain_default(FALSE, FALSE);
  $vars['linked_logo'] = l($vars['logo_img'], 'http://www.baltimore.ifsight.com'/* . $default_domain['subdomain']*/,
    array(
      'html' => TRUE,
      'external' => TRUE
    )
  );

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
    $vars['main_grid'] = 'medium-8';
    $vars['sidebar_first_grid'] = '';
    $vars['sidebar_sec_grid'] = 'medium-3';
  } elseif (!empty($left) && empty($right)) {
    $vars['main_grid'] = 'medium-8 medium-push-3';
    $vars['sidebar_first_grid'] = 'medium-3 medium-pull-9';
    $vars['sidebar_sec_grid'] = '';
  } else {
    $vars['main_grid'] = 'medium-12';
    $vars['sidebar_first_grid'] = '';
    $vars['sidebar_sec_grid'] = '';
  }
}

/**
 * Replacement theme callback for theme('breadcrumb').
 *
 * @param $variables
 * @return string
 *   Rendered breadcrumb HTML
 */
function flight_city_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (empty($breadcrumb)) {
    return;
  }

  // These settings may be missing, if theme('breadcrumb') is called from
  // somewhere outside of Crumbs, or if another module is messing with the theme
  // registry.
  $variables += array(
    'crumbs_trailing_separator' => FALSE,
    'crumbs_separator' => ' &raquo; ',
    'crumbs_separator_span' => FALSE,
  );

  $separator = $variables['crumbs_separator'];
  if ($variables['crumbs_separator_span']) {
    $separator = '<span class="crumbs-separator">' . $separator . '</span>';
  }

  $token = urlencode('<firstchild>');
  $active_trail = menu_get_active_trail();
  foreach($breadcrumb as $k => $v) {
    if (FALSE !== strpos($v, $token)) {
      $breadcrumb[$k] = str_replace($token, drupal_get_path_alias($active_trail[$k]['href']), $v);
    }
  }

  $output = implode('</li><li>' . $separator, $breadcrumb);
  if ($variables['crumbs_trailing_separator']) {
    $output .= $separator;
  }

  $output = '<ul class="breadcrumbs"><li>' . $output . '</li></ul>';

  // Provide a navigational heading to give context for breadcrumb links to
  // screen-reader users. Make the heading invisible with .element-invisible.
  return '<h2 class="element-invisible">' . t('You are here') . '</h2>' . $output;
}

/**
 * Implements template_preprocess_node
 *
 */
//function flight_city_preprocess_node(&$variables) {
//}


//
function _flight_city_child_menu_back_button($menu_item) {
  $menu_item['#below'] = array();
  $menu_item['#attributes'] = array(
    'data-menu-back' => $menu_item['#original_link']['depth'] - 1
  );
  $set_zero = array(
    'has_children', 'plid', 'mlid', 'p1', 'p2', 'p3', 'p4', 'p5', 'p6'
  );
  foreach ($set_zero as  $value) {
    $menu_item['#original_link'][$value] = 0;
  }
  $menu_item['#title'] = 'Back';
  return $menu_item;
}

function _flight_city_child_menu_recurse($current_menu, &$menus, &$active, $parent = FALSE) {
  $count = count($menus) + 1;
  $menu_level = 'level_' . $count;

  // Add menu wrapper
  $menus[$menu_level] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => 'level-' . $count
    )
  );
  
  // We have a parent, so add back button, set title
  if($parent) {
    $menus[$menu_level]['title']['#markup'] = '<h4>' . $parent['#title'] . '</h4>';
    $menus[$menu_level]['menu'] = array(
      'back' => _flight_city_child_menu_back_button($parent)
    );
  }
  // No parent so title is main menu, init array
  else {
    $menus[$menu_level]['title']['#markup'] = '<h4>' . t('Main Menu') . '</h4>';
    $menus[$menu_level]['menu'] = array();
  }
  // run through menu items
  foreach($current_menu as $key => $value) {
    $menus[$menu_level]['menu'][$key] = $value;
    if(is_array($value)) {

      // children
      $children = !empty($value['#below']);

      // active item, record level
      if(!empty($value['#attributes']) && in_array('active', $value['#attributes']['class'])) {
        $active = ($children) ? $value['#original_link']['depth'] : $value['#original_link']['depth'] - 1;
      }
      // we have children, so recurse
      if($children) {
        _flight_city_child_menu_recurse($value['#below'], $menus, $active, $value);
        $menus[$menu_level]['menu'][$key]['#below'] = array();
      }
      // End of the line
      else {
        // Check for active trails on last level
        $active_trail = !empty($value['#attributes']) && in_array('active-trail', $value['#attributes']['class']);
        if(empty($active) && $active_trail) {
          $active = ($children) ? $value['#original_link']['depth'] : $value['#original_link']['depth'] - 1;
        }
      }
    }
  }
}


/**
 * Implements hook_preprocess_menu_block_wrapper()
 */
function flight_city_preprocess_menu_block_wrapper(&$vars) {
  if($vars['delta'] == 'main-menu') {
    //dpm($vars);
    // Set variables
    $menus = array();
    $active = 0;
    // Recurse through menu, adding all children menus as children
    _flight_city_child_menu_recurse($vars['content'], $menus, $active);
    //dpm($menus);
    if(!empty($menus)) {
      $number = count($menus);
      $vars['content'] = $menus;
      $vars['classes_array'][] = 'level_' . $active;
    }
  }
}

/**
 * Implements hook_preprocess_block_()
 */
function flight_city_preprocess_block(&$vars) {
  
  if($vars['block']->delta == 'gtranslate') {
    // Pulling out all flag links, scripts
    $matches = preg_split('~(<a.*</a>)~is', $vars['content'], NULL, PREG_SPLIT_DELIM_CAPTURE);
    // we have matches
    if(count($matches) === 3) {
      // This is all script info
      $vars['content'] = $matches[0]; 
      // Link attributes
      $attributes =  array(
        'html' => TRUE,
        'attributes' => array(
          'data-options' => 'align:left',
          'data-dropdown' => 'transDrop',
        )
      );
      $vars['content'] .= l(t('Translate') . ' <i class="fa-caret-down"></i>', '/', $attributes) . '<br/>';
      $vars['content'] .= '<div id="transDrop" data-dropdown-content class="f-dropdown content">';
      // All links
      $vars['content'] .= $matches[1] . '</div>';
    }
  }
}


/**
 * Implements hook_preprocess_block_()
 */
function flight_city_preprocess_search_result(&$vars) {

  if(isset($result['entity_type'])) {
    $vars['classes_array'][] = 'entity-' . $result['entity_type'];
  }
  if(isset($result['bundle'])) {
    $vars['classes_array'][] = 'bundle-' . $result['bundle'];
  }
}



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
 * Implements hook_preprocess_textfield().
 */
function flight_city_preprocess_form_element(&$vars) {

  // add placeholder text if applicable
  if(!empty($vars['element']['#type'])) {
    switch ($vars['element']['#type']) {
      case 'textfield':
      case 'textarea':
      case 'webform_email':

        if (!empty($vars['element']['#title'])) {
          $placeholder = array('placeholder' => t($vars['element']['#title']));
          if (is_array($vars['element']['#attributes'])) {
            $vars['element']['#attributes'] = array_merge($vars['element']['#attributes'], $placeholder);
          }
          else {
            $vars['element']['#attributes'] = $placeholder;
          }
        }
        break;
    }
  }
  // if autocopmplete add spinner
  if(!empty($vars['element']['#autocomplete_path'])) {
    //$prefix = '<span class='form-autocomplete-wrap"></span>';
    $suffix = '<span class="form-autocomplete-wrap"><span class="spinner"></span></span>';
    //$vars['element']['#field_prefix'] = isset($vars['element']['#field_prefix']) ? $prefix . $vars['element']['#field_prefix'] : $prefix;
    $vars['element']['#field_suffix'] = isset($vars['element']['#field_suffix']) ? $suffix . $vars['element']['#field_suffix'] : $suffix;
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
function flight_city_css_alter(&$css) {

  $auto_complete = drupal_get_path('module', 'apachesolr_autocomplete');
  $unset = array(
    $auto_complete . '/jquery-autocomplete/jquery.autocomplete.css',
    $auto_complete . '/apachesolr_autocomplete.css'
  );
  foreach($unset as $path) {
    if(isset($css[$path])) {
      unset($css[$path]);
    }
  }
}

/**
 * Implements hook_js_alter().
 */
function flight_city_js_alter(&$js) {
  $auto_complete = drupal_get_path('module', 'apachesolr_autocomplete');
  $unset = array(
    $auto_complete . '/apachesolr_autocomplete.js'
  );
  foreach($unset as $path) {
    if(isset($js[$path])) {
      unset($js[$path]);
    }
  }
}
