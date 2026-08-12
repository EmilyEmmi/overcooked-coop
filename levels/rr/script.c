#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "make_const_nonconst.h"
#include "levels/rr/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_rr_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _rr_segment_7SegmentRomStart, _rr_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, rr_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x64, WARP_NO_CHECKPOINT),
		OBJECT(E_MODEL_COUNTER_CENTER, -883, -1, 571, 0, -180, 0, (1 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 571, -1, -571, 0, 0, 0, (4 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -155, -1, 571, 0, -180, 0, (1 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -779, -1, 571, 0, -180, 0, (1 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -363, -1, 571, 0, -180, 0, (1 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -571, -1, 571, 0, -180, 0, (1 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -51, -1, 571, 0, -180, 0, (1 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 53, -1, 571, 0, -180, 0, (2 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 261, -1, 571, 0, -180, 0, (2 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 469, -1, 571, 0, -180, 0, (2 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 885, -1, 571, 0, -180, 0, (2 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -885, -1, -571, 0, 0, 0, (3 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -781, -1, -571, 0, 0, 0, (3 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -573, -1, -571, 0, 0, 0, (3 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -365, -1, -571, 0, 0, 0, (3 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -157, -1, -571, 0, 0, 0, (3 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -53, -1, -571, 0, 0, 0, (3 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 155, -1, -571, 0, 0, 0, (4 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 363, -1, -571, 0, 0, 0, (4 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 51, -1, -571, 0, 0, 0, (4 << 24) | (0 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -675, -1, 571, 0, -180, 0, (1 << 24) | (3 << 16) | (11), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -259, -1, 571, 0, -180, 0, (1 << 24) | (3 << 16) | (17), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -677, -1, -571, 0, 0, 0, (3 << 24) | (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -469, -1, -571, 0, 0, 0, (3 << 24) | (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -261, -1, -571, 0, 0, 0, (3 << 24) | (1 << 16), bhvCounter),
		OBJECT(E_MODEL_HEAT, 259, -1, -571, 0, 0, 0, (4 << 24) | (4 << 16), bhvCounter),
		OBJECT(E_MODEL_HEAT, 467, -1, -571, 0, 0, 0, (4 << 24) | (4 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 157, -1, 571, 0, -180, 0, (2 << 24) | (3 << 16) | (0), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -467, -1, 571, 0, -180, 0, (1 << 24) | (3 << 16) | (12), bhvCounter),
		OBJECT(E_MODEL_PLATE_COUNTER, 573, -1, 571, 0, -180, 0, (2 << 24) | (6 << 16), bhvCounter),
		OBJECT(E_MODEL_SERVING, 727, -1, -571, 0, 0, 0, (4 << 24) | (5 << 16), bhvCounter),
		OBJECT(E_MODEL_SINK, 729, -1, 571, 0, -180, 0, (2 << 24) | (7 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 365, -1, 571, 0, -180, 0, (2 << 24) | (3 << 16) | (4), bhvCounter),
		OBJECT(E_MODEL_TRASH, 883, -1, -571, 0, 0, 0, (4 << 24) | (2 << 16), bhvCounter),
		OBJECT(MODEL_NONE, 1, 582, -1, 0, 180, 0, 0x000A0000, bhvAirborneWarp),
		MARIO_POS(0x01, 180, 1, 582, -1),
		OBJECT(E_MODEL_NONE, 261, 51, -573, 0, 180, 0, (15), bhvIngredient),
		OBJECT(E_MODEL_NONE, 469, 51, -573, 0, 180, 0, (15), bhvIngredient),
		OBJECT(E_MODEL_NONE, 157, 51, -573, 0, 180, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, 365, 51, -573, 0, 180, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, 573, 51, -573, 0, 180, 0, (2), bhvIngredient),
		OBJECT(MODEL_NONE, 0, 560, 0, 0, 180, 0, 0x000A0000, bhvAirborneWarp),
		OBJECT(E_MODEL_RR_FLYING_CARPET, -468, 0, 312, 0, 0, 0, (1 << 8), bhvOcCarpet),
		OBJECT(E_MODEL_RR_FLYING_CARPET, 468, 0, 312, 0, 0, 0, (2 << 8), bhvOcCarpet),
		OBJECT(E_MODEL_RR_FLYING_CARPET, -468, 0, -312, 0, 0, 0, (3 << 8), bhvOcCarpet),
		OBJECT(E_MODEL_RR_FLYING_CARPET, 468, 0, -312, 0, 0, 0, (4 << 8), bhvOcCarpet),
		OBJECT(E_MODEL_NONE, -468, 13, 312, 0, 0, 0, (1 << 24) | (0 << 16), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, 468, 13, -312, 0, 0, 0, (3 << 24) | (1 << 16), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, -468, 13, -312, 0, 0, 0, (3 << 24) | (2 << 16), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, 468, 13, -312, 0, 0, 0, (4 << 24) | (3 << 16), bhvOcSpawn),
		TERRAIN(rr_area_1_collision),
		MACRO_OBJECTS(rr_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SLIDE),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 180, 1, 582, -1),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};