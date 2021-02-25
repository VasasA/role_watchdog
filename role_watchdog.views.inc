<?php

/**
 * @file
 * Role Watchdog Views hooks.
 *
 * Views module integration with the role watchdog module.
 *
 *
 * NOTE: The Views API hook hook_views_api must be defined in the main module.
 * @see role_watchdog_views_api() in role_watchdog.module.
 */

/**
 * Implements hook_views_data().
 *
 * The purpose of this hook is to tell Views what data we make available.
 */
function role_watchdog_views_data() {
  $data['role_watchdog']['table']['group'] = t('User');

  $data['role_watchdog']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'aid',
    ),
  );

  $data['role_watchdog']['hid'] = array(
    'title' => t('Role watchdog: history ID'),
    'help' => t('Role history ID'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['role_watchdog']['stamp'] = array(
    'title' => t('Role watchdog: date'),
    'help' => t('Date and time the role has changed'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['role_watchdog']['rid'] = array(
    'title' => t('Role watchdog: role'),
    'help' => t('The Role that changed'),
    'field' => array(
      'handler' => 'role_watchdog_handler_field_rid',
      'click sortable' => TRUE,
    ),
    // Information for accepting a rid as an argument.
    'argument' => array(
      'handler' => 'views_handler_argument_users_roles_rid',
      'name field' => 'title',
      'numeric' => TRUE,
      'validate type' => 'rid',
    ),
    // Information for accepting a uid as a filter.
    'filter' => array(
      'handler' => 'views_handler_filter_user_roles',
    ),
    // Information for sorting on a uid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['role_watchdog']['action'] = array(
    'title' => t('Role watchdog: change'),
    'help' => t('Type of change'),
    'field' => array(
      'handler' => 'role_watchdog_handler_field_action',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['role_watchdog']['uid'] = array(
    'title' => t('Role watchdog: user'),
    'help' => t('The user that changed the role'),
    // Information for displaying the uid.
    'field' => array(
      'handler' => 'role_watchdog_handler_field_uid',
      'click sortable' => TRUE,
    ),
    // Information for accepting a uid as an argument.
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'name field' => 'name',
      'numeric' => TRUE,
      'validate type' => 'uid',
    ),
    // Information for accepting a uid as a filter.
    'filter' => array(
      'handler' => 'views_handler_filter_user_name',
    ),
    // Information for sorting on a uid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

/**
 * Field rid handler.
 */
class role_watchdog_handler_field_rid extends views_handler_field {

  /**
   * Render the rid as the role name.
   */
  public function render($values) {
    $rid = $values->role_watchdog_rid;
    if (!empty($rid)) {
      $role = user_role_load($rid);
      return $role->label;
    }
  }

}

/**
 * Field action handler.
 */
class role_watchdog_handler_field_action extends views_handler_field {

  /**
   * Transform the binary action to human readable text.
   */
  public function render($values) {
    $action = $values->role_watchdog_action;
    if (isset($action)) {

      $action_value = '';

      switch ($action) {
        case 0:
          $action_value = t('removed by');
          break;

        case 1:
          $action_value = t('added by');
          break;
      }

      return $action_value;
    }
  }

}

/**
 * Field uid handler.
 */
class role_watchdog_handler_field_uid extends views_handler_field {

  /**
   * Render the uid as the username.
   */
  public function render($values) {
    $uid = $values->role_watchdog_uid;
    if (!empty($uid)) {
      $user = user_load($uid);
      return $user->name;
    }
  }

}
