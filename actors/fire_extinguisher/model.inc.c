Lights1 fire_extinguisher_fire_extinguisher_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 fire_extinguisher_fire_extinguisher_handle_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Texture fire_extinguisher_fire_extinguisher_ci4[] = {
	#include "actors/fire_extinguisher/fire_extinguisher.ci4.inc.c"
};

Texture fire_extinguisher_fire_extinguisher_pal_rgba16[] = {
	#include "actors/fire_extinguisher/fire_extinguisher.rgba16.pal"
};

Texture fire_extinguisher_fire_extinguisher_handle_ci4[] = {
	#include "actors/fire_extinguisher/fire_extinguisher_handle.ci4.inc.c"
};

Texture fire_extinguisher_fire_extinguisher_handle_pal_rgba16[] = {
	#include "actors/fire_extinguisher/fire_extinguisher_handle.rgba16.pal"
};

Vtx fire_extinguisher_fire_extinguisher_model_mesh_layer_1_vtx_0[52] = {
	{{{-95, -124, -95}, 0, {-61, 519}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{0, -124, -135}, 0, {513, 519}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{95, -124, -95}, 0, {636, 519}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{95, -124, 95}, 0, {636, 519}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{135, -124, 0}, 0, {681, 519}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-95, -124, 95}, 0, {-61, 519}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{0, -124, 135}, 0, {513, 519}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-135, -124, 0}, 0, {-299, 519}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-187, 172, 26}, 0, {173, 586}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-187, 222, 42}, 0, {173, 566}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-187, 252, 0}, 0, {173, 553}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-187, 172, -26}, 0, {173, 586}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-187, 222, -42}, 0, {173, 566}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{0, -124, -135}, 0, {513, 519}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{95, 70, -95}, 0, {636, 43}, {0x57, 0x1F, 0xA9, 0xFF}}},
	{{{95, -124, -95}, 0, {636, 519}, {0x5A, 0x00, 0xA6, 0xFF}}},
	{{{0, 70, -135}, 0, {513, 43}, {0x00, 0x1F, 0x85, 0xFF}}},
	{{{-95, -124, -95}, 0, {-61, 519}, {0xA6, 0x00, 0xA6, 0xFF}}},
	{{{-95, 70, -95}, 0, {-61, 43}, {0xA9, 0x1F, 0xA9, 0xFF}}},
	{{{-135, -124, 0}, 0, {-299, 519}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-135, 70, 0}, 0, {-299, 43}, {0x85, 0x1F, 0x00, 0xFF}}},
	{{{-95, -124, 95}, 0, {-61, 519}, {0xA6, 0x00, 0x5A, 0xFF}}},
	{{{-95, 70, 95}, 0, {-61, 43}, {0xA9, 0x1F, 0x57, 0xFF}}},
	{{{0, -124, 135}, 0, {513, 519}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{0, 70, 135}, 0, {513, 43}, {0x00, 0x1F, 0x7B, 0xFF}}},
	{{{95, -124, 95}, 0, {636, 519}, {0x5A, 0x00, 0x5A, 0xFF}}},
	{{{95, 70, 95}, 0, {636, 43}, {0x57, 0x1F, 0x57, 0xFF}}},
	{{{135, -124, 0}, 0, {681, 519}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{135, 70, 0}, 0, {681, 43}, {0x7B, 0x1F, 0x00, 0xFF}}},
	{{{68, 138, -68}, 0, {605, -442}, {0x3C, 0x5F, 0xC4, 0xFF}}},
	{{{0, 138, -96}, 0, {513, -442}, {0x00, 0x5F, 0xAC, 0xFF}}},
	{{{-68, 138, -68}, 0, {103, -442}, {0xC4, 0x5F, 0xC4, 0xFF}}},
	{{{-96, 138, 0}, 0, {-66, -442}, {0xAC, 0x5F, 0x00, 0xFF}}},
	{{{-68, 138, 68}, 0, {103, -442}, {0xC4, 0x5F, 0x3C, 0xFF}}},
	{{{0, 138, 96}, 0, {513, -442}, {0x00, 0x5F, 0x54, 0xFF}}},
	{{{68, 138, 68}, 0, {605, -442}, {0x3C, 0x5F, 0x3C, 0xFF}}},
	{{{96, 138, 0}, 0, {637, -442}, {0x54, 0x5F, 0x00, 0xFF}}},
	{{{0, 164, 0}, 0, {513, -461}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{0, 148, -38}, 0, {240, 594}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{0, 188, -38}, 0, {240, 546}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{33, 188, 19}, 0, {276, 546}, {0x6E, 0x00, 0x3F, 0xFF}}},
	{{{-33, 148, 19}, 0, {204, 594}, {0x92, 0x00, 0x3F, 0xFF}}},
	{{{-33, 188, 19}, 0, {204, 546}, {0x92, 0x00, 0x3F, 0xFF}}},
	{{{33, 148, 19}, 0, {276, 594}, {0x6E, 0x00, 0x3F, 0xFF}}},
	{{{-42, 232, 0}, 0, {315, 561}, {0x29, 0x78, 0x00, 0xFF}}},
	{{{-187, 222, -42}, 0, {173, 566}, {0x10, 0x28, 0x89, 0xFF}}},
	{{{-187, 252, 0}, 0, {173, 553}, {0x11, 0x7E, 0x00, 0xFF}}},
	{{{-42, 196, -21}, 0, {315, 577}, {0x27, 0xC2, 0x98, 0xFF}}},
	{{{-187, 172, -26}, 0, {173, 586}, {0x13, 0x99, 0xB9, 0xFF}}},
	{{{-42, 196, 21}, 0, {315, 577}, {0x27, 0xC2, 0x68, 0xFF}}},
	{{{-187, 172, 26}, 0, {173, 586}, {0x13, 0x99, 0x47, 0xFF}}},
	{{{-187, 222, 42}, 0, {173, 566}, {0x10, 0x28, 0x77, 0xFF}}},
};

Gfx fire_extinguisher_fire_extinguisher_model_mesh_layer_1_tri_0[] = {
	gsSPVertex(fire_extinguisher_fire_extinguisher_model_mesh_layer_1_vtx_0 + 0, 52, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(2, 4, 3, 0, 3, 5, 0, 0),
	gsSP2Triangles(3, 6, 5, 0, 5, 7, 0, 0),
	gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
	gsSP2Triangles(10, 12, 11, 0, 13, 14, 15, 0),
	gsSP2Triangles(13, 16, 14, 0, 17, 16, 13, 0),
	gsSP2Triangles(17, 18, 16, 0, 19, 18, 17, 0),
	gsSP2Triangles(19, 20, 18, 0, 21, 20, 19, 0),
	gsSP2Triangles(21, 22, 20, 0, 23, 22, 21, 0),
	gsSP2Triangles(23, 24, 22, 0, 25, 24, 23, 0),
	gsSP2Triangles(25, 26, 24, 0, 27, 26, 25, 0),
	gsSP2Triangles(27, 28, 26, 0, 15, 28, 27, 0),
	gsSP2Triangles(15, 14, 28, 0, 28, 14, 29, 0),
	gsSP2Triangles(14, 30, 29, 0, 14, 16, 30, 0),
	gsSP2Triangles(16, 31, 30, 0, 16, 18, 31, 0),
	gsSP2Triangles(18, 32, 31, 0, 18, 20, 32, 0),
	gsSP2Triangles(20, 33, 32, 0, 20, 22, 33, 0),
	gsSP2Triangles(22, 34, 33, 0, 22, 24, 34, 0),
	gsSP2Triangles(24, 35, 34, 0, 24, 26, 35, 0),
	gsSP2Triangles(26, 36, 35, 0, 26, 28, 36, 0),
	gsSP2Triangles(28, 29, 36, 0, 36, 29, 37, 0),
	gsSP2Triangles(29, 30, 37, 0, 30, 31, 37, 0),
	gsSP2Triangles(31, 32, 37, 0, 32, 33, 37, 0),
	gsSP2Triangles(33, 34, 37, 0, 34, 35, 37, 0),
	gsSP2Triangles(35, 36, 37, 0, 38, 39, 40, 0),
	gsSP2Triangles(41, 39, 38, 0, 41, 42, 39, 0),
	gsSP2Triangles(43, 42, 41, 0, 43, 40, 42, 0),
	gsSP2Triangles(38, 40, 43, 0, 44, 45, 46, 0),
	gsSP2Triangles(47, 45, 44, 0, 47, 48, 45, 0),
	gsSP2Triangles(48, 47, 49, 0, 50, 48, 49, 0),
	gsSP2Triangles(49, 51, 50, 0, 44, 51, 49, 0),
	gsSP1Triangle(44, 46, 51, 0),
	gsSPEndDisplayList(),
};

Vtx fire_extinguisher_fire_extinguisher_model_mesh_layer_1_vtx_1[44] = {
	{{{-50, 182, -45}, 0, {252, 4}, {0xFE, 0x81, 0x00, 0xFF}}},
	{{{37, 181, 45}, 0, {252, 4}, {0xEF, 0x82, 0x00, 0xFF}}},
	{{{-50, 182, 45}, 0, {252, 4}, {0xFE, 0x81, 0x00, 0xFF}}},
	{{{37, 181, -45}, 0, {252, 4}, {0xEF, 0x82, 0x00, 0xFF}}},
	{{{191, 142, -45}, 0, {252, 4}, {0xE1, 0x85, 0x00, 0xFF}}},
	{{{191, 142, 45}, 0, {252, 4}, {0xE1, 0x85, 0x00, 0xFF}}},
	{{{-50, 182, 45}, 0, {252, 4}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-50, 247, 45}, 0, {252, 4}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-50, 247, -45}, 0, {252, 4}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-50, 182, -45}, 0, {252, 4}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{37, 258, -45}, 0, {252, 4}, {0x01, 0x7F, 0x00, 0xFF}}},
	{{{-50, 247, -45}, 0, {252, 4}, {0xEF, 0x7E, 0x00, 0xFF}}},
	{{{-50, 247, 45}, 0, {252, 4}, {0xEF, 0x7E, 0x00, 0xFF}}},
	{{{37, 258, 45}, 0, {252, 4}, {0x01, 0x7F, 0x00, 0xFF}}},
	{{{150, 241, 45}, 0, {252, 4}, {0x13, 0x7E, 0x00, 0xFF}}},
	{{{150, 241, -45}, 0, {252, 4}, {0x13, 0x7E, 0x00, 0xFF}}},
	{{{37, 208, 45}, 0, {1002, 387}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{37, 181, 45}, 0, {1043, 458}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{191, 142, 45}, 0, {1106, 408}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-50, 182, 45}, 0, {-36, 342}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-50, 247, 45}, 0, {21, -82}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{37, 237, 45}, 0, {1050, 86}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{37, 258, 45}, 0, {1074, -21}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{150, 241, 45}, 0, {1140, 64}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{37, 208, -45}, 0, {1002, 387}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{191, 142, -45}, 0, {1106, 408}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{37, 181, -45}, 0, {1043, 458}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{-50, 182, -45}, 0, {-36, 342}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{-50, 247, -45}, 0, {21, -82}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{37, 237, -45}, 0, {1050, 86}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{37, 258, -45}, 0, {1074, -21}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{150, 241, -45}, 0, {1140, 64}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{37, 208, -45}, 0, {252, 4}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{37, 237, -45}, 0, {252, 4}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{37, 237, 45}, 0, {252, 4}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{37, 208, 45}, 0, {252, 4}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{37, 237, 45}, 0, {252, 4}, {0x05, 0x81, 0x00, 0xFF}}},
	{{{37, 237, -45}, 0, {252, 4}, {0x05, 0x81, 0x00, 0xFF}}},
	{{{150, 241, -45}, 0, {252, 4}, {0x05, 0x81, 0x00, 0xFF}}},
	{{{150, 241, 45}, 0, {252, 4}, {0x05, 0x81, 0x00, 0xFF}}},
	{{{37, 208, -45}, 0, {252, 4}, {0x32, 0x75, 0x00, 0xFF}}},
	{{{37, 208, 45}, 0, {252, 4}, {0x32, 0x75, 0x00, 0xFF}}},
	{{{191, 142, 45}, 0, {252, 4}, {0x32, 0x75, 0x00, 0xFF}}},
	{{{191, 142, -45}, 0, {252, 4}, {0x32, 0x75, 0x00, 0xFF}}},
};

Gfx fire_extinguisher_fire_extinguisher_model_mesh_layer_1_tri_1[] = {
	gsSPVertex(fire_extinguisher_fire_extinguisher_model_mesh_layer_1_vtx_1 + 0, 44, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(1, 3, 4, 0, 1, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
	gsSP2Triangles(10, 11, 12, 0, 10, 12, 13, 0),
	gsSP2Triangles(10, 13, 14, 0, 10, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 17, 16, 19, 0),
	gsSP2Triangles(16, 20, 19, 0, 16, 21, 20, 0),
	gsSP2Triangles(21, 22, 20, 0, 22, 21, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 26, 27, 24, 0),
	gsSP2Triangles(24, 27, 28, 0, 24, 28, 29, 0),
	gsSP2Triangles(29, 28, 30, 0, 30, 31, 29, 0),
	gsSP2Triangles(32, 33, 34, 0, 32, 34, 35, 0),
	gsSP2Triangles(36, 37, 38, 0, 36, 38, 39, 0),
	gsSP2Triangles(40, 41, 42, 0, 40, 42, 43, 0),
	gsSPEndDisplayList(),
};


Gfx mat_fire_extinguisher_fire_extinguisher[] = {
	gsSPSetLights1(fire_extinguisher_fire_extinguisher_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fire_extinguisher_fire_extinguisher_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 2),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, fire_extinguisher_fire_extinguisher_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 63, 2048),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 4, 0, G_TX_CLAMP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 60),
	gsSPEndDisplayList(),
};

Gfx mat_revert_fire_extinguisher_fire_extinguisher[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_fire_extinguisher_fire_extinguisher_handle[] = {
	gsSPSetLights1(fire_extinguisher_fire_extinguisher_handle_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fire_extinguisher_fire_extinguisher_handle_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 6),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, fire_extinguisher_fire_extinguisher_handle_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 63, 2048),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 4, 0, G_TX_CLAMP | G_TX_MIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 124, 60),
	gsSPEndDisplayList(),
};

Gfx mat_revert_fire_extinguisher_fire_extinguisher_handle[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx fire_extinguisher_fire_extinguisher_model_mesh_layer_1[] = {
	gsSPDisplayList(mat_fire_extinguisher_fire_extinguisher),
	gsSPDisplayList(fire_extinguisher_fire_extinguisher_model_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_fire_extinguisher_fire_extinguisher),
	gsSPDisplayList(mat_fire_extinguisher_fire_extinguisher_handle),
	gsSPDisplayList(fire_extinguisher_fire_extinguisher_model_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_fire_extinguisher_fire_extinguisher_handle),
	gsSPEndDisplayList(),
};

Gfx fire_extinguisher_material_revert_render_settings[] = {
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

