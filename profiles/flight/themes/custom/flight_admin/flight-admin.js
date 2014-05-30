(function ($) {

Drupal.behaviors.flight_city_organization_view = {
  attach: function (context) {

    // Make contextual help links pull up popup    
    $('a.contextual-help, .navbar-icon-help').bind('click', function(e) {
      var newwindow=window.open($(this).attr('href'), 'contextual-help', 'height=700,width=600');
      if (window.focus) {newwindow.focus()}
      e.preventDefault();
    });

  }
};

})(jQuery);
