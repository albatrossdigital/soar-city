
//http://stackoverflow.com/questions/3629183/why-doesnt-indexof-work-on-an-array-ie8
if (!Array.prototype.indexOf)
{
  Array.prototype.indexOf = function(elt)
  {
    var len = this.length >>> 0;

    var from = Number(arguments[1]) || 0;
    from = (from < 0)
         ? Math.ceil(from)
         : Math.floor(from);
    if (from < 0)
      from += len;

    for (; from < len; from++)
    {
      if (from in this &&
          this[from] === elt)
        return from;
    }
    return -1;
  };
}

// From https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/keys
if (!Object.keys) {
  Object.keys = (function () {
    'use strict';
    var hasOwnProperty = Object.prototype.hasOwnProperty,
        hasDontEnumBug = !({toString: null}).propertyIsEnumerable('toString'),
        dontEnums = [
          'toString',
          'toLocaleString',
          'valueOf',
          'hasOwnProperty',
          'isPrototypeOf',
          'propertyIsEnumerable',
          'constructor'
        ],
        dontEnumsLength = dontEnums.length;

    return function (obj) {
      if (typeof obj !== 'object' && (typeof obj !== 'function' || obj === null)) {
        throw new TypeError('Object.keys called on non-object');
      }

      var result = [], prop, i;

      for (prop in obj) {
        if (hasOwnProperty.call(obj, prop)) {
          result.push(prop);
        }
      }

      if (hasDontEnumBug) {
        for (i = 0; i < dontEnumsLength; i++) {
          if (hasOwnProperty.call(obj, dontEnums[i])) {
            result.push(dontEnums[i]);
          }
        }
      }
      return result;
    };
  }());
}

(function ($) {

Drupal.behaviors.social_stream = {
  attach: function (context, settings) {

    // @todo: randomize array
    //

    var display = {
      'twitter': {
        out: 'intro,date,text,user'
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
        if (!added.hasOwnProperty(value.url)) {
          if (feeds[value.network] == undefined) {
            feeds[value.network] = [];
          }
          if (settings.social_stream.max_feeds == undefined || feeds[value.network].length < settings.social_stream.max_feeds) {
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
                //console.log(value.url);
                //console.log(arr[arr.length-1]);
                feeds[value.network].push(arr[arr.length-1]);
            }
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
      if (feeds.youtube != undefined) {
        feeds.youtube.feed = 'uploads';
      }
      if (feeds.vimeo != undefined) {
        feeds.vimeo.feed = 'videos';
      }      
      

      // @todo: temp?
      feeds.wordpress = undefined;
      feeds.blogger = undefined;
      feeds.blog = undefined;
      feeds.soundcloud = undefined;

      feeds.instagram = undefined;

      if (feeds.rss.length === 0) {
        feeds.rss = undefined;
      }

      //console.log(data);
      //console.log(feeds);
      //return;

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
        height: settings.social_stream.height
      });

      // Click on active social network
      if(window.location.hash) {
        setTimeout(on_hashchange, 10000);
      }
      $(window).on('hashchange', on_hashchange);
      function on_hashchange() {
        var hash = window.location.hash.replace('#', '');
        if (hash != 'filter') {
          $('#wall li>a[rel='+ hash +']').trigger('click');
        }
      }

    });



    shuffle = function(o){ //v1.0
      for(var j, x, i = o.length; i; j = parseInt(Math.random() * i), x = o[--i], o[i] = o[j], o[j] = x);
      return o;
    };

  }
};

})(jQuery);