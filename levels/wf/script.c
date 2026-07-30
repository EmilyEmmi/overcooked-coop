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
#include "levels/wf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_GIANT_POLE, wf_geo_000AE0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM, wf_geo_0009B8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_SMALL_BOMP, wf_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_LARGE_BOMP, wf_geo_000A40), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_WOODEN_PLATFORM, wf_geo_000A58), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_SLIDING_PLATFORM, wf_geo_000A98), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART, wf_geo_000AB0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE, wf_geo_000AC8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_TRAPEZOID_PLATORM, wf_geo_000AF8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM, wf_geo_000B10), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_UNUSED, wf_geo_000B38), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_ELEVATOR, wf_geo_000B60), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BREAKABLE_WALL_RIGHT, wf_geo_000B78), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BREAKABLE_WALL_LEFT, wf_geo_000B90), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD, wf_geo_000BA8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_DOOR, wf_geo_000BE0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD_FELLED, wf_geo_000BC8), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(0x0A, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_WF, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_WF, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x34, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x66, WARP_NO_CHECKPOINT),
		OBJECT(E_MODEL_COUNTER_SIDE, 976, 3584, 425, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 976, 3584, 529, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 976, 3584, 633, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 976, 3584, 737, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 976, 3584, -407, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 2697, 3584, 413, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 2697, 3584, 101, 0, -90, 0, (1 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 3045, 3580, 1431, 0, 180, 0, (2 << 24) | (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 3355, 3580, -818, 0, 0, 0, (3 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 3043, 3580, -818, 0, 0, 0, (3 << 24), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 976, 3584, 321, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 976, 3584, -303, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 976, 3584, 113, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 976, 3584, 217, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 976, 3584, 945, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_PLATE_COUNTER, 976, 3584, 9, 0, 90, 0, (6 << 16), bhvCounter),
		OBJECT(E_MODEL_SERVING, 976, 3584, -147, 0, 90, 0, (5 << 16), bhvCounter),
		OBJECT(E_MODEL_TRASH, 976, 3584, 841, 0, 90, 0, (2 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 3357, 3580, 1431, 0, 180, 0, (2 << 24) | (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 3253, 3580, 1431, 0, 180, 0, (2 << 24) | (1 << 16), bhvCounter),
		OBJECT(E_MODEL_SINK, 3199, 3580, -818, 0, 0, 0, (3 << 24) | (7 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 2697, 3584, 205, 0, -90, 0, (1 << 24) | (3 << 16) | (0), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 2697, 3584, 309, 0, -90, 0, (1 << 24) | (3 << 16) | (4), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 3149, 3580, 1431, 0, 180, 0, (2 << 24) | (1 << 16), bhvCounter),
		OBJECT(MODEL_WF_BREAKABLE_WALL_LEFT, -1023, 2176, 2944, 0, 0, 0, 0x00000000, bhvWfBreakableWallLeft),
		OBJECT(MODEL_WF_BREAKABLE_WALL_RIGHT, 512, 2176, 2944, 0, 0, 0, 0x00000000, bhvWfBreakableWallRight),
		OBJECT(MODEL_WF_ROTATING_PLATFORM, 2304, 3584, 257, 0, 0, 0, 0x08000100, bhvRotatingPlatform),
		OBJECT(MODEL_WF_ROTATING_PLATFORM, 3200, 3584, 1051, 0, 0, 0, 0x08000200, bhvRotatingPlatform),
		OBJECT(MODEL_WF_ROTATING_PLATFORM, 3200, 3584, -443, 0, 0, 0, 0x08000300, bhvRotatingPlatform),
		OBJECT(MODEL_WF_ROTATING_WOODEN_PLATFORM, -255, 2560, 2304, 0, 0, 0, 0x00000000, bhvWfRotatingWoodenPlatform),
		OBJECT(MODEL_WF_SLIDING_PLATFORM, 3328, 1075, -1791, 0, 90, 0, 0x00020000, bhvWfSlidingPlatform),
		OBJECT(MODEL_WF_SLIDING_PLATFORM, 3328, 1075, -767, 0, 90, 0, 0x00010000, bhvWfSlidingPlatform),
		OBJECT(MODEL_WF_SLIDING_PLATFORM, 3328, 1075, -2815, 0, 90, 0, 0x00030000, bhvWfSlidingPlatform),
		OBJECT(MODEL_WF_TUMBLING_BRIDGE, 1792, 2496, 1600, 0, 0, 0, 0x00000000, bhvWfTumblingBridge),
		OBJECT(MODEL_WHOMP, -1545, 2560, -286, 0, 0, 0, 0x00000000, bhvSmallWhomp),
		OBJECT(E_MODEL_NONE, 976, 3636, 217, 0, 90, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, 976, 3636, 425, 0, 90, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, 976, 3636, 633, 0, 90, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, 1286, 3584, 389, 0, 90, 0, (0), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, 1286, 3584, 126, 0, 90, 0, (1), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, 1286, 3584, -262, 0, 90, 0, (2), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, 1286, 3584, 769, 0, 90, 0, (3), bhvOcSpawn),
		OBJECT(MODEL_NONE, 1181, 4185, 257, 0, 90, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(wf_area_1_collision),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};