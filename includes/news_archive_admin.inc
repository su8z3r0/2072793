<?php
/**
 * @file
 * Module Admin section 
 *
 * Implements hook_admin()
 */
 
 function news_archive_admin($form, &$form_state) {
   
   
   
   $form = array();
   //$content_type_list = array();
   
   if (count(_news_archive_get_content_types()) > 0) {
      
     if( variable_get('first_time') == "" ){
	   drupal_set_message( t('Please save the module\'s configuration.'), 'warning');
	 }
	 
     $form['news_archive_content_type'] = array(
       '#type' => 'select',
       '#title' => t('Content type'),
       '#options' => _news_archive_get_content_types(),
       '#default_value' => variable_get('news_archive_content_type'),
       '#ajax' => array(
         'event' => 'change',
         'callback' => 'news_archive_ajax_get_content_type_fields',
         'wrapper' => 'fields-wrapper',
        ),
       '#description' => t('Select the content type you want to use to build the archive'),
     );
     
	 
     $content_type_list = array('- Select Field -');
     $alias = "";
	 
	 if ( isset($form_state['values']['news_archive_content_type']) ) {
       $content_type_list = _news_archive_get_content_type_fields($form_state['values']['news_archive_content_type']);
	   $alias = _news_archive_get_node_type_alias($form_state['values']['news_archive_content_type']);
     }
    
	 
     if ( count($content_type_list) == 1 && !isset($form_state['values']['news_archive_content_type']) && variable_get('news_archive_content_type_fields') == '' ) {
       $content_type_list = _news_archive_get_content_type_fields(variable_get('news_archive_first_bundle'));
	   $alias = _news_archive_get_node_type_alias(variable_get('news_archive_first_bundle'));	   
     }

     if (variable_get('news_archive_content_type_fields') != "" && !isset($form_state['values']['news_archive_content_type'] )) {
       $content_type_list = _news_archive_get_content_type_fields(variable_get('news_archive_content_type'));  	
       $alias = _news_archive_get_node_type_alias(variable_get('news_archive_content_type'));		   
     }


     $form['news_archive_content_type_wrapper'] = array(
       '#prefix' => '<div id="fields-wrapper">',
       '#suffix' => '</div>',
     );

     $form['news_archive_content_type_wrapper']['news_archive_content_type_fields'] = array(
       '#type' => 'select',
       '#title' => t('Content type fields'),
       '#options' => $content_type_list,
       '#default_value' => variable_get('news_archive_content_type_fields'),
       '#description' => t('Select the field to use to build the archive'),
     );
	 
	 if($alias != "") {
	 	 
	   $form['news_archive_content_type_wrapper']['news_archive_content_type_alias'] = array( 
	     '#type' => 'textfield',
	     '#title' => t('Alias'),
	     '#size' => 15,
	     '#disabled' => TRUE,
	     '#default_value' => $alias,	   
	   );
	 }
	 
	 $form['news_archive_settings_wrapper'] = array(
	   '#type' => 'fieldset',
	   '#title' => t('Settings'),
	   '#collapsible' => TRUE,
	   '#collapsed' => FALSE,
	 );
	 
	 $form['news_archive_settings_wrapper']['news_archive_block_type'] = array(
	   '#type' => 'select',
	   '#title' => t('HTML Output:'),
	   '#options' => array(	     
		 0 => t('List'),
		 //1 => t('Tree'),
	   ),
	   '#default_value' => variable_get('news_archive_block_type'),
	   '#description' => t('Select how the module must make the HTML output.<br>	     
         - List: an archive orginzed by months with year ( eg: January 20130 )<br>'),
		 //- Tree: archive as tree organized by Year and months ( eg: 2013->january->posts)'),
	 );
	 
	 $form['news_archive_settings_wrapper']['news_archive_create_menu_item'] = array(
	   '#type' => 'checkbox',
	   '#title' => t('Create Menu Item'),
	   '#options' => array(
	     0 => 0,
		 1 => 1,
	   ),
	   '#default_value' => variable_get('news_archive_create_menu_item'),
	 );
	 
	 $form['news_archive_settings_wrapper']['news_archive_menu_info_wrapper'] = array(
	   '#type' => 'container',
	   '#states' => array(
         'visible' => array('input[name="news_archive_create_menu_item"]' => array('checked' => TRUE)),
       ),
	 );
	 
	 $form['news_archive_settings_wrapper']['news_archive_menu_info_wrapper']['news_archive_select_menu'] = array(
	   '#type' => 'select',
	   '#title' => t('Menu'),
	   '#options' => news_archive_get_menu_names(),
	   '#default_value' => variable_get('news_archive_select_menu'),
	   
	 );
	 
	 $form['news_archive_settings_wrapper']['news_archive_menu_info_wrapper']['news_archive_menu_name'] = array(
	   '#type' => 'textfield',
	   '#title' => t('Menu name'),
	   '#size' => 10,
	   '#default_value' => variable_get('news_archive_menu_name'),
	   '#disabled' => test_function(),
	 );
	 
	 
	 $form['#submit'][] = 'news_archive_save';
	 
   
   //_array_print( $form );
   }
   
   return system_settings_form($form);
   
 }
 
 function test_function(){
   if(variable_get('news_archive_menu_name') != "") {
     return TRUE; 
   } else {
     return FALSE;
   }
 }

/*
 * CALLBACK FUNCTION
 */
 function news_archive_ajax_get_content_type_fields( &$form, &$form_state ) {
   
   //watchdog('test', '<pre>' . print_r( $form, 1 ) . '</pre>');
   
   return $form['news_archive_content_type_wrapper'];   
 }


 
/*
 * CUSTOM FUNCTIONS
 */ 
 
 
 
 function news_archive_save( $form, &$form_state ) {
   
   $is_menu_item = $form_state['values']['news_archive_create_menu_item'];
   $link_title = $form_state['values']['news_archive_menu_name'];
   
   if ( !$is_menu_item ) {
     //$form_state['values']['news_archive_select_menu'] = -1;
	 $form_state['values']['news_archive_menu_name']['#disabled'] = FALSE;
     $form_state['values']['news_archive_menu_name'] = "";
	 drupal_set_message(t('Menu item "' . $link_title .'" correctly deleted.'), 'status');	
   }
   
   drupal_add_js(array('news_archive' => array('block_type' => variable_get('news_archive_block_type'))), array('type' => 'setting'));
   variable_set( 'first_time', 1 );
   
   views_invalidate_cache();   
 }