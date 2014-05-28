<?php

/**
 * Note: We could achieve the same with the nodeParent / entityParent,
 * but we do it with a custom plugin for a showcase.
 */
class menu_node_crumbs_CrumbsMultiPlugin_MenuNode implements crumbs_MultiPlugin_FindParentInterface {

  /**
   * {@inheritdoc}
   */
  function describe($api) {
    $api->ruleWithLabel('menu_node', t('Menu Node'), t('Menu Node Parent'));
    $api->descWithLabel(t('The parent item\'s path from menu node module'), t('Parent'));
  }

  /**
   * {@inheritdoc}
   */
  function findParent($path, $item) {

    // Collect candidates for the parent path, keyed by menu name.
    $candidates = array();
    if(is_array($item['page_arguments'])) {
      $menu = array_shift($item['page_arguments']);
      $plid = 0;
      switch($item['page_callback']) {
        // node page
        case 'node_page_view':
          if(isset($menu->menu_node_links) && is_array($menu->menu_node_links)) {
            $node_link = array_shift($menu->menu_node_links);
            $plid = isset($node_link->plid) ? $node_link->plid : 0;
          }
          break;
      }
      if(!empty($plid)) {
        $parent = menu_link_load($plid);
        if($parent && !isset($candidates[$parent['menu_name']])) {
          // we don't have a proper menu path
          if ('<firstchild>' === $parent['link_path']) {
            $candidates[$parent['menu_name']] = 'crumbs/firstchild-menu-item/' . $parent['mlid'];
          }
          else {
            $candidates[$parent['menu_name']] = $parent['link_path'];
          }
        }
      }
    }
    return $candidates;
  }
}
