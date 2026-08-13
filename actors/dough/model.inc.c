Lights1 dough_dough_lights = gdSPDefLights1(
	0x7C, 0x71, 0x55,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Texture dough_dough_ci8[] = {
	#include "actors/dough/dough.ci8.inc.c"
};

Texture dough_dough_pal_rgba16[] = {
	#include "actors/dough/dough.rgba16.pal"
};

Vtx dough_dough_model_mesh_layer_1_vtx_0[31] = {
	{{{-39, 131, -51}, 0, {371, 197}, {0xE0, 0x6F, 0xCB, 0xFF}}},
	{{{2, 146, 1}, 0, {522, 477}, {0x02, 0x7F, 0xFF, 0xFF}}},
	{{{42, 131, -42}, 0, {756, 316}, {0x27, 0x6F, 0xD0, 0xFF}}},
	{{{-62, 132, -3}, 0, {215, 398}, {0xC2, 0x6F, 0xFF, 0xFF}}},
	{{{-102, 87, -35}, 0, {49, 212}, {0x91, 0x37, 0xE2, 0xFF}}},
	{{{-67, 90, -88}, 0, {266, 0}, {0xC0, 0x41, 0xA8, 0xFF}}},
	{{{-1, 88, -106}, 0, {605, -21}, {0x03, 0x43, 0x94, 0xFF}}},
	{{{69, 88, -83}, 0, {926, 153}, {0x45, 0x40, 0xAA, 0xFF}}},
	{{{105, 86, -31}, 0, {1055, 430}, {0x6B, 0x3C, 0xDE, 0xFF}}},
	{{{61, 130, 3}, 0, {811, 546}, {0x3C, 0x70, 0xFD, 0xFF}}},
	{{{36, 129, 69}, 0, {627, 827}, {0x1D, 0x6D, 0x3A, 0xFF}}},
	{{{-39, 127, 59}, 0, {271, 708}, {0xD7, 0x6C, 0x34, 0xFF}}},
	{{{-101, 90, 26}, 0, {-2, 496}, {0x96, 0x41, 0x1B, 0xFF}}},
	{{{-108, 39, -30}, 0, {13, 228}, {0x8A, 0xDF, 0xDF, 0xFF}}},
	{{{-81, 41, -94}, 0, {202, -40}, {0xAE, 0xE3, 0xA4, 0xFF}}},
	{{{-8, 38, -119}, 0, {585, -89}, {0xF8, 0xDA, 0x87, 0xFF}}},
	{{{64, 37, -103}, 0, {920, 54}, {0x3E, 0xE2, 0x95, 0xFF}}},
	{{{115, 33, -39}, 0, {1112, 404}, {0x72, 0xD3, 0xDE, 0xFF}}},
	{{{116, 37, 40}, 0, {1044, 767}, {0x73, 0xD6, 0x21, 0xFF}}},
	{{{106, 93, 42}, 0, {991, 767}, {0x69, 0x3E, 0x24, 0xFF}}},
	{{{57, 88, 100}, 0, {700, 990}, {0x3B, 0x37, 0x62, 0xFF}}},
	{{{-8, 88, 113}, 0, {371, 987}, {0xF1, 0x40, 0x6D, 0xFF}}},
	{{{-62, 90, 89}, 0, {130, 827}, {0xBA, 0x3E, 0x56, 0xFF}}},
	{{{-76, 39, 95}, 0, {57, 839}, {0xAE, 0xEB, 0x5F, 0xFF}}},
	{{{-121, 32, 33}, 0, {-108, 506}, {0x88, 0xDD, 0x18, 0xFF}}},
	{{{-63, 1, -57}, 0, {258, 145}, {0xD2, 0x90, 0xD8, 0xFF}}},
	{{{53, -4, -63}, 0, {831, 231}, {0x22, 0x8D, 0xD7, 0xFF}}},
	{{{60, -1, 64}, 0, {748, 824}, {0x2B, 0x8F, 0x26, 0xFF}}},
	{{{65, 37, 105}, 0, {737, 1023}, {0x47, 0xDE, 0x64, 0xFF}}},
	{{{-4, 33, 131}, 0, {377, 1074}, {0xF9, 0xD7, 0x78, 0xFF}}},
	{{{-63, -1, 64}, 0, {147, 707}, {0xD6, 0x8F, 0x29, 0xFF}}},
};

Gfx dough_dough_model_mesh_layer_1_tri_0[] = {
	gsSPVertex(dough_dough_model_mesh_layer_1_vtx_0 + 0, 31, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(4, 3, 0, 0, 4, 0, 5, 0),
	gsSP2Triangles(5, 0, 6, 0, 6, 0, 2, 0),
	gsSP2Triangles(7, 6, 2, 0, 2, 8, 7, 0),
	gsSP2Triangles(2, 9, 8, 0, 2, 1, 9, 0),
	gsSP2Triangles(9, 1, 10, 0, 10, 1, 11, 0),
	gsSP2Triangles(11, 1, 3, 0, 11, 3, 12, 0),
	gsSP2Triangles(12, 3, 4, 0, 12, 4, 13, 0),
	gsSP2Triangles(4, 14, 13, 0, 4, 5, 14, 0),
	gsSP2Triangles(5, 15, 14, 0, 5, 6, 15, 0),
	gsSP2Triangles(6, 16, 15, 0, 6, 7, 16, 0),
	gsSP2Triangles(7, 17, 16, 0, 7, 8, 17, 0),
	gsSP2Triangles(8, 18, 17, 0, 8, 19, 18, 0),
	gsSP2Triangles(8, 9, 19, 0, 19, 9, 10, 0),
	gsSP2Triangles(19, 10, 20, 0, 10, 21, 20, 0),
	gsSP2Triangles(10, 11, 21, 0, 21, 11, 22, 0),
	gsSP2Triangles(11, 12, 22, 0, 23, 22, 12, 0),
	gsSP2Triangles(23, 12, 24, 0, 12, 13, 24, 0),
	gsSP2Triangles(25, 24, 13, 0, 13, 14, 25, 0),
	gsSP2Triangles(25, 14, 15, 0, 15, 26, 25, 0),
	gsSP2Triangles(15, 16, 26, 0, 26, 16, 17, 0),
	gsSP2Triangles(26, 17, 18, 0, 26, 18, 27, 0),
	gsSP2Triangles(18, 28, 27, 0, 19, 28, 18, 0),
	gsSP2Triangles(19, 20, 28, 0, 20, 29, 28, 0),
	gsSP2Triangles(20, 21, 29, 0, 21, 23, 29, 0),
	gsSP2Triangles(21, 22, 23, 0, 30, 29, 23, 0),
	gsSP2Triangles(27, 29, 30, 0, 26, 27, 30, 0),
	gsSP2Triangles(26, 30, 25, 0, 25, 30, 24, 0),
	gsSP2Triangles(30, 23, 24, 0, 27, 28, 29, 0),
	gsSPEndDisplayList(),
};


Gfx mat_dough_dough[] = {
	gsSPSetLights1(dough_dough_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, dough_dough_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 44),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, dough_dough_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_dough_dough[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx dough_dough_model_mesh_layer_1[] = {
	gsSPDisplayList(mat_dough_dough),
	gsSPDisplayList(dough_dough_model_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_dough_dough),
	gsSPEndDisplayList(),
};

Gfx dough_material_revert_render_settings[] = {
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

