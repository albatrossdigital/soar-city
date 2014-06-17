(function ($) {

Drupal.behaviors.social_stream = {
  attach: function (context, settings) {

    // @todo: randomize array
    //

    var display = {
      'twitter': {
        out: 'intro,date,text,user',
      },
      'facebook': {
        out: 'intro,date,text,user'
      },
      'youtube': {
        out: 'intro,date,text,user'
      }

    }
    
    $.getJSON(settings.social_stream.url, function(data) {
      var feeds = {rss: []}
      var added = [];

      var keys = Object.keys(data);
      if (settings.social_stream.randomize_feed != undefined && settings.social_stream.randomize_feed) {
        keys = shuffle(keys);
      }

      $.each(keys, function(i, key) {
        if (settings.social_stream.max != undefined && i >= settings.social_stream.max) {
          return;
        }
        value = data[key];
        if (added.indexOf(value.url) === -1) {
          if (feeds[value.network] == undefined) {
            feeds[value.network] = [];
          }
          var arr = value.url.split('/');
          switch (value.network) {
            case 'flickr':
              feeds[value.network].push(arr[arr.length-1].replace(/\?q\=/, ''));
              break;
            case 'blogger':
              feeds['rss'].push(value.url + 'feeds/posts/default?alt=rss');
              break;
            case 'wordpress':
              feeds['rss'].push(value.url + 'feed');
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
          default:
            if (value != undefined && value != '' && value.length) {
              var item = display[value.network] != undefined ? display[value.network] : {};
              item['id'] = value.join();
              feeds[index] = item;
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
      feeds.blog = undefined;
      feeds.soundcloud = undefined;

      feeds.instagram = undefined;

      if (!feeds.rss.length) {
        feeds.rss = undefined;
      }

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
        limit: settings.social_stream.limit,
        //order: 'random',
        iconPath: settings.social_stream.image_path,
        imagePath: settings.social_stream.image_path,
        height: settings.social_stream.height,
      });

    });

    shuffle = function(o){ //v1.0
      for(var j, x, i = o.length; i; j = parseInt(Math.random() * i), x = o[--i], o[i] = o[j], o[j] = x);
      return o;
    };


           

  }
};

})(jQuery);