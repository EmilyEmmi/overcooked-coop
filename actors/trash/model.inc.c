Lights1 trash_trash_black_lights = gdSPDefLights1(
	0xA, 0xA, 0xA,
	0x20, 0x20, 0x20, 0x28, 0x28, 0x28);

Lights1 trash_trash_border_lights = gdSPDefLights1(
	0x4C, 0x41, 0x2C,
	0x9D, 0x89, 0x60, 0x28, 0x28, 0x28);

Lights1 trash_trash_bag_lights = gdSPDefLights1(
	0x14, 0x36, 0xE,
	0x33, 0x73, 0x27, 0x28, 0x28, 0x28);

Vtx trash_trash_model_mesh_layer_1_vtx_0[24] = {
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
	{{{35, 70, -65}, 0, {725, 419}, {0xF3, 0x65, 0x4C, 0xFF}}},
	{{{-35, 70, -65}, 0, {779, 419}, {0x0D, 0x65, 0x4C, 0xFF}}},
	{{{-65, 70, -35}, 0, {803, 395}, {0x4C, 0x65, 0x0D, 0xFF}}},
	{{{-65, 70, 35}, 0, {803, 341}, {0x4C, 0x65, 0xF3, 0xFF}}},
	{{{-35, 70, 65}, 0, {779, 317}, {0x0D, 0x65, 0xB4, 0xFF}}},
	{{{35, 70, 65}, 0, {725, 317}, {0xF3, 0x65, 0xB4, 0xFF}}},
	{{{65, 70, 35}, 0, {701, 341}, {0xB4, 0x65, 0xF3, 0xFF}}},
	{{{65, 70, -35}, 0, {701, 395}, {0xB4, 0x65, 0x0D, 0xFF}}},
};

Gfx trash_trash_model_mesh_layer_1_tri_0[] = {
	gsSPVertex(trash_trash_model_mesh_layer_1_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 17, 18, 0, 18, 19, 16, 0),
	gsSP2Triangles(19, 20, 16, 0, 20, 21, 16, 0),
	gsSP2Triangles(21, 22, 16, 0, 22, 23, 16, 0),
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

Vtx trash_trash_model_mesh_layer_1_vtx_2[24] = {
	{{{-82, 129, 82}, 0, {850, 270}, {0x53, 0x30, 0xAD, 0xFF}}},
	{{{82, 129, 82}, 0, {654, 270}, {0xAD, 0x30, 0xAD, 0xFF}}},
	{{{-35, 70, 65}, 0, {779, 317}, {0x0D, 0x65, 0xB4, 0xFF}}},
	{{{35, 70, 65}, 0, {725, 317}, {0xF3, 0x65, 0xB4, 0xFF}}},
	{{{65, 70, 35}, 0, {701, 341}, {0xB4, 0x65, 0xF3, 0xFF}}},
	{{{65, 70, -35}, 0, {701, 395}, {0xB4, 0x65, 0x0D, 0xFF}}},
	{{{82, 129, -82}, 0, {654, 466}, {0xAD, 0x30, 0x53, 0xFF}}},
	{{{35, 70, -65}, 0, {725, 419}, {0xF3, 0x65, 0x4C, 0xFF}}},
	{{{-35, 70, -65}, 0, {779, 419}, {0x0D, 0x65, 0x4C, 0xFF}}},
	{{{-82, 129, -82}, 0, {850, 466}, {0x53, 0x30, 0x53, 0xFF}}},
	{{{-65, 70, -35}, 0, {803, 395}, {0x4C, 0x65, 0x0D, 0xFF}}},
	{{{-65, 70, 35}, 0, {803, 341}, {0x4C, 0x65, 0xF3, 0xFF}}},
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
	gsSPVertex(trash_trash_model_mesh_layer_1_vtx_2 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(1, 4, 3, 0, 1, 5, 4, 0),
	gsSP2Triangles(1, 6, 5, 0, 7, 5, 6, 0),
	gsSP2Triangles(8, 7, 6, 0, 8, 6, 9, 0),
	gsSP2Triangles(10, 8, 9, 0, 9, 0, 10, 0),
	gsSP2Triangles(0, 11, 10, 0, 0, 2, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 14, 13, 15, 0),
	gsSP2Triangles(16, 14, 15, 0, 15, 17, 16, 0),
	gsSP2Triangles(16, 17, 18, 0, 19, 16, 18, 0),
	gsSP2Triangles(18, 20, 19, 0, 19, 20, 21, 0),
	gsSP2Triangles(22, 19, 21, 0, 21, 23, 22, 0),
	gsSP2Triangles(22, 23, 12, 0, 14, 22, 12, 0),
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

