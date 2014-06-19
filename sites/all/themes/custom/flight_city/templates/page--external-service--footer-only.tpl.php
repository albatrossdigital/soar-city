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