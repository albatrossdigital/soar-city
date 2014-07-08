;(function ($, window, document, undefined) {
  'use strict';

  Foundation.libs.accordion = {
    name : 'accordion',

    version : '5.2.2',

    settings : {
      active_class: 'active',
      multi_expand: false,
      toggleable: true
    },

    init : function (scope, method, options) {
      this.bindings(method, options);
    },

    events : function () {
      var self = this;
      var S = this.S;
      jQuery(this.scope)
      .off('.fndtn.accordion')
      .on('click.fndtn.accordion', '[' + this.attr_name() + '] dd > a', function (e) {
        var accordion = jQuery(this).closest('[' + self.attr_name() + ']'),
            target = jQuery('#' + this.href.split('#')[1]),
            siblings = jQuery('dd > .content', accordion),
            aunts = jQuery('dd', accordion),
            settings = accordion.data(self.attr_name(true) + '-init'),
            active_content = jQuery('dd > .content.' + settings.active_class, accordion),
            active_parent = jQuery('dd.' + settings.active_class, accordion);
        e.preventDefault();

        if (! jQuery(this).closest('dl').is(accordion)) { return; }

        if (settings.toggleable && target.is(active_content)) {
          active_parent.toggleClass(settings.active_class, false);
          return target.toggleClass(settings.active_class, false);
        }

        if (!settings.multi_expand) {
          siblings.removeClass(settings.active_class);
          aunts.removeClass(settings.active_class);
        }

        target.addClass(settings.active_class).parent().addClass(settings.active_class);
      });
    },

    off : function () {},

    reflow : function () {}
  };
}(jQuery, this, this.document));
