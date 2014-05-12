<?php

class BaltimoreStoriesMigration extends XMLMigration {
  public function __construct($arguments) {
    $this->arguments = $arguments;
    parent::__construct();

    // IMPORTANT: Do not try this at home! We have included importable files
    // with the migrate_example module so it can be very simply installed and
    // run, but you should never include any data you want to keep private
    // (especially user data like email addresses, phone numbers, etc.) in the
    // module directory. Your source data should be outside of the webroot, and
    // should not be anywhere where it may get committed into a revision control
    // system.

    // This can also be an URL instead of a local file path.
    //$xml_folder = DRUPAL_ROOT . '/' .
    //              drupal_get_path('module', 'migrate_example') . '/xml/';
    $items_url = !empty($this->arguments['url']) ? $this->arguments['url'] : 'http://www.baltimorecity.gov/DesktopModules/DnnForge%20-%20NewsArticles/Rss.aspx?TabID=66&ModuleID=373&MaxCount=200';
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/rss/channel/item';
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /positions/position/sourceid.
    $item_ID_xpath = 'link';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('story');

    // The source ID here is the one retrieved from each data item in the XML
    // file, and used to identify specific items
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'link' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationRole::getKeySchema()
    );

    $this->addFieldMapping('title', 'title')
      ->xpath('title');
    $this->addFieldMapping(NULL, 'link')
      ->xpath('link');
    //$this->addFieldMapping('body', 'null');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('filtered_html');

    // Add redirect
    $this->addFieldMapping('migrate_redirects', 'link');

    //$this->addUnmigratedDestinations(array('weight'));
  }

  public function prepareRow($row) {
    $dom = new DomDocument;
    $dom->loadHTMLFile($row->link);
    $xpath = new DomXPath($dom);
    foreach($xpath->query('//div[@class="pressReleaseHeader"]|//h2|//div[@class="articlesMoreInfo"]|//div[@style="text-align:center;font-style:italic;"]') as $node) {
      $node->parentNode->removeChild($node);
    }
    $row->body = '';
    foreach ($xpath->query('//div[@class="articleViewWrapper"]') as $i => $node) {
      $row->body .= $node->ownerDocument->saveHTML($node);
    }
    $row->body = str_replace('<br><br>', '</p><p>', $row->body);
  }

  public function prepare(stdClass $entity, stdClass $row) {
    $entity->status = 1;
  }

  function complete($entity, $row) {
    // Create a redirect from the old path to the new one
    _baltimore_migrate_create_redirect($entity, $row->link, 'http://www.baltimorecity.gov/');
  }
}





class BaltimoreContentMigration extends Migration {
  public function __construct($arguments) {
    $this->arguments = $arguments;
    //$this->arguments['doctypes'] = !empty($this->arguments['doctypes']) ? $this->arguments['doctypes'] : array('pdf', 'doc', 'docx', 'xls', 'xlsx')
    if (empty($arguments['url'])) {
      return FALSE;
    }

    parent::__construct();

    //The defintion of the columns. Keys are integers. values are array(field name, description).
    $columns = array(
      0 => array('title', 'title'),
      1 => array('type', 'type'),
      2 => array('old_url', 'old url'),
      3 => array('migrate', 'migrate'),
      4 => array('section', 'section'),
    );

    //The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('Import entities from spreadsheet.');

    //The Source of the import
    $this->source = new MigrateSourceCSV($this->arguments['url'], $columns, array('delimiter' => ',', 'header_rows' => 1));

    //The destination boundle
    $this->destination = new MigrateDestinationNode(!empty($this->arguments['content_type']) ? $this->arguments['content_type'] : 'page');

    //Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    //Field mapping
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('filtered_html');
  }

  function prepareRow($row) {
    $row->title = trim($row->title);
    $row->old_url = trim($row->old_url);

    // Get the legacy content (if applicable)
    if ($row->migrate == 1 || strtoupper($row->migrate) === 'Y') {
      // Fixes fatal errors is there are more than one of the same id
      // See http://stackoverflow.com/questions/18943954/removing-docdocument-warning-while-parsing-page-content
      libxml_use_internal_errors(TRUE);
      $dom = new DomDocument;
      $dom->loadHTMLFile($row->old_url);
      libxml_clear_errors();
      $xpath = new DomXPath($dom);
      // @todo: implement exclude?
      //foreach($xpath->query('//div[@class="pressReleaseHeader"]|//h2|//div[@class="articlesMoreInfo"]|//div[@style="text-align:center;font-style:italic;"]') as $node) {
      //  $node->parentNode->removeChild($node);
      //}

      // Deal with legacy links and images
      foreach($xpath->query('//a[@href]') as $node) {
        $url = $node->getAttribute('href');
        if (strpos($url, $this->arguments['base_url']) !== FALSE) {
          if (strpos($url, '.htm') === FALSE) {
            _baltimore_migrate_save_file($url);
            $node->setAttribute('href', 'file/'.$file->fid);
          }
          else {
            // @todo: Record this somewhere that we'll need to update this link?
          }
        }
      }
      foreach($xpath->query('//img[@src]') as $node) {
        $url = $node->getAttribute('src');
        if (strpos($url, $this->arguments['base_url']) !== FALSE) {
          _baltimore_migrate_save_file($url);
          $node->setAttribute('src', 'file/'.$file->fid);
        }
      }

      $row->body = '';
      foreach ($xpath->query($this->arguments['xpath']) as $i => $node) {
        $row->body .= $node->ownerDocument->saveHTML($node);
      }
      unset($xpath);
      unset($dom);
      $row->body = str_replace('<br><br>', '</p><p>', $row->body);
    }
    else {
      $row->body = '';
    }
    dpm($row);

  }

  public function prepare($entity, stdClass $row){

    // Set the domain
    $node->domains[$this->arguments['domain']] = $this->arguments['domain'];

    // Override the default node type, if specified
    if (!empty($row->type)) {
      $entity->type = $row->type;
    }

    // Set moderation section
    $tid = !empty($row->section) ? $row->section : $this->arguments['default_section'];
    $entity->workbench_access = array($tid => $tid);

    // Create menu link
    $entity->menu = array(
      'link_title' => $row->title,
      'description' => $row->title,
      'menu_name' => $this->arguments['menu_name'],
      'plid' => 0,
      'enabled' => 1,
    );
    dpm($entity);
  }

  function complete($entity, $row) {
    // Create a redirect from the old path to the new one
    if (!empty($row->old_url)) {
      _baltimore_migrate_create_redirect($entity, $row->old_url, $this->arguments['base_url']);
    }
  }
  
}


// From http://www.group42.ca/creating_url_redirects_with_migrate_module
function _baltimore_migrate_create_redirect($entity, $url, $base_domain) {
  if (isset($url)) {
    // Create an object with our redirect parameters
    $redirect = new stdClass();
    $redirect->source = str_replace($base_domain, '', $url);
    $redirect->source_options = array();
    $redirect->redirect = 'node/'. $entity->nid;
    $redirect->redirect_options = array();
    $redirect->status_code = 0;
    $redirect->type = 'redirect';
    $redirect->language = LANGUAGE_NONE;

    // Create the redirect
    redirect_save($redirect);
  }
}


// From http://stackoverflow.com/questions/9082121/programmatically-save-image-from-external-url-drupal
function _baltimore_migrate_save_file($url) {
  $directory = file_build_uri('legacy');
  if (!file_prepare_directory($directory, FILE_CREATE_DIRECTORY)) {
    $directory = NULL;
  }
  $file = system_retrieve_file($url, $directory, TRUE);
  dpm($file);
  return $file;
}