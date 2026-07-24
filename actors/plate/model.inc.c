Lights1 plate_pot_liquid_onion_lights = gdSPDefLights1(
	0x67, 0x32, 0x15,
	0xD0, 0x6B, 0x35, 0x28, 0x28, 0x28);

Lights1 plate_pot_liquid_mushroom_lights = gdSPDefLights1(
	0x56, 0x4D, 0x3E,
	0xB0, 0xA0, 0x82, 0x28, 0x28, 0x28);

Lights1 plate_pot_liquid_tomato_lights = gdSPDefLights1(
	0x53, 0x6, 0x5,
	0xAB, 0x18, 0x13, 0x28, 0x28, 0x28);

Lights1 plate_pot_liquid_burnt_lights = gdSPDefLights1(
	0x7D, 0x7F, 0x67,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 plate_plate_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 plate_plate_bottom_lights = gdSPDefLights1(
	0x4F, 0x52, 0x55,
	0xAE, 0xAE, 0xAE, 0x28, 0x28, 0x28);

Lights1 plate_plate_dirty_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Texture plate_pot_liquid_burnt_ci8[] = {
	#include "actors/plate/pot_liquid_burnt.ci8.inc.c"
};

Texture plate_pot_liquid_burnt_pal_rgba16[] = {
	#include "actors/plate/pot_liquid_burnt.rgba16.pal"
};

Texture plate_blank_i8[] = {
	#include "actors/plate/blank.i8.inc.c"
};

Texture plate_plate_dirty_ci8[] = {
	#include "actors/plate/plate_dirty.ci8.inc.c"
};

Texture plate_plate_dirty_pal_rgba16[] = {
	#include "actors/plate/plate_dirty.rgba16.pal"
};

Vtx plate_plate_soup_onion_so_plate_soup_onion_mdl_mesh_layer_1_vtx_0[11] = {
	{{{4, 28, 7}, 0, {496, 496}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-119, 19, 87}, 0, {-122, 968}, {0xFA, 0x7F, 0x04, 0xFF}}},
	{{{-46, 19, 140}, 0, {260, 1260}, {0xFE, 0x7F, 0x07, 0xFF}}},
	{{{-147, 19, 0}, 0, {-268, 496}, {0xF9, 0x7F, 0x00, 0xFF}}},
	{{{-119, 19, -87}, 0, {-122, 24}, {0xFA, 0x7F, 0xFC, 0xFF}}},
	{{{-46, 19, -140}, 0, {260, -268}, {0xFE, 0x7F, 0xF9, 0xFF}}},
	{{{45, 19, -140}, 0, {732, -268}, {0x02, 0x7F, 0xF9, 0xFF}}},
	{{{119, 19, -87}, 0, {1114, 24}, {0x06, 0x7F, 0xFC, 0xFF}}},
	{{{147, 19, 0}, 0, {1260, 496}, {0x08, 0x7F, 0x00, 0xFF}}},
	{{{119, 19, 87}, 0, {1114, 968}, {0x06, 0x7F, 0x05, 0xFF}}},
	{{{45, 19, 140}, 0, {732, 1260}, {0x02, 0x7F, 0x07, 0xFF}}},
};

Gfx plate_plate_soup_onion_so_plate_soup_onion_mdl_mesh_layer_1_tri_0[] = {
	gsSPVertex(plate_plate_soup_onion_so_plate_soup_onion_mdl_mesh_layer_1_vtx_0 + 0, 11, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
	gsSP2Triangles(0, 6, 5, 0, 0, 7, 6, 0),
	gsSP2Triangles(0, 8, 7, 0, 0, 9, 8, 0),
	gsSP2Triangles(0, 10, 9, 0, 0, 2, 10, 0),
	gsSPEndDisplayList(),
};

Vtx plate_plate_soup_mushroom_so_plate_soup_mushroom_mdl_mesh_layer_1_vtx_0[11] = {
	{{{4, 28, 7}, 0, {496, 496}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-119, 19, 87}, 0, {-122, 968}, {0xFA, 0x7F, 0x04, 0xFF}}},
	{{{-46, 19, 140}, 0, {260, 1260}, {0xFE, 0x7F, 0x07, 0xFF}}},
	{{{-147, 19, 0}, 0, {-268, 496}, {0xF9, 0x7F, 0x00, 0xFF}}},
	{{{-119, 19, -87}, 0, {-122, 24}, {0xFA, 0x7F, 0xFC, 0xFF}}},
	{{{-46, 19, -140}, 0, {260, -268}, {0xFE, 0x7F, 0xF9, 0xFF}}},
	{{{45, 19, -140}, 0, {732, -268}, {0x02, 0x7F, 0xF9, 0xFF}}},
	{{{119, 19, -87}, 0, {1114, 24}, {0x06, 0x7F, 0xFC, 0xFF}}},
	{{{147, 19, 0}, 0, {1260, 496}, {0x08, 0x7F, 0x00, 0xFF}}},
	{{{119, 19, 87}, 0, {1114, 968}, {0x06, 0x7F, 0x05, 0xFF}}},
	{{{45, 19, 140}, 0, {732, 1260}, {0x02, 0x7F, 0x07, 0xFF}}},
};

Gfx plate_plate_soup_mushroom_so_plate_soup_mushroom_mdl_mesh_layer_1_tri_0[] = {
	gsSPVertex(plate_plate_soup_mushroom_so_plate_soup_mushroom_mdl_mesh_layer_1_vtx_0 + 0, 11, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
	gsSP2Triangles(0, 6, 5, 0, 0, 7, 6, 0),
	gsSP2Triangles(0, 8, 7, 0, 0, 9, 8, 0),
	gsSP2Triangles(0, 10, 9, 0, 0, 2, 10, 0),
	gsSPEndDisplayList(),
};

Vtx plate_plate_soup_tomato_so_plate_soup_tomato_mdl_mesh_layer_1_vtx_0[11] = {
	{{{4, 28, 7}, 0, {496, 496}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-119, 19, 87}, 0, {-122, 968}, {0xFA, 0x7F, 0x04, 0xFF}}},
	{{{-46, 19, 140}, 0, {260, 1260}, {0xFE, 0x7F, 0x07, 0xFF}}},
	{{{-147, 19, 0}, 0, {-268, 496}, {0xF9, 0x7F, 0x00, 0xFF}}},
	{{{-119, 19, -87}, 0, {-122, 24}, {0xFA, 0x7F, 0xFC, 0xFF}}},
	{{{-46, 19, -140}, 0, {260, -268}, {0xFE, 0x7F, 0xF9, 0xFF}}},
	{{{45, 19, -140}, 0, {732, -268}, {0x02, 0x7F, 0xF9, 0xFF}}},
	{{{119, 19, -87}, 0, {1114, 24}, {0x06, 0x7F, 0xFC, 0xFF}}},
	{{{147, 19, 0}, 0, {1260, 496}, {0x08, 0x7F, 0x00, 0xFF}}},
	{{{119, 19, 87}, 0, {1114, 968}, {0x06, 0x7F, 0x05, 0xFF}}},
	{{{45, 19, 140}, 0, {732, 1260}, {0x02, 0x7F, 0x07, 0xFF}}},
};

Gfx plate_plate_soup_tomato_so_plate_soup_tomato_mdl_mesh_layer_1_tri_0[] = {
	gsSPVertex(plate_plate_soup_tomato_so_plate_soup_tomato_mdl_mesh_layer_1_vtx_0 + 0, 11, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
	gsSP2Triangles(0, 6, 5, 0, 0, 7, 6, 0),
	gsSP2Triangles(0, 8, 7, 0, 0, 9, 8, 0),
	gsSP2Triangles(0, 10, 9, 0, 0, 2, 10, 0),
	gsSPEndDisplayList(),
};

Vtx plate_plate_soup_burnt_so_plate_soup_burnt_mdl_mesh_layer_1_vtx_0[11] = {
	{{{4, 28, 7}, 0, {496, 496}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-119, 19, 87}, 0, {-154, 992}, {0xFA, 0x7F, 0x04, 0xFF}}},
	{{{-46, 19, 140}, 0, {248, 1299}, {0xFE, 0x7F, 0x07, 0xFF}}},
	{{{-147, 19, 0}, 0, {-307, 496}, {0xF9, 0x7F, 0x00, 0xFF}}},
	{{{-119, 19, -87}, 0, {-154, 0}, {0xFA, 0x7F, 0xFC, 0xFF}}},
	{{{-46, 19, -140}, 0, {248, -307}, {0xFE, 0x7F, 0xF9, 0xFF}}},
	{{{45, 19, -140}, 0, {744, -307}, {0x02, 0x7F, 0xF9, 0xFF}}},
	{{{119, 19, -87}, 0, {1146, 0}, {0x06, 0x7F, 0xFC, 0xFF}}},
	{{{147, 19, 0}, 0, {1299, 496}, {0x08, 0x7F, 0x00, 0xFF}}},
	{{{119, 19, 87}, 0, {1146, 992}, {0x06, 0x7F, 0x05, 0xFF}}},
	{{{45, 19, 140}, 0, {744, 1299}, {0x02, 0x7F, 0x07, 0xFF}}},
};

Gfx plate_plate_soup_burnt_so_plate_soup_burnt_mdl_mesh_layer_1_tri_0[] = {
	gsSPVertex(plate_plate_soup_burnt_so_plate_soup_burnt_mdl_mesh_layer_1_vtx_0 + 0, 11, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
	gsSP2Triangles(0, 6, 5, 0, 0, 7, 6, 0),
	gsSP2Triangles(0, 8, 7, 0, 0, 9, 8, 0),
	gsSP2Triangles(0, 10, 9, 0, 0, 2, 10, 0),
	gsSPEndDisplayList(),
};

Vtx plate_plate_dl_mesh_layer_1_vtx_0[50] = {
	{{{-113, 8, -82}, 0, {151, 224}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{43, 8, -133}, 0, {625, 71}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-43, 8, -133}, 0, {363, 71}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{113, 8, -82}, 0, {837, 224}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-139, 8, 0}, 0, {70, 472}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{139, 8, 0}, 0, {918, 472}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-113, 8, 82}, 0, {151, 719}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{113, 8, 82}, 0, {837, 719}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-43, 8, 133}, 0, {363, 872}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{43, 8, 133}, 0, {625, 872}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-139, 8, 0}, 0, {70, 472}, {0x59, 0x5B, 0x00, 0xFF}}},
	{{{-155, 24, 0}, 0, {-3, 472}, {0x59, 0x5B, 0x00, 0xFF}}},
	{{{-126, 24, 91}, 0, {92, 762}, {0x48, 0x5B, 0xCC, 0xFF}}},
	{{{-113, 8, -82}, 0, {151, 224}, {0x48, 0x5B, 0x34, 0xFF}}},
	{{{-126, 24, -91}, 0, {92, 181}, {0x48, 0x5B, 0x34, 0xFF}}},
	{{{-43, 8, -133}, 0, {363, 71}, {0x1C, 0x5B, 0x55, 0xFF}}},
	{{{-48, 24, -148}, 0, {340, 2}, {0x1C, 0x5B, 0x55, 0xFF}}},
	{{{43, 8, -133}, 0, {625, 71}, {0xE4, 0x5B, 0x55, 0xFF}}},
	{{{48, 24, -148}, 0, {647, 2}, {0xE4, 0x5B, 0x55, 0xFF}}},
	{{{113, 8, -82}, 0, {837, 224}, {0xB8, 0x5B, 0x34, 0xFF}}},
	{{{126, 24, -91}, 0, {896, 181}, {0xB8, 0x5B, 0x34, 0xFF}}},
	{{{139, 8, 0}, 0, {918, 472}, {0xA7, 0x5B, 0x00, 0xFF}}},
	{{{155, 24, 0}, 0, {991, 472}, {0xA7, 0x5B, 0x00, 0xFF}}},
	{{{113, 8, 82}, 0, {837, 719}, {0xB8, 0x5B, 0xCC, 0xFF}}},
	{{{126, 24, 91}, 0, {896, 762}, {0xB8, 0x5B, 0xCC, 0xFF}}},
	{{{43, 8, 133}, 0, {625, 872}, {0xE4, 0x5B, 0xAB, 0xFF}}},
	{{{48, 24, 148}, 0, {647, 941}, {0xE4, 0x5B, 0xAB, 0xFF}}},
	{{{-43, 8, 133}, 0, {363, 872}, {0x1C, 0x5B, 0xAB, 0xFF}}},
	{{{-48, 24, 148}, 0, {340, 941}, {0x1C, 0x5B, 0xAB, 0xFF}}},
	{{{-113, 8, 82}, 0, {151, 719}, {0x48, 0x5B, 0xCC, 0xFF}}},
	{{{-155, 24, 0}, 0, {5, -5}, {0x32, 0x75, 0x00, 0xFF}}},
	{{{-144, 34, -105}, 0, {5, -5}, {0x28, 0x75, 0x1D, 0xFF}}},
	{{{-178, 34, 0}, 0, {5, -5}, {0x32, 0x75, 0x00, 0xFF}}},
	{{{-126, 24, -91}, 0, {5, -5}, {0x28, 0x75, 0x1D, 0xFF}}},
	{{{-55, 34, -169}, 0, {5, -5}, {0x0F, 0x75, 0x30, 0xFF}}},
	{{{-48, 24, -148}, 0, {5, -5}, {0x0F, 0x75, 0x30, 0xFF}}},
	{{{55, 34, -169}, 0, {5, -5}, {0xF1, 0x75, 0x30, 0xFF}}},
	{{{48, 24, -148}, 0, {5, -5}, {0xF1, 0x75, 0x30, 0xFF}}},
	{{{144, 34, -105}, 0, {5, -5}, {0xD8, 0x75, 0x1D, 0xFF}}},
	{{{126, 24, -91}, 0, {5, -5}, {0xD8, 0x75, 0x1D, 0xFF}}},
	{{{178, 34, 0}, 0, {5, -5}, {0xCE, 0x75, 0x00, 0xFF}}},
	{{{155, 24, 0}, 0, {5, -5}, {0xCE, 0x75, 0x00, 0xFF}}},
	{{{144, 34, 105}, 0, {5, -5}, {0xD8, 0x75, 0xE3, 0xFF}}},
	{{{126, 24, 91}, 0, {5, -5}, {0xD8, 0x75, 0xE3, 0xFF}}},
	{{{55, 34, 169}, 0, {5, -5}, {0xF1, 0x75, 0xD0, 0xFF}}},
	{{{48, 24, 148}, 0, {5, -5}, {0xF1, 0x75, 0xD0, 0xFF}}},
	{{{-55, 34, 169}, 0, {5, -5}, {0x0F, 0x75, 0xD0, 0xFF}}},
	{{{-48, 24, 148}, 0, {5, -5}, {0x0F, 0x75, 0xD0, 0xFF}}},
	{{{-144, 34, 105}, 0, {5, -5}, {0x28, 0x75, 0xE3, 0xFF}}},
	{{{-126, 24, 91}, 0, {5, -5}, {0x28, 0x75, 0xE3, 0xFF}}},
};

Gfx plate_plate_dl_mesh_layer_1_tri_0[] = {
	gsSPVertex(plate_plate_dl_mesh_layer_1_vtx_0 + 0, 50, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
	gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
	gsSP2Triangles(8, 7, 6, 0, 8, 9, 7, 0),
	gsSP2Triangles(10, 11, 12, 0, 13, 11, 10, 0),
	gsSP2Triangles(13, 14, 11, 0, 15, 14, 13, 0),
	gsSP2Triangles(15, 16, 14, 0, 17, 16, 15, 0),
	gsSP2Triangles(17, 18, 16, 0, 19, 18, 17, 0),
	gsSP2Triangles(19, 20, 18, 0, 21, 20, 19, 0),
	gsSP2Triangles(21, 22, 20, 0, 23, 22, 21, 0),
	gsSP2Triangles(23, 24, 22, 0, 25, 24, 23, 0),
	gsSP2Triangles(25, 26, 24, 0, 27, 26, 25, 0),
	gsSP2Triangles(27, 28, 26, 0, 29, 28, 27, 0),
	gsSP2Triangles(29, 12, 28, 0, 10, 12, 29, 0),
	gsSP2Triangles(30, 31, 32, 0, 30, 33, 31, 0),
	gsSP2Triangles(33, 34, 31, 0, 33, 35, 34, 0),
	gsSP2Triangles(35, 36, 34, 0, 35, 37, 36, 0),
	gsSP2Triangles(37, 38, 36, 0, 37, 39, 38, 0),
	gsSP2Triangles(39, 40, 38, 0, 39, 41, 40, 0),
	gsSP2Triangles(41, 42, 40, 0, 41, 43, 42, 0),
	gsSP2Triangles(43, 44, 42, 0, 43, 45, 44, 0),
	gsSP2Triangles(45, 46, 44, 0, 45, 47, 46, 0),
	gsSP2Triangles(47, 48, 46, 0, 47, 49, 48, 0),
	gsSP2Triangles(49, 32, 48, 0, 49, 30, 32, 0),
	gsSPEndDisplayList(),
};

Vtx plate_plate_dl_mesh_layer_1_vtx_1[50] = {
	{{{-113, 8, -82}, 0, {151, 224}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-43, 8, -133}, 0, {363, 71}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{43, 8, -133}, 0, {625, 71}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{113, 8, -82}, 0, {837, 224}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-139, 8, 0}, 0, {70, 472}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{139, 8, 0}, 0, {918, 472}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-113, 8, 82}, 0, {151, 719}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{113, 8, 82}, 0, {837, 719}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-43, 8, 133}, 0, {363, 872}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{43, 8, 133}, 0, {625, 872}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-139, 8, 0}, 0, {70, 472}, {0xA7, 0xA5, 0x00, 0xFF}}},
	{{{-113, 8, 82}, 0, {151, 719}, {0xB8, 0xA5, 0x34, 0xFF}}},
	{{{-126, 24, 91}, 0, {92, 762}, {0xB8, 0xA5, 0x34, 0xFF}}},
	{{{-48, 24, 148}, 0, {340, 941}, {0xE4, 0xA5, 0x55, 0xFF}}},
	{{{-43, 8, 133}, 0, {363, 872}, {0xE4, 0xA5, 0x55, 0xFF}}},
	{{{48, 24, 148}, 0, {647, 941}, {0x1C, 0xA5, 0x55, 0xFF}}},
	{{{43, 8, 133}, 0, {625, 872}, {0x1C, 0xA5, 0x55, 0xFF}}},
	{{{126, 24, 91}, 0, {896, 762}, {0x48, 0xA5, 0x34, 0xFF}}},
	{{{113, 8, 82}, 0, {837, 719}, {0x48, 0xA5, 0x34, 0xFF}}},
	{{{155, 24, 0}, 0, {991, 472}, {0x59, 0xA5, 0x00, 0xFF}}},
	{{{139, 8, 0}, 0, {918, 472}, {0x59, 0xA5, 0x00, 0xFF}}},
	{{{126, 24, -91}, 0, {896, 181}, {0x48, 0xA5, 0xCC, 0xFF}}},
	{{{113, 8, -82}, 0, {837, 224}, {0x48, 0xA5, 0xCC, 0xFF}}},
	{{{48, 24, -148}, 0, {647, 2}, {0x1C, 0xA5, 0xAB, 0xFF}}},
	{{{43, 8, -133}, 0, {625, 71}, {0x1C, 0xA5, 0xAB, 0xFF}}},
	{{{-48, 24, -148}, 0, {340, 2}, {0xE4, 0xA5, 0xAB, 0xFF}}},
	{{{-43, 8, -133}, 0, {363, 71}, {0xE4, 0xA5, 0xAB, 0xFF}}},
	{{{-126, 24, -91}, 0, {92, 181}, {0xB8, 0xA5, 0xCC, 0xFF}}},
	{{{-113, 8, -82}, 0, {151, 224}, {0xB8, 0xA5, 0xCC, 0xFF}}},
	{{{-155, 24, 0}, 0, {-3, 472}, {0xA7, 0xA5, 0x00, 0xFF}}},
	{{{-155, 24, 0}, 0, {-3, 472}, {0xCE, 0x8B, 0x00, 0xFF}}},
	{{{-144, 34, 105}, 0, {56, 788}, {0xD8, 0x8B, 0x1D, 0xFF}}},
	{{{-178, 34, 0}, 0, {-48, 472}, {0xCE, 0x8B, 0x00, 0xFF}}},
	{{{-126, 24, 91}, 0, {92, 762}, {0xD8, 0x8B, 0x1D, 0xFF}}},
	{{{-55, 34, 169}, 0, {327, 984}, {0xF1, 0x8B, 0x30, 0xFF}}},
	{{{-48, 24, 148}, 0, {340, 941}, {0xF1, 0x8B, 0x30, 0xFF}}},
	{{{55, 34, 169}, 0, {661, 984}, {0x0F, 0x8B, 0x30, 0xFF}}},
	{{{48, 24, 148}, 0, {647, 941}, {0x0F, 0x8B, 0x30, 0xFF}}},
	{{{144, 34, 105}, 0, {932, 788}, {0x28, 0x8B, 0x1D, 0xFF}}},
	{{{126, 24, 91}, 0, {896, 762}, {0x28, 0x8B, 0x1D, 0xFF}}},
	{{{178, 34, 0}, 0, {1036, 472}, {0x32, 0x8B, 0x00, 0xFF}}},
	{{{155, 24, 0}, 0, {991, 472}, {0x32, 0x8B, 0x00, 0xFF}}},
	{{{144, 34, -105}, 0, {932, 155}, {0x28, 0x8B, 0xE3, 0xFF}}},
	{{{126, 24, -91}, 0, {896, 181}, {0x28, 0x8B, 0xE3, 0xFF}}},
	{{{55, 34, -169}, 0, {661, -41}, {0x0F, 0x8B, 0xD0, 0xFF}}},
	{{{48, 24, -148}, 0, {647, 2}, {0x0F, 0x8B, 0xD0, 0xFF}}},
	{{{-55, 34, -169}, 0, {327, -41}, {0xF1, 0x8B, 0xD0, 0xFF}}},
	{{{-48, 24, -148}, 0, {340, 2}, {0xF1, 0x8B, 0xD0, 0xFF}}},
	{{{-144, 34, -105}, 0, {56, 155}, {0xD8, 0x8B, 0xE3, 0xFF}}},
	{{{-126, 24, -91}, 0, {92, 181}, {0xD8, 0x8B, 0xE3, 0xFF}}},
};

Gfx plate_plate_dl_mesh_layer_1_tri_1[] = {
	gsSPVertex(plate_plate_dl_mesh_layer_1_vtx_1 + 0, 50, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 0, 3, 0, 4, 3, 5, 0),
	gsSP2Triangles(6, 4, 5, 0, 6, 5, 7, 0),
	gsSP2Triangles(8, 6, 7, 0, 8, 7, 9, 0),
	gsSP2Triangles(10, 11, 12, 0, 11, 13, 12, 0),
	gsSP2Triangles(11, 14, 13, 0, 14, 15, 13, 0),
	gsSP2Triangles(14, 16, 15, 0, 16, 17, 15, 0),
	gsSP2Triangles(16, 18, 17, 0, 18, 19, 17, 0),
	gsSP2Triangles(18, 20, 19, 0, 20, 21, 19, 0),
	gsSP2Triangles(20, 22, 21, 0, 22, 23, 21, 0),
	gsSP2Triangles(22, 24, 23, 0, 24, 25, 23, 0),
	gsSP2Triangles(24, 26, 25, 0, 26, 27, 25, 0),
	gsSP2Triangles(26, 28, 27, 0, 28, 29, 27, 0),
	gsSP2Triangles(28, 10, 29, 0, 10, 12, 29, 0),
	gsSP2Triangles(30, 31, 32, 0, 30, 33, 31, 0),
	gsSP2Triangles(33, 34, 31, 0, 33, 35, 34, 0),
	gsSP2Triangles(35, 36, 34, 0, 35, 37, 36, 0),
	gsSP2Triangles(37, 38, 36, 0, 37, 39, 38, 0),
	gsSP2Triangles(39, 40, 38, 0, 39, 41, 40, 0),
	gsSP2Triangles(41, 42, 40, 0, 41, 43, 42, 0),
	gsSP2Triangles(43, 44, 42, 0, 43, 45, 44, 0),
	gsSP2Triangles(45, 46, 44, 0, 45, 47, 46, 0),
	gsSP2Triangles(47, 48, 46, 0, 47, 49, 48, 0),
	gsSP2Triangles(49, 32, 48, 0, 49, 30, 32, 0),
	gsSPEndDisplayList(),
};


Gfx mat_plate_pot_liquid_onion[] = {
	gsSPSetLights1(plate_pot_liquid_onion_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_plate_pot_liquid_onion[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_plate_pot_liquid_mushroom[] = {
	gsSPSetLights1(plate_pot_liquid_mushroom_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_plate_pot_liquid_mushroom[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_plate_pot_liquid_tomato[] = {
	gsSPSetLights1(plate_pot_liquid_tomato_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_plate_pot_liquid_tomato[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_plate_pot_liquid_burnt[] = {
	gsSPSetLights1(plate_pot_liquid_burnt_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, plate_pot_liquid_burnt_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 10),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, plate_pot_liquid_burnt_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_plate_pot_liquid_burnt[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_plate_plate[] = {
	gsSPSetLights1(plate_plate_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 1, plate_blank_i8),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_plate_plate[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_plate_plate_bottom[] = {
	gsSPSetLights1(plate_plate_bottom_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_plate_plate_bottom[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_plate_plate_dirty[] = {
	gsSPSetLights1(plate_plate_dirty_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, plate_plate_dirty_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 112),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, plate_plate_dirty_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_plate_plate_dirty[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx plate_plate_soup_onion_so_plate_soup_onion_mdl_mesh_layer_1[] = {
	gsSPDisplayList(mat_plate_pot_liquid_onion),
	gsSPDisplayList(plate_plate_soup_onion_so_plate_soup_onion_mdl_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_plate_pot_liquid_onion),
	gsSPEndDisplayList(),
};

Gfx plate_plate_soup_mushroom_so_plate_soup_mushroom_mdl_mesh_layer_1[] = {
	gsSPDisplayList(mat_plate_pot_liquid_mushroom),
	gsSPDisplayList(plate_plate_soup_mushroom_so_plate_soup_mushroom_mdl_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_plate_pot_liquid_mushroom),
	gsSPEndDisplayList(),
};

Gfx plate_plate_soup_tomato_so_plate_soup_tomato_mdl_mesh_layer_1[] = {
	gsSPDisplayList(mat_plate_pot_liquid_tomato),
	gsSPDisplayList(plate_plate_soup_tomato_so_plate_soup_tomato_mdl_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_plate_pot_liquid_tomato),
	gsSPEndDisplayList(),
};

Gfx plate_plate_soup_burnt_so_plate_soup_burnt_mdl_mesh_layer_1[] = {
	gsSPDisplayList(mat_plate_pot_liquid_burnt),
	gsSPDisplayList(plate_plate_soup_burnt_so_plate_soup_burnt_mdl_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_plate_pot_liquid_burnt),
	gsSPEndDisplayList(),
};

Gfx plate_plate_dl_mesh_layer_1[] = {
	gsSPDisplayList(mat_plate_plate),
	gsSPDisplayList(plate_plate_dl_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_plate_plate),
	gsSPDisplayList(mat_plate_plate_bottom),
	gsSPDisplayList(plate_plate_dl_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_plate_plate_bottom),
	gsSPEndDisplayList(),
};

Gfx plate_plate_dl_mesh_layer_1_mat_override_plate_dirty_0[] = {
	gsSPDisplayList(mat_plate_plate_dirty),
	gsSPDisplayList(plate_plate_dl_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_plate_plate_dirty),
	gsSPDisplayList(mat_plate_plate_bottom),
	gsSPDisplayList(plate_plate_dl_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_plate_plate_bottom),
	gsSPEndDisplayList(),
};

Gfx plate_material_revert_render_settings[] = {
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

