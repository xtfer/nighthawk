<?php

/**
 * Define bits and bobs
 */

/**
 *  Site root
 */
define(NH_SITE_ROOT, '/');

/**
 * Server
 */
define(NH_SERVER, 'http://example.com');

/**
 * Site home path.
 */
define(NH_HOME, 'index');

/**
 * Site folder
 */
define(NH_SITE_FOLDER, 'site');

/**
 * Whether or not to use clean URLs.
 */
define(NH_CLEAN_URL, TRUE);

// Add includes folder to include_path
set_include_path(dirname(__FILE__) . ':' . get_include_path());