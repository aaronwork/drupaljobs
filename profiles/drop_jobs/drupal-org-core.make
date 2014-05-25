api = 2
core = 7.x

projects[drupal][type] = core
projects[drupal][version] = 7.19

; Core Patches

; Fixes object of class stdClass could not be converted to int in _menu_router_build().
projects[drupal][patch][] = http://drupal.org/files/issues/object_conversion_menu_router_build-972536-1.patch

; Fixed nothing Clears the "5 Failed Login Attempts" Security message.
projects[drupal][patch][] = http://drupal.org/files/issues/992540-3-reset_flood_limit_on_password_reset-drush.patch

; Fixes undefined index: configurable in actions_synchronize().
projects[drupal][patch][] = http://drupal.org/files/drupal-actions-985814-11-D7.patch

; Make install profiles inheritable.
projects[drupal][patch][] = http://drupal.org/files/1356276-make-D7-21.patch

; Fixes integrity constraint violation when adding permissions, see http://drupal.org/node/1063204.
projects[drupal][patch][] = http://drupal.org/files/drupal-7.x-fix_pdoexception_grant_permissions-737816-26-do-not-test.patch

; Add "exclusive" property to install profiles to auto-select them.
; @todo: Part of core as of 7.20, so remove whenever that comes out.
projects[drupal][patch][1727430] = http://drupal.org/files/drupal-provide_exclusive_property_install_profiles-1727430-35-d7.patch