@todo: put this in install.php
Note: you need to run this sql command after installation to make these run after pathauto
```
update system set weight=2 where name="flight_city_workbench";
update system set weight=2 where name="domain_access";
```

This module requires the patch https://drupal.org/files/workbench_access-list_of_users-1350764-26.patch from https://drupal.org/node/1350764#comment-7146170 to make the workbench_access rules work.