(function ($, Drupal) {

  Drupal.behaviors.flight_city = {
    attach: function(context, settings) {
      // Get your Yeti started.

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
    }
  };

})(jQuery, Drupal);
