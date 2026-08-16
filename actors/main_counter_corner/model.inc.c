Lights1 main_counter_corner_wood_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 main_counter_corner_wood2_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Texture main_counter_corner_wood_ci8[] = {
	#include "actors/main_counter_corner/wood.ci8.inc.c"
};

Texture main_counter_corner_wood_pal_rgba16[] = {
	#include "actors/main_counter_corner/wood.rgba16.pal"
};

Texture main_counter_corner_wood2_ci8[] = {
	#include "actors/main_counter_corner/wood2.ci8.inc.c"
};

Texture main_counter_corner_wood2_pal_rgba16[] = {
	#include "actors/main_counter_corner/wood2.rgba16.pal"
};

Vtx main_counter_corner_main_counter_corner_model_mesh_layer_1_vtx_0[4] = {
	{{{-114, 134, -114}, 0, {1001, 10}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{139, 134, 139}, 0, {1001, 2471}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{139, 134, -114}, 0, {2231, 631}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-114, 134, 139}, 0, {-229, 631}, {0x00, 0x7F, 0x00, 0xFF}}},
};

Gfx main_counter_corner_main_counter_corner_model_mesh_layer_1_tri_0[] = {
	gsSPVertex(main_counter_corner_main_counter_corner_model_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSPEndDisplayList(),
};

Vtx main_counter_corner_main_counter_corner_model_mesh_layer_1_vtx_1[30] = {
	{{{-114, 0, 139}, 0, {916, 2528}, {0x00, 0x00, 0x7F, 0x00}}},
	{{{-114, 218, 139}, 0, {916, -32}, {0x00, 0x00, 0x7F, 0x00}}},
	{{{-140, 218, 139}, 0, {1100, -32}, {0x00, 0x00, 0x7F, 0x00}}},
	{{{-140, 0, 139}, 0, {1100, 2528}, {0x00, 0x00, 0x7F, 0x00}}},
	{{{-140, 218, -139}, 0, {1008, 835}, {0x00, 0x7F, 0x00, 0x00}}},
	{{{-140, 218, 139}, 0, {-16, 1084}, {0x00, 0x7F, 0x00, 0x00}}},
	{{{-114, 218, 139}, 0, {-16, 1412}, {0x00, 0x7F, 0x00, 0x00}}},
	{{{-114, 218, -114}, 0, {1008, 1412}, {0x00, 0x7F, 0x00, 0x00}}},
	{{{139, 218, -139}, 0, {2032, 1084}, {0x00, 0x7F, 0x00, 0x00}}},
	{{{139, 218, -114}, 0, {2032, 1412}, {0x00, 0x7F, 0x00, 0x00}}},
	{{{-140, 0, 139}, 0, {-16, 2528}, {0x81, 0x00, 0x00, 0x00}}},
	{{{-140, 218, 139}, 0, {-16, -32}, {0x81, 0x00, 0x00, 0x00}}},
	{{{-140, 218, -139}, 0, {1114, -32}, {0x81, 0x00, 0x00, 0x00}}},
	{{{-140, 0, -139}, 0, {1008, 2528}, {0x81, 0x00, 0x00, 0x00}}},
	{{{-114, 0, -114}, 0, {1008, 2528}, {0x7F, 0x00, 0x00, 0x00}}},
	{{{-114, 218, -114}, 0, {1008, -32}, {0x7F, 0x00, 0x00, 0x00}}},
	{{{-114, 218, 139}, 0, {-16, -32}, {0x7F, 0x00, 0x00, 0x00}}},
	{{{-114, 0, 139}, 0, {-16, 2528}, {0x7F, 0x00, 0x00, 0x00}}},
	{{{139, 0, -139}, 0, {1100, 2528}, {0x7F, 0x00, 0x00, 0x00}}},
	{{{139, 218, -114}, 0, {916, -32}, {0x7F, 0x00, 0x00, 0x00}}},
	{{{139, 0, -114}, 0, {916, 2528}, {0x7F, 0x00, 0x00, 0x00}}},
	{{{139, 218, -139}, 0, {1100, -32}, {0x7F, 0x00, 0x00, 0x00}}},
	{{{139, 0, -114}, 0, {2032, 2528}, {0x00, 0x00, 0x7F, 0x00}}},
	{{{139, 218, -114}, 0, {2032, -32}, {0x00, 0x00, 0x7F, 0x00}}},
	{{{-114, 218, -114}, 0, {1008, -32}, {0x00, 0x00, 0x7F, 0x00}}},
	{{{-114, 0, -114}, 0, {1008, 2528}, {0x00, 0x00, 0x7F, 0x00}}},
	{{{-140, 0, -139}, 0, {1008, 2528}, {0x00, 0x00, 0x81, 0x00}}},
	{{{139, 218, -139}, 0, {2032, -32}, {0x00, 0x00, 0x81, 0x00}}},
	{{{139, 0, -139}, 0, {2032, 2528}, {0x00, 0x00, 0x81, 0x00}}},
	{{{-140, 218, -139}, 0, {1008, 526}, {0x00, 0x00, 0x81, 0x00}}},
};

Gfx main_counter_corner_main_counter_corner_model_mesh_layer_1_tri_1[] = {
	gsSPVertex(main_counter_corner_main_counter_corner_model_mesh_layer_1_vtx_1 + 0, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 4, 7, 0, 8, 7, 9, 0),
	gsSP2Triangles(10, 11, 12, 0, 10, 12, 13, 0),
	gsSP2Triangles(14, 15, 16, 0, 14, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 18, 21, 19, 0),
	gsSP2Triangles(22, 23, 24, 0, 22, 24, 25, 0),
	gsSP2Triangles(26, 27, 28, 0, 26, 29, 27, 0),
	gsSPEndDisplayList(),
};


Gfx mat_main_counter_corner_wood[] = {
	gsSPSetLights1(main_counter_corner_wood_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, main_counter_corner_wood_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 15),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, main_counter_corner_wood_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPEndDisplayList(),
};

Gfx mat_revert_main_counter_corner_wood[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_main_counter_corner_wood2[] = {
	gsSPSetLights1(main_counter_corner_wood2_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, main_counter_corner_wood2_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 13),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, main_counter_corner_wood2_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPEndDisplayList(),
};

Gfx mat_revert_main_counter_corner_wood2[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx main_counter_corner_main_counter_corner_model_mesh_layer_1[] = {
	gsSPDisplayList(mat_main_counter_corner_wood),
	gsSPDisplayList(main_counter_corner_main_counter_corner_model_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_main_counter_corner_wood),
	gsSPDisplayList(mat_main_counter_corner_wood2),
	gsSPDisplayList(main_counter_corner_main_counter_corner_model_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_main_counter_corner_wood2),
	gsSPEndDisplayList(),
};

Gfx main_counter_corner_material_revert_render_settings[] = {
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

