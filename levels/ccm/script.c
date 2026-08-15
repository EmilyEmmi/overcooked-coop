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
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	LOAD_MIO0(0x0A, _ccm_skybox_mio0SegmentRomStart, _ccm_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x64, WARP_NO_CHECKPOINT),
		OBJECT(E_MODEL_COUNTER_CORNER, -573, 1521, -1926, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -469, 1521, -1926, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -53, 1521, -1926, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 51, 1521, -1926, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 467, 1521, -1926, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CORNER, 571, 1521, -1926, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -261, 584, 718, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -157, 584, 718, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -53, 584, 718, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 155, 584, 718, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -573, 1521, -1510, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 363, 584, 718, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 571, 584, 718, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 571, 1521, -1822, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -157, 1521, -1926, 0, 0, 0, (3 << 16) | (17), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 259, 1521, -1926, 0, 0, 0, (3 << 16) | (25), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -573, 1521, -1614, 0, 90, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -573, 1521, -1822, 0, 90, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -573, 1521, -1718, 0, 90, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -365, 1521, -1926, 0, 0, 0, (3 << 16) | (20), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 363, 1521, -1926, 0, 0, 0, (3 << 16) | (8), bhvCounter),
		OBJECT(E_MODEL_OVEN, 467, 584, 718, 0, -180, 0, (8 << 16), bhvCounter),
		OBJECT(E_MODEL_OVEN, 259, 584, 718, 0, -180, 0, (8 << 16), bhvCounter),
		OBJECT(E_MODEL_OVEN, 51, 584, 718, 0, -180, 0, (8 << 16), bhvCounter),
		OBJECT(E_MODEL_PLATE_COUNTER, 571, 1521, -1510, 0, -90, 0, (6 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 155, 1521, -1926, 0, 0, 0, (3 << 16) | (23), bhvCounter),
		OBJECT(E_MODEL_SERVING, -417, 584, 718, 0, -180, 0, (5 << 16), bhvCounter),
		OBJECT(E_MODEL_SINK, 571, 1521, -1666, 0, -90, 0, (7 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -261, 1521, -1926, 0, 0, 0, (3 << 16) | (4), bhvCounter),
		OBJECT(E_MODEL_TRASH, -573, 584, 718, 0, -180, 0, (2 << 16), bhvCounter),
		OBJECT(MODEL_NONE, 0, 2000, -1655, 0, 180, 0, 0x000A0000, bhvAirborneWarp),
		MARIO_POS(0x01, 180, 0, 2000, -1655),
		OBJECT(E_MODEL_NONE, -53, 636, 718, 0, 0, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, 155, 636, 718, 0, 0, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, 363, 636, 718, 0, 0, 0, (2), bhvIngredient),
		OBJECT(MODEL_NONE, 0, 2000, -1655, 0, 180, 0, 0x000A0000, bhvAirborneWarp),
		OBJECT(E_MODEL_NONE, -313, 1521, -1653, 0, 0, 0, (0), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, 312, 1521, -1653, 0, 0, 0, (1), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, -313, 584, 506, 0, 0, 0, (2), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, 312, 584, 506, 0, 0, 0, (3), bhvOcSpawn),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SNOW),
		TERRAIN_TYPE(TERRAIN_SNOW),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 180, 0, 2000, -1655),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};