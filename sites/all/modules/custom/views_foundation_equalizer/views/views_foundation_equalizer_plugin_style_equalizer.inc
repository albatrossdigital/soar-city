<?php
/**
 * @file
 * Views Foundation Eqaulizer plugin.
 *
 * @see http://foundation.zurb.com/docs/components/equalizer.html
 */

/**
 * Style plugin to render rows in a Foundation Clearing plugin.
 *
 * @ingroup views_style_plugins
 */
class views_foundation_equalizer_plugin_style_equalizer extends views_plugin_style {

  /**
   * Set default options.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['equalizer_on_row'] = array('default' => TRUE, 'bool' => TRUE);
    $options['row_wrapper_class'] = array('default' => 'row');
    $options['items_per_row'] = array('default' => '2');

    return $options;
  }

  /**
   * Provide a form for setting options.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['equalizer_on_row'] = array(
      '#title' => t('Put equalizer data on row?'),
      '#description' => t('If unchecked, "data-equalizer-watch" must put on some internal element.'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['equalizer_on_row'],
    );

    $form['row_wrapper_class'] = array(
      '#title' => t('Class for each row wrapper'),
      '#description' => t('This is the div that contains the "data-equalizer" attribute.'),
      '#type' => 'textfield',
      '#default_value' => $this->options['row_wrapper_class'],
    );

    $form['items_per_row'] = array(
      '#title' => t('Items per row'),
      '#description' => t('If unchecked, "data-equalizer-watch" must put on some internal element.'),
      '#type' => 'textfield',
      '#default_value' => $this->options['items_per_row'],
    );
  }

}
