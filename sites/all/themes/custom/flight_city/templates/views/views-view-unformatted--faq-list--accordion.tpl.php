<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
$nid = $_GET['nid'];
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

<dl class="accordion" data-accordion="faq" id="faq">

<?php foreach ($rows as $id => $row): ?>
  <?php $active = ((empty($nid) && $id == 0) || strpos($row, '#nid-'.$nid) !== FALSE) ? ' active' : ''; ?>
  <dd<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] . $active . '"';  } ?>>
    <?php print str_replace('class="content nid-', 'class="content'. $active .'" id="nid-', $row); ?>
  </dd>
<?php endforeach; ?>

</dl>
