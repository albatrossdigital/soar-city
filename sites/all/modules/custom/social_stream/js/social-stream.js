(function ($) {

Drupal.behaviors.social_stream = {
  attach: function (context, settings) {

    // @todo: randomize array
    //data.sort( function() { return 0.5 - Math.random() } );
    
    $.getJSON(settings.social_stream.url, function(data) {
      var feeds = {}
      var added = [];

      $.each(data, function(index, value) {
        if (added.indexOf(value.url) === -1) {
          if (feeds[value.network] == undefined) {
            feeds[value.network] = [];
          }
          var arr = value.url.split('/');
          console.log(value.network);
          switch (value.network) {
            case 'blogger':
            case 'wordpress':
              //@todo
              break;
            default:
              feeds[value.network].push(arr[arr.length-1]);
          } 
        }
      });
      $.each(feeds, function(index, value) {
        switch (index) {
          case 'blogspot':
          case 'wordpress':
            //@todo
            break;
          default:
            feeds[index] = {id: feeds[index].join()};
        }
      });
      feeds.blogger = undefined;
      feeds.wordpress = undefined;
      feeds.soundcloud = undefined;
      console.log(feeds);


      $('#social-stream').dcSocialStream({
        feeds: feeds,
        rotate: {
          delay: 0
        },
        control: false,
        filter: true,
        wall: settings.social_stream.type === 'wall' ? true : false,
        cache: true,
        days: 30,
        max: 'limit',
        limit: 10,
        iconPath: settings.social_stream.image_path,
        imagePath: settings.social_stream.image_path
      });



      console.log(settings);
    });

    
           

  }
};

})(jQuery);
