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
			$output[$var] = sanitize($val);
		}
	}
	else {
		// Simple sanitization using htmlspecialchars
		// Magic quotes removed in PHP 5.4, mysql_* functions removed in PHP 7.0
		$output = check_plain($input);
	}
	return $output;
}

