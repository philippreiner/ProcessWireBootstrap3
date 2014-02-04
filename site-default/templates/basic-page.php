<?php 
// Template basic-page
include('./includes/header.inc');

echo '<section class="container">';
echo '<h1>' . $page->title . '</h1><hr>';
echo $page->body;
echo '</section>';

include('./includes/footer.inc');

