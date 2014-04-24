<?php
/**
 * @file
 * You can configure how many columns the panel region should be.
 * Choose one of available grid systems: 960.gs, Foundation or Bootstrap.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Template region'),
  'description' => t('Choose template for this region'),
  'render region' => 'panels_region_layout_templates_style_render_region',
  'settings form' => 'panels_region_layout_templates_settings_form',
);

/**
 * Render callback for region.
 *
 * @ingroup themeable
 */
function theme_panels_region_layout_templates_style_render_region($vars) {
  $panes = $vars['panes'];
  $settings = $vars['settings'];

  // Rendering region panes.
  $items = array();
  foreach ($panes as $item) {
    $items[] = $item;
  }

  dsm(panels_region_layout_get_templates());

  dsm($vars);

  $output = array(
    'items' => $items,
  );
  if(isset($vars['settings']['region_layout_template'])) {
    return theme($vars['settings']['region_layout_template'], $output);  
  } else {
    return theme('panels_region_layout_region_style', $output);  
  }
}

/**
 * Helper function. Returns settings form for region and pane.
 */
function panels_region_layout_templates_settings_form($style_settings, $display, $pid, $type, $form_state) {
  dsm($style_settings);
  dsm($display);

  
  $registered_templates = panels_region_layout_get_templates();
  $template_options = array();
  foreach ($registered_templates as $key => $value) {
    $template_options[$key] = $value['title'];
  }
  $form['region_layout_template'] = array(
    '#type' => 'select',
    '#title' => t('Choose template'),
    '#options' => $template_options,
    '#default_value' => (isset($style_settings['region_layout_template'])) ? $style_settings['region_layout_template'] : '0',
  );

  $form['region_layout_number_items'] = array(
    '#type' => 'select',
    '#title' => t('Number of items'),
    '#options' => array(0,1,2),
    '#default_value' => (isset($style_settings['region_layout_number_items'])) ? $style_settings['region_layout_number_items'] : '0',
  );

  return $form;
}
