/* Drop Jobs Admin scripts */

(function($, Drupal){
  "use strict";

  Drupal.behaviors.drop_jobs_admin = {
    attach: function(context, settings) {
      // Add smooth "Back to Top" animation.
      var $toplink = $('a.action-top', context);

      if ($toplink.length) {
        $toplink.click(function(e){
          jQuery.scrollTo(0, 600, {
            easing : 'easeInCubic'
          });
          e.preventDefault();
          return false;
        });
      }
    }
  }
})(jQuery, Drupal);