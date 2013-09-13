<?php

function news_archive_views_default_views() {
    
  $node_type = variable_get('news_archive_content_type');

  //
  
  $alias = "";
  if(variable_get('news_archive_content_type_alias') && variable_get('news_archive_content_type_alias') != "" && variable_get('news_archive_content_type_alias') != "content" ){
    $alias = variable_get('news_archive_content_type_alias');
  } else {
    $alias = "page";
  }
  
  $field_name = variable_get('news_archive_content_type_fields');
  $node_type = variable_get('news_archive_content_type');
  
  
  $view = new view();
  $view->name = 'news_archive_module_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News Archive Module View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News Archive Module View';
  $handler->display->display_options['css_class'] = 'news-archive';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Contenuto: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  
  
  /* Contextual filter: Data - Anno */
  $handler->display->display_options['arguments'][$field_name . '_value']['id'] = $field_name . '_value';
  $handler->display->display_options['arguments'][$field_name . '_value']['table'] = 'field_data_' . $field_name;
  $handler->display->display_options['arguments'][$field_name . '_value']['field'] = $field_name . '_value';
  $handler->display->display_options['arguments'][$field_name . '_value']['ui_name'] = 'Data - Anno';
  $handler->display->display_options['arguments'][$field_name . '_value']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments'][$field_name . '_value']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments'][$field_name . '_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments'][$field_name . '_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments'][$field_name . '_value']['summary_options']['items_per_page'] = '10';
  $handler->display->display_options['arguments'][$field_name . '_value']['granularity'] = 'year';
  /* Contextual filter: Data - Mese */
  $handler->display->display_options['arguments'][$field_name . '_value_1']['id'] = $field_name . '_value_1';
  $handler->display->display_options['arguments'][$field_name . '_value_1']['table'] = 'field_data_' . $field_name;
  $handler->display->display_options['arguments'][$field_name . '_value_1']['field'] = $field_name . '_value';
  $handler->display->display_options['arguments'][$field_name . '_value_1']['ui_name'] = 'Data - Mese';
  $handler->display->display_options['arguments'][$field_name . '_value_1']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments'][$field_name . '_value_1']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments'][$field_name . '_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments'][$field_name . '_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments'][$field_name . '_value_1']['summary_options']['items_per_page'] = '10';

  /* Filter criterion: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    $node_type => $node_type,
  ); 

  /* Display: Page */
  
    
  $menu_name = variable_get('news_archive_select_menu', '');
  $menu_title = variable_get('news_archive_menu_name', '');
  
  /*
  watchdog('menu title', $menu_title);
  
  if( $menu_title != "" ) {
    $handler = $view->new_display('page', 'Page', 'page');
    $handler->display->display_options['path'] = $alias . "/all";
    $handler->display->display_options['menu']['type'] = 'normal';
    $handler->display->display_options['menu']['title'] = $menu_title;
    $handler->display->display_options['menu']['weight'] = '0';
    $handler->display->display_options['menu']['name'] = $menu_name;
    $handler->display->display_options['menu']['context'] = 0;
    $handler->display->display_options['menu']['context_only_inline'] = 0;
  }
  */
  
  
  /* Display: Page */
  $handler = $view->new_display('page', 'News Archive Module View', 'page');
  $handler->display->display_options['path'] = $alias;
  if( !empty($menu_name) ) {
    $handler->display->display_options['menu']['type'] = 'normal';
    $handler->display->display_options['menu']['title'] = $menu_title;
    $handler->display->display_options['menu']['weight'] = '0';
    $handler->display->display_options['menu']['name'] = $menu_name;
    $handler->display->display_options['menu']['context'] = 0;
    $handler->display->display_options['menu']['context_only_inline'] = 0;
  }
  
  $translatables['test'] = array(
    t('Master'),
    t('test'),
    t('more'),
    t('Apply'),
    t('Ripristina'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« prima'),
    t('‹ precedente'),
    t('seguente ›'),
    t('ultima »'),
    t('Page'),
  );
  
  $views[$view->name] = $view;
  return $views;
}





/*
function news_archive_views_query_alter(&$view, &$query) {
  //global $user;
  //dpm($view, __FUNCTION__);
  //dpm($query, __FUNCTION__);
  if ($view->name === 'news_archive_module_view') {
    
    $key = variable_get('news_archive_content_type_fields') . '_value';
	
    // This will only work as-is if you always have something in the filter by
    // default, I guess. This hook runs always so you could just put
    // 'test@test.com' as the email to filter by in views and this
    // will always override it. I'm sure there is a cleaner way to put
    // the filter dynamically at runtime. But i think thats more complex
    // php that customizes a view.
    //
    // The index 2 below is the index of the condition for the email filter.
    // Your $query structure may be different in your dpm() of the View $query.
	$url = explode("/",$_GET["q"]);
	
	_array_print( $url );
	
	if(is_numeric( $url[1])) {
	 
	 
	  $query->where[1]['conditions'][2][$key]['value'] = $url[1];
	}
	
    
  }
}


function news_archive_views_pre_build( &$view ) { //, &$display_id , &$args ){
  
  /*print $view->name;
  */
  //if ($view->name === 'news_archive_module_view' && $view->current_display === 'page' && isset($args[0])){
    
	//print "OK";
	

  /*
  if( $view->name === 'news_archive_module_view' ) {
    
	
	
	$key = variable_get('news_archive_content_type_fields') . '_value';
	//$view->display['page']->handler->options['filters'][$field_name . '_value']['value'] = "2012";
	
	$filter = $view->get_item('page', 'filter', $key);	
	
	//_array_print( $filter );
	
	$url = explode("/",$_GET["q"]);
    
	if(is_numeric( $url[1])) {
      
	  
	  
      $url_data = $url[1] . "/" . $url[2];
	  $filter['value'] = $url_data;
	  $view->set_item($display_id, 'filter', $key, $filter);
	  
	  return $view;
	  
	}
	/*
    $filter['value']['min'] = $value['min'];
    $filter['value']['max'] = $value['max'];
    $view->set_item($display_id, 'filter', $key, $filter);
	*/
	
  //}
  
  //print $display_id;
  
//}

/*
function news_archive_views_pre_build( &$view ) {
  
  $field_name = variable_get('news_archive_content_type_fields');
  
  //print $view->name;
  
  if ( $view->name == 'view_blocchi' ) {
    
	$url = explode("/",$_GET["q"]);
  
    //_array_print( $url );
    
    $url_data = $url[1] . "-" . $url[2];
	
	// Display ID of the view.
    $display_id = 'page';
    // get the view object.
    $view = views_get_view('view_blocchi'); //Replace with your view name
    $filter = $view->get_item($display_id, 'filter', $field_name . '_value');
    
	
	/*
	if ($year) {
      $filter['value']['value'] = $year;
      $filter['granularity'] = 'year';
    }
    if ($year && $month) {
      $filter['value']['value'] = $year . '-' . $month;
      $filter['granularity'] = 'month';
    }
    if ($year && $month && $day) {
      $filter['value']['value'] = $year . '-' . $month . '-' . $day;
      $filter['granularity'] = 'day';
    
	}*/
	
	/*
    $view->set_item($display_id, 'filter', 'field_event_date_value', $url_data);
    // If you have any other arguments read from the URL and pass it here as part of args array
    $result = $view->execute_display($display_id, $args);
    
  }
}
	*/
    // Rendering will return the HTML of the the view
    //print $view->render();
 
	
	//_array_print( $url_data );
	
	//get_events($url_data[1], $url_data[2], '', $field_name);
	
	//$filters = $view->display_handler->get_option('filters');
	
	//$filters['field_data_value']['value'] = $url_data[1] . "-" . $url_data[2];
	//_array_print($view->display['page']->handler->handlers);
	/*die();
	
	$view->display['page']->handler->handlers['filter'][$field_name . '_value']->value['value'] = 8;
    return $view;*/
	/*
  }
  

}
*/