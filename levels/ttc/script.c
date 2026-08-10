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
#include "levels/ttc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ttc_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _ttc_segment_7SegmentRomStart, _ttc_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ttc_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x64, WARP_NO_CHECKPOINT),
		OBJECT(E_MODEL_COUNTER_SIDE, 1196, 0, -364, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1196, 0, -260, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1196, 0, -156, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1196, 0, 260, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, 1196, 0, 364, 0, -90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -1196, 0, 364, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -1196, 0, 156, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_SIDE, -1196, 0, -52, 0, 90, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 52, 1391, 624, 0, 180, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -260, 1391, -624, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -52, 1391, -624, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 52, 1391, -624, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 260, 1391, -624, 0, 0, 0, 0x00000000, bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 260, 1391, 624, 0, 180, 0, (3 << 16) | (11), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -52, 1391, 624, 0, 180, 0, (3 << 16) | (17), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, 156, 1391, -624, 0, 0, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_COUNTER_CENTER, -156, 1391, -624, 0, 0, 0, (1 << 16), bhvCounter),
		OBJECT(E_MODEL_HEAT, -1196, 0, 260, 0, 90, 0, (4 << 16), bhvCounter),
		OBJECT(E_MODEL_HEAT, -1196, 0, 52, 0, 90, 0, (4 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -156, 1391, 624, 0, 180, 0, (3 << 16) | (0), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, 156, 1391, 624, 0, 180, 0, (3 << 16) | (12), bhvCounter),
		OBJECT(E_MODEL_PLATE_COUNTER, 1196, 0, 156, 0, -90, 0, (6 << 16), bhvCounter),
		OBJECT(E_MODEL_SERVING, 1196, 0, 0, 0, -90, 0, (5 << 16), bhvCounter),
		OBJECT(E_MODEL_SINK, -1196, 0, -208, 0, 90, 0, (7 << 16), bhvCounter),
		OBJECT(E_MODEL_INGREDIENT_BOX, -260, 1391, 624, 0, 180, 0, (3 << 16) | (4), bhvCounter),
		OBJECT(E_MODEL_TRASH, -1196, 0, -364, 0, 90, 0, (2 << 16), bhvCounter),
		OBJECT(MODEL_NONE, 0, 80, 0, 0, 180, 0, 0x000A0000, bhvInstantActiveWarp),
		MARIO_POS(0x01, 180, 0, 80, 0),
		OBJECT(E_MODEL_NONE, -1196, 52, 52, 0, -90, 0, (15), bhvIngredient),
		OBJECT(E_MODEL_NONE, -1196, 52, 260, 0, -90, 0, (15), bhvIngredient),
		OBJECT(E_MODEL_NONE, 1196, 52, -364, 0, 90, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, 1196, 52, -260, 0, 90, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, 1196, 52, -156, 0, 90, 0, (2), bhvIngredient),
		OBJECT(E_MODEL_NONE, 780, 0, 0, 0, 90, 0, 0x00000000, bhvOcSpawn),
		OBJECT(E_MODEL_NONE, 520, 1391, 0, 0, 90, 0, (1), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, -520, 1391, 0, 0, 90, 0, (2), bhvOcSpawn),
		OBJECT(E_MODEL_NONE, -780, 0, 0, 0, 90, 0, (3), bhvOcSpawn),
		TERRAIN(ttc_area_1_collision),
		MACRO_OBJECTS(ttc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SLIDE),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 180, 0, 80, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};