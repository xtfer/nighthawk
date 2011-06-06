<?php
/**
 * Utilities
 */

function l($destination,$text,$class=NULL){
  //return '<a href="index.php?q='.$destination.'">'.$text.'</a>';
  $attributes = ' href="' . k($destination) . '"';
  if ($class) {
    $attributes .= ' class="' . $class . '"';
  }
  return '<a' . $attributes . '>' . $text . '</a>';
}

function k($destination){
  static $clean;
  if (!isset($clean)) {
    $clean = defined('NH_CLEAN_URL') && NH_CLEAN_URL;
  }

  static $url_base;
  if (!isset($url_base)) {
    $url_base = NH_SITE_ROOT;
    if (!$clean) {
      $url_base .= 'index.php?q=';
    }
  }
  if (defined('NH_HOME') && $destination == NH_HOME) {
    return $clean ? NH_SITE_ROOT : NH_SITE_ROOT . 'index.php';
  } else {
    return $url_base . $destination;
  }
}