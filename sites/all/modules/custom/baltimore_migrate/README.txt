To install
* Create files/legacy/ dir

To run migrations:
  ~/drush/drush @pantheon.baltimorecity.dev  dis -y menu_trail_by_path ckeditor_link_file
  ~/drush/drush @pantheon.baltimorecity.dev  en maillog
  ~/drush/drush @pantheon.baltimorecity.dev  vset maillog_send 0
  ~/drush/drush @pantheon.baltimorecity.dev  vset maillog_devel 0
  ~/drush/drush @pantheon.baltimorecity.dev  mi ...
  ~/drush/drush @pantheon.baltimorecity.dev  en -y menu_trail_by_path ckeditor_link_file flight_input_formats