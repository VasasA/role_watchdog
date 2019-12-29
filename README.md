Role Watchdog
=============

Role watchdog automatically logs all role changes made through the user profile
or the User List in its own table. A record of these changes is shown in a Track
role history tab on each user's page. Role watchdog can optionally monitor one or 
more specific roles for changes and notify members of selected roles via email 
whenever a change occurs.

This module might be useful when there are multiple administrators for a site, 
and you need auditing or alerting of manual role changes.


Dependencies
------------

None.


Installation
------------

- Install this module using the official Backdrop CMS instructions at
https://backdropcms.org/guide/modules
- Configuration page: Administration > Configuration > User accounts > Role watchdog


Usage
-----

Role watchdog will automatically start recording all role changes. No further 
configuration is necessary for this functionality, the module will do this "out
of the box". A record of these changes is shown in a Track role history tab on
each user's page and optionally in the Watchdog log if enabled. Users will need 
either "View role history" or "View own role history" access permissions to 
view the tab.

The Track role grants tab on the administrator's page lists the role changes
provided by the administrator.

Role watchdog generates a report about role assignments for users:
Administration > Reports > Role grants report

Role watchdog can optionally email members of selected Notify roles when 
selected Monitor roles are added or removed. This was specifically added to 
keep a closer eye on certain role changes, such as an Administrator role. At 
least one Monitor role and one Notify role must be selected for this 
functionality.

Role watchdog is integrated with Views module:
- Create a new view what shows "User accounts".
(Administration > Structure > Views > Add view > Show: User accounts)
- Add fields provided by Role watchdog: role, change, date, user, history ID 


Issues
------

Bugs and Feature requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/role_watchdog/issues


Current Maintainers
-------------------

- Attila Vasas (https://github.com/vasasa).


Credits
-------

- Ported to Backdrop CMS by Attila Vasas (https://github.com/vasasa).
- Originally written for Drupal by John Money (https://www.drupal.org/u/johnmoney).


License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.


Screenshots
-----------
Track role history tab on the user's page:
![Role watchdog screenshot 1](https://github.com/backdrop-contrib/role_watchdog/blob/1.x-1.x/images/screenshot1.png)

Integration with Views module:
![Role watchdog screenshot 2](https://github.com/backdrop-contrib/role_watchdog/blob/1.x-1.x/images/screenshot2.png)
