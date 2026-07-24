const GeoLayout plate_tomato_plate_tomato_flat[] = {
	GEO_NODE_START(),
	GEO_RETURN(),
};
const GeoLayout plate_tomato_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(0, plate_tomato_switch),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, plate_tomato_plate_tomato_dl_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, plate_tomato_plate_tomato_flat),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, plate_tomato_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
