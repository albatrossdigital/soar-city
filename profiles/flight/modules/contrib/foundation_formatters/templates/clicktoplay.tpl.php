<div class="click-to-play<?=$additional_classes?>" id="click-to-play-wrapper-<?php print $id; ?>">
  <a href="#" data-reveal-id="click-to-play-<?php print $id; ?>">
    <?php print $placeholder; ?>
    <div class="<?php print $play_class; ?>" class=""></div>
  </a>
  <div id="click-to-play-<?php print $id; ?>" class="reveal-modal<?=$additional_classes?>" data-reveal>
    <?php print $content; ?>
  </div>
</div>