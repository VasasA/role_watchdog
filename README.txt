$Id$


Description
-----------
Role Watchdog automatically logs all role changes made through the user profile
or the User List. Role Watchdog can also monitor one or more roles for user 
additions or deletions and notify via email whenever a change occurs. This 
module might be useful when there are multiple administrators for a site, and 
you need auditing or alerting of manual role changes.


Prerequisites
-------------
None


Installation
------------
1. copy the role_watchdog directory and all its contents to your modules 
   directory
2. enable the module: admin/build/modules
3. configure the module: admin/settings/role_watchdog


Usage
-----
After enabling the module, Role Watchdog will automatically start recording
role changes in the log. If you have configured Role Watchdog to monitor one or
more roles for changes, members of the notification group(s) will also receive
emails notifying them of role changes.


Download
--------
Download package and report bugs, feature requests, or submit a patch from the 
project page on the Drupal web site.
http://drupal.org/project/role_watchdog


Changelog
---------
1.0  initial release


Todo List
---------
None


Author
------
ossemble LLC
http://ossemble.com

Module development sponsored by LifeWire, a subsidiary of The New York Times 
Company.
http://www.lifewire.com
