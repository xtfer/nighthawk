<?php
/**
 * Site preloader
 */
// Load bootstrap
require_once('includes/bootstrap.inc');

// Get the query string and santize
$_GET  = sanitize($_GET);
$dest = $_GET['q'];

// strip site root from query string (if we are in a subfolder)
$l = strlen(NH_SITE_ROOT);
if(substr($dest, 0, $l) == NH_SITE_ROOT) {
	$k = strlen($dest);
	$m = $l - $k;
	$dest = substr($dest,$m + 1);
}

// check type of query string to include
if($dest == '' || $dest == 'index' || $dest == 'home') {
	// site root
	$call = NH_SITE_FOLDER.'/index.php';
	
} elseif(substr($dest,-4) == '.php') {
	// specific file
	$call = NH_SITE_FOLDER.'/'.$dest;
	
} else {
	// folder, load index.php in context
	$call = NH_SITE_FOLDER.'/'.$dest.'/index.php';

} 

ob_start();
// include the content
include($call);
$content = ob_get_clean();

// include the header 
include('includes/header.inc');

// Print content
echo $content;

// include the footer
include('includes/footer.inc');