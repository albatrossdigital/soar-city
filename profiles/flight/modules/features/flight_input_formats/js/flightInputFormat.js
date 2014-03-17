/* New D7 Wrapper --> */(function ($) {


Drupal.behaviors.flightInputFormat = {
  attach: function(context, settings) { //new attach function
    // alter settings
    // @todo: re-enable this? It was throwing a fatal js err - JL Feb 22, 2014
    if(settings.ckeditor && settings.ckeditor.elements && _.size(settings.ckeditor.elements)) {
      // grab window height
      var height = "innerHeight" in window 
               ? window.innerHeight
               : document.documentElement.offsetHeight;
      // run through formats 
      _.each(settings.ckeditor.input_formats, function(format) {
        // restrict autogrow
        if(format.autoGrow_maxHeight && format.autoGrow_maxHeight > 0) {
          format.autoGrow_maxHeight = height * .75;
        }
        // make replace false by default for templates
        format.templates_replaceContent = false;
      });
    }
    
  }//attach
};//behaviors

/* New D7 Wrapper --> */ })(jQuery);

