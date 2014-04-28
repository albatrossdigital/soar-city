(function ($, Drupal) {

  // Register custom media query
  Foundation.utils.register_media('before-menu', 'before-menu');
  Foundation.utils.register_media('past-menu', 'past-menu');

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

  Drupal.behaviors.flight_city = {
    attach: function(context, settings) {

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
        triggerImageSize($orbitImage, function() {
          $(window).trigger('resize');
        });

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
    }
  };

})(jQuery, Drupal);
