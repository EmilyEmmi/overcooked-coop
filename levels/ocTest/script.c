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
#include "levels/ocTest/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ocTest_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _ocTest_segment_7SegmentRomStart, _ocTest_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ocTest_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x64, WARP_NO_CHECKPOINT),
		OBJECT(E_MODEL_INGREDIENT_BOX, 729, -1, -313, 0, -90, 0, (3 << 16) | (11), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 729, -1, -105, 0, -90, 0, (3 << 16) | (17), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1, -1, -417, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 105, -1, -417, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -623, -1, -417, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CORNER, -727, -1, -417, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -727, -1, -313, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -727, -1, -209, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -727, -1, -105, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -727, -1, -1, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -727, -1, 415, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -415, -1, 415, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 417, -1, 415, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -623, -1, 415, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 625, -1, 415, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 729, -1, 415, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CORNER, 729, -1, -417, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 209, -1, -417, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 313, -1, -417, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 417, -1, -417, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 625, -1, -417, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -207, -1, -417, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -103, -1, -417, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 105, -1, 415, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 1, -1, 415, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -103, -1, 415, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -207, -1, 415, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 209, -1, 415, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -727, -1, 103, 0, 90, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -727, -1, 207, 0, 90, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -727, -1, 311, 0, 90, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_HEAT, -519, -1, 415, 0, -180, 0, (4 << 16), bhvCounter),
		OBJECT(E_MODEL_HEAT, -311, -1, 415, 0, -180, 0, (4 << 16), bhvCounter),
		OBJECT(E_MODEL_HEAT, 313, -1, 415, 0, -180, 0, (4 << 16), bhvCounter),
		OBJECT(E_MODEL_HEAT, 521, -1, 415, 0, -180, 0, (4 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 729, -1, -1, 0, -90, 0, (3 << 16) | (0), bhvCounter),
		OBJECT(MODEL_NONE, 1, 582, -1, 0, 180, 0, 0x000A0000, bhvAirborneWarp),
		MARIO_POS(0x01, 180, 1, 582, -1),
		OBJECT(E_MODEL_INGREDIENT_BOX, 729, -1, -209, 0, -90, 0, (3 << 16) | (12), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 729, -1, 311, 0, -90, 0, (3 << 16) | (8), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 729, -1, 207, 0, -90, 0, (3 << 16) | (6), bhvCounter),
		OBJECT(E_MODEL_NONE, -519, 51, 415, 0, 0, 0, (15), bhvIngredient),
		OBJECT(E_MODEL_NONE, -311, 51, 415, 0, 0, 0, (15), bhvIngredient),
		OBJECT(E_MODEL_NONE, -727, 51, -105, 0, 90, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_PLATE_COUNTER, -311, -1, -417, 0, 0, 0, (6 << 16), bhvCounter),
		OBJECT(E_MODEL_NONE, -727, 51, -209, 0, 90, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, -727, 51, -313, 0, 90, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, 313, 51, 415, 0, 0, 0, (3), bhvIngredient),
		OBJECT(E_MODEL_NONE, 521, 51, 415, 0, 0, 0, (3), bhvIngredient),
		OBJECT(E_MODEL_SERVING, -467, -1, -417, 0, 0, 0, (5 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 729, -1, 103, 0, -90, 0, (3 << 16) | (4), bhvCounter),
		OBJECT(E_MODEL_TRASH, 521, -1, -417, 0, 0, 0, (2 << 16), bhvCounter),
		OBJECT(MODEL_NONE, 0, 560, 0, 0, 180, 0, 0x000A0000, bhvAirborneWarp),
		TERRAIN(ocTest_area_1_collision),
		MACRO_OBJECTS(ocTest_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
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