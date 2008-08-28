$Id$

Description
-------------
Role Watchdog automatically logs all role changes made through the user profile 
or the User List. Role Watchdog can optionally monitor one or more roles for 
changes and notify members of selected roles via email whenever a change 
occurs. Role Watchdog can optionally log role changes in its own table and 
display the role history on each user's page. 

This module might be useful when there are multiple administrators for a site, 
and you need auditing or alerting of manual role changes.


Dependencies
-------------
None


Installation
-------------
1. install module: copy role_watchdog directory and all its contents to your 
   modules directory
2. enable module: admin/build/modules
3. configure module: admin/user/roles/role_watchdog
4. configure access permissions: admin/user/access


Usage
-------------
Role Watchdog has three modes of operation. The module will automatically start 
recording all role changes in the watchdog log. No further configuration is 
necessary for this functionality, the module will do this "out of the box".

Role Watchdog can optionally email members of selected Notify roles when 
selected Monitor roles are added or removed. This was specifically added to 
keep a closer eye on certain role changes, such as an Administrator role. At 
least one Monitor role and one Notify role must be selected for this 
functionality.

Role Watchdog can optionally log role changes in its own table and display the 
role history on each user's page. Users will need either "View role history" or 
"View own role history" access permissions to view the tab. This functionality 
was added for a more permanent audit of role history.


Download
-------------
Download package and report bugs, feature requests, or submit a patch from the 
project page on the Drupal web site.
http://drupal.org/project/role_watchdog


Todo List
---------
None


Author
------
John Money
ossemble LLC.
http://ossemble.com

Module development sponsored by LifeWire, a service of About.com, a part of 
The New York Times Company.
http://www.lifewire.com
