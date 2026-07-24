Lights1 knife_knife_handle_lights = gdSPDefLights1(
	0x5D, 0x12, 0x6,
	0xBE, 0x2F, 0x16, 0x28, 0x28, 0x28);

Lights1 knife_knife_handle_tip_lights = gdSPDefLights1(
	0x4, 0x4, 0x4,
	0x10, 0x10, 0x10, 0x28, 0x28, 0x28);

Lights1 knife_knife_metal_lights = gdSPDefLights1(
	0x3A, 0x3A, 0x3A,
	0xBE, 0xBE, 0xBE, 0x28, 0x28, 0x28);

Vtx knife_knife_model_mesh_layer_1_vtx_0[10] = {
	{{{13, -8, -32}, 0, {368, 496}, {0x46, 0xBA, 0xB0, 0xFF}}},
	{{{-23, -12, 31}, 0, {368, 752}, {0xA8, 0xAB, 0x21, 0xFF}}},
	{{{-13, -8, -32}, 0, {368, 752}, {0xBE, 0xB9, 0xAE, 0xFF}}},
	{{{18, -12, 31}, 0, {368, 496}, {0x55, 0xA6, 0x1D, 0xFF}}},
	{{{13, 8, -32}, 0, {624, 496}, {0x46, 0x46, 0xB0, 0xFF}}},
	{{{18, 12, 31}, 0, {624, 496}, {0x55, 0x5A, 0x1D, 0xFF}}},
	{{{-13, 8, -32}, 0, {624, 752}, {0xBE, 0x47, 0xAE, 0xFF}}},
	{{{-23, 12, 31}, 0, {624, 752}, {0xA8, 0x55, 0x21, 0xFF}}},
	{{{-8, 0, 49}, 0, {496, 752}, {0xE0, 0x00, 0x7B, 0xFF}}},
	{{{11, 0, 49}, 0, {496, 496}, {0x34, 0x00, 0x74, 0xFF}}},
};

Gfx knife_knife_model_mesh_layer_1_tri_0[] = {
	gsSPVertex(knife_knife_model_mesh_layer_1_vtx_0 + 0, 10, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
	gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
	gsSP2Triangles(2, 7, 6, 0, 2, 1, 7, 0),
	gsSP2Triangles(1, 8, 7, 0, 3, 8, 1, 0),
	gsSP2Triangles(3, 9, 8, 0, 5, 9, 3, 0),
	gsSP2Triangles(7, 9, 5, 0, 7, 8, 9, 0),
	gsSPEndDisplayList(),
};

Vtx knife_knife_model_mesh_layer_1_vtx_1[8] = {
	{{{0, 0, 2}, 0, {496, 1008}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-22, 14, -39}, 0, {624, 752}, {0xA9, 0x50, 0xD1, 0xFF}}},
	{{{-22, -14, -39}, 0, {368, 752}, {0xA9, 0xB0, 0xD1, 0xFF}}},
	{{{22, 14, -39}, 0, {624, 496}, {0x57, 0x50, 0xD1, 0xFF}}},
	{{{22, -14, -39}, 0, {368, 496}, {0x57, 0xB0, 0xD1, 0xFF}}},
	{{{0, 0, 2}, 0, {496, 112}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-22, 14, -39}, 0, {880, 496}, {0xA9, 0x50, 0xD1, 0xFF}}},
	{{{-22, -14, -39}, 0, {112, 496}, {0xA9, 0xB0, 0xD1, 0xFF}}},
};

Gfx knife_knife_model_mesh_layer_1_tri_1[] = {
	gsSPVertex(knife_knife_model_mesh_layer_1_vtx_1 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
	gsSP2Triangles(2, 3, 4, 0, 4, 3, 5, 0),
	gsSP2Triangles(3, 6, 5, 0, 7, 4, 5, 0),
	gsSPEndDisplayList(),
};

Vtx knife_knife_model_mesh_layer_1_vtx_2[10] = {
	{{{18, -11, -36}, 0, {368, 240}, {0x42, 0xAE, 0x47, 0xFF}}},
	{{{18, 10, -36}, 0, {624, 240}, {0x42, 0x52, 0x47, 0xFF}}},
	{{{-36, 0, -36}, 0, {368, -16}, {0x90, 0x00, 0x3C, 0xFF}}},
	{{{18, -5, -191}, 0, {368, 496}, {0x1D, 0xBA, 0x9A, 0xFF}}},
	{{{-36, 0, -36}, 0, {112, 240}, {0x90, 0x00, 0x3C, 0xFF}}},
	{{{-17, 0, -136}, 0, {112, 496}, {0x84, 0x00, 0xE3, 0xFF}}},
	{{{18, 5, -191}, 0, {624, 496}, {0x1D, 0x46, 0x9A, 0xFF}}},
	{{{-17, 0, -136}, 0, {624, 752}, {0x84, 0x00, 0xE3, 0xFF}}},
	{{{-36, 0, -36}, 0, {880, 240}, {0x90, 0x00, 0x3C, 0xFF}}},
	{{{-17, 0, -136}, 0, {880, 496}, {0x84, 0x00, 0xE3, 0xFF}}},
};

Gfx knife_knife_model_mesh_layer_1_tri_2[] = {
	gsSPVertex(knife_knife_model_mesh_layer_1_vtx_2 + 0, 10, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSP2Triangles(3, 0, 4, 0, 5, 3, 4, 0),
	gsSP2Triangles(1, 3, 6, 0, 7, 6, 3, 0),
	gsSP2Triangles(8, 1, 6, 0, 9, 8, 6, 0),
	gsSPEndDisplayList(),
};


Gfx mat_knife_knife_handle[] = {
	gsSPSetLights1(knife_knife_handle_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_knife_knife_handle[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_knife_knife_handle_tip[] = {
	gsSPSetLights1(knife_knife_handle_tip_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_knife_knife_handle_tip[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_knife_knife_metal[] = {
	gsSPSetLights1(knife_knife_metal_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_knife_knife_metal[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx knife_knife_model_mesh_layer_1[] = {
	gsSPDisplayList(mat_knife_knife_handle),
	gsSPDisplayList(knife_knife_model_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_knife_knife_handle),
	gsSPDisplayList(mat_knife_knife_handle_tip),
	gsSPDisplayList(knife_knife_model_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_knife_knife_handle_tip),
	gsSPDisplayList(mat_knife_knife_metal),
	gsSPDisplayList(knife_knife_model_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_knife_knife_metal),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

