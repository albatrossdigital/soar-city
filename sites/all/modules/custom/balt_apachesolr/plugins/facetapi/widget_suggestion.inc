<?php

/**
 * @file
 * The facetapi_suggestion widget plugin classes.
 */

/**
 * Widget that renders facets as a list of clickable checkboxes.
 *
 * This widget renders facets in the same way as FacetapiWidgetLinks but uses
 * JavaScript to transform the links into checkboxes followed by the facet.
 */
class FacetapiWidgetSuggestion extends FacetapiWidgetLinks {

  /**
   * Overrides FacetapiWidgetLinks::init().
   *
   */
  public function init() {
    parent::init();
  }

    /**
   * Overrides FacetapiWidgetLinks::settingsForm().
   */
  function settingsForm(&$form, &$form_state) {
    parent::settingsForm($form, $form_state);
  }

  /**
   * Recursive function that sets each item's theme hook.
   *
   */
  protected function setThemeHooks(array &$build) {
    foreach ($build as $value => &$item) {
      if(is_array($item)) {
        if($item['#active']) {
          $item['#theme'] = 'balt_facetapi_link_active';
          $build['#active-item'] = $value;
        }
        else {
          $item['#theme'] = 'balt_facetapi_link_inactive';
        }
        if (!empty($item['#item_children'])) {
          $this->setThemeHooks($item['#item_children']);
        }
      }
    }
    return $this;
  }

  /**
   * Implements FacetapiWidget::execute().
   *
   * Transforms the render array into something that can be themed by
   * theme_item_list().
   *
   * @see FacetapiWidgetLinks::setThemeHooks()
   * @see FacetapiWidgetLinks::buildListItems()
   */
  public function execute() {
    $element = &$this->build[$this->facet['field alias']];
    // Allow other modules to alter
    drupal_alter('balt_apachesolr_suggestion_items', $element, $this->facet['field alias']);
    $element['#active-item'] = NULL;
    // Sets each item's theme hook, builds item list.
    $this->setThemeHooks($element);
    $active = array_pop($element);
    $items = $this->buildListItems($element);
    $element = array(
      '#theme' => 'balt_apachesolr_suggestion_box',
      '#items' => $items,
      '#active-item' => $active,
      '#attributes' => $this->build['#attributes'],
    );
  }
}