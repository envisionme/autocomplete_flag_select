<?php
/**
 * @file
 *  Adminstrative page callbacks for the Autcomplete User Flag Select Module
 *
 * @ingroup Autocomplete flag select
 */
 
/**
 * Implementation of flag select settings form.
 */
function autocomplete_user_flag_select_settings_form() {
  $form = array();
  $flag_types = array();
  
  // get all the flag types from the system
  $flags = flag_get_flags();
  foreach ($flags as $flag) {
    if ($flag->content_type == 'user')
      $flag_types[$flag->fid] = $flag->title;
  }
  
  // List all Flag types
  $form['autocomplete_user_flag_select_flag_fid'] = array(
    '#type' => 'select',
    '#title' => t('Flag type'),
    '#default_value' => variable_get('autocomplete_user_flag_select_flag_fid', ''),
    '#options' => $flag_types,
    '#description' => t('Choose Flag'),
  );
  return system_settings_form($form);
} 