<?php

/**
 * @file
 * Defines a plugin for a switch facet API widget.
 */

/**
 * Widget that renders facets as a switch element.
 */
class FacetapiSwitchWidget extends FacetapiWidgetLinks {
  /**
   * Renders the facet.
   */
  public function execute() {
    // We need a separate form ID for each facet, so Drupal can distinguish
    // between multiple facets on the page. See facetapi_switch_forms().
    // Use drupal_static() because a regular static variable is buggy here for
    // some reason.
    $count = &drupal_static('FacetapiMultiSwitchWidget:execute', 0);
    $form_id = 'facetapi_switch_form_' . ++$count;
    $element = &$this->build[$this->facet['field alias']];
    $reset = $this->settings->settings['all_reset'];
    
    // we're treating a value as all or adding reset value
    if($this->value_as_all() || $reset) {
      $all_active = 1;
      $any_active = 0;
      $non_all_keys = array();
      // run through element
      foreach ($element as $key => &$e) {
        // one value is not active
        if(!$e['#active']) {
          $all_active = 0;
        }
        else {
          $any_active = 1;
        }
        // this value is designated as "all"
        if($e['#indexed_value'] == $this->settings->settings['value_as_all_val']) {
          $all_key = $this->settings->settings['value_as_all_val'];
          $e['#is_all'] = TRUE;
        }
        // all still active, so add this key to be unset
        else if($all_active) {
          $non_all_keys[] = $key;
        }
      }
      // we have an all key
      if(isset($all_key)) {
        // unset active for others if all is active
        if(!empty($non_all_keys) && $all_active) {
          foreach($non_all_keys as $key) {
            $element[$key]['#active'] = 0;
          }
        }
        $element[$all_key]['#active'] = $all_active;
      }
      if($reset) {
        $reset_key = $this->reset_key();
        $element[$reset_key] = current(array_slice($element, -1));
        $element[$reset_key]['#markup'] = $this->settings->settings['all_reset_title'];
        $element[$reset_key]['#indexed_value'] = NULL;
        $element[$reset_key]['#count'] = NULL;
        $element[$reset_key]['#item_parents'] = array();
        $element[$reset_key]['#item_children'] = array();
        $element[$reset_key]['#active'] = $any_active ? 0 : 1;
        unset($element[$reset_key]['#query']['f']);
      }
    }

    $element = drupal_get_form($form_id, $this, $element);
  }

  /**
   * Builds an array of #options for our select element.
   */
  public function buildOptions(&$element) {
    $settings = $this->settings->settings;
    $options = array();

    foreach ($element as $item) {
      if (empty($item['#item_children'])) {
        if (!$item['#active'] || ($item['#active'] && !$settings['remove_selected'])) {
          $key = $this->getOptionKey($item);
          $options[$key] = $settings['add_count'] ? $item['#markup'] . ' (' . $item['#count'] . ')' : $item['#markup'];
        }
      }
      else {
        // Recursively add any children of the item to the #options array (this
        // will result in them being placed inside optgroups).
        $options[$item['#markup']] = $this->buildOptions($item['#item_children']);
      }
    }
    return $options;
  }

  /**
   * Builds a #default_value array for our select element.
   */
  public function buildDefaultValue($element) {
    foreach ($element as $item) {
      if ($item['#active']) {
        return $this->getOptionKey($item);
      }
    }
  }

  /**
   * Returns if using empty as all values
   */
  protected function value_as_all() {
    return $this->settings->settings['value_as_all'];
  }

  /**
   * Returns if using empty as all values
   */
  public function reset_key() {
    return 'facetswitchreset';
  }

  /**
   * Returns if using empty as all values
   */
  public function value_as_all_key() {
    return drupal_encode_path($this->facet['field alias']) . ':' . $this->settings->settings['value_as_all_val'];
  }

  /**
   * Gets the key to use for an item in the select element #options array.
   */
  protected function getOptionKey($item) {
    // Set the key to the filter that will appear in the URL if this item is
    // selected. We need to do it this way (rather than using $item['#query'])
    // so that multiple selections can be combined together in the form's
    // submit handler.
    if(!isset($item['#indexed_value'])) {
      return $this->reset_key();
    }
    else {
      return drupal_encode_path($this->facet['field alias']) . ':' . $item['#indexed_value'];
    }
    
  }

  /**
   * Allows the widget to provide additional settings to the form.
   */
  function settingsForm(&$form, &$form_state) {
    $form['widget']['widget_settings']['links'][$this->id]['auto_submit'] = array(
      '#type' => 'checkbox',
      '#title' => t('Autosubmit'),
      '#description' => t('Hide submit button and submit selection automatically.'),
      '#default_value' => $this->settings->settings['auto_submit'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
    $form['widget']['widget_settings']['links'][$this->id]['switch_label'] = array(
      '#type' => 'textfield',
      '#title' => t('Label for radio switch'),
      '#description' => t('displays in the form'),
      '#default_value' => $this->settings->settings['switch_label'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
    $form['widget']['widget_settings']['links'][$this->id]['value_as_all'] = array(
      '#type' => 'checkbox',
      '#title' => t('Treat boolean optoion as all values'),
      '#description' => t('Choose option to be treated as "all values."'),
      '#default_value' => $this->settings->settings['value_as_all'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
    $form['widget']['widget_settings']['links'][$this->id]['all_reset'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add all reset option'),
      '#description' => t('Adds "All" radio.'),
      '#default_value' => $this->settings->settings['all_reset'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
    $form['widget']['widget_settings']['links'][$this->id]['all_reset_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Label for the all reset'),
      '#description' => t('Choose which value will be treatet as all'),
      '#default_value' => $this->settings->settings['all_reset_title'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
          ':input[name="all_reset"]' => array('checked' => TRUE),
        ),
      ),
    );
    $form['widget']['widget_settings']['links'][$this->id]['value_as_all_val'] = array(
      '#type' => 'textfield',
      '#title' => t('What value is treated as all'),
      '#description' => t('Choose which value will be treatet as all'),
      '#default_value' => $this->settings->settings['value_as_all_val'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
          ':input[name="value_as_all"]' => array('checked' => TRUE),
        ),
      ),
    );
    $form['widget']['widget_settings']['links'][$this->id]['submit_text'] = array(
      '#type' => 'textfield',
      '#title' => t('Submit button text'),
      '#default_value' => $this->settings->settings['submit_text'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
  }

  /**
   * Returns defaults for the settings this widget provides.
   */
  function getDefaultSettings() {
    return array(
      'auto_submit' => 0,
      'submit_text' => t('Submit'),
      'value_as_all' => 0,
      'switch_label' => '',
      'value_as_all_val' => FALSE,
      'all_reset' => TRUE,
      'all_reset_title' => t('All')
    );
  }
}
