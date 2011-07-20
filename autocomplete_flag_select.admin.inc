<?php
/**
 * @file
 * Administrative page callbacks for the Autocomplete Publish Tools module.
 *
 * @ingroup Autocomplete flag select
 */
 
/**
 * Implementations of flag select settings form
 */ 
function autocomplete_flag_select_settings_form() {  
  
  $form = array();
  // get all content types
	$types = array();
  
	foreach (node_get_types('types') as  $type) {
    $types[$type->type] = $type->name;
  }
	
	// get all content types to search for
	$reference_types = array();;
	foreach ($types as $key => $type) {  
    $content_types[$key] = $type;
	}
  
  $flags = flag_get_flags();
  $flag_names = array();
  foreach ($flags as $flag) {
    $flag_names[$flag->name] = $flag->title;
  }
    
	$form['autocomplete_flag_select_node_type'] = array(
    '#type' => 'select',
    '#title' => t('Content-type for Autocomplete flag content'),
    '#default_value' => variable_get('autocomplete_flag_select_node_type', ''),
    '#options' => $content_types,
    '#description' => t('Content type to be used for the Autocomplete flag'),
  );
  
  $form['autocomplete_flag_select_flag_type'] = array(
    '#type' => 'select',
    '#title' => t('Flag type'),
    '#default_value' => variable_get('autocomplete_flag_select_flag_type', ''),
    '#options' => $flag_names,
    '#description' => t('Choose Flag'),
  );
	return system_settings_form($form);
}