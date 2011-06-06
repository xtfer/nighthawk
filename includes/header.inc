<?php 
/**
 * Header.inc
 */

$_title = $page_title ? $page_title . ' - ' : '';

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
			<base href="<?php echo NH_SERVER . NH_SITE_ROOT; ?>" />
      <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
      <meta name="keywords" content="" />
	    <meta name="description" content="My website" />
      <title><?php echo $_title; ?></title>
      <link rel="stylesheet" href="css/main.css"></link>
      <!--[if IE]>
		    <link rel="stylesheet" type="text/css" href="ie-only.css" />
	    <![endif]-->
    </head>
    
    <body>
    	<div id="main">
				<div id="header">
					<h1><?php echo $page_title; ?></h1>
					<div id="menu">
						<ul>
							<li><a href="/">Home</a></li>
							<li><a href="<?php echo k('section'); ?>">Link to page 2</a>
								<ul>
									<li><a href="<?php echo k('section/page'); ?>">Link to page 3</a></li>
								</ul>
							</li>
						</ul>
					</div>
				</div>