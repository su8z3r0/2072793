(function ($) {

  Drupal.behaviors.news_archive = {
    attach: function (context, settings) {
      
	  var path = Drupal.settings.news_archive.news_archive_path;
      
	  //var block_type = Drupal.settings.news_archive.block_path;
	  
	  alert(block_type);
	  
	  $(".treeview").treeview({
	  	collapsed: true,
	  	animated: "fast",
	  	prerendered: true,
	  });
	  
	  /*
	  $('.news-archive li').each(function(){
	    if($(this).hasClass('active')){
		  $(this).addClass('minusbox');
		  $(this).children().css('display', 'block');
		  if($(this).hasClass('news-archive-posts-leaf')){
		    $(this).css('list-style', 'none');
		  }
		} else {
		  $(this).addClass('plusbox');
		  if($(this).hasClass('news-archive-posts-leaf')){
		    $(this).css('list-style', 'none');
		  }
		}
	  });*/
	  
	  
	  /*
	  $('.news-archive-wrapper li:has(ul)').click(function(event){
		if (this == event.target) {
		  $(this).toggleClass('active');
		  alert("OK");
		   //$('.news-archive li').each(function(){
	      if($(this).hasClass('active')){
		    if($(this).children().is(':hidden')){
		      $(this).removeClass('plusbox');
		      $(this).addClass('minusbox');
		      $(this).children().css('display', 'block');
		    } else {
		      $(this).addClass('plusbox');
	          $(this).removeClass('minusbox');
		      if($(this).hasClass('news-archive-posts-leaf')){
		        $(this).css('list-style', 'none');
		      }
		    }
		    
		    if($(this).hasClass('news-archive-posts-leaf')){
		      $(this).css('list-style', 'none');
		    }
		  }
		}
	    //});
	  });
	  */
	  /*
	  $('.news-archive-wrapper li').css('pointer','default')
      $('.news-archive-wrapper li')
          .click(function(){
              
			  if( $(this).children('ul').is(':hidden')){
                
			  }
			  /*
			  if (this == event.target) {
			    alert("OK");
                $(this).toggleClass('active');
                if(!$(this).children().is(':hidden')){
                  $(this).addClass('plusbox');
                  $(this).removeClass('minusbox');
                } else {
                  $(this).removeClass('plusbox');
                  $(this).addClass('minusbox');
                }				      
                $(this).children().show();
              }
			  */
       /*   })
          .css({cursor:'pointer'})
		  .addClass("plusbox")
          
      $('li:not(:has(ul))').css({cursor:'default', 'list-style-image':'none'});

	  /*	  
	  $('.news-archive li').each(function(){
	    if($(this).hasClass('active')){
		  $(this).children('ul').toggle();
          if($(this).children().is(':hidden')){
            $(this).addClass('plusbox');
            $(this).removeClass('minusbox');
          } else {
            $(this).removeClass('plusbox');
            $(this).addClass('minusbox');
          }
		  if($(this).hasClass('news-archive-posts-leaf')){
		    $(this).css('list-style', 'none');
		  }
	    } else {
		  $(this).removeClass('active');
	    }
	  });
	  */
    }
  };

})(jQuery);