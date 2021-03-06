(function ($) {

Drupal.behaviors.flight_city_311_view = {
  attach: function (context, settings) {

    var secondary = {};
    $('select[name^=tid]', context).once(function() {      
      $(this).hide().parent().prepend('<div class="tid-select-wrapper"><select id="tid-select-primary"><option value="">- Select -</option></select><div id="secondary-wrapper"><label>Specifically</label><select id="tid-select-secondary"></select></div></div>');
      var $submit = $('#edit-submit-311-home');
      $submit.hide();
      var $primary = $('#tid-select-primary');
      var $secondary = $('#tid-select-secondary');
      var $secondaryWrapper = $('#secondary-wrapper');
      $secondaryWrapper.hide();

      var last = null;
      $(this).find('option').each(function() {
        var value = $(this).val();
        var text = $(this).text();

        if (value != 'All') {
          if (text.charAt(0) === '-') {
            text = text.substr(1);
            secondary[last].push({'value': value, 'text': text});
          }
          else {
            last = value;
            secondary[last] = [];
            $primary.append('<option value="'+ value +'">'+ text +'</option>');
          }
        }
      });

      $primary.bind('change', function(e) {
        buildSecondary($(this).val());
      });

      $secondary.bind('change', function(e) {
        if ($(this).val()) {
          $('input[name^=search]').val('');
          $('select[name^=tid] option[value='+ $(this).val() +']').prop('selected', 'selected');
          $submit.trigger('click');
        }
      });

      function buildSecondary(primary) {
        $secondary.html('').append('<option value="">- Select -</option>');
        if (primary) {
          $.each(secondary[primary], function (value, item) {
            $secondary.append('<option value="'+ item.value +'">'+ item.text +'</option>');
          });
          $secondaryWrapper.slideDown();
        }
        else {
          $secondaryWrapper.slideUp();
        }
        setPlaceholder();
      }

      function setPlaceholder() {
        $('.view-id-311_home.view-display-id-page').html(settings.service_request.placeholder);
      }
      if ($('.view-id-311_home.view-display-id-page').text().trim() == '') {
        setPlaceholder();
      }

      // Manually autosubmit the text search field
      var timeout;
      $('input[name^=search]').bind('keyup', function() {
        window.clearTimeout(timeout);
        if ($(this).val() != '') {
          timeout = setTimeout(function() {
            $('select[name^=tid] option, #tid-select-primary option, #tid-select-secondary').prop('selected', '');
            $secondaryWrapper.slideUp();
            $submit.trigger('click');
          }, 500);
        }
      });

    });

    // Fix the edit links
    $('.views-field-edit-term a', context).each(function() {
      $(this).attr('href', $(this).attr('href').replace('destination', 'destination1') + '&destination=311-services');
    });

  }
};

})(jQuery);
