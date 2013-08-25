(function ($) {

  Drupal.behaviors.news_archive = {
    attach: function (context, settings) {
      
	  var path = Drupal.settings.news_archive.news_archive_path;

	  
	  $('li')
        .css('pointer','default')
        .css('list-style-image','none');
      $('li:has(ul)')
          .click(function(event){
              if (this == event.target) {
                  $(this).css('list-style-image',
                      (!$(this).children().is(':hidden')) ? 'url("' + path + '/images/plusbox.gif")' : 'url("' + path + '/images/minusbox.gif")').toggleClass('active');
                  $(this).children().toggle('fast');
              }
              return false;
          })
          .css({cursor:'pointer', 'list-style-image':'url("' + path + '/images/plusbox.gif")'})
          .children().hide();
      $('li:not(:has(ul))').css({cursor:'default', 'list-style-image':'none'});
	  
	  $('li a').click(function(){
	    //alert($(this).attr('href'));
		document.location.href = $(this).attr('href');
	  });

	  	  
	  $('.news-archive li').each(function(){
	    if($(this).hasClass('active')){
		  $(this).children('ul').toggle();
		  $(this).css('list-style-image',
                      (!$(this).hasClass('active')) ? 'url("' + path + '/images/plusbox.gif")' : 'url("' + path + '/images/minusbox.gif")');
	    } else {
		  $(this).removeClass('active');
	    }
	  });
	  
    }
  };

})(jQuery);