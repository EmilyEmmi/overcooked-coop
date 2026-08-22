Lights1 box_box_label_steak_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 box_box_label_cheese_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 box_box_label_onion_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 box_box_label_lettuce_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 box_box_label_buns_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 box_box_label_tomato_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 box_box_label_mushroom_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 box_box_label_chicken_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 box_box_label_sausage_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 box_box_label_dough_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 box_box_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 box_box_hole_lights = gdSPDefLights1(
	0x9, 0x6, 0x4,
	0x1F, 0x17, 0x11, 0x28, 0x28, 0x28);

Texture box_box_label_steak_ci4[] = {
	#include "actors/box/box_label_steak.ci4.inc.c"
};

Texture box_box_label_steak_pal_rgba16[] = {
	#include "actors/box/box_label_steak.rgba16.pal"
};

Texture box_box_label_cheese_ci4[] = {
	#include "actors/box/box_label_cheese.ci4.inc.c"
};

Texture box_box_label_cheese_pal_rgba16[] = {
	#include "actors/box/box_label_cheese.rgba16.pal"
};

Texture box_box_label_onion_ci4[] = {
	#include "actors/box/box_label_onion.ci4.inc.c"
};

Texture box_box_label_onion_pal_rgba16[] = {
	#include "actors/box/box_label_onion.rgba16.pal"
};

Texture box_box_label_lettuce_ci4[] = {
	#include "actors/box/box_label_lettuce.ci4.inc.c"
};

Texture box_box_label_lettuce_pal_rgba16[] = {
	#include "actors/box/box_label_lettuce.rgba16.pal"
};

Texture box_box_label_buns_ci4[] = {
	#include "actors/box/box_label_buns.ci4.inc.c"
};

Texture box_box_label_buns_pal_rgba16[] = {
	#include "actors/box/box_label_buns.rgba16.pal"
};

Texture box_box_label_tomato_ci4[] = {
	#include "actors/box/box_label_tomato.ci4.inc.c"
};

Texture box_box_label_tomato_pal_rgba16[] = {
	#include "actors/box/box_label_tomato.rgba16.pal"
};

Texture box_box_label_mushroom_ci4[] = {
	#include "actors/box/box_label_mushroom.ci4.inc.c"
};

Texture box_box_label_mushroom_pal_rgba16[] = {
	#include "actors/box/box_label_mushroom.rgba16.pal"
};

Texture box_box_label_chicken_ci4[] = {
	#include "actors/box/box_label_chicken.ci4.inc.c"
};

Texture box_box_label_chicken_pal_rgba16[] = {
	#include "actors/box/box_label_chicken.rgba16.pal"
};

Texture box_box_label_sausage_ci4[] = {
	#include "actors/box/box_label_sausage.ci4.inc.c"
};

Texture box_box_label_sausage_pal_rgba16[] = {
	#include "actors/box/box_label_sausage.rgba16.pal"
};

Texture box_box_label_dough_ci4[] = {
	#include "actors/box/box_label_dough.ci4.inc.c"
};

Texture box_box_label_dough_pal_rgba16[] = {
	#include "actors/box/box_label_dough.rgba16.pal"
};

Texture box_box_ci8[] = {
	#include "actors/box/box.ci8.inc.c"
};

Texture box_box_pal_rgba16[] = {
	#include "actors/box/box.rgba16.pal"
};

Vtx box_box_label_model_mesh_layer_4_vtx_0[4] = {
	{{{87, 13, 52}, 0, {935, 57}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-87, 13, 52}, 0, {57, 57}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-87, 13, 226}, 0, {57, 935}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{87, 13, 226}, 0, {935, 935}, {0x00, 0x7F, 0x00, 0xFF}}},
};

Gfx box_box_label_model_mesh_layer_4_tri_0[] = {
	gsSPVertex(box_box_label_model_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx box_box_lid_mesh_layer_1_vtx_0[48] = {
	{{{-139, 23, 0}, 0, {1230, 1397}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 0, 278}, 0, {-238, 1518}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 23, 278}, 0, {-238, 1397}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 0, 0}, 0, {1230, 1518}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 23, 278}, 0, {-238, 1397}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-139, 0, 278}, 0, {-238, 1518}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{139, 0, 278}, 0, {1230, 1518}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{139, 23, 278}, 0, {1230, 1397}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{139, 23, 0}, 0, {1230, 1397}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{-139, 0, 0}, 0, {-238, 1518}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{-139, 23, 0}, 0, {-238, 1397}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{139, 0, 0}, 0, {1230, 1518}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{139, 23, 278}, 0, {-238, 1397}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 0, 278}, 0, {-238, 1518}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 0, 0}, 0, {1230, 1518}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 23, 0}, 0, {1230, 1397}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{98, 23, 41}, 0, {987, 1505}, {0xA6, 0x00, 0x5A, 0xFF}}},
	{{{-98, 23, 41}, 0, {5, 1505}, {0x5A, 0x00, 0x5A, 0xFF}}},
	{{{-98, 9, 41}, 0, {5, 1586}, {0x5A, 0x00, 0x5A, 0xFF}}},
	{{{98, 9, 41}, 0, {987, 1586}, {0xA6, 0x00, 0x5A, 0xFF}}},
	{{{98, 23, 237}, 0, {170, 1505}, {0xA6, 0x00, 0xA6, 0xFF}}},
	{{{98, 23, 41}, 0, {1152, 1505}, {0xA6, 0x00, 0x5A, 0xFF}}},
	{{{98, 9, 41}, 0, {1152, 1586}, {0xA6, 0x00, 0x5A, 0xFF}}},
	{{{98, 9, 237}, 0, {170, 1586}, {0xA6, 0x00, 0xA6, 0xFF}}},
	{{{-98, 23, 41}, 0, {1152, 1505}, {0x5A, 0x00, 0x5A, 0xFF}}},
	{{{-98, 23, 237}, 0, {170, 1505}, {0x5A, 0x00, 0xA6, 0xFF}}},
	{{{-98, 9, 237}, 0, {170, 1586}, {0x5A, 0x00, 0xA6, 0xFF}}},
	{{{-98, 9, 41}, 0, {1152, 1586}, {0x5A, 0x00, 0x5A, 0xFF}}},
	{{{-98, 23, 237}, 0, {5, 1505}, {0x5A, 0x00, 0xA6, 0xFF}}},
	{{{98, 23, 237}, 0, {987, 1505}, {0xA6, 0x00, 0xA6, 0xFF}}},
	{{{98, 9, 237}, 0, {987, 1586}, {0xA6, 0x00, 0xA6, 0xFF}}},
	{{{-98, 9, 237}, 0, {5, 1586}, {0x5A, 0x00, 0xA6, 0xFF}}},
	{{{98, 9, 41}, 0, {858, 172}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-98, 9, 41}, 0, {134, 172}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-98, 9, 237}, 0, {134, 896}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{98, 9, 237}, 0, {858, 896}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{139, 0, 278}, 0, {1114, 1027}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-139, 0, 0}, 0, {-122, 2357}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{139, 0, 0}, 0, {1114, 2357}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-139, 0, 278}, 0, {-122, 1027}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-139, 23, 0}, 0, {-238, 1030}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-139, 23, 278}, 0, {-238, 2498}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-98, 23, 237}, 0, {-23, 2283}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{98, 23, 237}, 0, {1015, 2283}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{139, 23, 278}, 0, {1230, 2498}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{98, 23, 41}, 0, {1015, 1245}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{139, 23, 0}, 0, {1230, 1030}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-98, 23, 41}, 0, {-23, 1245}, {0x00, 0x7F, 0x00, 0xFF}}},
};

Gfx box_box_lid_mesh_layer_1_tri_0[] = {
	gsSPVertex(box_box_lid_mesh_layer_1_vtx_0 + 0, 48, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 11, 9, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSP2Triangles(32, 33, 34, 0, 32, 34, 35, 0),
	gsSP2Triangles(36, 37, 38, 0, 36, 39, 37, 0),
	gsSP2Triangles(40, 41, 42, 0, 41, 43, 42, 0),
	gsSP2Triangles(41, 44, 43, 0, 44, 45, 43, 0),
	gsSP2Triangles(44, 46, 45, 0, 46, 47, 45, 0),
	gsSP2Triangles(46, 40, 47, 0, 40, 42, 47, 0),
	gsSPEndDisplayList(),
};

Vtx box_box_model_mesh_layer_1_vtx_0[112] = {
	{{{-139, 41, 98}, 0, {-199, 2131}, {0x00, 0x5A, 0xA6, 0xFF}}},
	{{{-139, 98, 98}, 0, {-199, 1794}, {0x00, 0xA6, 0xA6, 0xFF}}},
	{{{-125, 98, 98}, 0, {-129, 1794}, {0x00, 0xA6, 0xA6, 0xFF}}},
	{{{-125, 41, 98}, 0, {-129, 2131}, {0x00, 0x5A, 0xA6, 0xFF}}},
	{{{-139, 41, -98}, 0, {-199, 1101}, {0x00, 0x5A, 0x5A, 0xFF}}},
	{{{-139, 41, 98}, 0, {-199, 2254}, {0x00, 0x5A, 0xA6, 0xFF}}},
	{{{-125, 41, 98}, 0, {-129, 2254}, {0x00, 0x5A, 0xA6, 0xFF}}},
	{{{-125, 41, -98}, 0, {-129, 1101}, {0x00, 0x5A, 0x5A, 0xFF}}},
	{{{-139, 98, 98}, 0, {-199, 2254}, {0x00, 0xA6, 0xA6, 0xFF}}},
	{{{-139, 98, -98}, 0, {-199, 1101}, {0x00, 0xA6, 0x5A, 0xFF}}},
	{{{-125, 98, -98}, 0, {-129, 1101}, {0x00, 0xA6, 0x5A, 0xFF}}},
	{{{-125, 98, 98}, 0, {-129, 2254}, {0x00, 0xA6, 0xA6, 0xFF}}},
	{{{-139, 98, -98}, 0, {-199, 1794}, {0x00, 0xA6, 0x5A, 0xFF}}},
	{{{-139, 41, -98}, 0, {-199, 2131}, {0x00, 0x5A, 0x5A, 0xFF}}},
	{{{-125, 41, -98}, 0, {-129, 2131}, {0x00, 0x5A, 0x5A, 0xFF}}},
	{{{-125, 98, -98}, 0, {-129, 1794}, {0x00, 0xA6, 0x5A, 0xFF}}},
	{{{139, 41, -98}, 0, {1191, 2131}, {0x00, 0x5A, 0x5A, 0xFF}}},
	{{{139, 98, -98}, 0, {1191, 1794}, {0x00, 0xA6, 0x5A, 0xFF}}},
	{{{125, 98, -98}, 0, {1121, 1794}, {0x00, 0xA6, 0x5A, 0xFF}}},
	{{{125, 41, -98}, 0, {1121, 2131}, {0x00, 0x5A, 0x5A, 0xFF}}},
	{{{139, 41, 98}, 0, {1191, 2254}, {0x00, 0x5A, 0xA6, 0xFF}}},
	{{{139, 41, -98}, 0, {1191, 1101}, {0x00, 0x5A, 0x5A, 0xFF}}},
	{{{125, 41, -98}, 0, {1121, 1101}, {0x00, 0x5A, 0x5A, 0xFF}}},
	{{{125, 41, 98}, 0, {1121, 2254}, {0x00, 0x5A, 0xA6, 0xFF}}},
	{{{139, 98, -98}, 0, {1191, 1101}, {0x00, 0xA6, 0x5A, 0xFF}}},
	{{{139, 98, 98}, 0, {1191, 2254}, {0x00, 0xA6, 0xA6, 0xFF}}},
	{{{125, 98, 98}, 0, {1121, 2254}, {0x00, 0xA6, 0xA6, 0xFF}}},
	{{{125, 98, -98}, 0, {1121, 1101}, {0x00, 0xA6, 0x5A, 0xFF}}},
	{{{139, 98, 98}, 0, {1191, 1794}, {0x00, 0xA6, 0xA6, 0xFF}}},
	{{{139, 41, 98}, 0, {1191, 2131}, {0x00, 0x5A, 0xA6, 0xFF}}},
	{{{125, 41, 98}, 0, {1121, 2131}, {0x00, 0x5A, 0xA6, 0xFF}}},
	{{{125, 98, 98}, 0, {1121, 1794}, {0x00, 0xA6, 0xA6, 0xFF}}},
	{{{98, 41, 139}, 0, {-34, 2131}, {0xA6, 0x5A, 0x00, 0xFF}}},
	{{{98, 98, 139}, 0, {-34, 1794}, {0xA6, 0xA6, 0x00, 0xFF}}},
	{{{98, 98, 125}, 0, {36, 1794}, {0xA6, 0xA6, 0x00, 0xFF}}},
	{{{98, 41, 125}, 0, {36, 2131}, {0xA6, 0x5A, 0x00, 0xFF}}},
	{{{-98, 41, 139}, 0, {5, 2412}, {0x5A, 0x5A, 0x00, 0xFF}}},
	{{{98, 41, 139}, 0, {987, 2412}, {0xA6, 0x5A, 0x00, 0xFF}}},
	{{{98, 41, 125}, 0, {987, 2331}, {0xA6, 0x5A, 0x00, 0xFF}}},
	{{{-98, 41, 125}, 0, {5, 2331}, {0x5A, 0x5A, 0x00, 0xFF}}},
	{{{98, 98, 139}, 0, {987, 2412}, {0xA6, 0xA6, 0x00, 0xFF}}},
	{{{-98, 98, 139}, 0, {5, 2412}, {0x5A, 0xA6, 0x00, 0xFF}}},
	{{{-98, 98, 125}, 0, {5, 2331}, {0x5A, 0xA6, 0x00, 0xFF}}},
	{{{98, 98, 125}, 0, {987, 2331}, {0xA6, 0xA6, 0x00, 0xFF}}},
	{{{-98, 98, 139}, 0, {-34, 1794}, {0x5A, 0xA6, 0x00, 0xFF}}},
	{{{-98, 41, 139}, 0, {-34, 2131}, {0x5A, 0x5A, 0x00, 0xFF}}},
	{{{-98, 41, 125}, 0, {36, 2131}, {0x5A, 0x5A, 0x00, 0xFF}}},
	{{{-98, 98, 125}, 0, {36, 1794}, {0x5A, 0xA6, 0x00, 0xFF}}},
	{{{-125, 41, 98}, 0, {134, 489}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-125, 98, 98}, 0, {134, 277}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-125, 98, -98}, 0, {858, 277}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-125, 41, -98}, 0, {858, 489}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-98, 41, -125}, 0, {134, 489}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{-98, 98, -125}, 0, {134, 277}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{98, 98, -125}, 0, {858, 277}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{98, 41, -125}, 0, {858, 489}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{125, 41, -98}, 0, {858, 489}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{125, 98, -98}, 0, {858, 277}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{125, 98, 98}, 0, {134, 277}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{125, 41, 98}, 0, {134, 489}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{98, 41, 125}, 0, {858, 489}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{98, 98, 125}, 0, {858, 277}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-98, 98, 125}, 0, {134, 277}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-98, 41, 125}, 0, {134, 489}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-139, 0, 139}, 0, {-238, 1980}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 116, 139}, 0, {-238, 1367}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 98, 98}, 0, {-23, 1461}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 98, -98}, 0, {1015, 1461}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 116, -139}, 0, {1230, 1367}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 41, -98}, 0, {1015, 1764}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 0, -139}, 0, {1230, 1980}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 41, 98}, 0, {-23, 1764}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{-139, 0, 139}, 0, {-238, 1980}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{139, 0, 139}, 0, {1230, 1980}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{98, 41, 139}, 0, {1015, 1764}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{98, 98, 139}, 0, {1015, 1461}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{139, 116, 139}, 0, {1230, 1367}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-98, 98, 139}, 0, {-23, 1461}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-139, 116, 139}, 0, {-238, 1367}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-98, 41, 139}, 0, {-23, 1764}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-139, 0, -139}, 0, {-238, 1980}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{-139, 116, -139}, 0, {-238, 1367}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{-98, 98, -139}, 0, {-23, 1461}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{98, 98, -139}, 0, {1015, 1461}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{139, 116, -139}, 0, {1230, 1367}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{98, 41, -139}, 0, {1015, 1764}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{139, 0, -139}, 0, {1230, 1980}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{-98, 41, -139}, 0, {-23, 1764}, {0x00, 0x00, 0x81, 0xFF}}},
	{{{139, 0, 139}, 0, {-238, 1980}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 0, -139}, 0, {1230, 1980}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 41, -98}, 0, {1015, 1764}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 98, -98}, 0, {1015, 1461}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 116, -139}, 0, {1230, 1367}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 98, 98}, 0, {-23, 1461}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 116, 139}, 0, {-238, 1367}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{139, 41, 98}, 0, {-23, 1764}, {0x7F, 0x00, 0x00, 0xFF}}},
	{{{-98, 41, -139}, 0, {134, 1779}, {0x5A, 0x5A, 0x00, 0xFF}}},
	{{{-98, 98, -139}, 0, {134, 1567}, {0x5A, 0xA6, 0x00, 0xFF}}},
	{{{-98, 98, -125}, 0, {134, 1567}, {0x5A, 0xA6, 0x00, 0xFF}}},
	{{{98, 98, -125}, 0, {858, 1567}, {0xA6, 0xA6, 0x00, 0xFF}}},
	{{{98, 98, -139}, 0, {858, 1567}, {0xA6, 0xA6, 0x00, 0xFF}}},
	{{{98, 41, -125}, 0, {858, 1779}, {0xA6, 0x5A, 0x00, 0xFF}}},
	{{{98, 41, -139}, 0, {858, 1779}, {0xA6, 0x5A, 0x00, 0xFF}}},
	{{{-98, 41, -125}, 0, {134, 1779}, {0x5A, 0x5A, 0x00, 0xFF}}},
	{{{139, 116, -139}, 0, {1170, 892}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-139, 116, -139}, 0, {-178, 892}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-110, 116, -110}, 0, {12, 1080}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-110, 116, 110}, 0, {12, 2041}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-139, 116, 139}, 0, {-178, 2230}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{110, 116, 110}, 0, {980, 2041}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{139, 116, 139}, 0, {1170, 2230}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{110, 116, -110}, 0, {980, 1080}, {0x00, 0x7F, 0x00, 0xFF}}},
};

Gfx box_box_model_mesh_layer_1_tri_0[] = {
	gsSPVertex(box_box_model_mesh_layer_1_vtx_0 + 0, 64, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSP2Triangles(32, 33, 34, 0, 32, 34, 35, 0),
	gsSP2Triangles(36, 37, 38, 0, 36, 38, 39, 0),
	gsSP2Triangles(40, 41, 42, 0, 40, 42, 43, 0),
	gsSP2Triangles(44, 45, 46, 0, 44, 46, 47, 0),
	gsSP2Triangles(48, 49, 50, 0, 48, 50, 51, 0),
	gsSP2Triangles(52, 53, 54, 0, 52, 54, 55, 0),
	gsSP2Triangles(56, 57, 58, 0, 56, 58, 59, 0),
	gsSP2Triangles(60, 61, 62, 0, 60, 62, 63, 0),
	gsSPVertex(box_box_model_mesh_layer_1_vtx_0 + 64, 48, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(1, 4, 3, 0, 4, 5, 3, 0),
	gsSP2Triangles(4, 6, 5, 0, 6, 7, 5, 0),
	gsSP2Triangles(6, 0, 7, 0, 0, 2, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 9, 11, 10, 0),
	gsSP2Triangles(9, 12, 11, 0, 12, 13, 11, 0),
	gsSP2Triangles(12, 14, 13, 0, 14, 15, 13, 0),
	gsSP2Triangles(14, 8, 15, 0, 8, 10, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 17, 19, 18, 0),
	gsSP2Triangles(17, 20, 19, 0, 20, 21, 19, 0),
	gsSP2Triangles(20, 22, 21, 0, 22, 23, 21, 0),
	gsSP2Triangles(22, 16, 23, 0, 16, 18, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 25, 27, 26, 0),
	gsSP2Triangles(25, 28, 27, 0, 28, 29, 27, 0),
	gsSP2Triangles(28, 30, 29, 0, 30, 31, 29, 0),
	gsSP2Triangles(30, 24, 31, 0, 24, 26, 31, 0),
	gsSP2Triangles(32, 33, 34, 0, 33, 35, 34, 0),
	gsSP2Triangles(33, 36, 35, 0, 36, 37, 35, 0),
	gsSP2Triangles(36, 38, 37, 0, 38, 39, 37, 0),
	gsSP2Triangles(38, 32, 39, 0, 32, 34, 39, 0),
	gsSP2Triangles(40, 41, 42, 0, 41, 43, 42, 0),
	gsSP2Triangles(41, 44, 43, 0, 44, 45, 43, 0),
	gsSP2Triangles(44, 46, 45, 0, 46, 47, 45, 0),
	gsSP2Triangles(46, 40, 47, 0, 40, 42, 47, 0),
	gsSPEndDisplayList(),
};

Vtx box_box_model_mesh_layer_1_vtx_1[7] = {
	{{{110, 116, -110}, 0, {1230, 675}, {0xD5, 0x6F, 0x2B, 0xFF}}},
	{{{-110, 116, -110}, 0, {-238, 675}, {0x2B, 0x6F, 0x2B, 0xFF}}},
	{{{0, 31, 0}, 0, {496, 675}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{110, 116, 110}, 0, {-238, 675}, {0xD5, 0x6F, 0xD5, 0xFF}}},
	{{{-110, 116, -110}, 0, {1230, 675}, {0x2B, 0x6F, 0x2B, 0xFF}}},
	{{{-110, 116, 110}, 0, {-238, 675}, {0x2B, 0x6F, 0xD5, 0xFF}}},
	{{{110, 116, 110}, 0, {1230, 675}, {0xD5, 0x6F, 0xD5, 0xFF}}},
};

Gfx box_box_model_mesh_layer_1_tri_1[] = {
	gsSPVertex(box_box_model_mesh_layer_1_vtx_1 + 0, 7, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(4, 5, 2, 0, 5, 6, 2, 0),
	gsSPEndDisplayList(),
};


Gfx mat_box_box_label_steak[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(box_box_label_steak_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_AVERAGE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, box_box_label_steak_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 4),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, box_box_label_steak_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_box_box_label_steak[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_box_box_label_cheese[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(box_box_label_cheese_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_AVERAGE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, box_box_label_cheese_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 5),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, box_box_label_cheese_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_box_box_label_cheese[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_box_box_label_onion[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(box_box_label_onion_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_AVERAGE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, box_box_label_onion_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 5),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, box_box_label_onion_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_box_box_label_onion[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_box_box_label_lettuce[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(box_box_label_lettuce_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_AVERAGE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, box_box_label_lettuce_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 5),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, box_box_label_lettuce_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_box_box_label_lettuce[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_box_box_label_buns[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(box_box_label_buns_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_AVERAGE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, box_box_label_buns_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 5),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, box_box_label_buns_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_box_box_label_buns[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_box_box_label_tomato[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(box_box_label_tomato_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_AVERAGE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, box_box_label_tomato_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 6),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, box_box_label_tomato_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_box_box_label_tomato[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_box_box_label_mushroom[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(box_box_label_mushroom_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_AVERAGE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, box_box_label_mushroom_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 7),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, box_box_label_mushroom_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_box_box_label_mushroom[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_box_box_label_chicken[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(box_box_label_chicken_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_AVERAGE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, box_box_label_chicken_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 6),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, box_box_label_chicken_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_box_box_label_chicken[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_box_box_label_sausage[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(box_box_label_sausage_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_AVERAGE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, box_box_label_sausage_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 5),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, box_box_label_sausage_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_box_box_label_sausage[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_box_box_label_dough[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(box_box_label_dough_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_AVERAGE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, box_box_label_dough_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 5),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, box_box_label_dough_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_box_box_label_dough[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_box_box[] = {
	gsSPSetLights1(box_box_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, box_box_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 15),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, box_box_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 252),
	gsSPEndDisplayList(),
};

Gfx mat_revert_box_box[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_box_box_hole[] = {
	gsSPSetLights1(box_box_hole_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_box_box_hole[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx box_box_label_model_mesh_layer_4[] = {
	gsSPDisplayList(mat_box_box_label_steak),
	gsSPDisplayList(box_box_label_model_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_box_box_label_steak),
	gsSPEndDisplayList(),
};

Gfx box_box_label_model_mesh_layer_4_mat_override_box_label_cheese_0[] = {
	gsSPDisplayList(mat_box_box_label_cheese),
	gsSPDisplayList(box_box_label_model_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_box_box_label_cheese),
	gsSPEndDisplayList(),
};

Gfx box_box_label_model_mesh_layer_4_mat_override_box_label_onion_1[] = {
	gsSPDisplayList(mat_box_box_label_onion),
	gsSPDisplayList(box_box_label_model_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_box_box_label_onion),
	gsSPEndDisplayList(),
};

Gfx box_box_label_model_mesh_layer_4_mat_override_box_label_lettuce_2[] = {
	gsSPDisplayList(mat_box_box_label_lettuce),
	gsSPDisplayList(box_box_label_model_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_box_box_label_lettuce),
	gsSPEndDisplayList(),
};

Gfx box_box_label_model_mesh_layer_4_mat_override_box_label_buns_3[] = {
	gsSPDisplayList(mat_box_box_label_buns),
	gsSPDisplayList(box_box_label_model_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_box_box_label_buns),
	gsSPEndDisplayList(),
};

Gfx box_box_label_model_mesh_layer_4_mat_override_box_label_tomato_4[] = {
	gsSPDisplayList(mat_box_box_label_tomato),
	gsSPDisplayList(box_box_label_model_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_box_box_label_tomato),
	gsSPEndDisplayList(),
};

Gfx box_box_label_model_mesh_layer_4_mat_override_box_label_mushroom_5[] = {
	gsSPDisplayList(mat_box_box_label_mushroom),
	gsSPDisplayList(box_box_label_model_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_box_box_label_mushroom),
	gsSPEndDisplayList(),
};

Gfx box_box_label_model_mesh_layer_4_mat_override_box_label_chicken_6[] = {
	gsSPDisplayList(mat_box_box_label_chicken),
	gsSPDisplayList(box_box_label_model_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_box_box_label_chicken),
	gsSPEndDisplayList(),
};

Gfx box_box_label_model_mesh_layer_4_mat_override_box_label_sausage_7[] = {
	gsSPDisplayList(mat_box_box_label_sausage),
	gsSPDisplayList(box_box_label_model_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_box_box_label_sausage),
	gsSPEndDisplayList(),
};

Gfx box_box_label_model_mesh_layer_4_mat_override_box_label_dough_8[] = {
	gsSPDisplayList(mat_box_box_label_dough),
	gsSPDisplayList(box_box_label_model_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_box_box_label_dough),
	gsSPEndDisplayList(),
};

Gfx box_box_lid_mesh_layer_1[] = {
	gsSPDisplayList(mat_box_box),
	gsSPDisplayList(box_box_lid_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_box_box),
	gsSPEndDisplayList(),
};

Gfx box_box_lid_mesh_layer_1_mat_override_box_label_cheese_0[] = {
	gsSPDisplayList(mat_box_box),
	gsSPDisplayList(box_box_lid_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_box_box),
	gsSPEndDisplayList(),
};

Gfx box_box_lid_mesh_layer_1_mat_override_box_label_onion_1[] = {
	gsSPDisplayList(mat_box_box),
	gsSPDisplayList(box_box_lid_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_box_box),
	gsSPEndDisplayList(),
};

Gfx box_box_lid_mesh_layer_1_mat_override_box_label_lettuce_2[] = {
	gsSPDisplayList(mat_box_box),
	gsSPDisplayList(box_box_lid_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_box_box),
	gsSPEndDisplayList(),
};

Gfx box_box_lid_mesh_layer_1_mat_override_box_label_buns_3[] = {
	gsSPDisplayList(mat_box_box),
	gsSPDisplayList(box_box_lid_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_box_box),
	gsSPEndDisplayList(),
};

Gfx box_box_lid_mesh_layer_1_mat_override_box_label_tomato_4[] = {
	gsSPDisplayList(mat_box_box),
	gsSPDisplayList(box_box_lid_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_box_box),
	gsSPEndDisplayList(),
};

Gfx box_box_lid_mesh_layer_1_mat_override_box_label_mushroom_5[] = {
	gsSPDisplayList(mat_box_box),
	gsSPDisplayList(box_box_lid_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_box_box),
	gsSPEndDisplayList(),
};

Gfx box_box_lid_mesh_layer_1_mat_override_box_label_chicken_6[] = {
	gsSPDisplayList(mat_box_box),
	gsSPDisplayList(box_box_lid_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_box_box),
	gsSPEndDisplayList(),
};

Gfx box_box_lid_mesh_layer_1_mat_override_box_label_sausage_7[] = {
	gsSPDisplayList(mat_box_box),
	gsSPDisplayList(box_box_lid_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_box_box),
	gsSPEndDisplayList(),
};

Gfx box_box_lid_mesh_layer_1_mat_override_box_label_dough_8[] = {
	gsSPDisplayList(mat_box_box),
	gsSPDisplayList(box_box_lid_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_box_box),
	gsSPEndDisplayList(),
};

Gfx box_box_model_mesh_layer_1[] = {
	gsSPDisplayList(mat_box_box),
	gsSPDisplayList(box_box_model_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_box_box),
	gsSPDisplayList(mat_box_box_hole),
	gsSPDisplayList(box_box_model_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_box_box_hole),
	gsSPEndDisplayList(),
};

Gfx box_material_revert_render_settings[] = {
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

