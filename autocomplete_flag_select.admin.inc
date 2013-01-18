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
  $types = array();

  foreach (node_get_types('types') as  $type) {
  $types[$type->type] = $type->name;
  }

  // Get all content types to search for.
  foreach ($types as $key => $type) {
  $content_types[$key] = $type;
  }

  // get all the flag types from the system
  $flags = flag_get_flags();
  foreach ($flags as $flag) {
      $flag_types[$flag->fid] = $flag->title;
  }
  
  // List all Content Types
  $form['autocomplete_flag_select_node_type'] = array(
    '#type' => 'select',
    '#title' => t('Content-type for Autocomplete flag content'),
    '#default_value' => variable_get('autocomplete_flag_select_node_type', ''),
    '#options' => $content_types,
    '#description' => t('Content type to be used for the Autocomplete flag'),
  );
  // List all Flag types
  $form['autocomplete_flag_select_flag_fid'] = array(
    '#type' => 'select',
    '#title' => t('Flag type'),
    '#default_value' => variable_get('autocomplete_flag_select_flag_fid', ''),
    '#options' => $flag_types,
    '#description' => t('Choose Flag'),
  );
  return system_settings_form($form);
}