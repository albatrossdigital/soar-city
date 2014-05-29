(function ($) {

Drupal.behaviors.flight_city_organization_view = {
  attach: function (context) {
    
    $('select[name^=category]', context).once(function() {
      $(this).hide().parent().prepend('<div class="item-list"><ul id="category-list"></ul></div>');
      
      $(this).find('option').each(function() {

        var $item = $('<li><a hre="#'+ $(this).attr('value') +'" rel="'+ $(this).attr('value') +'">'+ $(this).text() +'</a></li>');
        var $that = $(this);

        $item.find('a').bind('click', function() {
          if ($(this).parent().hasClass('highlighted')) {
            $(this).parent().removeClass('highlighted');
            $that.removeProp('selected');
          }
          else {
            $that.prop('selected', 'selected');
            $(this).parent().addClass('highlighted');
          }
          $that.parent().trigger('change');
        });

        $item.appendTo('#category-list');
      });

    })

  }
};

})(jQuery);
