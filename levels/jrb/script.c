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
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _wdw_skybox_yay0SegmentRomStart, _wdw_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group5_yay0SegmentRomStart, _group5_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group16_yay0SegmentRomStart, _group16_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
	JUMP_LINK(script_func_global_17), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x64, WARP_NO_CHECKPOINT),
		OBJECT(E_MODEL_BARRIER, -52, -116, -1059, 0, 0, 0, (1 << 24) | (10 << 16) | (8 << 8) | (10), bhvPlayerBarrier),
		OBJECT(E_MODEL_BARRIER, -52, -116, -331, 0, 0, 0, (1 << 24) | (10 << 16) | (8 << 8) | (10), bhvPlayerBarrier),
		OBJECT(E_MODEL_COUNTER_CENTER, -520, -168, -1787, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -416, -168, -1059, 0, 0, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -312, -168, -1059, 0, 0, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -208, -168, -1059, 0, 0, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -104, -168, -1059, 0, 0, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, -168, -1059, 0, 0, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 104, -168, -1059, 0, 0, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 208, -168, -1059, 0, 0, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 312, -168, -1059, 0, 0, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_SINK, 416, -168, -1215, 0, -90, 0, (7 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 416, -168, -1059, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 416, -168, -955, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 416, -168, -851, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 416, -168, -643, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 416, -168, -331, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 416, -168, -435, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 208, -168, -331, 0, 180, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 104, -168, -331, 0, 180, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, -168, -331, 0, 180, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -104, -168, -331, 0, 180, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -208, -168, -331, 0, 180, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -312, -168, -331, 0, 180, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -416, -168, -331, 0, 180, 0, (1 << 24) | (8 << 8), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -520, -168, -1371, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -520, -168, -1267, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -520, -168, -1163, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -520, -168, -1059, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -520, -168, -955, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -520, -168, -851, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -520, -168, -643, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 416, -168, -539, 0, -90, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 416, -168, -747, 0, -90, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_HEAT, -520, -168, -539, 0, 90, 0, (4 << 16), bhvCounter),
		OBJECT(E_MODEL_HEAT, -520, -168, -747, 0, 90, 0, (4 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 416, -168, -1579, 0, -90, 0, (3 << 16) | (8), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 416, -168, -1371, 0, -90, 0, (3 << 16) | (6), bhvCounter),
		OBJECT(E_MODEL_PLATE_COUNTER, -520, -168, -1683, 0, 90, 0, (6 << 16), bhvCounter),
		OBJECT(E_MODEL_SERVING, -520, -168, -1527, 0, 90, 0, (5 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 416, -168, -1475, 0, -90, 0, (3 << 16) | (4), bhvCounter),
		OBJECT(E_MODEL_TRASH, 312, -168, -331, 0, 180, 0, (1 << 24) | (2 << 16) | (8 << 8), bhvCounter),
		MARIO_POS(0x01, -180, -72, 2063, 1106),
		OBJECT(E_MODEL_NONE, 208, -116, -331, 0, 180, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, 104, -116, -331, 0, 180, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, 0, -116, -331, 0, 180, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, -520, -116, -539, 0, 90, 0, (3), bhvIngredient),
		OBJECT(E_MODEL_NONE, -520, -116, -743, 0, 90, 0, (3), bhvIngredient),
		OBJECT(E_MODEL_NONE, -52, -168, -1059, 0, -180, 0, (7 << 16) | (1 << 8), bhvShipMovementController),
		OBJECT(E_MODEL_NONE, -316, -168, -1507, 0, 90, 0, (0), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, -316, -168, -571, 0, 90, 0, (1), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, 204, -168, -571, 0, 90, 0, (2), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, 204, -168, -1507, 0, 90, 0, (3), bhvOcSpawn),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_WATER),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, -72, 2063, 1106),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};