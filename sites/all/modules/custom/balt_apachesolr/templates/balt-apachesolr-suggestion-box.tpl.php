<?php if($hide_show): ?>
  <div class="hide-show-wrapper">
<?php endif; ?>
<h5><?php print $title_text; ?>&nbsp;&nbsp;
<?php if($hide_show): ?>
  <a class="hide-show-toggle"><i class="fa-plus-square-o"></i><?php print $hide_show_text; ?></a>
<?php endif; ?>
</h5>
<?php if($hide_show): ?>
  <div class="hide-show-content">
<?php endif; ?>
<?php if($additional_text): ?>
<?php print $additional_text; ?>
<?php endif; ?>
<?php if($hide_show): ?>
  </div></div>
<?php endif; ?>