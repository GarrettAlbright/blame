<?php

/**
 * Blame module admin settings form.
 */
function blame_settings_form() {
  $form = array();  
  $form['blame_roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Blame Roles'),
    '#options' => user_roles(),
    '#description' => t('Select which roles you would like to track. If no roles 
      are selected, all roles will be tracked. If you do select a role(s), then
      only forms submitted by users of those roles will be tracked.'),
    '#default_value' => variable_get('blame_roles', array()),
  );
  
  $form['blame_no_admin'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable Admin'),
    '#description' => t('Out of the box, the Blame module is going to track 
      form submits that are made by everyone, including admin (uid 1). You can
      disable admin (uid 1) from being tracked at all by checking this box.
      It is not recommended you do this, but we have it here in case you
      absolutely need it.'),
    '#default_value' => variable_get('blame_no_admin', 0),
  );
  
  $form['blame_uids'] = array(
    '#type' => 'textfield',
    '#title' => t('Blame UIDs'),
    '#description' => t('You have the ability to track specific users based on 
      their UID if you would like to. Provide a list of UID\'s that you want to
      track, separated by commas. This will still use the above role settings
      and will only track the user if the user has one of the available roles
      checked above.'),
    '#default_value' => variable_get('blame_uids', ''),
  );
  
  $form['blame_exclude_form_ids'] = array(
    '#type' => 'textarea',
    '#title' => t('Exclude Form Ids'),
    '#description' => t('You can exclude specific form ids if you would like to.
      This can by done by adding a form id on each line. Each form id that you
      enter will be excluded from tracking / blaming.'),
    '#default_value' => variable_get('blame_exclude_form_ids', ''),
  );
  
  return system_settings_form($form); 
}