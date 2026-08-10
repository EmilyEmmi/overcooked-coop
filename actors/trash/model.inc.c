Lights1 trash_trash_black_lights = gdSPDefLights1(
	0x0, 0x0, 0x0,
	0x20, 0x20, 0x20, 0x28, 0x28, 0x28);

Lights1 trash_trash_border_lights = gdSPDefLights1(
	0x4C, 0x41, 0x2C,
	0x9D, 0x89, 0x60, 0x28, 0x28, 0x28);

Lights1 trash_trash_bag_lights = gdSPDefLights1(
	0x14, 0x36, 0xE,
	0x33, 0x73, 0x27, 0x28, 0x28, 0x28);

Lights1 trash_trash_hole_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Texture trash_trash_hole_ia8[] = {
	#include "actors/trash/trash_hole.ia8.inc.c"
};

Vtx trash_trash_model_mesh_layer_1_vtx_0[16] = {
	{{{95, -2, 95}, 0, {368, 240}, {0x00, 0xD7, 0x78, 0xFF}}},
	{{{-128, 95, 128}, 0, {554, -16}, {0x00, 0xD7, 0x78, 0xFF}}},
	{{{-95, -2, 95}, 0, {368, -16}, {0x00, 0xD7, 0x78, 0xFF}}},
	{{{128, 95, 128}, 0, {554, 240}, {0x00, 0xD7, 0x78, 0xFF}}},
	{{{-95, -2, 95}, 0, {368, 1008}, {0x88, 0xD7, 0x00, 0xFF}}},
	{{{-128, 95, 128}, 0, {554, 1008}, {0x88, 0xD7, 0x00, 0xFF}}},
	{{{-128, 95, -128}, 0, {554, 752}, {0x88, 0xD7, 0x00, 0xFF}}},
	{{{-95, -2, -95}, 0, {368, 752}, {0x88, 0xD7, 0x00, 0xFF}}},
	{{{-95, -2, -95}, 0, {368, 752}, {0x00, 0xD7, 0x88, 0xFF}}},
	{{{-128, 95, -128}, 0, {554, 752}, {0x00, 0xD7, 0x88, 0xFF}}},
	{{{128, 95, -128}, 0, {554, 496}, {0x00, 0xD7, 0x88, 0xFF}}},
	{{{95, -2, -95}, 0, {368, 496}, {0x00, 0xD7, 0x88, 0xFF}}},
	{{{95, -2, -95}, 0, {368, 496}, {0x78, 0xD7, 0x00, 0xFF}}},
	{{{128, 95, 128}, 0, {554, 240}, {0x78, 0xD7, 0x00, 0xFF}}},
	{{{95, -2, 95}, 0, {368, 240}, {0x78, 0xD7, 0x00, 0xFF}}},
	{{{128, 95, -128}, 0, {554, 496}, {0x78, 0xD7, 0x00, 0xFF}}},
};

Gfx trash_trash_model_mesh_layer_1_tri_0[] = {
	gsSPVertex(trash_trash_model_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSPEndDisplayList(),
};

Vtx trash_trash_model_mesh_layer_1_vtx_1[24] = {
	{{{-128, 95, 128}, 0, {554, 1008}, {0x82, 0x10, 0x00, 0xFF}}},
	{{{-124, 129, 124}, 0, {624, 1008}, {0x82, 0x10, 0x00, 0xFF}}},
	{{{-124, 129, -124}, 0, {624, 752}, {0x82, 0x10, 0x00, 0xFF}}},
	{{{-128, 95, -128}, 0, {554, 752}, {0x82, 0x10, 0x00, 0xFF}}},
	{{{128, 95, 128}, 0, {554, 240}, {0x00, 0x10, 0x7E, 0xFF}}},
	{{{124, 129, 124}, 0, {624, 240}, {0x00, 0x10, 0x7E, 0xFF}}},
	{{{-124, 129, 124}, 0, {624, -16}, {0x00, 0x10, 0x7E, 0xFF}}},
	{{{-128, 95, 128}, 0, {554, -16}, {0x00, 0x10, 0x7E, 0xFF}}},
	{{{-128, 95, -128}, 0, {554, 752}, {0x00, 0x10, 0x82, 0xFF}}},
	{{{-124, 129, -124}, 0, {624, 752}, {0x00, 0x10, 0x82, 0xFF}}},
	{{{124, 129, -124}, 0, {624, 496}, {0x00, 0x10, 0x82, 0xFF}}},
	{{{128, 95, -128}, 0, {554, 496}, {0x00, 0x10, 0x82, 0xFF}}},
	{{{128, 95, -128}, 0, {554, 496}, {0x7E, 0x10, 0x00, 0xFF}}},
	{{{124, 129, -124}, 0, {624, 496}, {0x7E, 0x10, 0x00, 0xFF}}},
	{{{124, 129, 124}, 0, {624, 240}, {0x7E, 0x10, 0x00, 0xFF}}},
	{{{128, 95, 128}, 0, {554, 240}, {0x7E, 0x10, 0x00, 0xFF}}},
	{{{-82, 129, 82}, 0, {850, 270}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-82, 129, -82}, 0, {850, 466}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-124, 129, -124}, 0, {880, 496}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{124, 129, -124}, 0, {624, 496}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{82, 129, -82}, 0, {654, 466}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{124, 129, 124}, 0, {624, 240}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{82, 129, 82}, 0, {654, 270}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-124, 129, 124}, 0, {880, 240}, {0x00, 0x7F, 0x00, 0xFF}}},
};

Gfx trash_trash_model_mesh_layer_1_tri_1[] = {
	gsSPVertex(trash_trash_model_mesh_layer_1_vtx_1 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 17, 19, 18, 0),
	gsSP2Triangles(17, 20, 19, 0, 20, 21, 19, 0),
	gsSP2Triangles(20, 22, 21, 0, 22, 23, 21, 0),
	gsSP2Triangles(22, 16, 23, 0, 16, 18, 23, 0),
	gsSPEndDisplayList(),
};

Vtx trash_trash_model_mesh_layer_1_vtx_2[20] = {
	{{{-82, 129, -82}, 0, {850, 466}, {0x50, 0x3A, 0x50, 0xFF}}},
	{{{-82, 129, 82}, 0, {850, 270}, {0x50, 0x3A, 0xB0, 0xFF}}},
	{{{-55, 54, 55}, 0, {778, 342}, {0x3B, 0x5F, 0xC5, 0xFF}}},
	{{{55, 54, 55}, 0, {726, 342}, {0xC4, 0x5F, 0xC5, 0xFF}}},
	{{{82, 129, 82}, 0, {654, 270}, {0xB0, 0x3A, 0xB0, 0xFF}}},
	{{{55, 54, -55}, 0, {726, 394}, {0xC5, 0x5F, 0x3C, 0xFF}}},
	{{{82, 129, -82}, 0, {654, 466}, {0xB0, 0x3A, 0x50, 0xFF}}},
	{{{-55, 54, -55}, 0, {778, 394}, {0x3B, 0x5F, 0x3C, 0xFF}}},
	{{{-133, 80, 0}, 0, {-16, 1008}, {0xFD, 0x94, 0x43, 0xFF}}},
	{{{-148, 72, 148}, 0, {-16, 1008}, {0xBC, 0x53, 0x44, 0xFF}}},
	{{{-123, 114, 123}, 0, {-16, 1008}, {0x26, 0xDF, 0x8B, 0xFF}}},
	{{{0, 80, 133}, 0, {-16, 1008}, {0xAA, 0x11, 0x5C, 0xFF}}},
	{{{123, 114, 123}, 0, {-16, 1008}, {0xA5, 0xF0, 0xA8, 0xFF}}},
	{{{148, 72, 148}, 0, {-16, 1008}, {0x44, 0x53, 0x44, 0xFF}}},
	{{{133, 80, 0}, 0, {-16, 1008}, {0xAD, 0x46, 0xBE, 0xFF}}},
	{{{123, 114, -123}, 0, {-16, 1008}, {0x8C, 0xE1, 0x28, 0xFF}}},
	{{{148, 72, -148}, 0, {-16, 1008}, {0x44, 0x53, 0xBC, 0xFF}}},
	{{{0, 80, -133}, 0, {-16, 1008}, {0xE1, 0x9B, 0xBA, 0xFF}}},
	{{{-123, 114, -123}, 0, {-16, 1008}, {0x48, 0xBA, 0x4D, 0xFF}}},
	{{{-148, 72, -148}, 0, {-16, 1008}, {0xBC, 0x53, 0xBC, 0xFF}}},
};

Gfx trash_trash_model_mesh_layer_1_tri_2[] = {
	gsSPVertex(trash_trash_model_mesh_layer_1_vtx_2 + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(1, 4, 3, 0, 4, 5, 3, 0),
	gsSP2Triangles(4, 6, 5, 0, 7, 5, 6, 0),
	gsSP2Triangles(7, 6, 0, 0, 0, 2, 7, 0),
	gsSP2Triangles(5, 7, 2, 0, 5, 2, 3, 0),
	gsSP2Triangles(8, 9, 10, 0, 10, 9, 11, 0),
	gsSP2Triangles(12, 10, 11, 0, 11, 13, 12, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 12, 14, 0),
	gsSP2Triangles(14, 16, 15, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 15, 17, 0, 17, 19, 18, 0),
	gsSP2Triangles(18, 19, 8, 0, 10, 18, 8, 0),
	gsSPEndDisplayList(),
};

Vtx trash_trash_model_mesh_layer_5_vtx_0[12] = {
	{{{-79, 128, 79}, 0, {37, 37}, {0x3C, 0x5E, 0xC4, 0xFF}}},
	{{{79, 128, 79}, 0, {443, 37}, {0xC4, 0x5E, 0xC4, 0xFF}}},
	{{{55, 98, 56}, 0, {426, 334}, {0xC4, 0x5E, 0xC4, 0xFF}}},
	{{{55, 98, -55}, 0, {425, 334}, {0xC4, 0x5F, 0x3C, 0xFF}}},
	{{{79, 128, -79}, 0, {443, 37}, {0xC4, 0x5F, 0x3C, 0xFF}}},
	{{{-56, 98, -55}, 0, {54, 334}, {0x3C, 0x5F, 0x3C, 0xFF}}},
	{{{-79, 128, -79}, 0, {37, 37}, {0x3C, 0x5F, 0x3C, 0xFF}}},
	{{{-56, 98, 56}, 0, {54, 333}, {0x3C, 0x5E, 0xC4, 0xFF}}},
	{{{47, 88, 47}, 0, {419, 442}, {0xD4, 0x6F, 0xD4, 0xFF}}},
	{{{47, 87, -47}, 0, {419, 443}, {0xD4, 0x6F, 0x2C, 0xFF}}},
	{{{-47, 88, -47}, 0, {60, 442}, {0x2C, 0x6F, 0x2C, 0xFF}}},
	{{{-47, 88, 47}, 0, {60, 441}, {0x2C, 0x6F, 0xD4, 0xFF}}},
};

Gfx trash_trash_model_mesh_layer_5_tri_0[] = {
	gsSPVertex(trash_trash_model_mesh_layer_5_vtx_0 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(1, 4, 3, 0, 5, 3, 4, 0),
	gsSP2Triangles(5, 4, 6, 0, 6, 7, 5, 0),
	gsSP2Triangles(6, 0, 7, 0, 0, 2, 7, 0),
	gsSP2Triangles(7, 2, 8, 0, 2, 9, 8, 0),
	gsSP2Triangles(2, 3, 9, 0, 10, 9, 3, 0),
	gsSP2Triangles(10, 3, 5, 0, 5, 11, 10, 0),
	gsSP2Triangles(5, 7, 11, 0, 7, 8, 11, 0),
	gsSP2Triangles(9, 11, 8, 0, 9, 10, 11, 0),
	gsSPEndDisplayList(),
};


Gfx mat_trash_trash_black[] = {
	gsSPSetLights1(trash_trash_black_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_trash_trash_black[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_trash_trash_border[] = {
	gsSPSetLights1(trash_trash_border_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_trash_trash_border[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_trash_trash_bag[] = {
	gsSPSetLights1(trash_trash_bag_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_trash_trash_bag[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_trash_trash_hole[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(trash_trash_hole_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_AVERAGE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b_LOAD_BLOCK, 1, trash_trash_hole_ia8),
	gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 127, 1024),
	gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 4, 0, G_TX_CLAMP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 60),
	gsSPEndDisplayList(),
};

Gfx mat_revert_trash_trash_hole[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPEndDisplayList(),
};

Gfx trash_trash_model_mesh_layer_1[] = {
	gsSPDisplayList(mat_trash_trash_black),
	gsSPDisplayList(trash_trash_model_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_trash_trash_black),
	gsSPDisplayList(mat_trash_trash_border),
	gsSPDisplayList(trash_trash_model_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_trash_trash_border),
	gsSPDisplayList(mat_trash_trash_bag),
	gsSPDisplayList(trash_trash_model_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_trash_trash_bag),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

Gfx trash_trash_model_mesh_layer_5[] = {
	gsSPDisplayList(mat_trash_trash_hole),
	gsSPDisplayList(trash_trash_model_mesh_layer_5_tri_0),
	gsSPDisplayList(mat_revert_trash_trash_hole),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

