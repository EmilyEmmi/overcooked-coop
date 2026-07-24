Lights1 plate_counter_plate_counters_lights = gdSPDefLights1(
	0x31, 0x19, 0x3E,
	0x6B, 0x3C, 0x83, 0x28, 0x28, 0x28);

Lights1 plate_counter_plate_counters_gray_lights = gdSPDefLights1(
	0x3C, 0x3C, 0x3C,
	0xA9, 0xA9, 0xA9, 0x28, 0x28, 0x28);

Vtx plate_counter_plate_counter_model_mesh_layer_1_vtx_0[32] = {
	{{{-139, 0, 139}, 0, {368, 240}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 99, -139}, 0, {557, -16}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 0, -139}, 0, {368, -16}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 99, 139}, 0, {557, 240}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 0, -139}, 0, {368, 1008}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{-139, 99, -139}, 0, {557, 1008}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{139, 99, -139}, 0, {557, 752}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{139, 0, -139}, 0, {368, 752}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{139, 0, -139}, 0, {368, 752}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 99, -139}, 0, {557, 752}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 99, 139}, 0, {557, 496}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 0, 139}, 0, {368, 496}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 99, 139}, 0, {557, 496}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-139, 99, 139}, 0, {557, 240}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-139, 0, 139}, 0, {368, 240}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{139, 0, 139}, 0, {368, 496}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-110, 133, 0}, 0, {752, 291}, {0x21, 0x7B, 0x00, 0xFF}}},
	{{{-78, 133, 78}, 0, {675, 291}, {0x17, 0x7B, 0xE9, 0xFF}}},
	{{{-57, 126, 57}, 0, {675, 291}, {0x0F, 0x7D, 0xF1, 0xFF}}},
	{{{0, 126, 81}, 0, {675, 368}, {0x00, 0x7D, 0xEB, 0xFF}}},
	{{{0, 133, 110}, 0, {675, 368}, {0x00, 0x7B, 0xDF, 0xFF}}},
	{{{57, 126, 57}, 0, {675, 445}, {0xF1, 0x7D, 0xF1, 0xFF}}},
	{{{78, 133, 78}, 0, {675, 445}, {0xE9, 0x7B, 0xE9, 0xFF}}},
	{{{81, 126, 0}, 0, {752, 445}, {0xEB, 0x7D, 0x00, 0xFF}}},
	{{{110, 133, 0}, 0, {752, 445}, {0xDF, 0x7B, 0x00, 0xFF}}},
	{{{57, 126, -57}, 0, {829, 445}, {0xF1, 0x7D, 0x0F, 0xFF}}},
	{{{78, 133, -78}, 0, {829, 445}, {0xE9, 0x7B, 0x17, 0xFF}}},
	{{{0, 126, -81}, 0, {829, 368}, {0x00, 0x7D, 0x15, 0xFF}}},
	{{{0, 133, -110}, 0, {829, 368}, {0x00, 0x7B, 0x21, 0xFF}}},
	{{{-57, 126, -57}, 0, {829, 291}, {0x0F, 0x7D, 0x0F, 0xFF}}},
	{{{-78, 133, -78}, 0, {829, 291}, {0x17, 0x7B, 0x17, 0xFF}}},
	{{{-81, 126, 0}, 0, {752, 291}, {0x15, 0x7D, 0x00, 0xFF}}},
};

Gfx plate_counter_plate_counter_model_mesh_layer_1_tri_0[] = {
	gsSPVertex(plate_counter_plate_counter_model_mesh_layer_1_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 17, 19, 18, 0),
	gsSP2Triangles(17, 20, 19, 0, 20, 21, 19, 0),
	gsSP2Triangles(20, 22, 21, 0, 22, 23, 21, 0),
	gsSP2Triangles(22, 24, 23, 0, 24, 25, 23, 0),
	gsSP2Triangles(24, 26, 25, 0, 26, 27, 25, 0),
	gsSP2Triangles(26, 28, 27, 0, 28, 29, 27, 0),
	gsSP2Triangles(28, 30, 29, 0, 30, 31, 29, 0),
	gsSP2Triangles(30, 16, 31, 0, 16, 18, 31, 0),
	gsSPEndDisplayList(),
};

Vtx plate_counter_plate_counter_model_mesh_layer_1_vtx_1[36] = {
	{{{-139, 99, 139}, 0, {557, 240}, {0x8B, 0x31, 0x00, 0xFF}}},
	{{{-125, 133, 125}, 0, {624, 240}, {0x8B, 0x31, 0x00, 0xFF}}},
	{{{-125, 133, -125}, 0, {624, -16}, {0x8B, 0x31, 0x00, 0xFF}}},
	{{{-139, 99, -139}, 0, {557, -16}, {0x8B, 0x31, 0x00, 0xFF}}},
	{{{125, 133, 125}, 0, {624, 496}, {0x00, 0x31, 0x75, 0xFF}}},
	{{{-125, 133, 125}, 0, {624, 240}, {0x00, 0x31, 0x75, 0xFF}}},
	{{{-139, 99, 139}, 0, {557, 240}, {0x00, 0x31, 0x75, 0xFF}}},
	{{{139, 99, 139}, 0, {557, 496}, {0x00, 0x31, 0x75, 0xFF}}},
	{{{139, 99, -139}, 0, {557, 752}, {0x75, 0x31, 0x00, 0xFF}}},
	{{{125, 133, 125}, 0, {624, 496}, {0x75, 0x31, 0x00, 0xFF}}},
	{{{139, 99, 139}, 0, {557, 496}, {0x75, 0x31, 0x00, 0xFF}}},
	{{{125, 133, -125}, 0, {624, 752}, {0x75, 0x31, 0x00, 0xFF}}},
	{{{-139, 99, -139}, 0, {557, 1008}, {0x00, 0x31, 0x8B, 0xFF}}},
	{{{125, 133, -125}, 0, {624, 752}, {0x00, 0x31, 0x8B, 0xFF}}},
	{{{139, 99, -139}, 0, {557, 752}, {0x00, 0x31, 0x8B, 0xFF}}},
	{{{-125, 133, -125}, 0, {624, 1008}, {0x00, 0x31, 0x8B, 0xFF}}},
	{{{-81, 126, 0}, 0, {752, 291}, {0x15, 0x7D, 0x00, 0xFF}}},
	{{{-57, 126, 57}, 0, {675, 291}, {0x0F, 0x7D, 0xF1, 0xFF}}},
	{{{0, 126, 81}, 0, {675, 368}, {0x00, 0x7D, 0xEB, 0xFF}}},
	{{{81, 126, 0}, 0, {752, 445}, {0xEB, 0x7D, 0x00, 0xFF}}},
	{{{57, 126, 57}, 0, {675, 445}, {0xF1, 0x7D, 0xF1, 0xFF}}},
	{{{0, 126, -81}, 0, {829, 368}, {0x00, 0x7D, 0x15, 0xFF}}},
	{{{57, 126, -57}, 0, {829, 445}, {0xF1, 0x7D, 0x0F, 0xFF}}},
	{{{-57, 126, -57}, 0, {829, 291}, {0x0F, 0x7D, 0x0F, 0xFF}}},
	{{{0, 133, 110}, 0, {675, 368}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-78, 133, 78}, 0, {675, 291}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-125, 133, 125}, 0, {624, 240}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-110, 133, 0}, 0, {752, 291}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-125, 133, -125}, 0, {880, 240}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-78, 133, -78}, 0, {829, 291}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{0, 133, -110}, 0, {829, 368}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{125, 133, -125}, 0, {880, 496}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{78, 133, -78}, 0, {829, 445}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{110, 133, 0}, 0, {752, 445}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{125, 133, 125}, 0, {624, 496}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{78, 133, 78}, 0, {675, 445}, {0x00, 0x7F, 0x00, 0xFF}}},
};

Gfx plate_counter_plate_counter_model_mesh_layer_1_tri_1[] = {
	gsSPVertex(plate_counter_plate_counter_model_mesh_layer_1_vtx_1 + 0, 36, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 11, 9, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(18, 20, 19, 0, 19, 21, 16, 0),
	gsSP2Triangles(19, 22, 21, 0, 21, 23, 16, 0),
	gsSP2Triangles(24, 25, 26, 0, 26, 25, 27, 0),
	gsSP2Triangles(27, 28, 26, 0, 27, 29, 28, 0),
	gsSP2Triangles(28, 29, 30, 0, 30, 31, 28, 0),
	gsSP2Triangles(30, 32, 31, 0, 31, 32, 33, 0),
	gsSP2Triangles(33, 34, 31, 0, 33, 35, 34, 0),
	gsSP2Triangles(34, 35, 24, 0, 24, 26, 34, 0),
	gsSPEndDisplayList(),
};


Gfx mat_plate_counter_plate_counters[] = {
	gsSPSetLights1(plate_counter_plate_counters_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_plate_counter_plate_counters[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_plate_counter_plate_counters_gray[] = {
	gsSPSetLights1(plate_counter_plate_counters_gray_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_plate_counter_plate_counters_gray[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx plate_counter_plate_counter_model_mesh_layer_1[] = {
	gsSPDisplayList(mat_plate_counter_plate_counters),
	gsSPDisplayList(plate_counter_plate_counter_model_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_plate_counter_plate_counters),
	gsSPDisplayList(mat_plate_counter_plate_counters_gray),
	gsSPDisplayList(plate_counter_plate_counter_model_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_plate_counter_plate_counters_gray),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

