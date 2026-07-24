const GeoLayout plate_lettuce_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SCALE(LAYER_OPAQUE, 16384),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, plate_lettuce_plate_lettuce_mdl_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, plate_lettuce_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
