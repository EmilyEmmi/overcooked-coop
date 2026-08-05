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
#include "levels/ssl/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ssl_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _ssl_segment_7SegmentRomStart, _ssl_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _ssl_skybox_mio0SegmentRomStart, _ssl_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ssl_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x64, WARP_NO_CHECKPOINT),
		OBJECT(E_MODEL_COUNTER_SIDE, -764, 280, 416, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -1180, 280, 312, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 763, 280, 416, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -1180, 280, 0, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -1180, 280, -104, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -1180, 280, -208, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 867, 280, 416, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CORNER, -1180, 280, -416, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -1076, 280, -416, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -868, 280, -416, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -660, 280, -416, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -452, 280, -416, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CORNER, -1180, 280, 416, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -1076, 280, 416, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -972, 280, 416, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -556, 280, 416, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -452, 280, 416, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1179, 280, 0, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1179, 280, 104, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1179, 280, 208, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1179, 280, 312, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CORNER, 1179, 280, 416, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1075, 280, 416, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 659, 280, 416, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 451, 280, 416, 0, -180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CORNER, 1179, 280, -416, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1075, 280, -416, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 867, 280, -416, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 763, 280, -416, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 659, 280, -416, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 451, 280, -416, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -660, 280, 416, 0, -180, 0, (3 << 16) | (11), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 971, 280, 416, 0, -180, 0, (3 << 16) | (17), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 555, 280, 416, 0, -180, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 555, 280, -416, 0, 0, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 971, 280, -416, 0, 0, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_HEAT, -972, 280, -416, 0, 0, 0, (4 << 16), bhvCounter),
		OBJECT(E_MODEL_HEAT, -764, 280, -416, 0, 0, 0, (4 << 16), bhvCounter),
		OBJECT(E_MODEL_HEAT, -556, 280, -416, 0, 0, 0, (4 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -868, 280, 416, 0, -180, 0, (3 << 16) | (12), bhvCounter),
		OBJECT(E_MODEL_PLATE_COUNTER, 1179, 280, -312, 0, -90, 0, (6 << 16), bhvCounter),
		OBJECT(E_MODEL_SERVING, -1180, 280, 156, 0, 90, 0, (5 << 16), bhvCounter),
		OBJECT(E_MODEL_SINK, 1179, 280, -156, 0, -90, 0, (7 << 16), bhvCounter),
		OBJECT(E_MODEL_TRASH, -1180, 280, -312, 0, 90, 0, (2 << 16), bhvCounter),
		OBJECT(MODEL_NONE, -2000, 560, 0, 0, 180, 0, 0x000A0000, bhvAirborneWarp),
		MARIO_POS(0x01, 180, -2000, 560, 0),
		OBJECT(E_MODEL_NONE, -764, 332, -416, 0, -180, 0, (15), bhvIngredient),
		OBJECT(E_MODEL_NONE, -972, 332, -416, 0, -180, 0, (15), bhvIngredient),
		OBJECT(E_MODEL_NONE, -556, 332, -416, 0, -180, 0, (15), bhvIngredient),
		OBJECT(E_MODEL_NONE, -764, 332, 416, 0, -180, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, -556, 332, 416, 0, -180, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, -972, 332, 416, 0, -180, 0, (2), bhvIngredient),
		OBJECT(MODEL_NONE, -2000, 560, 0, 0, 180, 0, 0x000A0000, bhvAirborneWarp),
		OBJECT(E_MODEL_LLL_SINKING_SQUARE_PLATFORMS, 0, 0, 2, 0, 0, 0, 0x00000000, bhvLllSinkingSquarePlatforms),
		OBJECT(MODEL_NONE, -816, 280, 208, 0, 90, 0, (0), bhvOcSpawn),
		OBJECT(MODEL_NONE, 752, 280, 208, 0, -90, 0, (1), bhvOcSpawn),
		OBJECT(MODEL_NONE, -816, 280, -208, 0, 90, 0, (2), bhvOcSpawn),
		OBJECT(MODEL_NONE, 752, 280, -208, 0, -90, 0, (3), bhvOcSpawn),
		TERRAIN(ssl_area_1_collision),
		MACRO_OBJECTS(ssl_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_HOT),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 180, -2000, 560, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};