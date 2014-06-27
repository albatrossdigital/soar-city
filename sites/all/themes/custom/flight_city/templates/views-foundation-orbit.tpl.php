<?php
/**
 * @file
 * View template to display a list of rows.
 *
 * Available variables:
 * - $view: The view object.
 * - $rows: The output for the rows.
 * - $captions: The output for the images captions.
 * - $title: The title of this group of rows. May be empty.
 * - $options: Orbit slider options.
 *
 * @ingroup views_templates
 */

?>

<ul id="orbit-<?php print $view->dom_id; ?>" data-orbit data-options="resume_on_mouseout:true; orbit_transition_class:transitioning; timer:true; timer_speed: 7500; bullets:false; animation:slide; slide_number:false; navigation_arrows:true;">
  <?php foreach ($rows as $id => $row): ?>
  <li>
    <?php print $row; ?>
  </li>
  <?php endforeach; ?>
</ul>
