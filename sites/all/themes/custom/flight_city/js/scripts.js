(function ($, Drupal) {

  // Register custom media query
  Foundation.utils.register_media('small-only', 'small-only');
  Foundation.utils.register_media('mobile-to-menu', 'mobile-to-menu');
  Foundation.utils.register_media('past-menu', 'past-menu');

  jQuery.fn.reverse = [].reverse;


  // Triggers callback after image is loaded
  function triggerImageSize($imageWrapper, callback) {
    if(!$imageWrapper.hasClass('size-processing')) {
      $imageWrapper.addClass('size-processing');

      Foundation.utils.image_loaded($('img', $imageWrapper), function() {
        $imageWrapper.removeClass('size-processing');
        callback();
      });
    }
  }

  // grab pertinent domain from subdomain
  var domain = window.location.hostname;
  domain = domain.substring(domain.indexOf('.') + 1);
  //var reg = RegExp('/[^#]|^mailto|' + window.location.host + '/');

  // toggle items switch from header area
  // to topbar on "past-menu" media query
  // searchInTopbar == false if in header, true if in topbar 
  var searchInTopbar = true;

  Drupal.behaviors.flight_city = {
    attach: function(context, settings) {

      // Open links in new window
      $("a[href^='http']").not("[href*='" + domain + "']").attr('target','_blank');

        // toggle items switch from header area
        // to topbar on "past-menu" media query
        // searchInTopbar == false if in header, true if in topbar 
        var $toggleItems = $('section.block-balt-apachesolr, section.block-gtranslate-gtranslate, section.block-bean-subscribe-link'),
          $headerRegion = $('.l-header-region > .header-region-right'),
          $offCanvas = $('aside.right-off-canvas-menu'),
          $body = $('body'),
          $page = $body.children('.page');

      // toggle search from header to topbar
      function toggleSearch(topbar) {

        // going from topbar to header 
        if(!topbar) {
          // only react if in topbar
          if(searchInTopbar) {
            $toggleItems.each(function() {
              $headerRegion.prepend($(this));
            });
            searchInTopbar = false;
          }
        }
        // going from header to topbar
        else {
          // only react if NOT in topbar
          if(!searchInTopbar) {
            $toggleItems.reverse().each(function() {
              $offCanvas.prepend($(this));
            });
            $toggleItems.reverse();
            searchInTopbar = true;
          }
        }
      }

      // checks widths
      function searchCheck() {
        // Toggle search for mobile
        if (matchMedia(Foundation.media_queries['small-only']).matches){
          toggleSearch(true);
        };

        // Toggle search to topbar
        if (matchMedia(Foundation.media_queries['medium']).matches){
          toggleSearch(false);
        };
      }

      // Watch width, throttled
      $(window).resize(Foundation.utils.throttle(function(e){
        searchCheck();
      }, 100));

      // Search button, add focus
      $('#search-toggle', context).once('main-off-canvas', function() {
        $(this).click(function() {
          if(!$page.hasClass('move-left')) {
            $('input[type="text"]', $searchForm).select();
          }
        });
      });

      // Main section menu (entity submenu)
      $('#toggle-main-section-menu, #toggle-main-section-menu-close', context).once('main-off-canvas', function() {
        $(this).click(function(e) {
          $('.l-main[data-offcanvas]').toggleClass('move-right');
          e.preventDefault();
        });
      });


      // orbits helper
      $('ul[data-orbit]', context).once('orbit-helper', function() {

        var $orbit = $(this),
          $orbitImage = $orbit.children('li:last-child');

        $orbit.on("before-slide-change.fndtn.orbit", function(event) {
          $orbit.addClass('orbit-transitioning');
        });
        $orbit.on("after-slide-change.fndtn.orbit", function(event) {
          $orbit.removeClass('orbit-transitioning');
        });

        // init
        /*triggerImageSize($orbitImage, function() {
          $(window).trigger('resize');
        });*/

        // on interchage changes, watch images again
        $(document).on('replace', 'img', function (e, new_path, original_path) {
          triggerImageSize($orbitImage, function() {
            $(window).trigger('resize');
          });
        });
      });

      // add back options
      $('[data-menu-back]').click(function(e) {
        var $self = $(this),
          level = $self.data('menu-back');
        // switch classes
        $self.parents('div').addClass('level_' + level).removeClass('level_' + (level + 1));
        e.preventDefault();
      });

      // Call resize to init theme js
      $(window).trigger('resize');
    }
  };

})(jQuery, Drupal);
