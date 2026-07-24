const GeoLayout ingredients_geo_opt_1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ingredients_ingredient_dl_mesh_layer_5_opt_1_with_revert),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ingredients_geo_opt_2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ingredients_ingredient_dl_mesh_layer_5_opt_2_with_revert),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ingredients_geo_opt_3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ingredients_ingredient_dl_mesh_layer_5_opt_3_with_revert),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ingredients_geo_opt_4[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ingredients_ingredient_dl_mesh_layer_5_opt_4_with_revert),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ingredients_geo_opt_5[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ingredients_ingredient_dl_mesh_layer_5_opt_5_with_revert),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ingredients_geo_opt_6[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ingredients_ingredient_dl_mesh_layer_5_opt_6_with_revert),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ingredients_geo_opt_7[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ingredients_ingredient_dl_mesh_layer_5_opt_7_with_revert),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ingredients_geo_opt_8[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ingredients_ingredient_dl_mesh_layer_5_opt_8_with_revert),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ingredients_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(1, 180, 60),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_FORCE, 16384),
			GEO_OPEN_NODE(),
				GEO_SWITCH_CASE(9, geo_switch_anim_state),
				GEO_OPEN_NODE(),
					GEO_NODE_START(),
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ingredients_ingredient_dl_mesh_layer_5_with_revert),
					GEO_CLOSE_NODE(),
					GEO_BRANCH(1, ingredients_geo_opt_1),
					GEO_BRANCH(1, ingredients_geo_opt_2),
					GEO_BRANCH(1, ingredients_geo_opt_3),
					GEO_BRANCH(1, ingredients_geo_opt_4),
					GEO_BRANCH(1, ingredients_geo_opt_5),
					GEO_BRANCH(1, ingredients_geo_opt_6),
					GEO_BRANCH(1, ingredients_geo_opt_7),
					GEO_BRANCH(1, ingredients_geo_opt_8),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
