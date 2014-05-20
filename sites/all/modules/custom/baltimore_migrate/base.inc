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
    $items_url = $this->arguments['url'];
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

    // Published date
    $this->addFieldMapping('created', 'pubDate')
      ->xpath('pubDate');
    $this->addFieldMapping('updated', 'pubDate')
      ->xpath('pubDate');

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
    $row->body = _baltimore_migrate_strip_tags($row->body);
  }

  public function prepare(stdClass $entity, stdClass $row) {
    $entity->status = 1;

    // Set the story type
    if (!empty($this->arguments['story_type'])) {
      $entity->field_story_type[LANGUAGE_NONE][0]['tid'] = $this->arguments['story_type'];
    }

    // Set the domain
    $entity->domains[$this->arguments['domain']] = $this->arguments['domain'];

    // Set moderation section
    $entity->workbench_access = array($this->arguments['default_section'] => $this->arguments['default_section']);
  }

  function complete($entity, $row) {
    // Create a redirect from the old path to the new one
    if ($this->arguments['create_redirect']) {
      _baltimore_migrate_create_redirect($entity, $row->link, 'http://www.baltimorecity.gov/');
    }
  }
}





class BaltimoreContentMigration extends Migration {
  public function __construct($arguments) {
    $this->arguments = $arguments;

    //$this->arguments['doctypes'] = !empty($this->arguments['doctypes']) ? $this->arguments['doctypes'] : array('pdf', 'doc', 'docx', 'xls', 'xlsx')
    if (empty($arguments['url'])) {
      return FALSE;
    }
    $arguments['file_destination'] = !empty($arguments['file_destination']) ? $arguments['file_destination'] : 'public://';

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
    if ((empty($row->migrate) || $row->migrate == '' || $row->migrate == 1 || strtoupper($row->migrate) === 'Y') && !empty($row->old_url)) {
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
        $url = strpos($url, 'http://') === FALSE ? $this->arguments['base_url'].$url : $url;
        if (!empty($url) && strpos($url, $this->arguments['base_url']) !== FALSE) {
          $extension = end(explode('.', $url));
          //dpm($url);
          //dpm($extension);
          if (
            (strlen($extension) > 2 && strlen($extension) < 5 && !in_array($extension, array('html', 'htm', 'asp', 'aspx'))) 
            || strpos($url, 'LinkClick.aspx?fileticket=') !== FALSE
          ) {
            //dpm($url);

            if ($file = _baltimore_migrate_save_file($url, $arguments['file_destination'])) {
              if (empty($file->type) || $file->type == 'undefined') {
                $file->type = 'document';
                $file->filemime = 'application/pdf';
                file_save($file);
              }
              //dpm($file);
              $node->setAttribute('href', url('file/'.$file->fid));
            }
          }
          else {
            //@ todo: log this somewhere?
            //db_query('insert into {baltimore_migrate_redirects} (class_name, source_old_url, link_url) values("'.$this->arguments['class_name'].'", "'.$row->old_url.'", "'.$url.'");');
          }
        }
      }
      /*foreach($xpath->query('//img[@src]') as $node) {
        $url = $node->getAttribute('src');
        if (strpos($url, $this->arguments['base_url']) !== FALSE) {
          $file = _baltimore_migrate_save_file($url);
          $node->setAttribute('src', 'file/'.$file->fid);
        }
      }*/

      $row->body = '';
      foreach ($xpath->query($this->arguments['xpath']) as $i => $node) {
        $row->body .= $node->ownerDocument->saveHTML($node);
      }
      unset($xpath);
      unset($dom);
      $row->body = _baltimore_migrate_strip_tags($row->body);
    }
    else {
      $row->body = '';
    }
  }

  public function prepare($entity, stdClass $row){

    // Set the domain
    $entity->domains[$this->arguments['domain']] = $this->arguments['domain'];

    // Override the default node type, if specified
    if (!empty($row->type)) {
      $entity->type = $row->type;
    }

    // Set moderation section
    $section = !empty($row->section) ? $row->section : $this->arguments['default_section'];
    //$entity->workbench_access = is_numeric($section) ?  array($section => $section) : _baltimore_migrate_workbench_access_get_item($section);
    $entity->workbench_access = array($section => $section);


    // Create menu link
    $entity->menu = array(
      'link_title' => $row->title,
      'description' => $row->title,
      'menu_name' => $this->arguments['menu_name'],
      'plid' => 0,
      'enabled' => 1,
    );
    //dpm($entity);
  }

  function complete($entity, $row) {
    // Create a redirect from the old path to the new one
    if (!empty($row->old_url) && $this->arguments['create_redirect']) {
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
function _baltimore_migrate_save_file($url, $destination) {
  $filename = basename($url);
  $url = str_replace(' ', '%20', $url);
  // @todo: break apart the url and use urlencode()?
  //$url = urlencode($url);
  // @tood: check mimetype?
  //$type = get_headers($url, 1)["Content-Type"];
  //if (in_array($type, array('application/pdf'))) {
    /*$directory = file_build_uri('public://legacy');
    if (!file_prepare_directory($directory, FILE_CREATE_DIRECTORY)) {
      $directory = NULL;
    }*/

    $file = system_retrieve_file($url, $destination, TRUE);
    if (!empty($file->fid)) {
      $file->filename = $filename;
      file_save($file);
    }
    return $file;
  //}
  // @todo: Record this somewhere that we'll need to update this link?
  return FALSE;
}


function _baltimore_migrate_strip_tags($text) {
  $text = str_replace('<br><br>', '</p><p>', $text);
  $text = strip_tags($text, '<p><a><h2><h3><h4><h5><strong><b><i><em><cite><blockquote><table><tr><td><scode><thead><tbody><img><ul><ol><li><dt><dd><sub><cite>');
  return $text;
}

