<?php
/**
 * Bootstrap
 */

require_once('config.inc');
require_once('util.inc');

function check_plain($text) {
  return (preg_match('/^./us', $text) == 1) ? htmlspecialchars($text, ENT_QUOTES, 'UTF-8') : '';
}

function sanitize($input) {
	if (is_array($input)) {
		$output = array();
	  foreach($input as $var=>$val) {

			$output[$var] = check_plain($val);
	   }
	}
	else {
		if (get_magic_quotes_gpc()) {
			$input = stripslashes($input);
		}
		$input  = cleanInput($input);
		$output = mysql_real_escape_string($input);
	}
	return $output;
}

