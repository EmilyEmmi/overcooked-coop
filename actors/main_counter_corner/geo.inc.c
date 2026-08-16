const GeoLayout main_counter_corner_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SCALE(LAYER_OPAQUE, 16384),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, main_counter_corner_main_counter_corner_model_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, main_counter_corner_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
