Lights1 main_counter_side_wood2_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 main_counter_side_wood_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 main_counter_side_handle_lights = gdSPDefLights1(
	0x34, 0x34, 0x34,
	0x6F, 0x6F, 0x6F, 0x28, 0x28, 0x28);

Texture main_counter_side_wood2_ci8[] = {
	#include "actors/main_counter_side/wood2.ci8.inc.c"
};

Texture main_counter_side_wood2_pal_rgba16[] = {
	#include "actors/main_counter_side/wood2.rgba16.pal"
};

Texture main_counter_side_wood_ci8[] = {
	#include "actors/main_counter_side/wood.ci8.inc.c"
};

Texture main_counter_side_wood_pal_rgba16[] = {
	#include "actors/main_counter_side/wood.rgba16.pal"
};

Vtx main_counter_side_main_counter_side_model_mesh_layer_1_vtx_0[41] = {
	{{{-140, 0, -114}, 0, {916, 2528}, {0x81, 0x00, 0x00, 0x00}}},
	{{{-140, 218, -114}, 0, {916, -32}, {0x81, 0x00, 0x00, 0x00}}},
	{{{-140, 218, -139}, 0, {1100, -32}, {0x81, 0x00, 0x00, 0x00}}},
	{{{-140, 0, -139}, 0, {1100, 2528}, {0x81, 0x00, 0x00, 0x00}}},
	{{{139, 0, -114}, 0, {2032, 2528}, {0x00, 0x00, 0x7F, 0x00}}},
	{{{-140, 218, -114}, 0, {-16, -32}, {0x00, 0x00, 0x7F, 0x00}}},
	{{{-140, 0, -114}, 0, {-16, 2528}, {0x00, 0x00, 0x7F, 0x00}}},
	{{{139, 218, -114}, 0, {2032, -32}, {0x00, 0x00, 0x7F, 0x00}}},
	{{{139, 218, -139}, 0, {2032, 1084}, {0x00, 0x7F, 0x00, 0x00}}},
	{{{-140, 218, -139}, 0, {-16, 1084}, {0x00, 0x7F, 0x00, 0x00}}},
	{{{-140, 218, -114}, 0, {-16, 1412}, {0x00, 0x7F, 0x00, 0x00}}},
	{{{139, 218, -114}, 0, {2032, 1412}, {0x00, 0x7F, 0x00, 0x00}}},
	{{{-140, 0, -139}, 0, {-16, 2528}, {0x00, 0x00, 0x81, 0x00}}},
	{{{-140, 218, -139}, 0, {-16, -32}, {0x00, 0x00, 0x81, 0x00}}},
	{{{139, 218, -139}, 0, {2032, -32}, {0x00, 0x00, 0x81, 0x00}}},
	{{{139, 0, -139}, 0, {2032, 2528}, {0x00, 0x00, 0x81, 0x00}}},
	{{{139, 0, -139}, 0, {1100, 2528}, {0x7F, 0x00, 0x00, 0x00}}},
	{{{139, 218, -114}, 0, {916, -32}, {0x7F, 0x00, 0x00, 0x00}}},
	{{{139, 0, -114}, 0, {916, 2528}, {0x7F, 0x00, 0x00, 0x00}}},
	{{{139, 218, -139}, 0, {1100, -32}, {0x7F, 0x00, 0x00, 0x00}}},
	{{{-139, 0, 139}, 0, {1925, 1510}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 100, 139}, 0, {1925, 481}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 100, -114}, 0, {295, 481}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 0, -114}, 0, {295, 1510}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{139, 0, -114}, 0, {1765, 1510}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 100, -114}, 0, {1765, 481}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 100, 139}, 0, {135, 481}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 0, 139}, 0, {135, 1510}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{-129, 10, 139}, 0, {505, 1402}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-129, 89, 139}, 0, {505, 588}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-139, 100, 139}, 0, {485, 481}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{139, 100, 139}, 0, {997, 481}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{129, 89, 139}, 0, {978, 588}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{139, 0, 139}, 0, {997, 1510}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{129, 10, 139}, 0, {978, 1402}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-139, 0, 139}, 0, {485, 1510}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-129, 10, 139}, 0, {1714, 1856}, {0x57, 0x4B, 0x35, 0xFF}}},
	{{{129, 10, 139}, 0, {1714, 118}, {0xA9, 0x4B, 0x35, 0xFF}}},
	{{{0, 50, -128}, 0, {941, 987}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{129, 89, 139}, 0, {168, 118}, {0xA9, 0xB5, 0x35, 0xFF}}},
	{{{-129, 89, 139}, 0, {168, 1856}, {0x57, 0xB5, 0x35, 0xFF}}},
};

Gfx main_counter_side_main_counter_side_model_mesh_layer_1_tri_0[] = {
	gsSPVertex(main_counter_side_main_counter_side_model_mesh_layer_1_vtx_0 + 0, 41, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 19, 17, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 29, 31, 30, 0),
	gsSP2Triangles(29, 32, 31, 0, 32, 33, 31, 0),
	gsSP2Triangles(32, 34, 33, 0, 34, 35, 33, 0),
	gsSP2Triangles(34, 28, 35, 0, 28, 30, 35, 0),
	gsSP2Triangles(36, 37, 38, 0, 37, 39, 38, 0),
	gsSP2Triangles(39, 40, 38, 0, 40, 36, 38, 0),
	gsSPEndDisplayList(),
};

Vtx main_counter_side_main_counter_side_model_mesh_layer_1_vtx_1[20] = {
	{{{-139, 100, 139}, 0, {199, 1128}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{139, 100, 139}, 0, {1977, 1128}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{139, 134, 139}, 0, {1977, 779}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-139, 134, 139}, 0, {199, 779}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-139, 100, -114}, 0, {361, 1208}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 100, 139}, 0, {1991, 1208}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 134, 139}, 0, {1991, 859}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 134, -114}, 0, {361, 859}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{139, 100, 139}, 0, {201, 1208}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 100, -114}, 0, {1831, 1208}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 134, -114}, 0, {1831, 859}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 134, 139}, 0, {201, 859}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{129, 10, 131}, 0, {978, 1402}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-129, 89, 131}, 0, {505, 588}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-129, 10, 131}, 0, {505, 1402}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{129, 89, 131}, 0, {978, 588}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-139, 134, 139}, 0, {108, 1908}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{139, 134, 139}, 0, {1908, 1908}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{139, 134, -114}, 0, {1908, 258}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-139, 134, -114}, 0, {108, 258}, {0x00, 0x7F, 0x00, 0xFF}}},
};

Gfx main_counter_side_main_counter_side_model_mesh_layer_1_tri_1[] = {
	gsSPVertex(main_counter_side_main_counter_side_model_mesh_layer_1_vtx_1 + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSPEndDisplayList(),
};

Vtx main_counter_side_main_counter_side_model_mesh_layer_1_vtx_2[14] = {
	{{{-33, 68, 144}, 0, {-16, 1008}, {0x00, 0x7F, 0xFA, 0x00}}},
	{{{-33, 57, -116}, 0, {-16, 1008}, {0xB4, 0xA9, 0x36, 0x00}}},
	{{{-42, 51, 144}, 0, {-16, 1008}, {0x8B, 0xCE, 0xFB, 0x00}}},
	{{{-24, 51, 144}, 0, {-16, 1008}, {0x75, 0xCE, 0xFB, 0x00}}},
	{{{33, 68, 144}, 0, {-16, 1008}, {0x00, 0x7F, 0xFA, 0x00}}},
	{{{42, 51, 144}, 0, {-16, 1008}, {0x75, 0xCE, 0xFB, 0x00}}},
	{{{33, 57, -116}, 0, {-16, 1008}, {0x9B, 0xBF, 0x28, 0x00}}},
	{{{23, 51, 144}, 0, {-16, 1008}, {0x8B, 0xCE, 0xFB, 0x00}}},
	{{{-46, 57, 163}, 0, {-16, 1008}, {0xB9, 0x00, 0x69, 0x00}}},
	{{{46, 71, 141}, 0, {-16, 1008}, {0x46, 0x5D, 0xCD, 0x00}}},
	{{{-46, 71, 141}, 0, {-16, 1008}, {0xBA, 0x5D, 0xCD, 0x00}}},
	{{{46, 57, 163}, 0, {-16, 1008}, {0x47, 0x00, 0x69, 0x00}}},
	{{{-46, 43, 141}, 0, {-16, 1008}, {0xBA, 0xA3, 0xCD, 0x00}}},
	{{{46, 43, 141}, 0, {-16, 1008}, {0x46, 0xA3, 0xCD, 0x00}}},
};

Gfx main_counter_side_main_counter_side_model_mesh_layer_1_tri_2[] = {
	gsSPVertex(main_counter_side_main_counter_side_model_mesh_layer_1_vtx_2 + 0, 14, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(4, 5, 6, 0, 7, 4, 6, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 11, 9, 0),
	gsSP2Triangles(12, 11, 8, 0, 10, 12, 8, 0),
	gsSP2Triangles(12, 13, 11, 0, 11, 13, 9, 0),
	gsSPEndDisplayList(),
};


Gfx mat_main_counter_side_wood2[] = {
	gsSPSetLights1(main_counter_side_wood2_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, main_counter_side_wood2_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 13),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, main_counter_side_wood2_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPEndDisplayList(),
};

Gfx mat_revert_main_counter_side_wood2[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_main_counter_side_wood[] = {
	gsSPSetLights1(main_counter_side_wood_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, main_counter_side_wood_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 15),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, main_counter_side_wood_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPEndDisplayList(),
};

Gfx mat_revert_main_counter_side_wood[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_main_counter_side_handle[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(main_counter_side_handle_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_main_counter_side_handle[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx main_counter_side_main_counter_side_model_mesh_layer_1[] = {
	gsSPDisplayList(mat_main_counter_side_wood2),
	gsSPDisplayList(main_counter_side_main_counter_side_model_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_main_counter_side_wood2),
	gsSPDisplayList(mat_main_counter_side_wood),
	gsSPDisplayList(main_counter_side_main_counter_side_model_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_main_counter_side_wood),
	gsSPDisplayList(mat_main_counter_side_handle),
	gsSPDisplayList(main_counter_side_main_counter_side_model_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_main_counter_side_handle),
	gsSPEndDisplayList(),
};

Gfx main_counter_side_material_revert_render_settings[] = {
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

