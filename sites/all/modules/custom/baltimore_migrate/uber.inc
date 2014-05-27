<?php
class UberOrganizationMigration extends Migration {
  public function __construct() {
    parent::__construct();

    //The defintion of the columns. Keys are integers. values are array(field name, description).
    $columns = array(
      0 => array('id_csv', 'ID'),
      1 => array('category_csv', 'Category'),
      2 => array('title_csv', 'Name'),
      4 => array('url_csv', 'URL'),
      5 => array('social_csv', 'Social Media Name'),
      6 => array('Facebook', 'Facebook'),
      7 => array('Twitter', 'Twitter'),
      8 => array('YouTube', 'YouTube'),
      9 => array('GovDelivery', 'GovDelivery'),
      10=> array('Instagram', 'Instagram'),
      11=> array('GooglePlus', 'Google Plus'),
      12=> array('SoundCloud', 'SoundCloud'),
      13=> array('SoundCloud', 'Flickr'),
      14=> array('Blogger', 'Blogger'),
      15=> array('WordPress', 'WordPress'),
      16=> array('Pinterest', 'Pinterest'),
      17=> array('Vimeo', 'Vimeo'),
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
    
    $this->addFieldMapping('field_url', 'url_csv');
    $this->addFieldMapping('field_social_label', 'social_csv');
    
    
    //$this->addFieldMapping('field_short_title', 'Facebook');

    //$this->addUnmigratedSources(array('Facebook', 'Twitter', 'YouTube', 'GovDelivery', 'Instagram', 'Google Plus', 'SoundCloud', 'Blogger', 'WordPress', 'Pinterest', 'Vimeo'), t('Do Not Migrate'));
  }

  function prepareRow($row) {
  }

  public function prepare($entity, stdClass $row){
    //dpm($row);
    //dpm($entity);
  }

  public function complete($entity, $row) {
    $fields = array('Facebook', 'Twitter', 'YouTube', 'GovDelivery', 'Instagram', 'Google Plus', 'SoundCloud', 'Blogger', 'WordPress', 'Pinterest', 'Vimeo');

    foreach ($fields as $field) {
      if (!empty($row->{$field})) {
        $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_social_networks'));
        $field_collection_item->field_social_network_type[LANGUAGE_NONE][0]['value'] = strtolower($field);
        $field_collection_item->field_social_network_account[LANGUAGE_NONE][0]['value'] = $row->{$field};
        $field_collection_item->setHostEntity('node', $entity);
        $field_collection_item->save(TRUE);
      }
    }
    node_save($entity);
  }
}