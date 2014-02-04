	<?php
	//Ryans original "Page Edit" Link
	if($page->editable())
		echo "<a id='editpage' href='{$config->urls->admin}page/edit/?id={$page->id}'>Edit page</a>"; 
	?>
    <!-- jQuery  -->
    <script src="https://code.jquery.com/jquery.js"></script>
    <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="<?php echo $config->urls->templates; ?>js/bootstrap.min.js"></script>
  </body>
</html>