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
#include "levels/bowser_1/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bowser_1_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bowser_1_segment_7SegmentRomStart, _bowser_1_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _bidw_skybox_mio0SegmentRomStart, _bidw_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x06, _group12_mio0SegmentRomStart, _group12_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group12_geoSegmentRomStart, _group12_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_13), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, bowser_1_yellow_sphere_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bowser_1_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x64, WARP_NO_CHECKPOINT),
		OBJECT(E_MODEL_COUNTER_CENTER, -416, 307, -1664, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -312, 307, -1664, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 312, 307, -1664, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 416, 307, -1664, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 1664, 307, -364, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 1664, 307, -260, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 1664, 307, 156, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 1664, 307, 260, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 1664, 307, 364, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 416, 307, 1664, 0, 180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -416, 307, 1664, 0, 180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -1664, 307, 364, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -1664, 307, 260, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -1664, 307, 156, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -1664, 307, -156, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -1664, 307, -260, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -208, 307, 208, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 307, 208, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 208, 307, 208, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -208, 307, -208, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 0, 307, -208, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 208, 307, -208, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -208, 307, 0, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 208, 307, 0, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -208, 307, -1664, 0, 0, 0, (3 << 16) | (11), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 0, 307, -1664, 0, 0, 0, (3 << 16) | (17), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 104, 307, 1664, 0, 180, 0, (3 << 16) | (17), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -104, 307, 1664, 0, 180, 0, (3 << 16) | (25), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -104, 307, -208, 0, -180, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 104, 307, -208, 0, -180, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -104, 307, 208, 0, 0, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 104, 307, 208, 0, 0, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 312, 307, 1664, 0, 180, 0, (3 << 16) | (20), bhvCounter),
		OBJECT(E_MODEL_HEAT, -208, 307, -104, 0, -90, 0, (4 << 16), bhvCounter),
		OBJECT(E_MODEL_HEAT, -208, 307, 104, 0, -90, 0, (4 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 104, 307, -1664, 0, 0, 0, (3 << 16) | (0), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -104, 307, -1664, 0, 0, 0, (3 << 16) | (12), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -208, 307, 1664, 0, 180, 0, (3 << 16) | (8), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -312, 307, 1664, 0, 180, 0, (3 << 16) | (6), bhvCounter),
		OBJECT(E_MODEL_OVEN, 208, 307, -104, 0, 90, 0, (8 << 16), bhvCounter),
		OBJECT(E_MODEL_OVEN, 208, 307, 104, 0, 90, 0, (8 << 16), bhvCounter),
		OBJECT(E_MODEL_PLATE_COUNTER, 1664, 307, -156, 0, -90, 0, (6 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 0, 307, 1664, 0, 180, 0, (3 << 16) | (23), bhvCounter),
		OBJECT(E_MODEL_SERVING, -1664, 307, 0, 0, 90, 0, (5 << 16), bhvCounter),
		OBJECT(E_MODEL_SINK, 1664, 307, 0, 0, -90, 0, (7 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 208, 307, -1664, 0, 0, 0, (3 << 16) | (4), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 208, 307, 1664, 0, 180, 0, (3 << 16) | (4), bhvCounter),
		OBJECT(E_MODEL_TRASH, -1664, 307, -364, 0, 90, 0, (2 << 16), bhvCounter),
		OBJECT(MODEL_NONE, 0, 880, 0, 0, 180, 0, 0x000A0000, bhvInstantActiveWarp),
		MARIO_POS(0x01, 180, 0, 880, 0),
		OBJECT(E_MODEL_NONE, -208, 359, -104, 0, 90, 0, (15), bhvIngredient),
		OBJECT(E_MODEL_NONE, -416, 359, -1664, 0, 180, 0, (15), bhvIngredient),
		OBJECT(E_MODEL_NONE, -1664, 359, 260, 0, -90, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, -1664, 359, 156, 0, -90, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, -1664, 359, -156, 0, -90, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, -1664, 359, -260, 0, -90, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, -208, 359, 104, 0, 90, 0, (3), bhvIngredient),
		OBJECT(E_MODEL_NONE, 416, 359, 1664, 0, -90, 0, (3), bhvIngredient),
		OBJECT(MODEL_NONE, 0, 307, -676, 0, 180, 0, (0), bhvOcSpawn),
		OBJECT(MODEL_NONE, 0, 307, 676, 0, 0, 0, (1), bhvOcSpawn),
		OBJECT(MODEL_NONE, -676, 307, 0, 0, -90, 0, (2), bhvOcSpawn),
		OBJECT(MODEL_NONE, 676, 307, 0, 0, 90, 0, (3), bhvOcSpawn),
		TERRAIN(bowser_1_area_1_collision),
		MACRO_OBJECTS(bowser_1_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_BOSS_KOOPA),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 180, 0, 880, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};