Lights1 plate_lettuce_lettuce_lights = gdSPDefLights1(
	0x53, 0x62, 0x4C,
	0xDB, 0xEF, 0xD3, 0x28, 0x28, 0x28);

Texture plate_lettuce_lettuce_rgba16[] = {
	#include "actors/plate_lettuce/lettuce.rgba16.inc.c"
};

Vtx plate_lettuce_plate_lettuce_mdl_mesh_layer_4_vtx_0[26] = {
	{{{-104, 16, 111}, 0, {-16, 2032}, {0x03, 0x7F, 0x00, 0xFF}}},
	{{{5, 14, 137}, 0, {496, 2032}, {0x03, 0x7F, 0x00, 0xFF}}},
	{{{-108, 16, -105}, 0, {-16, -16}, {0x03, 0x7F, 0x00, 0xFF}}},
	{{{0, 14, -138}, 0, {496, -16}, {0x03, 0x7F, 0x00, 0xFF}}},
	{{{109, 12, -122}, 0, {1008, -16}, {0x03, 0x7F, 0x00, 0xFF}}},
	{{{113, 12, 116}, 0, {1008, 2032}, {0x03, 0x7F, 0x00, 0xFF}}},
	{{{60, 30, 167}, 0, {-16, 2032}, {0x07, 0x7E, 0xF6, 0xFF}}},
	{{{94, 23, 114}, 0, {367, 2032}, {0xF0, 0x7B, 0x1C, 0xFF}}},
	{{{-177, 29, -6}, 0, {-16, -16}, {0x01, 0x7F, 0xFC, 0xFF}}},
	{{{-43, 41, -2}, 0, {367, 777}, {0xFB, 0x7E, 0xEF, 0xFF}}},
	{{{115, 47, 86}, 0, {467, 2032}, {0x0A, 0x7E, 0xF9, 0xFF}}},
	{{{0, 16, -54}, 0, {688, 777}, {0x02, 0x7F, 0xF6, 0xFF}}},
	{{{137, 20, 65}, 0, {688, 2032}, {0x17, 0x79, 0xE0, 0xFF}}},
	{{{178, 26, 8}, 0, {1008, 2032}, {0xF6, 0x7E, 0x08, 0xFF}}},
	{{{-58, 26, -166}, 0, {1008, -16}, {0x04, 0x7F, 0x09, 0xFF}}},
	{{{-66, 25, -80}, 0, {-16, 1150}, {0xF7, 0x7E, 0xF0, 0xFF}}},
	{{{-168, 39, 1}, 0, {-16, 2032}, {0x02, 0x7F, 0xF9, 0xFF}}},
	{{{-20, 35, -29}, 0, {505, 1167}, {0xF9, 0x7D, 0xE8, 0xFF}}},
	{{{-141, 38, 36}, 0, {176, 2032}, {0xF2, 0x7A, 0xDE, 0xFF}}},
	{{{-122, 55, 45}, 0, {367, 2032}, {0xF7, 0x7F, 0x05, 0xFF}}},
	{{{12, 50, 12}, 0, {688, 1079}, {0xFE, 0x7E, 0xF2, 0xFF}}},
	{{{-129, 28, 70}, 0, {467, 2032}, {0x04, 0x74, 0x34, 0xFF}}},
	{{{-58, 30, 152}, 0, {1008, 2032}, {0xF3, 0x7E, 0x0B, 0xFF}}},
	{{{81, 47, 77}, 0, {1008, 911}, {0x01, 0x7F, 0x04, 0xFF}}},
	{{{169, 39, -20}, 0, {1008, -16}, {0x01, 0x7F, 0xF9, 0xFF}}},
	{{{68, 39, -162}, 0, {-16, -16}, {0xF9, 0x7F, 0xFF, 0xFF}}},
};

Gfx plate_lettuce_plate_lettuce_mdl_mesh_layer_4_tri_0[] = {
	gsSPVertex(plate_lettuce_plate_lettuce_mdl_mesh_layer_4_vtx_0 + 0, 26, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(4, 3, 1, 0, 5, 4, 1, 0),
	gsSP2Triangles(6, 7, 8, 0, 7, 9, 8, 0),
	gsSP2Triangles(7, 10, 9, 0, 9, 10, 11, 0),
	gsSP2Triangles(10, 12, 11, 0, 12, 13, 11, 0),
	gsSP2Triangles(13, 14, 11, 0, 11, 14, 8, 0),
	gsSP2Triangles(9, 11, 8, 0, 15, 16, 17, 0),
	gsSP2Triangles(16, 18, 17, 0, 18, 19, 17, 0),
	gsSP2Triangles(19, 20, 17, 0, 19, 21, 20, 0),
	gsSP2Triangles(21, 22, 20, 0, 22, 23, 20, 0),
	gsSP2Triangles(20, 23, 24, 0, 20, 24, 17, 0),
	gsSP2Triangles(24, 25, 17, 0, 25, 15, 17, 0),
	gsSPEndDisplayList(),
};


Gfx mat_plate_lettuce_lettuce[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(plate_lettuce_lettuce_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, plate_lettuce_lettuce_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 252),
	gsSPEndDisplayList(),
};

Gfx mat_revert_plate_lettuce_lettuce[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx plate_lettuce_plate_lettuce_mdl_mesh_layer_4[] = {
	gsSPDisplayList(mat_plate_lettuce_lettuce),
	gsSPDisplayList(plate_lettuce_plate_lettuce_mdl_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_plate_lettuce_lettuce),
	gsSPEndDisplayList(),
};

Gfx plate_lettuce_material_revert_render_settings[] = {
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

