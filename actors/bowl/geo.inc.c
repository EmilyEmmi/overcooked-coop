const GeoLayout bowl_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(1, 180, 100),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 16384),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bowl_bowl_model_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bowl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
