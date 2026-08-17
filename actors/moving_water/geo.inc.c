#include "src/game/envfx_snow.h"

const GeoLayout moving_water_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, moving_water_Moving_Water_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, moving_water_final_revert_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
