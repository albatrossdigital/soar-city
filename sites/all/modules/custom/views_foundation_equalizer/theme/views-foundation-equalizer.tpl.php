<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php $i = 0; $len = count($rows); ?>
<?php foreach ($rows as $id => $row): ?>
  <? if($i % $items_per_row == 0): ?>
    <div data-equalizer<?php print $row_wrapper_class; ?>>
  <? endif; ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"'; } print $row_attribute; ?>>
    <?php print $row; ?>
  </div>
  <? if(($i % $items_per_row == ($items_per_row - 1)) || $i >= ($len - 1)): ?>
    </div>
  <? endif; ?>
  <? $i++; ?>
<?php endforeach; ?>
