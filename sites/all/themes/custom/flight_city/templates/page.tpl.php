<!--.page -->
<div data-offcanvas role="document" class="page off-canvas-wrap"><div class="inner-wrap">

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
        <li class="toggle-off-canvas menu-toggle"><a class="right-off-canvas-toggle" href="#"><span><?php print $top_bar_menu_text; ?></span> <i class="fa-bars"></i></a></li>
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
          <a id="toggle-main-section-menu" href="#"><i class="fa-angle-left"></i><span><?php print t('Sub Menu'); ?></span></a>
        <?php endif; ?>
        <?php print render($page['header']); ?>
      </div>
    </section>
      <!--/.l-header-region -->
  </header>
  <!--/.l-header -->

  <?php if (!empty($page['help']) || $breadcrumb): ?>
    <!--/.l-help -->
    <section class="l-help row">
      <div class="medium-12 columns">
        <?php if ($breadcrumb): print $breadcrumb; endif; ?>
        <?php if (!empty($page['help'])): print render($page['help']); endif; ?>
      </div>
    </section>
    <!--/.l-help -->
  <?php endif; ?>

  <?php if ($messages && !$zurb_foundation_messages_modal): ?>
    <!--/.l-messages -->
    <section class="l-messages row">
      <div class="medium-12 columns">
        <?php if ($messages): print $messages; endif; ?>
      </div>
    </section>
    <!--/.l-messages -->
  <?php endif; ?>

  <?php if (!empty($page['featured'])): ?>
    <!--/.featured -->
    <section class="l-featured row">
      <div class="medium-12 columns">
        <?php print render($page['featured']); ?>
      </div>
    </section>
    <!--/.l-featured -->
  <?php endif; ?>

  <main role="main" class="l-main off-canvas-wrap" data-offcanvas><div class="inner-wrap"><div id="dnn_ContentPane" class="row">
    <div class="<?php print $main_grid; ?> main columns">
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlight panel callout">
          <?php print render($page['highlighted']); ?>
        </div>
      <?php endif; ?>

      <a id="main-content"></a>

      <?php print render($title_prefix); ?>
      <?php if (($section_title || $title) && !$is_front): ?>
        <?php if($section_title): ?>
          <?php if(is_array($section_title)): ?>
            <?php print render($section_title); ?>
          <?php else: ?>
            <h1 id="section-title" class="title"><?php print $section_title; ?></h1>
          <?php endif; ?>
        <?php else: ?>
          <h1 id="page-title" class="title"><?php print $title; ?></h1>
        <?php endif; ?>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
        <?php if (!empty($tabs2)): print render($tabs2); endif; ?>
      <?php endif; ?>

      <?php if ($action_links): ?>
        <ul class="action-links">
          <?php print render($action_links); ?>
        </ul>
      <?php endif; ?>

      <?php print render($page['content']); ?>

      <?php if (!empty($page['content_triple_1_l']) || !empty($page['content_triple_1_c']) || !empty($page['content_triple_1_r'])): ?>
        <!--.content-bottom-1-->
        <section class="l-content-bottom-triple row">
          <div class="content-bottom-triple-left medium-4 columns">
            <?php print render($page['content_triple_1_l']); ?>
          </div>
          <div class="content-bottom-triple-center medium-4 columns">
            <?php print render($page['content_triple_1_c']); ?>
          </div>
          <div class="content-bottom-triple-right medium-4 columns">
            <?php print render($page['content_triple_1_r']); ?>
          </div>
        </section>
      <?php endif; ?>
      <?php if (!empty($page['content_half_1_l']) || !empty($page['content_half_1_r'])): ?>
        <section class="l-content-bottom-1 row">
          <div class="content-bottom-left medium-6 columns">
            <?php print render($page['content_half_1_l']); ?>
          </div>
          <div class="content-bottom-right medium-6 columns">
            <?php print render($page['content_half_1_r']); ?>
          </div>
        </section>
      <?php endif; ?>
      <?php if(!empty($page['content_full_1'])): ?>
        <section class="l-content-bottom-1 row">
          <div class="content-bottom-full medium-12 columns">
            <?php print render($page['content_full_1']); ?>
          </div>
        </section>
        <!--/.content-bottom-1 -->
      <?php endif; ?>
     

      <?php if (!empty($page['content_half_2_l']) || !empty($page['content_half_2_r']) || !empty($page['content_full_2'])): ?>
        <!--.content-bottom-2-->
        <section class="l-content-bottom-2 row">
          <div class="content-bottom-left medium-6 columns">
            <?php print render($page['content_half_2_l']); ?>
          </div>
          <div class="content-bottom-right medium-6 columns">
            <?php print render($page['content_half_2_r']); ?>
          </div>
          <div class="content-bottom-full medium-12 columns">
            <?php print render($page['content_full_2']); ?>
          </div>
        </section>
        <!--/.content-bottom-2 -->
      <?php endif; ?>
    </div>
    <!--/.main region -->

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside role="complementary" class="<?php print $sidebar_first_grid; ?> sidebar-first left-off-canvas-menu columns sidebar">
        <a id="toggle-main-section-menu-close" href="#"><span><?php print t('Close'); ?></span> <i class="fa-times"></i></a>
        <?php print render($page['sidebar_first']); ?>
      </aside>
    <?php endif; ?>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside role="complementary" class="<?php print $sidebar_sec_grid; ?> sidebar-second columns sidebar">
        <?php print render($page['sidebar_second']); ?>
      </aside>
    <?php endif; ?>
  </div></div></main>
  <!--/.main-->

  <?php if (!empty($page['triptych_first']) || !empty($page['triptych_middle']) || !empty($page['triptych_last'])): ?>
    <!--.triptych-->
    <section class="l-triptych row">
      <div class="triptych-first medium-4 columns">
        <?php print render($page['triptych_first']); ?>
      </div>
      <div class="triptych-middle medium-4 columns">
        <?php print render($page['triptych_middle']); ?>
      </div>
      <div class="triptych-last medium-4 columns">
        <?php print render($page['triptych_last']); ?>
      </div>
    </section>
    <!--/.triptych -->
  <?php endif; ?>

  <div class="footer-push" id="footer-push"></div>
  <?php if ($messages && $zurb_foundation_messages_modal): print $messages; endif; ?>
</div></div>
<!--/.page -->


<!--.l-footer-->
<footer class="l-footer" role="contentinfo">
  <?php if (!empty($page['footer_top'])): ?>
    <section class="l-footer-top">
      <div class="row"><div class="footer-top medium-12 columns">
        <?php print render($page['footer_top']); ?>
      </div></div>
    </section>
  <?php endif; ?>
  <?php if (!empty($page['footer_firstcolumn']) || !empty($page['footer_secondcolumn']) || !empty($page['footer_thirdcolumn']) || !empty($page['footer_fourthcolumn'])): ?>
    <!--.footer-columns -->
    <section class="row l-footer-sections-top">
      <?php if (!empty($page['footer_firstcolumn'])): ?>
        <div class="footer-first medium-7 columns">
          <?php print render($page['footer_firstcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_secondcolumn'])): ?>
        <div class="footer-second medium-5 columns">
          <?php print render($page['footer_secondcolumn']); ?>
        </div>
      <?php endif; ?>
    </section>
    <section class="row l-footer-sections-bottom">
      <?php if (!empty($page['footer_thirdcolumn'])): ?>
        <div class="footer-third medium-6 columns">
          <?php print render($page['footer_thirdcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_fourthcolumn'])): ?>
        <div class="footer-fourth medium-6 columns">
          <?php print render($page['footer_fourthcolumn']); ?>
        </div>
      <?php endif; ?>
    </section>
    <!--/.footer-columns-->
  <?php endif; ?>

  <?php if (!empty($page['footer'])): ?>
    <section class="l-footer-wrap"><div class="row">
      <div class="footer medium-12 columns">
        <?php print render($page['footer']); ?>
      </div>
    </div></section>
  <?php endif; ?>
</footer>
<!--/.footer-->