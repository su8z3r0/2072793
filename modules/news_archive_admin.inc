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
     if ( isset($form_state['values']['news_archive_content_type']) ) {
       //print $form_state['news_archive_content_type'];
       $content_type_list = _news_archive_get_content_type_fields($form_state['values']['news_archive_content_type']);
     }

     if ( count($content_type_list) == 1 && !isset($form_state['values']['news_archive_content_type']) && variable_get('news_archive_content_type_fields') == '' ) {
       $content_type_list = _news_archive_get_content_type_fields(variable_get('news_archive_first_bundle'));
     }


     if (variable_get('news_archive_content_type_fields') != "" && !isset($form_state['values']['news_archive_content_type'] )) {
       $content_type_list = _news_archive_get_content_type_fields(variable_get('news_archive_content_type'));  
     }


     $form['content_type_wrapper'] = array(
       '#prefix' => '<div id="fields-wrapper">',
       '#suffix' => '</div>',
     );

     $form['content_type_wrapper']['news_archive_content_type_fields'] = array(
       '#type' => 'select',
       '#title' => t('Content type fields'),
       '#options' => $content_type_list,
       '#default_value' => variable_get('news_archive_content_type_fields'),
       '#description' => t('Select the field to use to build the archive'),
     );
   
   //_array_print( $form );
   }
   
 
   return system_settings_form($form); 
 }
 

/*
 * CALLBACK FUNCTION
 */
 function news_archive_ajax_get_content_type_fields( $form, &$form_state ) {
   return $form['content_type_wrapper'];   
 }


 
/*
 * CUSTOM FUNCTIONS
 */ 
 
 function _news_archive_get_content_types() {
   
   $return_array = array();
   
      
   //Get all content type list
   $types = node_type_get_types();
   $node_types = array();     
   
   foreach ( $types as $node_type ) {
     $node_types[$node_type->type] = $node_type->name;
   }
         
   //get all field of a given bundle
   $content_type_fields = array();
   $count = 0;
   foreach ($node_types as $key => $val) {
     $content_type_fields = field_info_instances("node", $key);
     if ( $count == 0 ) {
       variable_set('news_archive_first_bundle', $key);
     }
     foreach ($content_type_fields as $keys => $values) {
       //print $keys . " -> " . $values['widget']['module'] . "<br>";
       if ( $values['widget']['module'] == 'date' ) {
         $return_array[$key] = $val;
       }
     }
     $count++;
   }
     
   
   if ( count( $return_array ) > 0 ) {
     return $return_array;
   }
   else {     
     drupal_set_message(t('No date field exists.'), 'error');
     return array();
   }
 }


 function _news_archive_get_content_type_fields( $content_type='' ) {

   
   $fields_info_instance = array();
   $fields = array();
   
   $fields_info_instance = field_info_instances("node", $content_type);
   
   foreach ( $fields_info_instance as $key => $val ) {
     if ( $val['widget']['module'] == 'date' ) {
       $fields[$key] = $key;
     }

   }
   
   return $fields;   
 }
 