
Description
---------------
Role watchdog automatically logs all role changes made through the user profile
or the User List in its own table. A record of these changes is shown in a Role
history tab on each user's page. Role watchdog can optionally monitor one or 
more specific roles for changes and notify members of selected roles via email 
whenever a change occurs.

This module might be useful when there are multiple administrators for a site, 
and you need auditing or alerting of manual role changes.

2010-04-28: the Role history tab is no longer optional. Going forward, 5.x will
no longer be supported.


Dependencies
---------------
None. Database logging is a Core (optional) module.

Tested compatible with:
* user edit (e.g. http://example.com/user/3/edit)
* user list (e.g. http://example.com/admin/user/user)
* Views Bulk Operations (VBO) 6.x-1.10
* Role Delegation 6.x-1.4

Related Modules
---------------
Role Delegation (http://drupal.org/project/role_delegation), 
RoleAssign (http://drupal.org/project/roleassign),
Administer Users by Role (http://drupal.org/project/administerusersbyrole)
  modules that enable user access to assign roles to other users where the
  auditing of Role watchdog is a nice fit.

Role Change Notify (http://drupal.org/project/role_change_notify)
  the mirror functionality of Role watchdog, notifying the user when a role is
  added to their account.


Installation
---------------
1. install module: copy role_watchdog directory and all its contents to your 
   modules directory
2. enable module: admin/build/modules
3. configure module: admin/user/roles/role_watchdog
4. configure access permissions: admin/user/permissions#module-role_watchdog


Usage
---------------
Role watchdog will automatically start recording all role changes. No further 
configuration is necessary for this functionality, the module will do this "out
of the box". A record of these changes is shown in a Role history tab on each
user's page and optionally in the Watchdog log if enabled. Users will need 
either "View role history" or "View own role history" access permissions to 
view the tab. 

Role watchdog can optionally email members of selected Notify roles when 
selected Monitor roles are added or removed. This was specifically added to 
keep a closer eye on certain role changes, such as an Administrator role. At 
least one Monitor role and one Notify role must be selected for this 
functionality.



Download
---------------
Download package and report bugs, feature requests, or submit a patch from the 
project page on the Drupal web site.
http://drupal.org/project/role_watchdog


Author
---------------
John Money
ossemble LLC.
http://ossemble.com

Module development sponsored by LifeWire, a service of About.com, a part of 
The New York Times Company.
http://www.lifewire.com
