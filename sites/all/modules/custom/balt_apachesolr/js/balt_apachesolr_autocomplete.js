
/**
 * Adds the custom autocomplete widget behavior.
 */
Drupal.behaviors.balt_apachesolr_autocomplete = {
  attach: function(context) {
    var urlPattern = new RegExp('^(https?:\/\/)');
    jQuery(".balt-apachesolr-autocomplete.unprocessed", context).add(".balt-apachesolr-autocomplete.unprocessed input", context).autocomplete(Drupal.settings.balt_apachesolr_autocomplete.path,
    {
      // Classnames for the widget.
      inputClass: "",
      loadingClass: "throbbing",
      // Do not select first suggestion by default.
      selectFirst: false,
      // Specify no matching as it wil be done on server-side.
      matchContains: false,
      matchSubset: false,
      // Maximum number of items to show in widget.
      max: 50,
      scroll: true,
      scrollHeight: 360,
      // Data returned from server is JSON-encoded.
      dataType: "json",
      // Function to parse returned json into elements.
      parse: function(data) {
        return jQuery.map(data, function(item) {
          return {
            data: item,          // Echo the input data.
            value: item.display, // This will be shown in the options widget.
            result: item.key     // The actual value to put into the form element.
          }
        });
      },
      // Return the HTML to display in the options widget.
      formatItem: function(item) {
        return item.display;
      }
    }).result(function(item, element) {
      // element is keyed for direct
      if(element.hasOwnProperty('gotoUrl')) {
        window.location = element.gotoUrl;
      }
      // use standard
      else {
        // Handle selection of an element in the autocomplete widget.
        // We should submit the widget's parent form.
        jQuery(this).get(0).form.submit();
      }
    }).addClass('form-autocomplete'); // Add Drupal autocomplete widget's style.
  }
};
