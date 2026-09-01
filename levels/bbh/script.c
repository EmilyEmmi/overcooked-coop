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
#include "levels/bbh/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bbh_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bbh_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x64, WARP_NO_CHECKPOINT),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, -260, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, -364, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, -468, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, -572, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, -676, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, -780, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, -884, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 156, 50, 1661, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 260, 50, 1661, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, -988, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -156, 50, 1661, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -260, 50, 1661, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1661, 50, -52, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1661, 50, -156, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1661, 50, -260, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1661, 50, 52, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1661, 50, 156, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1661, 50, 260, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, 260, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, 364, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -260, 50, -1661, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, 468, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, 572, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 260, 50, -1661, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, 676, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, 780, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, 884, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 0, 988, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -1661, 50, 52, 0, 90, 0, (3 << 16) | (17), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -1661, 50, -156, 0, 90, 0, (3 << 16) | (25), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -260, 0, 0, 0, -90, 0, (1 << 24) | (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -260, 0, 104, 0, -90, 0, (1 << 24) | (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -260, 0, -104, 0, -90, 0, (1 << 24) | (1 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -1661, 50, 260, 0, 90, 0, (3 << 16) | (20), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -1661, 50, -260, 0, 90, 0, (3 << 16) | (8), bhvCounter),
		OBJECT(E_MODEL_OVEN, 260, 0, 0, 0, 90, 0, (1 << 24) | (8 << 16), bhvCounter),
		OBJECT(E_MODEL_OVEN, 260, 0, -104, 0, 90, 0, (1 << 24) | (8 << 16), bhvCounter),
		OBJECT(E_MODEL_OVEN, 260, 0, 104, 0, 90, 0, (1 << 24) | (8 << 16), bhvCounter),
		OBJECT(E_MODEL_PLATE_COUNTER, -156, 50, -1661, 0, 0, 0, (6 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -1661, 50, -52, 0, 90, 0, (3 << 16) | (23), bhvCounter),
		OBJECT(E_MODEL_SERVING, 0, 50, 1661, 0, -180, 0, (5 << 16), bhvCounter),
		OBJECT(E_MODEL_SINK, 0, 50, -1661, 0, 0, 0, (7 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -1661, 50, 156, 0, 90, 0, (3 << 16) | (4), bhvCounter),
		OBJECT(E_MODEL_TRASH, 156, 50, -1661, 0, 0, 0, (2 << 16), bhvCounter),
		OBJECT(MODEL_NONE, -500, 500, 0, 0, 180, 0, 0x000A0000, bhvInstantActiveWarp),
		MARIO_POS(0x01, 180, -500, 500, 0),
		OBJECT(E_MODEL_NONE, 260, 102, 1661, 0, -180, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, 156, 102, 1661, 0, -180, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, -156, 102, 1661, 0, -180, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, -260, 102, 1661, 0, -180, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_BARRIER, 0, 50, 0, 0, -90, 0, (1 << 24) | (22 << 16), bhvPlayerBarrier),
		OBJECT(E_MODEL_BBH_MERRY_GO_ROUND, 0, 0, 0, 0, 90, 0, (1 << 8), bhvMerryGoRound),
		OBJECT(MODEL_NONE, -550, 0, 0, 0, -90, 0, (0 << 16), bhvOcSpawn),
		OBJECT(MODEL_NONE, 550, 0, 0, 0, 90, 0, (1 << 16), bhvOcSpawn),
		OBJECT(MODEL_NONE, 0, 0, -550, 0, -180, 0, (2 << 16), bhvOcSpawn),
		OBJECT(MODEL_NONE, 0, 0, 550, 0, 0, 0, (3 << 16), bhvOcSpawn),
		TERRAIN(bbh_area_1_collision),
		MACRO_OBJECTS(bbh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SPOOKY),
		TERRAIN_TYPE(TERRAIN_SPOOKY),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 180, -500, 500, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};