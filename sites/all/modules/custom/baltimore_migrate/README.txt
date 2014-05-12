To install
* Create files/legacy/ dir

To run migrations:
  drush dis -y active_trail_by_menu ckeditor_link_file
  drush en maillog
  drush vset maillog_send 0
  drush vset maillog_devel 0
  drush mi ...
  drush en -y active_trail_by_menu ckeditor_link_file