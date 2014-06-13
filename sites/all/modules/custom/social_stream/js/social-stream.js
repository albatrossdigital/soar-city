(function ($) {

Drupal.behaviors.social_stream = {
  attach: function (context, settings) {

    // @todo: randomize array
    //
    
    $.getJSON(settings.social_stream.url, function(data) {
      var feeds = {}
      var added = [];

      console.log(data);

      $.each(data, function(index, value) {
        if (added.indexOf(value.url) === -1) {
          if (feeds[value.network] == undefined) {
            feeds[value.network] = [];
          }
          var arr = value.url.split('/');
          console.log(value.network);
          switch (value.network) {
            case 'flickr':
              feeds[value.network].push(arr[4]);
              break;
            case 'blogger':
            case 'wordpress':
              //@todo
              break;
            case 'wall':
            case 'govdelivery':
            case 'soundcloud':
              feeds[value.network] = undefined;
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
            if (value != undefined) {
              feeds[index] = {id: feeds[index].join()};
            }
        }
      });
      if (feeds.twitter != undefined) {
        feeds.twitter.url = settings.social_stream.twitter_url;
      }
      if (feeds.instagram != undefined) {
        feeds.instagram.clientId = '3b5aa6b2bd0842eb9702f191eb5c384d';
        feeds.instagram.redirectUrl = 'http://www.baltimore.ifsight.com/social_stream';
      }

      // @todo: temp?
      feeds.wordpress = undefined;
      feeds.blogger = undefined;
      feeds.soundcloud = undefined;

      feeds.instagram = undefined;
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
        days: data.length < 15 ? 30 : 50,
        max: 'limit',
        limit: data.length < 15 ? 10 : 2,
        //order: 'random',
        iconPath: settings.social_stream.image_path,
        imagePath: settings.social_stream.image_path,
      });

    });

    
           

  }
};

})(jQuery);