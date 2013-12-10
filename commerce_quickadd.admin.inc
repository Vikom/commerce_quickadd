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
    '#required' => TRUE,
    '#options' => array('title' => t('Title'), 'sku' => t('SKU')),
    '#default_value' => variable_get('commerce_quickadd_addby', 'title'),
  );

  $form['commerce_quickadd_product_label'] = array(
    '#title' => t('Product field label'),
    '#type' => 'textfield',
    '#default_value' => variable_get('commerce_quickadd_product_label', 'Product'),
  );

  $form['commerce_quickadd_quantity_label'] = array(
    '#title' => t('Quantity label'),
    '#type' => 'textfield',
    '#default_value' => variable_get('commerce_quickadd_quantity_label', 'Quantity'),
  );

  $form['commerce_quickadd_submit_value'] = array(
    '#title' => t('Submit value'),
    '#type' => 'textfield',
    '#default_value' => variable_get('commerce_quickadd_submit_value', 'Add to cart'),
  );

  $form['commerce_quickadd_description'] = array(
    '#title' => t('Description'),
    '#type' => 'textfield',
    '#default_value' => variable_get('commerce_quickadd_description', 'Add products directly to your cart by enetering the article number and quantity and click the add to cart button.'),
  );

  $form['commerce_quickadd_result_limit'] = array(
    '#title' => t('Result limit'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('commerce_quickadd_result_limit', 10),
  );

  return system_settings_form($form);
}

function commerce_quickadd_admin_settings_form_validate($form, &$form_state) {
  // Check to ensure the result limit is valid.
  if (!is_numeric($form_state['values']['commerce_quickadd_result_limit'])) {
    form_set_error('commerce_quickadd_result_limit', t('Result limit has to be numeric.'));
  }
  elseif ($form_state['values']['commerce_quickadd_result_limit'] <= 0) {
  	form_set_error('commerce_quickadd_result_limit', t('Result limit has to be at least one.'));
  }
}
