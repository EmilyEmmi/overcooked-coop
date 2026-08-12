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
	LOAD_MIO0(0x0A, _ccm_skybox_mio0SegmentRomStart, _ccm_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ocTest_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x64, WARP_NO_CHECKPOINT),
		OBJECT(E_MODEL_COUNTER_SIDE, 0, 1500, -1456, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(MODEL_NONE, 1, 1961, -961, 0, 180, 0, 0x000A0000, bhvAirborneWarp),
		MARIO_POS(0x01, 180, 1, 1961, -961),
		OBJECT(MODEL_NONE, 0, 1940, -960, 0, 180, 0, 0x000A0000, bhvAirborneWarp),
		OBJECT(E_MODEL_NONE, -570, 1500, -988, 0, 0, 0, (0), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, 570, 1500, -988, 0, 0, 0, (1), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, -570, 0, 1323, 0, 0, 0, (2), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, 570, 0, 1307, 0, 0, 0, (3), bhvOcSpawn),
		TERRAIN(ocTest_area_1_collision),
		MACRO_OBJECTS(ocTest_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SNOW),
		TERRAIN_TYPE(TERRAIN_SNOW),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 180, 1, 1961, -961),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};