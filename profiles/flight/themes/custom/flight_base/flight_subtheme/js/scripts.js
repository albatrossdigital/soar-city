(function ($, Drupal) {

  Drupal.behaviors.flight_subtheme = {
    attach: function(context, settings) {
      // Get your Yeti started.

      // Open external links in a new window
      var reg = RegExp('/' + window.location.host + '/');
      $('a').each(function() {
         if(!reg.test(this.href)) {
             $(this).click(function(event) {
                 event.preventDefault();
                 event.stopPropagation();
                 window.open(this.href, '_blank');
             });
         }
      });

      // waits for image(s) to load then calls callback
      function triggerImageSize($image, callback) {
        if(!$image.hasClass('size-processing')) {
          $image.addClass('size-processing');
          $image.waitForImages({
              finished: function() {
                callback();
                $image.removeClass('size-processing');
              },
              each: $.noop,
              waitForAll: true
          });
        }
      }

      // attach orbit image loading
      if(Drupal.settings.charityOrbit) {
        // add orbit transitioning class 
        $.each(Drupal.settings.charityOrbit, function(key, id) {

          var $orbit = $('#'+id),
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
      }
    }
  };

})(jQuery, Drupal);
