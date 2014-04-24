<!--.page -->
<div data-offcanvas role="document" class="page off-canvas-wrap"><div class="inner-wrap">

  <!--.l-header -->
  <header role="banner" class="l-header .contain">
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
        <li class="toggle-off-canvas"><a class="right-off-canvas-toggle" href="#"><span><?php print $top_bar_menu_text; ?></span> <i class="fa-bars"></i></a></li>
      </ul>
      <aside class="right-off-canvas-menu top-bar-section">
        <?php if (!empty($page['topbar'])): ?>
          <?php print render($page['topbar']); ?>
        <?php endif; ?>
      </aside>
    </nav>
    <?php if ($top_bar_classes): ?>
      </div>
    <?php endif; ?>

    <!--.l-header-region -->
    <section class="l-header-region row">
      <div class="medium-6 columns">
        <?php if($entity_title): ?>
          <h2 id="entity-title" class="title"><?php print $entity_title; ?></h2>
        <?php endif; ?>
      </div>
      <div class="medium-6 columns">
        <?php print render($page['header']); ?>
      </div>
    </section>
      <!--/.l-header-region -->
  </header>
  <!--/.l-header -->

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

  <main role="main" class="row l-main"><div id="dnn_ContentPane">
    <div class="<?php print $main_grid; ?> main columns">
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlight panel callout">
          <?php print render($page['highlighted']); ?>
        </div>
      <?php endif; ?>

      <a id="main-content"></a>

      <?php print render($title_prefix); ?>
      <?php if ($title && !$is_front): ?>
        <h1 id="page-title" class="title"><?php print $title; ?></h1>
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
    </div>
    <!--/.main region -->

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside role="complementary" class="<?php print $sidebar_first_grid; ?> sidebar-first columns sidebar">
        <?php print render($page['sidebar_first']); ?>
      </aside>
    <?php endif; ?>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside role="complementary" class="<?php print $sidebar_sec_grid; ?> sidebar-second columns sidebar">
        <?php print render($page['sidebar_second']); ?>
      </aside>
    <?php endif; ?>
  </div></main>
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
        <div class="footer-third medium-7 columns">
          <?php print render($page['footer_thirdcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_fourthcolumn'])): ?>
        <div class="footer-fourth medium-5 columns">
          <?php print render($page['footer_fourthcolumn']); ?>
        </div>
      <?php endif; ?>
    </section>
    <!--/.footer-columns-->
  <?php endif; ?>

  <?php if (!empty($page['footer'])): ?>
    <section class="row l-footer-wrap">
      <div class="footer medium-12 columns">
        <?php print render($page['footer']); ?>
      </div>
    </section>
  <?php endif; ?>
</footer>
<!--/.footer-->