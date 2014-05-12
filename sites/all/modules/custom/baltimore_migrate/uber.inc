<?php
class UberOrganizationMigration extends Migration {
  public function __construct() {
    parent::__construct();

    //The defintion of the columns. Keys are integers. values are array(field name, description).
    $columns = array(
      1 => array('id_csv', 'ID'),
      1 => array('category_csv', 'Category'),
      2 => array('title_csv', 'Name'),
      8 => array('Facebook', 'Facebook'),
      9 => array('Twitter', 'Twitter'),
      10=> array('YouTube', 'YouTube'),
      11=> array('GovDelivery', 'GovDelivery'),
      12=> array('Instagram', 'Instagram'),
      13=> array('GooglePlus', 'Google Plus'),
      14=> array('SoundCloud', 'SoundCloud'),
      15=> array('Blogger', 'Blogger'),
      16=> array('WordPress', 'WordPress'),
      17=> array('Pinterest', 'Pinterest'),
      18=> array('Vimeo', 'Vimeo'),
    );

    //The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('Import entities from spreadsheet.');

    //The Source of the import
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/WORKING/data/entities.csv', $columns, array('delimiter' => ',', 'header_rows' => 1));

    //The destination boundle
    $this->destination = new MigrateDestinationNode('organization');

    //Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'title_csv' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    //Field mapping
    $this->addFieldMapping('title', 'title_csv');
    $this->addFieldMapping('field_organization_category', 'category_csv');
    $this->addFieldMapping('field_organization_category:create_term')
      ->defaultValue(TRUE);
    
    
    $this->addFieldMapping('field_short_title', 'Facebook');

    //$this->addUnmigratedSources(array('Facebook', 'Twitter', 'YouTube', 'GovDelivery', 'Instagram', 'Google Plus', 'SoundCloud', 'Blogger', 'WordPress', 'Pinterest', 'Vimeo'), t('Do Not Migrate'));
  }

  function prepareRow($row) {
    dpm($row);
  }

  public function prepare($entity, stdClass $row){
    //dpm($row);
    //dpm($entity);
  }
}