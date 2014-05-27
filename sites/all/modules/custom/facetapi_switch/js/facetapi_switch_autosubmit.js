(function($){
  Drupal.behaviors.facetapi_switch = {
    attach: function (context, settings) {
      $('form[id^="facetapi-switch-form"] .form-submit', context).hide();
      $('form[id^="facetapi-switch-form"] input[type=radio]', context).change(function () {
        $(this).closest('form').submit();
      });
    }
  };
})(jQuery);
