<?php

/**
 * @file
 * Theme functions for the Facet API module.
 */

/**
 * Returns HTML for an inactive facet item.
 */
function template_preprocess_balt_apachesolr_suggestion_box(&$variables) {
  $active = $variables['active-item'];
  $variables['additional_text'] = '';
  if(isset($active)) {
    foreach ($variables['items'] as $item) {
      if($item['data']['active']) {
        $text = $item['data']['text'];
        $item['data']['text'] = t('entire site');
        $variables['title_text'] = t('You\'re searching within the !site', array(
          '!site' => '<strong>' . $text . '</strong>',
        ));
        $variables['additional_text'] = t('Expand your search to the !expand.', array(
          '!expand' => theme_link($item['data']),
        ));
        break;
      }
    }
  }
  else {
    $variables['title_text'] = t('You\'re searching the !site.  Filter by subsite:', array(
      '!site' => '<strong>full site</strong>',
    ));
    foreach($variables['items'] as &$item) {
      $item['data'] = theme_link($item['data']);
    }
    $variables['additional_text'] = theme('item_list', $variables);
  }
}


/**
 * Returns HTML for an inactive facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', 'options', and
 *   'count'. See the l() and theme_facetapi_count() functions for information
 *   about these variables.
 *
 * @ingroup themeable
 */
function theme_balt_facetapi_link_inactive($variables) {
  // Builds accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => FALSE,
  );
  $accessible_markup = theme('facetapi_accessible_markup', $accessible_vars);

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $variables['text'] = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Adds count to link if one was passed.
  if (isset($variables['count'])) {
    $variables['count'] = theme('facetapi_count', $variables);
  }

  // Resets link text, sets to options to HTML since we already sanitized the
  // link text and are providing additional markup for accessibility.
  $variables['text'] .= $accessible_markup;
  $variables['options']['html'] = TRUE;
  $variables['active'] = FALSE;
  return $variables;
}

/**
 * Returns HTML for an inactive facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @see l()
 *
 * @ingroup themeable
 */
function theme_balt_facetapi_link_active($variables) {
  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
  );
  $variables['remove_text'] = t('!facetapi_accessible_markup', $replacements);
  $variables['options']['html'] = TRUE;
  $variables['active'] = TRUE;
  return $variables;
}


/**
 * Themes each returned suggestion.
 */
function theme_balt_apachesolr_answers_autocomplete($vars) {
  $html = '';
  $html .= '<div class="balt_apachesolr_autocomplete suggestion">';
  $html .= '<span class="suggest-title label secondary">' . t('Answer') . '</span>';
  $html .= $vars['title'];
  $html .= '</div>';
  return $html;
}