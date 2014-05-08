(function ($) {

/**
* Puts the currently highlighted suggestion into the autocomplete field.
* Overridden from misc/autocomplete.js to add an event trigger on autocomplete
*/
Drupal.jsAC.prototype.select = function (node) {
  this.input.value = $(node).data('autocompleteValue');
  // Custom: add an event trigger
  $(this.input).trigger('autocompleteSelect', [node]);
};

Drupal.behaviors.flightAddressHelper = {
  attach: function(context, settings) { //new attach function

    function addFormContent(content, field, callback) {
      field = field.replace("_", "-");
      $.each(content, function(index, value) {
        $('#edit-' + field + '-und-0-' + index.replace("_", "-")).val(value);
      });
      callback();
    }

    function getAddressInfo(nid, field, callback) {
      $.ajax({
        url: settings.flightAddressHelper.url + field + '/' + nid,
        data: {},
        dataType: "json",
        callbackParameter: "callback",
        timeout: 50000,
        success: function(data) {
          if(data) {
            // Populate form
            addFormContent(data, field, callback);
          }
        },
        error: function(XHR, textStatus, errorThrown) {
          //alert("Error: " + textStatus);
          //alert("Error: " + errorThrown);
        }
      });
    }

    $('input[address-autocomplete-field]', context).bind('autocompleteSelect', function() {
      var $self = $(this),
        // Match nid in autocomplete
        matches = $self.val().match(/\((.*?)\)/g);
      // We have matches
      if(matches && matches.length) {
        $self.parents('fieldset').first().css({'opacity':0.5});
        // Call for data
        getAddressInfo(matches.pop().replace(/[\(\)]/g, ""), $self.attr('address-autocomplete-field'), function() {
          $self.parents('fieldset').first().css({'opacity':1});
        });
      }
    });

  }//attach
};//behaviors
})(jQuery);
