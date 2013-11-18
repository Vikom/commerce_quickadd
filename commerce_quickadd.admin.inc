<?php

/**
 * @file
 * Administration page callbacks for Commerce Quick add.
 */

/**
 * Implements hook_admin_settings().
 */
function commerce_quickadd_admin_settings_form($form_state) {
  $form['commerce_quickadd_addby'] = array(
    '#title' => t('Add products by'),
    '#type' => 'select',
    '#options' => array('title' => t('Product title'), 'sku' => t('Product SKU')),
    '#default_value' => variable_get('commerce_quickadd_addby', ''),
  );

  return system_settings_form($form);
}
