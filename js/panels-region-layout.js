(function ($) {

  Drupal.behaviors.panelsRegionLayoutIPE = {
    attach: function (context, settings) {
    	for (var i in Drupal.settings.PanelsIPECacheKeys) {
	      var key = Drupal.settings.PanelsIPECacheKeys[i];
	      var DrupalPanelsIPE = Drupal.PanelsIPE.editors[key];
	      if(DrupalPanelsIPE) {
	     	DrupalPanelsIPE.sortableOptions.items = 'div.region-layout-panel';
	      }
	      //console.log(Drupal.ajax.prototype.commands.insertNewPane);
	      if(Drupal.ajax.prototype.commands.insertNewPane) {
	      	Drupal.ajax.prototype.commands.insertNewPane.bind(function () {
		      	console.log('happeing');
		      });	
	      }
	      

	      // $('.panels-ipe-portlet-wrapper').removeClass('panels-ipe-portlet-wrapper');
	      // $('div.region-layout-panel').addClass('panels-ipe-portlet-wrapper');
	    }
    }
  };

  $(document).bind('insertNewPane', function() {
    alert('MY_EVENT');
  });

})(jQuery);