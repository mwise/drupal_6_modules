<?php

/**
 * Form builder. Define this site’s station call letters and band frequency.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function imagecache_ninesixty_admin_settings() {
  $form['imagecache_ninesixty_padding'] = array(
    '#type' => 'textfield',
    '#title' => t('Padding'),
    '#description' => t('The amount of padding to apply to imagecache presets, in pixels.'),
    '#default_value' => variable_get('imagecache_ninesixty_padding', '0'),
    '#size' => 2,
  );    
     
  return system_settings_form($form);
}