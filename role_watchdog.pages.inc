<?php

/**
 * @file
 * User page callbacks for the role_watchdog module.
 */

/**
 * Display tab page from menu callback.
 *
 * @param $account
 *   User object.
 */
function role_watchdog_history($account) {
  $output = '';
  $rows = $rows2 = array();

  $roles = user_roles();
  $roles_account = $account->roles;
  unset($roles_account[DRUPAL_AUTHENTICATED_RID]); // No built-in roles.
  $roles_output = count($roles_account) ? '<h3>' . t('Roles') . '</h3>' . theme('item_list', array('items' => array_keys(array_flip($roles_account)))) : '';

  $view_profile = user_access('access user profiles');
  $header = array(
    array(
      'data' => t('Date'),
      'style' => 'width: 25%;',
    ),
    array(
      'data' => t('Role'),
      'style' => 'width: 30%;',
    ),
    array(
      'data' => t('Change'),
      'style' => 'width: 15%;',
    ),
    array(
      'data' => t('User'),
      'style' => 'width: 40%;',
    ),
  );

  $result = db_query('SELECT rw.rid, rw.action, rw.uid, rw.stamp, u.name FROM {role_watchdog} rw INNER JOIN {users} u USING (uid) WHERE rw.aid = :aid ORDER BY rw.stamp DESC', array(':aid' => $account->uid));
  while ($row = $result->fetchObject()) {
    $rows[] = array(
      format_date($row->stamp),
      $roles[$row->rid],
      $row->action ? t('added by') : t('removed by'),
      $view_profile ? l($row->name, 'user/' . $row->uid) : $row->name,
    );
  }

  if (sizeof($rows)) {
    $output .= '<h3>' . t('Role History') . '</h3>' . theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('style' => 'width: 99%;')));
  }

  $result = db_query('SELECT rw.rid, rw.action, rw.aid, rw.stamp, u.name FROM {role_watchdog} rw INNER JOIN {users} u ON (rw.aid = u.uid) WHERE rw.uid = :uid ORDER BY rw.stamp DESC', array(':uid' => $account->uid));
  while ($row = $result->fetchObject()) {
    $rows2[] = array(
      format_date($row->stamp),
      $roles[$row->rid],
      $row->action ? t('added to') : t('removed from'),
      $view_profile ? l($row->name, 'user/' . $row->aid) : $row->name,
    );
  }

  if (sizeof($rows2)) {
    $output .= '<h3>' . t('Role Changes Made') . '</h3>' . theme('table', array('header' => $header, 'rows' => $rows2, 'attributes' => array('style' => 'width: 99%;')));
  }

  return $output ? $roles_output . $output : t('No role history found.');
}
