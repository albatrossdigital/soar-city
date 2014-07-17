<?php

/**
 * @file
 * Because the name of this file is the module name plus '.migrate.inc', when
 * hook_migrate_api is invoked by the Migrate module this file is automatically
 * loaded - thus, you don't need to implement your hook in the .module file.
 */

/*
 * You must implement hook_migrate_api(), setting the API level to 2, if you are
 * implementing any migration classes. As of Migrate 2.5, you should also
 * register your migration and handler classes explicitly here - the former
 * method of letting them get automatically registered on a cache clear will
 * break in certain environments (see http://drupal.org/node/1778952).
 */
function baltimore_migrate_migrate_api() {

  $migrations = array(
    'UberOrganization' => array('class_name' => 'UberOrganizationMigration'),


    // Placeholder / Demo
    // This is needed for legacy support
    // @todo: remove
    'BaltimoreContent' => array(
      'class_name' => 'BaltimoreContentMigration',
      'domain' => 3,
      'menu_name' => '8a5cf1368d89144ef92c695bf3eb0e21',
      'url' => DRUPAL_ROOT . '/WORKING/data/health-content.csv',
      'base_url' => 'http://www.baltimorehealth.org/',
      'default_section' => 36,
    ),

    // Mayor
    'BaltimoreMayorStories' => array(
      'class_name' => 'BaltimoreMayorStoriesMigration',
      'domain' => 2,
      'base_url' => 'http://www.baltimorecity.gov/',
      'default_section' => 'f6a2f72ba753a685bd81acf755ff8635',
      'create_redirect' => TRUE,
      'story_type' => 58,
      'url' => 'http://www.baltimorecity.gov/DesktopModules/DnnForge%20-%20NewsArticles/Rss.aspx?TabID=66&ModuleID=373&MaxCount=2000&FeaturedOnly=True&sortBy=StartDate&sortDirection=DESC',
      'file_destination' => 'public://mayor/legacy',
      // These are hard-coded into the base migration
      //'xpath' => '//div[@class="contentDiv"]',
      //'xpath_exclude' => '//div[@class="contentDiv"]',
    ),
    'BaltimoreMayorContent' => array(
      'class_name' => 'BaltimoreMayorContentMigration',
      'domain' => 2,
      'menu_name' => '8a5cf1368d89144ef92c695bf3eb0e21',
      'url' => DRUPAL_ROOT . '/WORKING/data/mayor-content.csv',
      'base_url' => 'http://www.baltimorecity.gov/',
      'default_section' => 'f6a2f72ba753a685bd81acf755ff8635',
      'xpath' => '//div[@id="dnn_ContentPane"]',
      'file_destination' => 'public://mayor/legacy',
      'create_redirect' => TRUE,
    ),

    // Health
    'BaltimoreHealthContent' => array(
      'class_name' => 'BaltimoreHealthContentMigration',
      'domain' => 3,
      'menu_name' => '8a5cf1368d89144ef92c695bf3eb0e21',
      'url' => DRUPAL_ROOT . '/WORKING/data/health-content.csv',
      'base_url' => 'http://www.baltimorehealth.org/',
      'default_section' => '8a5cf1368d89144ef92c695bf3eb0e21',
      'xpath' => '//div[@class="contentDiv"]',
      'file_destination' => 'public://health/legacy',
      'create_redirect' => TRUE,
    ),
    'BaltimoreHealthContentMore' => array(
      'class_name' => 'BaltimoreHealthContentMoreMigration',
      'domain' => 3,
      'menu_name' => '8a5cf1368d89144ef92c695bf3eb0e21',
      'url' => DRUPAL_ROOT . '/WORKING/data/health-content.csv',
      'base_url' => 'http://www.baltimorehealth.org/',
      'default_section' => '8a5cf1368d89144ef92c695bf3eb0e21',
      'xpath' => '//div[@class="contentDiv"]',
      'file_destination' => 'public://health/legacy',
      'create_redirect' => TRUE,
    ),

    // Tier-1 simple Agencies
    'BaltimoreWarMemorialContent' => array(
      'class_name' => 'BaltimoreWarMemorialContentMigration',
      'domain' => 5,
      'subdomain' => 'War Memorial Commission',
      'menu_name' => '480eeaeaeab4db3c8327ed0d9871c83c',
      'url' => DRUPAL_ROOT . '/WORKING/data/warmemorial-content.csv',
      'base_url' => 'http://warmemorial.baltimorecity.gov/',
      'default_section' => '1212',
      'xpath' => '//div[@id="dnn_ContentPane"]',
      'file_destination' => 'public://warmemorial/legacy',
      'create_redirect' => TRUE,
    ),
    'BaltimoreLaborCommissionContent' => array(
      'class_name' => 'BaltimoreLaborCommissionContentMigration',
      'domain' => 7,
      'subdomain' => 'Labor Commissioner\'s Office',
      'menu_name' => '0314cec21ebb781fa0fbf81350645138',
      'url' => DRUPAL_ROOT . '/WORKING/data/labor-commissioner-content.csv',
      'base_url' => 'http://www.baltimorecity.gov/',
      'default_section' => '1213',
      'xpath' => '//div[@id="dnn_ContentPane"]',
      'file_destination' => 'public://labor-commissioner/legacy',
      'create_redirect' => TRUE,
    ),
    'BaltimoreLawContent' => array(
      'class_name' => 'BaltimoreLawContentMigration',
      'domain' => 6,
      'subdomain' => 'Baltimore City Law Department',
      'menu_name' => 'f18a4d7eb2d32b3f139819ad68d1853d',
      'url' => DRUPAL_ROOT . '/WORKING/data/law-content.csv',
      'base_url' => 'http://www.baltimorecity.gov/',
      'default_section' => '1211',
      'xpath' => '//div[@id="dnn_ContentPane"]',
      'file_destination' => 'public://law/legacy',
      'create_redirect' => TRUE,
    ),
  );

  $api = array(
    'api' => 2,
    'migrations' => $migrations,
  );
  return $api;
}


