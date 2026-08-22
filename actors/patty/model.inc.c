Lights1 patty_burger_patty_raw_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 patty_burger_patty_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 patty_pot_liquid_burnt_lights = gdSPDefLights1(
	0x7D, 0x7F, 0x67,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Texture patty_patty_raw_ci8[] = {
	#include "actors/patty/patty_raw.ci8.inc.c"
};

Texture patty_patty_raw_pal_rgba16[] = {
	#include "actors/patty/patty_raw.rgba16.pal"
};

Texture patty_patty_rgba16[] = {
	#include "actors/patty/patty.rgba16.inc.c"
};

Texture patty_pot_liquid_burnt_ci8[] = {
	#include "actors/patty/pot_liquid_burnt.ci8.inc.c"
};

Texture patty_pot_liquid_burnt_pal_rgba16[] = {
	#include "actors/patty/pot_liquid_burnt.rgba16.pal"
};

Vtx patty_patty_model_mesh_layer_1_vtx_0[78] = {
	{{{0, 49, -106}, 0, {-178, 1170}, {0x00, 0x5D, 0xAA, 0xFF}}},
	{{{-75, 49, -75}, 0, {-502, 496}, {0xC3, 0x5D, 0xC3, 0xFF}}},
	{{{0, 53, 0}, 0, {496, 496}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-106, 49, 0}, 0, {-178, -178}, {0xAA, 0x5D, 0x00, 0xFF}}},
	{{{-75, 49, 75}, 0, {496, -502}, {0xC3, 0x5D, 0x3D, 0xFF}}},
	{{{0, 49, 106}, 0, {1170, -178}, {0x00, 0x5D, 0x56, 0xFF}}},
	{{{75, 49, 75}, 0, {1494, 496}, {0x3D, 0x5D, 0x3D, 0xFF}}},
	{{{106, 49, 0}, 0, {1170, 1170}, {0x56, 0x5D, 0x00, 0xFF}}},
	{{{75, 49, -75}, 0, {496, 1494}, {0x3D, 0x5D, 0xC3, 0xFF}}},
	{{{0, 49, -106}, 0, {-178, 1170}, {0x00, 0x5D, 0xAA, 0xFF}}},
	{{{77, 3, -77}, 0, {496, 1518}, {0x3F, 0xA6, 0xC1, 0xFF}}},
	{{{109, 3, 0}, 0, {1186, 1186}, {0x59, 0xA6, 0x00, 0xFF}}},
	{{{0, 0, 0}, 0, {496, 496}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{77, 3, 76}, 0, {1518, 496}, {0x3F, 0xA6, 0x3F, 0xFF}}},
	{{{0, 3, 108}, 0, {1186, -194}, {0x00, 0xA6, 0x59, 0xFF}}},
	{{{-77, 3, 76}, 0, {496, -526}, {0xC1, 0xA6, 0x3F, 0xFF}}},
	{{{0, 3, -109}, 0, {-194, 1186}, {0x00, 0xA6, 0xA7, 0xFF}}},
	{{{77, 3, -77}, 0, {496, 1518}, {0x3F, 0xA6, 0xC1, 0xFF}}},
	{{{-77, 3, -77}, 0, {-526, 496}, {0xC1, 0xA6, 0xC1, 0xFF}}},
	{{{-109, 3, 0}, 0, {-194, -194}, {0xA7, 0xA6, 0x00, 0xFF}}},
	{{{-77, 3, -77}, 0, {-526, 496}, {0xC1, 0xA6, 0xC1, 0xFF}}},
	{{{-77, 3, 76}, 0, {496, -526}, {0xC1, 0xA6, 0x3F, 0xFF}}},
	{{{77, 3, -77}, 0, {1098, 1374}, {0x3F, 0xA6, 0xC1, 0xFF}}},
	{{{0, 25, -114}, 0, {492, 502}, {0x00, 0x04, 0x81, 0xFF}}},
	{{{81, 25, -81}, 0, {1269, 1277}, {0x5A, 0x04, 0xA6, 0xFF}}},
	{{{0, 3, -109}, 0, {358, 636}, {0x00, 0xA6, 0xA7, 0xFF}}},
	{{{-81, 25, -81}, 0, {-284, -274}, {0xA6, 0x04, 0xA6, 0xFF}}},
	{{{-77, 3, -77}, 0, {-381, -103}, {0xC1, 0xA6, 0xC1, 0xFF}}},
	{{{109, 3, 0}, 0, {358, 356}, {0x59, 0xA6, 0x00, 0xFF}}},
	{{{77, 3, -77}, 0, {-381, 1096}, {0x3F, 0xA6, 0xC1, 0xFF}}},
	{{{81, 25, -81}, 0, {-284, 1267}, {0x5A, 0x04, 0xA6, 0xFF}}},
	{{{114, 25, 0}, 0, {492, 490}, {0x7F, 0x04, 0x00, 0xFF}}},
	{{{77, 3, 76}, 0, {1097, -383}, {0x3F, 0xA6, 0x3F, 0xFF}}},
	{{{81, 25, 80}, 0, {1268, -286}, {0x5A, 0x04, 0x5A, 0xFF}}},
	{{{106, 49, 0}, 0, {642, 639}, {0x56, 0x5D, 0x00, 0xFF}}},
	{{{75, 49, 75}, 0, {1363, -83}, {0x3D, 0x5D, 0x3D, 0xFF}}},
	{{{0, 3, 108}, 0, {358, 636}, {0x00, 0xA6, 0x59, 0xFF}}},
	{{{77, 3, 76}, 0, {1098, 1374}, {0x3F, 0xA6, 0x3F, 0xFF}}},
	{{{81, 25, 80}, 0, {1269, 1277}, {0x5A, 0x04, 0x5A, 0xFF}}},
	{{{0, 25, 114}, 0, {492, 502}, {0x00, 0x04, 0x7F, 0xFF}}},
	{{{-77, 3, -77}, 0, {-381, 1096}, {0xC1, 0xA6, 0xC1, 0xFF}}},
	{{{-109, 3, 0}, 0, {358, 356}, {0xA7, 0xA6, 0x00, 0xFF}}},
	{{{-114, 25, 0}, 0, {492, 490}, {0x81, 0x04, 0x00, 0xFF}}},
	{{{-81, 25, -81}, 0, {-284, 1267}, {0xA6, 0x04, 0xA6, 0xFF}}},
	{{{-109, 3, 0}, 0, {358, 356}, {0xA7, 0xA6, 0x00, 0xFF}}},
	{{{-77, 3, 76}, 0, {1097, -383}, {0xC1, 0xA6, 0x3F, 0xFF}}},
	{{{-81, 25, 80}, 0, {1268, -286}, {0xA6, 0x04, 0x5A, 0xFF}}},
	{{{-114, 25, 0}, 0, {492, 490}, {0x81, 0x04, 0x00, 0xFF}}},
	{{{-77, 3, 76}, 0, {-381, -103}, {0xC1, 0xA6, 0x3F, 0xFF}}},
	{{{0, 3, 108}, 0, {358, 636}, {0x00, 0xA6, 0x59, 0xFF}}},
	{{{-81, 25, 80}, 0, {-284, -274}, {0xA6, 0x04, 0x5A, 0xFF}}},
	{{{81, 25, -81}, 0, {1269, 1277}, {0x5A, 0x04, 0xA6, 0xFF}}},
	{{{0, 25, -114}, 0, {492, 502}, {0x00, 0x04, 0x81, 0xFF}}},
	{{{0, 49, -106}, 0, {641, 352}, {0x00, 0x5D, 0xAA, 0xFF}}},
	{{{75, 49, -75}, 0, {1364, 1074}, {0x3D, 0x5D, 0xC3, 0xFF}}},
	{{{114, 25, 0}, 0, {492, 490}, {0x7F, 0x04, 0x00, 0xFF}}},
	{{{81, 25, -81}, 0, {-284, 1267}, {0x5A, 0x04, 0xA6, 0xFF}}},
	{{{75, 49, -75}, 0, {-80, 1362}, {0x3D, 0x5D, 0xC3, 0xFF}}},
	{{{106, 49, 0}, 0, {642, 639}, {0x56, 0x5D, 0x00, 0xFF}}},
	{{{81, 25, 80}, 0, {1269, 1277}, {0x5A, 0x04, 0x5A, 0xFF}}},
	{{{75, 49, 75}, 0, {1364, 1074}, {0x3D, 0x5D, 0x3D, 0xFF}}},
	{{{0, 49, 106}, 0, {641, 352}, {0x00, 0x5D, 0x56, 0xFF}}},
	{{{-81, 25, -81}, 0, {-284, -274}, {0xA6, 0x04, 0xA6, 0xFF}}},
	{{{-75, 49, -75}, 0, {-81, -369}, {0xC3, 0x5D, 0xC3, 0xFF}}},
	{{{0, 25, -114}, 0, {492, 502}, {0x00, 0x04, 0x81, 0xFF}}},
	{{{-75, 49, -75}, 0, {-81, -369}, {0xC3, 0x5D, 0xC3, 0xFF}}},
	{{{0, 49, -106}, 0, {641, 352}, {0x00, 0x5D, 0xAA, 0xFF}}},
	{{{-81, 25, -81}, 0, {-284, 1267}, {0xA6, 0x04, 0xA6, 0xFF}}},
	{{{-114, 25, 0}, 0, {492, 490}, {0x81, 0x04, 0x00, 0xFF}}},
	{{{-106, 49, 0}, 0, {642, 639}, {0xAA, 0x5D, 0x00, 0xFF}}},
	{{{-75, 49, -75}, 0, {-80, 1362}, {0xC3, 0x5D, 0xC3, 0xFF}}},
	{{{-81, 25, 80}, 0, {-284, -274}, {0xA6, 0x04, 0x5A, 0xFF}}},
	{{{0, 25, 114}, 0, {492, 502}, {0x00, 0x04, 0x7F, 0xFF}}},
	{{{0, 49, 106}, 0, {641, 352}, {0x00, 0x5D, 0x56, 0xFF}}},
	{{{-75, 49, 75}, 0, {-81, -369}, {0xC3, 0x5D, 0x3D, 0xFF}}},
	{{{-81, 25, 80}, 0, {1268, -286}, {0xA6, 0x04, 0x5A, 0xFF}}},
	{{{-75, 49, 75}, 0, {1363, -83}, {0xC3, 0x5D, 0x3D, 0xFF}}},
	{{{-106, 49, 0}, 0, {642, 639}, {0xAA, 0x5D, 0x00, 0xFF}}},
};

Gfx patty_patty_model_mesh_layer_1_tri_0[] = {
	gsSPVertex(patty_patty_model_mesh_layer_1_vtx_0 + 0, 64, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(3, 4, 2, 0, 4, 5, 2, 0),
	gsSP2Triangles(5, 6, 2, 0, 6, 7, 2, 0),
	gsSP2Triangles(7, 8, 2, 0, 8, 9, 2, 0),
	gsSP2Triangles(10, 11, 12, 0, 11, 13, 12, 0),
	gsSP2Triangles(13, 14, 12, 0, 14, 15, 12, 0),
	gsSP2Triangles(16, 17, 12, 0, 18, 16, 12, 0),
	gsSP2Triangles(19, 20, 12, 0, 21, 19, 12, 0),
	gsSP2Triangles(22, 23, 24, 0, 22, 25, 23, 0),
	gsSP2Triangles(25, 26, 23, 0, 25, 27, 26, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSP2Triangles(32, 28, 31, 0, 32, 31, 33, 0),
	gsSP2Triangles(33, 31, 34, 0, 33, 34, 35, 0),
	gsSP2Triangles(36, 37, 38, 0, 36, 38, 39, 0),
	gsSP2Triangles(40, 41, 42, 0, 40, 42, 43, 0),
	gsSP2Triangles(44, 45, 46, 0, 44, 46, 47, 0),
	gsSP2Triangles(48, 49, 39, 0, 48, 39, 50, 0),
	gsSP2Triangles(51, 52, 53, 0, 51, 53, 54, 0),
	gsSP2Triangles(55, 56, 57, 0, 55, 57, 58, 0),
	gsSP2Triangles(39, 59, 60, 0, 39, 60, 61, 0),
	gsSP1Triangle(23, 62, 63, 0),
	gsSPVertex(patty_patty_model_mesh_layer_1_vtx_0 + 64, 14, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(3, 5, 6, 0, 7, 8, 9, 0),
	gsSP2Triangles(7, 9, 10, 0, 4, 11, 12, 0),
	gsSP1Triangle(4, 12, 13, 0),
	gsSPEndDisplayList(),
};


Gfx mat_patty_burger_patty_raw[] = {
	gsSPSetLights1(patty_burger_patty_raw_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, patty_patty_raw_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 70),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, patty_patty_raw_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_patty_burger_patty_raw[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_patty_burger_patty[] = {
	gsSPSetGeometryMode(G_FRESNEL_ALPHA_EXT),
	gsSPSetLights1(patty_burger_patty_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, SHADE_ALPHA, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, SHADE_ALPHA, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPFresnel(0xffed, 0x0012),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, patty_patty_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_patty_burger_patty[] = {
	gsSPClearGeometryMode(G_FRESNEL_ALPHA_EXT),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_patty_pot_liquid_burnt[] = {
	gsSPSetLights1(patty_pot_liquid_burnt_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, patty_pot_liquid_burnt_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 10),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, patty_pot_liquid_burnt_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_patty_pot_liquid_burnt[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx patty_patty_model_mesh_layer_1[] = {
	gsSPDisplayList(mat_patty_burger_patty_raw),
	gsSPDisplayList(patty_patty_model_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_patty_burger_patty_raw),
	gsSPEndDisplayList(),
};

Gfx patty_patty_model_mesh_layer_1_mat_override_burger_patty_0[] = {
	gsSPDisplayList(mat_patty_burger_patty),
	gsSPDisplayList(patty_patty_model_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_patty_burger_patty),
	gsSPEndDisplayList(),
};

Gfx patty_patty_model_mesh_layer_1_mat_override_pot_liquid_burnt_1[] = {
	gsSPDisplayList(mat_patty_pot_liquid_burnt),
	gsSPDisplayList(patty_patty_model_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_patty_pot_liquid_burnt),
	gsSPEndDisplayList(),
};

Gfx patty_material_revert_render_settings[] = {
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

