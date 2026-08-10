const GeoLayout oven_model_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, oven_model_oven_model_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, oven_model_oven_model_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_ALPHA, oven_model_oven_model_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
