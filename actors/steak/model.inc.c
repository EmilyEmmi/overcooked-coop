Lights1 steak_steak_raw_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Texture steak_steak_raw_ci8[] = {
	#include "actors/steak/steak_raw.ci8.inc.c"
};

Texture steak_steak_raw_pal_rgba16[] = {
	#include "actors/steak/steak_raw.rgba16.pal"
};

Vtx steak_steak_model_mesh_layer_1_vtx_0[48] = {
	{{{51, 1, -146}, 0, {1473, -6}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{72, 1, -72}, 0, {1655, 225}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-5, 1, -145}, 0, {909, -6}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-30, 1, -128}, 0, {815, 26}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-120, 1, 7}, 0, {-11, 524}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-22, 1, 137}, 0, {906, 979}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{58, 1, 129}, 0, {1538, 951}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{118, 1, 27}, 0, {2032, 590}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{118, 1, 82}, 0, {2032, 779}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-93, 1, 99}, 0, {400, 926}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-113, 1, -79}, 0, {112, 243}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-97, 1, -110}, 0, {271, 90}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{51, 64, -146}, 0, {1473, -6}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-5, 64, -145}, 0, {909, -6}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{72, 64, -72}, 0, {1655, 225}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-30, 64, -128}, 0, {815, 26}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-120, 64, 7}, 0, {-11, 524}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-113, 64, -79}, 0, {112, 243}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-97, 64, -110}, 0, {271, 90}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-22, 64, 137}, 0, {906, 979}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-93, 64, 99}, 0, {400, 926}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{58, 64, 129}, 0, {1538, 951}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{118, 64, 27}, 0, {2032, 590}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{118, 64, 82}, 0, {2032, 779}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{72, 1, -72}, 0, {1547, 269}, {0x77, 0x00, 0xD4, 0xFF}}},
	{{{51, 1, -146}, 0, {1402, 1}, {0x4B, 0x00, 0x9A, 0xFF}}},
	{{{51, 64, -146}, 0, {1511, -50}, {0x4B, 0x00, 0x9A, 0xFF}}},
	{{{-5, 64, -145}, 0, {906, -50}, {0xD9, 0x00, 0x87, 0xFF}}},
	{{{-5, 1, -145}, 0, {932, 1}, {0xD9, 0x00, 0x87, 0xFF}}},
	{{{-30, 64, -128}, 0, {801, -23}, {0xCB, 0x00, 0x8D, 0xFF}}},
	{{{-30, 1, -128}, 0, {791, 62}, {0xCB, 0x00, 0x8D, 0xFF}}},
	{{{-97, 64, -110}, 0, {216, 48}, {0xB2, 0x00, 0x9C, 0xFF}}},
	{{{-97, 1, -110}, 0, {268, 115}, {0xB2, 0x00, 0x9C, 0xFF}}},
	{{{-113, 64, -79}, 0, {45, 218}, {0x86, 0x00, 0xDC, 0xFF}}},
	{{{-113, 1, -79}, 0, {306, 272}, {0x86, 0x00, 0xDC, 0xFF}}},
	{{{-120, 64, 7}, 0, {-5, 512}, {0x82, 0x00, 0x0E, 0xFF}}},
	{{{-120, 1, 7}, 0, {298, 481}, {0x82, 0x00, 0x0E, 0xFF}}},
	{{{-93, 64, 99}, 0, {355, 972}, {0x9D, 0x00, 0x50, 0xFF}}},
	{{{-93, 1, 99}, 0, {502, 853}, {0x9D, 0x00, 0x50, 0xFF}}},
	{{{-22, 64, 137}, 0, {898, 1031}, {0xE7, 0x00, 0x7C, 0xFF}}},
	{{{-22, 1, 137}, 0, {924, 897}, {0xE7, 0x00, 0x7C, 0xFF}}},
	{{{58, 64, 129}, 0, {1578, 1000}, {0x30, 0x00, 0x76, 0xFF}}},
	{{{58, 1, 129}, 0, {1450, 874}, {0x30, 0x00, 0x76, 0xFF}}},
	{{{118, 64, 82}, 0, {2108, 810}, {0x72, 0x00, 0x37, 0xFF}}},
	{{{118, 1, 82}, 0, {1862, 730}, {0x72, 0x00, 0x37, 0xFF}}},
	{{{118, 64, 27}, 0, {2108, 600}, {0x7C, 0x00, 0xE5, 0xFF}}},
	{{{118, 1, 27}, 0, {1862, 572}, {0x7C, 0x00, 0xE5, 0xFF}}},
	{{{72, 64, -72}, 0, {1703, 198}, {0x77, 0x00, 0xD4, 0xFF}}},
};

Gfx steak_steak_model_mesh_layer_1_tri_0[] = {
	gsSPVertex(steak_steak_model_mesh_layer_1_vtx_0 + 0, 48, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
	gsSP2Triangles(3, 1, 4, 0, 1, 5, 4, 0),
	gsSP2Triangles(5, 1, 6, 0, 1, 7, 6, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 4, 5, 0),
	gsSP2Triangles(10, 3, 4, 0, 3, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 13, 15, 14, 0),
	gsSP2Triangles(15, 16, 14, 0, 17, 16, 15, 0),
	gsSP2Triangles(15, 18, 17, 0, 14, 16, 19, 0),
	gsSP2Triangles(20, 19, 16, 0, 19, 21, 14, 0),
	gsSP2Triangles(14, 21, 22, 0, 21, 23, 22, 0),
	gsSP2Triangles(24, 25, 26, 0, 25, 27, 26, 0),
	gsSP2Triangles(25, 28, 27, 0, 28, 29, 27, 0),
	gsSP2Triangles(28, 30, 29, 0, 30, 31, 29, 0),
	gsSP2Triangles(30, 32, 31, 0, 32, 33, 31, 0),
	gsSP2Triangles(32, 34, 33, 0, 34, 35, 33, 0),
	gsSP2Triangles(34, 36, 35, 0, 36, 37, 35, 0),
	gsSP2Triangles(36, 38, 37, 0, 38, 39, 37, 0),
	gsSP2Triangles(38, 40, 39, 0, 40, 41, 39, 0),
	gsSP2Triangles(40, 42, 41, 0, 42, 43, 41, 0),
	gsSP2Triangles(42, 44, 43, 0, 44, 45, 43, 0),
	gsSP2Triangles(44, 46, 45, 0, 46, 47, 45, 0),
	gsSP2Triangles(46, 24, 47, 0, 24, 26, 47, 0),
	gsSPEndDisplayList(),
};


Gfx mat_steak_steak_raw[] = {
	gsSPSetLights1(steak_steak_raw_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, steak_steak_raw_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 185),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, steak_steak_raw_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_steak_steak_raw[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx steak_steak_model_mesh_layer_1[] = {
	gsSPDisplayList(mat_steak_steak_raw),
	gsSPDisplayList(steak_steak_model_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_steak_steak_raw),
	gsSPEndDisplayList(),
};

Gfx steak_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, 0),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP  | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, 0),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 256, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(6, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 256, 1, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(1, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

