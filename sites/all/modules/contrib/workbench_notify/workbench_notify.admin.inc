<?php

/**
 * @file
 * Workbench Notify settings form.
 */


/**
 * Workbench Notify settings form.
 */
function workbench_notify_settings() {

  $form = array();
  $form['help'] = array(
    '#markup' => '<h2>' . t('Workbench Notify settings') . '</h2>',
  );

  $form['help']['#markup'] .= '<p>' . t('Workbench Notify enables to automatically notify the editors as previously specified and individually defined in the Workbench Access\'s section <a href="!url1">Editorial assignments by editor</a> or defined by their role in the Workbench Access\'s section <a href="!url2">Editorial assignments by role</a>, on a transition state set in Workbench Moderation. Notifications will be sent only to the editors (or users) whose roles are configured accordingly in this settings.', array('!url1' => url('admin/config/workbench/access'), '!url2' => url('admin/config/workbench/access/roles'))) . '</p>';

  $transitions = workbench_moderation_transitions();
  $transition_state = array();
  foreach ($transitions as $transition) {
    $transition_state[$transition->from_name . ',' . $transition->to_name] = $transition->from_name . ' --> ' . $transition->to_name;
  }

  $form['workbench_notify_transition_state'] = array(
    '#type' => 'radios',
    '#title' => t('Transition state'),
    '#default_value' => variable_get('workbench_notify_transition_state', array()),
    '#options' => $transition_state,
    '#description' => t('Select the transition states for which you want to enable automatic sending of notifications'),

  );

  $form['workbench_notify_roles'] = array(
    '#title' => t('Roles'),
    '#type' => 'checkboxes',
    '#description' => t('Select the roles for which the editors will be notified on the transition state set above. This setting only affects the editors as previously specified and individually defined in the Workbench Access\'s menu <a href="!url1">Editorial assignments by editor</a>. The editors defined by their role in the Workbench Access\'s menu <a href="!url2">Editorial assignments by role</a> will always be notified.', array('!url1' => url('admin/config/workbench/access'), '!url2' => url('admin/config/workbench/access/roles'))),
    '#default_value' => variable_get('workbench_notify_roles', array()),
    '#options' => user_roles(TRUE),
  );

  $form['workbench_notify_from'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('workbench_notify_from', ''),
    '#description' => t("The mail's from address. Leave it empty to use the site-wide configured address."),
    '#title' => t('From'),
    '#maxlength' => 255,
  );

  $form['workbench_notify_subject'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('workbench_notify_subject', t('A new content need reviews')),
    '#description' => t("The mail's subject."),
    '#title' => t('Subject'),
    '#maxlength' => 255,
    '#required' => TRUE,
  );

  $form['workbench_notify_message'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('workbench_notify_message', t('[node:author] had submit a new content [node:title] wich need review before to be published. <br />the article is available from the following address. <br />[node:url]')),
    '#title' => t('Message'),
    '#description' => t("The mail's message body."),
    '#size' => 30,
    '#required' => TRUE,
  );

  $form['workbench_notify_display_message'] = array(
    '#type' => 'checkbox',
    '#title' => t('Confirmation to the user'),
    '#return_value' => 1,
    '#default_value' => variable_get('workbench_notify_display_message', 0),
    '#description' => t("Display a message on the site wich confirm sending notifications with the names of editors who have been notified."),
  );

  $form['#tree'] = TRUE;

  $form['token_set'] = array(
    '#type' => 'fieldset',
    '#title' => t('Available Tokens'),
    '#collapsible' => TRUE,
  );

  $form['token_set']['tokens'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('node', 'user'),
    '#click_insert' => TRUE,
  );

  return system_settings_form($form);
}
