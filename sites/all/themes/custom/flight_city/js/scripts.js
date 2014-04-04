(function ($, Drupal) {

  Drupal.behaviors.flight_city = {
    attach: function(context, settings) {
      // Get your Yeti started.

      if(Drupal.settings.flightOrbit) {
        // add orbit transitioning class 
        $.each(Drupal.settings.flightOrbit, function(key, id) {
          $('#'+id).on("before-slide-change.fndtn.orbit", function(event) {
            $(this).addClass('orbit-transitioning');
          });
          $('#'+id).on("after-slide-change.fndtn.orbit", function(event) {
            $(this).removeClass('orbit-transitioning');
          });
        });
      }
    }
  };

})(jQuery, Drupal);
