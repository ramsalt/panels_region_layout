<?php
$item_chunks = array_chunk($items, 5);
dsm($item_chunks);
?>
<div class="region-layout layout-variant-1 clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
<?php 
	foreach($item_chunks as $chunk) {
		foreach($chunk as $item_key => $item) {
?>
  <div class="region-layout-panel layout-item-<?php print $item_key; ?>">
    <div class="inside"><?php print $item; ?></div>
  </div>
<?php 
}
}
?>
</div>
