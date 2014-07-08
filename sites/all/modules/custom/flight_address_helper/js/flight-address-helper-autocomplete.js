(function ($) {

/**
* Puts the currently highlighted suggestion into the autocomplete field.
* Overridden from misc/autocomplete.js to add an event trigger on autocomplete
*/
if (Drupal.jsAC) {
  Drupal.jsAC.prototype.select = function (node) {
    this.input.value = $(node).data('autocompleteValue');
    // Custom: add an event trigger
    $(this.input).trigger('autocompleteSelect', [node]);
  };

  Drupal.jsAC.prototype.hidePopup = function (keycode) {
    // Select item if the right key or mousebutton was pressed.
    if (this.selected && ((keycode && keycode != 46 && keycode != 8 && keycode != 27) || !keycode)) {
      this.input.value = $(this.selected).data('autocompleteValue');
      // Custom: add an event trigger
      $(this.input).trigger('autocompleteSelect');
    }
    // Hide popup.
    var popup = this.popup;
    if (popup) {
      this.popup = null;
      $(popup).fadeOut('fast', function () { $(popup).remove(); });
    }
    this.selected = false;
    $(this.ariaLive).empty();
  };
}

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
