<?php

// Provides the shared functions for the 12- and 16-column modules

function _get_items($cols){
  
  if($cols == 12){
    $col_width = 80;
  } else {
    $col_width = 60;
  }
  
  $padding = (int) variable_get('imagecache_ninesixty_padding', '0');

  for($i=1; $i<=$cols; $i++){
    $width = $i * $col_width - 20 - (2* $padding);
    
    $items["grid_$i"] = _get_item($i, $width,  $padding);
    $items["grid_$i" . '_square'] = _get_square($i, $width,  $padding);
    $items["grid_$i" . '_landscape'] = _get_landscape($i, $width,  $padding);
  }
  return $items;
}

function _get_item($i, $width,  $padding){

  $name = "grid_$i";
    
  $item = array(
     'presetname' => $name,
     'actions' => array(
       '0' => array(
         'weight' => '0',
         'module' => 'imagecache',
         'action' => 'imagecache_scale',
         'data' => array(
           'width' => $width,
           'height' => '',
           'upscale' => 0,
         ),
       ),
     ),
   );
   return $item; 
}


function _get_square($i, $width,  $padding){

  $name = "grid_$i" . '_square';
    
  $item = array(
     'presetname' => $name,
     'actions' => array(
       '0' => array(
         'weight' => '0',
         'module' => 'imagecache',
         'action' => 'imagecache_scale_and_crop',
         'data' => array(
           'width' => $width,
           'height' => $width,
           'upscale' => 0,
         ),
       ),
     ),
   );
   return $item; 
}

function _get_landscape($i, $width,  $padding){

  $name = "grid_$i" . '_landscape';
  $height = $width * .75;
    
  $item = array(
     'presetname' => $name,
     'actions' => array(
       '0' => array(
         'weight' => '0',
         'module' => 'imagecache',
         'action' => 'imagecache_scale_and_crop',
         'data' => array(
           'width' => $width,
           'height' => $height,
           'upscale' => 0,
         ),
       ),
     ),
   );
   return $item; 
}