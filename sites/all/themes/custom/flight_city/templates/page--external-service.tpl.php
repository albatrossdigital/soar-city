<div data-offcanvas role="document" class="page off-canvas-wrap"><div class="inner-wrap">
<h1>Header</h1>
<textarea rows="30"><?php print $external_header; ?></textarea>
<h1>Footer</h1>
<textarea rows="30"><?php print $external_footer; ?></textarea>
<?php if ($messages && !$zurb_foundation_messages_modal): ?>
  <!--/.l-messages -->
  <section class="l-messages row">
    <div class="medium-12 columns">
      <?php if ($messages): print $messages; endif; ?>
    </div>
  </section>
  <!--/.l-messages -->
<?php endif; ?>
</div></div>