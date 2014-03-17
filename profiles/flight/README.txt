Flight
======

Flight is a Drupal distribution that takes all of the cutting-edge Drupal 7 features and packages them together so they work out of the box. Whereas the excellent Panopoly distro relies heavily on Panels and Page Manager, we feel like Context and Display Suite save us clicks and help us finish projects faster. We use Zurb Foundation as a grid-based, responsive theme and add some advanced grunt and sass workflows to help you make your site look beautiful quicker.

Key Features
------------
+ Standardize your responsive design and theming workflow with Zurb Foundation (http://foundation.zurb.com) and SASS mixins
+ Setup grunt to watch for SASS changes, auto-reload your browser, and check theme optimization
+ Context for page layout and Display Suite for node view layout
+ Filepicker.io, oEmbed, and Media integration that works out of the box (and is fully responsive)
+ Edit and CKEditor's in-place editor for an amazing administrative interface out of the box

Pre-installation (not required)
-------------------------------
+ In the profile directory (profiles/flight), run
    drush make flight-libraries.make --no-core --contrib-destination .
  This manually installs a number of libraries that can't be installed by default because they are not yet whitelisted on http://drupal.org/packaging-whitelist.

Installation
------------
Flight is fully packaged by Drupal.org and can be downloaded and installed on your own server similar to Drupal core.

Post-Installation
-----------------
+ If CKEditor is not appearing, go to /admin/config/content/ckeditor/edit/Flight and check the Rich Text and Unfiltered Rich Text checkboxes.
+ To get the Ink Filepicker to work, Go to https://filepicker.io and create an account. Enter your key on /admin/config/media/filepickerio.
+ To get share buttons to work, go to http://share42.com and, select your libraries and put in profiles/flight/libraries/share42 (or sites/all/libraries/share42)
+ Optional: To support embedding from over 200 sources including YouTube and Scribd: Enable oembedembedly. Go to http://embed.ly, and create an account. Enter your account credentials on

Other Features
--------------
+ Beans for exportable blocks
+ Quickly create your sub-theme with Grunt (and no search and replace)
+ Bash scripts to install LiveReload so you don't need to hit F5 everytime you edit your SASS file
+ Administration Menu is used for superuser, while Toolbar is used for all other administration users
+ Easily add support for slideshows, event calendars, webforms (with form builder) and advanced workflows (with Workbench), by enabling optional features

Drupal Structure Document
-------------------------
Site planning is an essential part to any successful Drupal Build. ___ came up with an excellent
Google Docs spreadsheet template for planning content types, view, display modes and more.  We have
created a version of this structure document for all of the Flight features.  Use it to start your
planning for your next project:
https://docs.google.com/spreadsheet/ccc?key=0Alw0s_pQVmyXdFRwWmxLWnFfNHFSM1BSQkhsdG4wcmc&usp=sharing

What's the difference between the 1.0 and 2.0 branches?
-------------------------------------------------------
We overhauled most of this distro between 7.x-1.0-alpha1 and 7.x-2.0-alpha1, including:
* Changing the base theme from the Twitter Bootstrap-based Open Framework to Zurb Foundation
* Removing Edit (the edit-in-place module) because of a fatal error with CKEditor/Media
* Adding more required modules and configuration out-of-the-box
For a full list, see CHANGELOG.txt

Who
---
Flight was developed and is maintained by Albatross Digital. We use it as the starting-point for our projects.

Manually Building
-----------------
  drush verify-makefile drupal-org.make
  drush make --no-cache --drupal-org drupal-org.make tmp
  rsync -a tmp/* .
  rm -r tmp
  drush make flight-libraries.make --no-core --contrib-destination .


If you would prefer to manually build the additional libraries, here are the steps:

Download the CKEditor Silver skin and unzip it in flight/libraries/ckeditor/skins
https://github.com/oleq/silver/archive/master.zip
Rename the directory to "silver" so that the path to skin.js is flight/libraries/ckeditor/skins/silver/skin.js

Download the CKEditor Autogrow plugin and unzip it in flight/libraries/ckeditor/plugins
http://download.ckeditor.com/autogrow/releases/autogrow_4.3.zip
Your path to plugin.js should be profiles/flight/libraries/ckeditor/plugins/autogrow/plugin.js

Download version 2.1.2 of the imagesloaded jquery plugin. Unzip it in your libraries directory.
http://github.com/desandro/imagesloaded/archive/v2.1.2.tar.gz
Rename the directory to jquery.imagesloaded so that the path to jquery.imagesloaded.min.js is either
sites/all/libraries/jquery.imagesloaded/jquery.imagesloaded.min.js
profiles/flight/libraries/jquery.imagesloaded/jquery.imagesloaded.min.js

Download the imgareaselect JQuery plugin and unzip it in your libraries directory.
http://odyniec.net/projects/imgareaselect/jquery.imgareaselect-0.9.10.zip
Rename your directory to jquery.imgareaselect. Your path to jquery.imgareaselect.min.js should be
sites/all/libraries/jquery.imgareaselect/scripts/jquery.imgareaselect.min.js
profiles/flight/libraries/jquery.imgareaselect.min.js/scripts/jquery.imgareaselect.min.js


Recommended customizations to settings.php
------------------------------------------
These are common changes made to settings.php for Pantheon-hosted sites:

<?php
// It's easier to store some api configs in settings.php if deploying multiple sites
$conf['media_inkfilepicker_key'] = '';

// Force caching on prod site
if (isset($_SERVER['PANTHEON_ENVIRONMENT']) && $_SERVER['PANTHEON_ENVIRONMENT'] === 'live') {
  $conf['cache'] = 1;
  $conf['block_cache'] = 1;
  $conf['preprocess_css'] = 1;
  $conf['preprocess_js'] = 1;
  $conf['page_cache_maximum_age'] = 900;  // 15 mins
  $conf['advagg_enabled'] = 1; 
}

// Setup redis
if (defined('PANTHEON_ENVIRONMENT')) {
  // Use Redis for caching.
  $conf['redis_client_interface'] = 'PhpRedis';
  $conf['cache_backends'][] = 'profiles/flight/modules/contrib/redis/redis.autoload.inc';
  $conf['cache_default_class'] = 'Redis_Cache';
  $conf['cache_prefix'] = array('default' => 'pantheon-redis');
  // Do not use Redis for cache_form (no performance difference).
  $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
  // Use Redis for Drupal locks (semaphore).
  $conf['lock_inc'] = 'sites/all/modules/contrib/redis/redis.lock.inc';
}
// Optional Pantheon redis settings.
if (defined('PANTHEON_ENVIRONMENT')) {
  // High performance - no hook_boot(), no hook_exit(), ignores Drupal IP blacklists.
  $conf['page_cache_without_database'] = TRUE;
  $conf['page_cache_invoke_hooks'] = FALSE;
  // Explicitly set page_cache_maximum_age as database won't be available.
  $conf['page_cache_maximum_age'] = 300;
}

// Redirect all domains to TLD
if (isset($_SERVER['PANTHEON_ENVIRONMENT']) && $_SERVER['PANTHEON_ENVIRONMENT'] === 'live') {
  if ($_SERVER['HTTP_HOST'] != 'example.com') {
    header('HTTP/1.0 301 Moved Permanently'); 
    header('Location: http://example.com'. $_SERVER['REQUEST_URI']); 
    exit();
  }
}

// Allow feeds to import more records per run
//$conf['feeds_process_limit'] = 1000;


?>


Recommended settings for a local settings.php
---------------------------------------------
Disable caches, reset the files directory
<?php
$conf['cache'] = 0;
$conf['block_cache'] = 0;
$conf['preprocess_css'] = 0;
$conf['preprocess_js'] = 0;
$conf['preprocess_js'] = 0;
$conf['file_temporary_path'] = '/tmp';
$conf['file_public_path'] = 'sites/example.local/files';
$conf['file_private_path'] = 'sites/example.local/files/private';

?>