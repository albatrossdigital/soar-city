<!--.l-header -->
  <header role="banner" class="l-header">
    <?php if ($top_bar_classes): ?>
      <div class="<?php print $top_bar_classes; ?>">
    <?php endif; ?>
    <nav class="top-bar"<?php print $top_bar_options; ?>>
      <ul class="title-area">
        <li class="name">
          <?php if ($linked_logo): print $linked_logo; endif; ?>
          <?php if ($site_name): ?>
          <div id="site-name" class="element-invisible">
            <strong>
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
            </strong>
          </div>
          <?php endif; ?>
        </li>
        <li class="toggle-off-canvas menu-toggle"><a class="right-off-canvas-toggle" href="#"><span><?php print $top_bar_menu_text; ?></span> <i class="<?php print $top_bar_menu_icon; ?>"></i></a></li>
        <li class="toggle-off-canvas search-toggle"><a id="search-toggle" class="right-off-canvas-toggle" href="#"><span><?php print t('Search'); ?></span> <i class="fa-search"></i></a></li>
      </ul>
      <aside class="right-off-canvas-menu top-bar-section">
        <?php if (!empty($page['topbar'])): ?>
          <a class="right-off-canvas-toggle" href="#"><span><?php print t('Close'); ?></span> <i class="fa-times"></i></a>
          <?php print render($page['topbar']); ?>
        <?php endif; ?>
      </aside>
    </nav>
    <?php if ($top_bar_classes): ?>
      </div>
    <?php endif; ?>

    <!--.l-header-region -->
    <section class="l-header-region row">
      <div class="medium-8 columns header-branding<?php if (empty($page['logo'])) { print ' no-logo'; } ?>">
        <?php if (!empty($page['logo'])): ?>
          <div class="region-logo">
            <?php print render($page['logo']); ?>
          </div>
        <?php endif; ?>
        <?php if($entity_title): ?>
          <div class="vertical-center"><div class="vertical-center-inner">
            <h2 id="entity-title" class="title"><?php print $entity_title; ?></h2>
          </div></div>
        <?php endif; ?>
      </div>
      <div class="medium-4 columns header-region-right">
        <?php if (!empty($page['sidebar_first'])): ?>
          <a id="toggle-main-section-menu" class="button secondary-alt small radius" href="#"><i class="fa-bars"></i><span><?php print t('Menu'); ?></span></a>
        <?php endif; ?>
        <?php print render($page['header']); ?>
      </div>
    </section>
      <!--/.l-header-region -->
  </header>
  <!--/.l-header -->