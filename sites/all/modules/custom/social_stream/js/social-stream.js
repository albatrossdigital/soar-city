(function ($) {

Drupal.behaviors.social_stream = {
  attach: function (context, settings) {

    // @todo: randomize array
    //
    
    $.getJSON(settings.social_stream.url, function(data) {
      var feeds = {}
      var added = [];

      var keys = Object.keys(data);
      if (settings.randomize_feed != undefined && settings.randomize_feed) {
        keys = shuffle(keys);
      }

      $.each(keys, function(i, key) {
        if (settings.max != undefined && i >= settings.max) {
          return;
        }
        value = data[key];
        console.log(value);
        if (added.indexOf(value.url) === -1) {
          if (feeds[value.network] == undefined) {
            feeds[value.network] = [];
          }
          var arr = value.url.split('/');
          console.log(value.network);
          switch (value.network) {
            case 'flickr':
              feeds[value.network].push(arr[arr.length-1].replace('q=', ''));
              break;
            case 'blogger':
              feeds['rss'] = value.url . 'feeds/posts/default?alt=rss';
              break;
            case 'wordpress':
              feeds['rss'] = value.url . 'feed';
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
        //days: data.length < 15 ? 30 : 50, //igniored because max=limit
        max: 'limit',
        limit: settings.limit,
        //order: 'random',
        iconPath: settings.social_stream.image_path,
        imagePath: settings.social_stream.image_path,
      });

    });

    shuffle = function(o){ //v1.0
      for(var j, x, i = o.length; i; j = parseInt(Math.random() * i), x = o[--i], o[i] = o[j], o[j] = x);
      return o;
    };


           

  }
};

})(jQuery);