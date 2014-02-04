<?php

/*

Navigation for ProcessWire using the Bootstrap 2.3 markup

Altered by Philipp for usage with Bootstrap 3

This allows for endless sub-categories. However, this might not be a sensible use for touch devices and would be better to use just one level of dropdown. No alteration of this script is necessary, simply restrict the menu in the Pages section of the admin.

Note: The Top level item where they have children cannot be linked to a page. This is to allow "click to open" for touch devices. So you need to arrange your pages accordingly.

Bootstrap 3 - there is no guarantees that this will work in Bootstrap 3 (whenever that comes out) simply because they are considering scrapping sub menus.

This menu was written by Soma based on work by NetCarver and a very small bit thrown in by Joss

*** NOTES from Soma ***

 render markup menu for bootstrap nested navigation

 @param  PageArray  $pa     pages of the top level items
 @param  Page  $root   root page optional, if you use other root than home page (id:1)
 @param  string  $output for returned string collection
 @param  integer $level  internally used to count levels
 @return string          menu html string
*/

function renderChildrenOf($pa, $root = null, $output = '', $level = 0) {
    if(!$root) $root = wire("pages")->get(1);
    $output = '';
    $level++;
    foreach($pa as $child) {
        $atoggle = '';
        $class = '';
        $carret = '';
        $has_children = count($child->children) ? true : false;
 
        if($has_children && $child !== $root) {
            if($level == 1){
                $class .= 'dropdown'; // first level boostrap dropdown li class
                $carret = '<b class="caret"></b>';
                $atoggle .= ' class="dropdown-toggle" data-toggle="dropdown"'; // first level anchor attributes
            } else {
                $class .= 'dropdown-submenu'; // sub level boostrap dropdown li class
            }
        }
 
        // make the current page and only its first level parent have an active class
        if($child === wire("page")){
            $class .= ' active';
        } else if($level == 1 && $child !== $root){
            if($child === wire("page")->rootParent || wire("page")->parents->has($child)){
                $class .= ' active';
            }
        }
 
        $class = strlen($class) ? " class='".trim($class)."'" : '';
 
        $output .= "<li$class><a href='$child->url'$atoggle>$child->title$carret</a>";
 
        // If this child is itself a parent and not the root page, then render its children in their own menu too...
        if($has_children && $child !== $root) {
            $output .= renderChildrenOf($child->children, $root, $output, $level);
        }
        $output .= '</li>';
    }
    $outerclass = ($level == 1) ? "nav navbar-nav" : 'dropdown-menu';
    return "<ul class='$outerclass'>$output</ul>";
}
 
// bundle up the first level pages and prepend the root home page
$root = $pages->get(1);
$pa = $root->children;
 
// Set the ball rolling...
echo renderChildrenOf($pa); 
