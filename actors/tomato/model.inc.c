Lights1 tomato_tomato_outer_lights = gdSPDefLights1(
	0x3E, 0xA, 0x7,
	0x83, 0x1F, 0x1A, 0x28, 0x28, 0x28);

Lights1 tomato_tomato_stem_lights = gdSPDefLights1(
	0xBC, 0xBC, 0xBC,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 tomato_tomato_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Texture tomato_tomato_stem_ci4[] = {
	#include "actors/tomato/tomato_stem.ci4.inc.c"
};

Texture tomato_tomato_stem_pal_rgba16[] = {
	#include "actors/tomato/tomato_stem.rgba16.pal"
};

Texture tomato_tomato_ci8[] = {
	#include "actors/tomato/tomato.ci8.inc.c"
};

Texture tomato_tomato_pal_rgba16[] = {
	#include "actors/tomato/tomato.rgba16.pal"
};

Vtx tomato_segment_1_mesh_layer_1_vtx_0[13] = {
	{{{25, -5, -59}, 0, {817, 207}, {0x19, 0x6F, 0xC8, 0xFF}}},
	{{{27, 3, -26}, 0, {817, 207}, {0xD4, 0x77, 0xF6, 0xFF}}},
	{{{58, -5, -17}, 0, {817, 207}, {0x3B, 0x6F, 0xF1, 0xFF}}},
	{{{-25, -5, -59}, 0, {817, 207}, {0xE7, 0x6F, 0xC8, 0xFF}}},
	{{{-28, 3, -26}, 0, {817, 207}, {0xBD, 0x6C, 0xF7, 0xFF}}},
	{{{-58, -5, -17}, 0, {817, 207}, {0xC5, 0x6F, 0xF1, 0xFF}}},
	{{{-51, -5, 30}, 0, {817, 207}, {0xCC, 0x70, 0x1D, 0xFF}}},
	{{{-26, 3, 23}, 0, {817, 207}, {0xC1, 0x6E, 0x0A, 0xFF}}},
	{{{-20, -5, 56}, 0, {817, 207}, {0xED, 0x70, 0x38, 0xFF}}},
	{{{20, -5, 56}, 0, {817, 207}, {0x13, 0x70, 0x38, 0xFF}}},
	{{{26, 3, 23}, 0, {817, 207}, {0xD2, 0x76, 0x09, 0xFF}}},
	{{{51, -5, 30}, 0, {817, 207}, {0x34, 0x70, 0x1D, 0xFF}}},
	{{{0, -2, -1}, 0, {817, 207}, {0x91, 0x3C, 0x0D, 0xFF}}},
};

Gfx tomato_segment_1_mesh_layer_1_tri_0[] = {
	gsSPVertex(tomato_segment_1_mesh_layer_1_vtx_0 + 0, 13, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(3, 4, 1, 0, 5, 4, 3, 0),
	gsSP2Triangles(6, 4, 5, 0, 6, 7, 4, 0),
	gsSP2Triangles(8, 7, 6, 0, 9, 7, 8, 0),
	gsSP2Triangles(9, 10, 7, 0, 11, 10, 9, 0),
	gsSP2Triangles(2, 10, 11, 0, 2, 1, 10, 0),
	gsSP2Triangles(10, 1, 12, 0, 1, 4, 12, 0),
	gsSP2Triangles(4, 7, 12, 0, 7, 10, 12, 0),
	gsSPEndDisplayList(),
};

Vtx tomato_segment_1_mesh_layer_1_vtx_1[23] = {
	{{{-10, 20, -88}, 0, {224, -120}, {0xFE, 0x7D, 0x18, 0xFF}}},
	{{{-17, 7, -22}, 0, {195, 139}, {0x0E, 0x7D, 0x13, 0xFF}}},
	{{{19, 7, -20}, 0, {330, 150}, {0xEE, 0x7D, 0x10, 0xFF}}},
	{{{0, 0, 0}, 0, {259, 227}, {0xFE, 0x7F, 0xFE, 0xFF}}},
	{{{-25, 7, 8}, 0, {168, 258}, {0x18, 0x7C, 0xF7, 0xFF}}},
	{{{-82, 20, -25}, 0, {-47, 130}, {0x19, 0x7C, 0x06, 0xFF}}},
	{{{0, 7, 26}, 0, {259, 328}, {0xFE, 0x7D, 0xE8, 0xFF}}},
	{{{21, 7, 5}, 0, {336, 248}, {0xE4, 0x7B, 0xF6, 0xFF}}},
	{{{59, 20, 69}, 0, {480, 498}, {0xF0, 0x7D, 0xF0, 0xFF}}},
	{{{84, 20, -17}, 0, {571, 161}, {0xE7, 0x7D, 0x01, 0xFF}}},
	{{{-58, 20, 65}, 0, {44, 480}, {0x0F, 0x7D, 0xEC, 0xFF}}},
	{{{-1, 47, 0}, 0, {305, 12}, {0xCF, 0x75, 0x00, 0xFF}}},
	{{{-10, 43, -9}, 0, {230, 9}, {0xCF, 0x75, 0x00, 0xFF}}},
	{{{-18, 40, 0}, 0, {156, 7}, {0xCF, 0x75, 0x00, 0xFF}}},
	{{{-10, 43, 9}, 0, {230, 9}, {0xCF, 0x75, 0x00, 0xFF}}},
	{{{2, 3, 0}, 0, {258, 279}, {0x7F, 0x09, 0x00, 0xFF}}},
	{{{-1, 2, -3}, 0, {234, 280}, {0x0A, 0xEF, 0x83, 0xFF}}},
	{{{-10, 43, -9}, 0, {230, 9}, {0x10, 0xF0, 0x83, 0xFF}}},
	{{{-18, 40, 0}, 0, {156, 7}, {0x89, 0xD3, 0x00, 0xFF}}},
	{{{-4, 2, 0}, 0, {209, 281}, {0x89, 0xD3, 0x00, 0xFF}}},
	{{{-10, 43, 9}, 0, {230, 9}, {0x10, 0xF0, 0x7D, 0xFF}}},
	{{{-1, 2, 3}, 0, {234, 280}, {0x0A, 0xEF, 0x7D, 0xFF}}},
	{{{-1, 47, 0}, 0, {305, 12}, {0x7F, 0x09, 0x00, 0xFF}}},
};

Gfx tomato_segment_1_mesh_layer_1_tri_1[] = {
	gsSPVertex(tomato_segment_1_mesh_layer_1_vtx_1 + 0, 23, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(4, 3, 1, 0, 5, 4, 1, 0),
	gsSP2Triangles(6, 3, 4, 0, 7, 3, 6, 0),
	gsSP2Triangles(8, 7, 6, 0, 2, 3, 7, 0),
	gsSP2Triangles(9, 2, 7, 0, 10, 6, 4, 0),
	gsSP2Triangles(11, 12, 13, 0, 11, 13, 14, 0),
	gsSP2Triangles(15, 16, 17, 0, 16, 18, 17, 0),
	gsSP2Triangles(16, 19, 18, 0, 19, 20, 18, 0),
	gsSP2Triangles(19, 21, 20, 0, 21, 22, 20, 0),
	gsSP2Triangles(21, 15, 22, 0, 15, 17, 22, 0),
	gsSPEndDisplayList(),
};

Vtx tomato_segment_1_mesh_layer_1_vtx_2[8] = {
	{{{-25, -5, -59}, 0, {281, 1972}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{25, -5, -59}, 0, {711, 1972}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{58, -5, -17}, 0, {1004, 1276}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-58, -5, -17}, 0, {-12, 1276}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-51, -5, 30}, 0, {49, 483}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{51, -5, 30}, 0, {943, 483}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{20, -5, 56}, 0, {673, 44}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-20, -5, 56}, 0, {319, 44}, {0x00, 0x81, 0x00, 0xFF}}},
};

Gfx tomato_segment_1_mesh_layer_1_tri_2[] = {
	gsSPVertex(tomato_segment_1_mesh_layer_1_vtx_2 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(4, 3, 2, 0, 2, 5, 4, 0),
	gsSP2Triangles(5, 6, 4, 0, 6, 7, 4, 0),
	gsSPEndDisplayList(),
};

Vtx tomato_segment_2_mesh_layer_1_vtx_0[17] = {
	{{{83, -7, 48}, 0, {817, 207}, {0x5F, 0x41, 0x36, 0xFF}}},
	{{{51, 21, 30}, 0, {817, 207}, {0x34, 0x70, 0x1D, 0xFF}}},
	{{{20, 21, 56}, 0, {817, 207}, {0x13, 0x70, 0x38, 0xFF}}},
	{{{95, -7, -17}, 0, {817, 207}, {0x6D, 0x3E, 0xEE, 0xFF}}},
	{{{58, 21, -17}, 0, {817, 207}, {0x3B, 0x6F, 0xF1, 0xFF}}},
	{{{62, -7, -74}, 0, {817, 207}, {0x48, 0x3E, 0xAC, 0xFF}}},
	{{{25, 21, -59}, 0, {817, 207}, {0x19, 0x6F, 0xC8, 0xFF}}},
	{{{0, -7, -96}, 0, {817, 207}, {0x00, 0x3D, 0x91, 0xFF}}},
	{{{-25, 21, -59}, 0, {817, 207}, {0xE7, 0x6F, 0xC8, 0xFF}}},
	{{{-62, -7, -74}, 0, {817, 207}, {0xB8, 0x3E, 0xAC, 0xFF}}},
	{{{-58, 21, -17}, 0, {817, 207}, {0xC5, 0x6F, 0xF1, 0xFF}}},
	{{{-95, -7, -17}, 0, {817, 207}, {0x94, 0x40, 0xEE, 0xFF}}},
	{{{-83, -7, 48}, 0, {817, 207}, {0xA1, 0x41, 0x36, 0xFF}}},
	{{{-51, 21, 30}, 0, {817, 207}, {0xCC, 0x70, 0x1D, 0xFF}}},
	{{{-33, -7, 90}, 0, {817, 207}, {0xDB, 0x41, 0x67, 0xFF}}},
	{{{-20, 21, 56}, 0, {817, 207}, {0xED, 0x70, 0x38, 0xFF}}},
	{{{33, -7, 90}, 0, {817, 207}, {0x25, 0x41, 0x67, 0xFF}}},
};

Gfx tomato_segment_2_mesh_layer_1_tri_0[] = {
	gsSPVertex(tomato_segment_2_mesh_layer_1_vtx_0 + 0, 17, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(3, 4, 1, 0, 3, 5, 4, 0),
	gsSP2Triangles(5, 6, 4, 0, 5, 7, 6, 0),
	gsSP2Triangles(7, 8, 6, 0, 9, 8, 7, 0),
	gsSP2Triangles(10, 8, 9, 0, 11, 10, 9, 0),
	gsSP2Triangles(12, 10, 11, 0, 12, 13, 10, 0),
	gsSP2Triangles(14, 13, 12, 0, 14, 15, 13, 0),
	gsSP2Triangles(16, 15, 14, 0, 16, 2, 15, 0),
	gsSP1Triangle(0, 2, 16, 0),
	gsSPEndDisplayList(),
};

Vtx tomato_segment_2_mesh_layer_1_vtx_1[17] = {
	{{{-51, 21, 30}, 0, {38, 1531}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-20, 21, 56}, 0, {315, 1968}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{20, 21, 56}, 0, {677, 1968}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{51, 21, 30}, 0, {954, 1531}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{58, 21, -17}, 0, {1017, 741}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-58, 21, -17}, 0, {-25, 741}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-25, 21, -59}, 0, {275, 48}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{25, 21, -59}, 0, {717, 48}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{83, -7, 48}, 0, {945, 478}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{33, -7, 90}, 0, {673, 31}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{95, -7, -17}, 0, {1007, 1164}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-33, -7, 90}, 0, {319, 31}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{0, -7, -96}, 0, {496, 2006}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-62, -7, -74}, 0, {163, 1768}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-95, -7, -17}, 0, {-15, 1164}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-83, -7, 48}, 0, {47, 478}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{62, -7, -74}, 0, {829, 1768}, {0x00, 0x81, 0x00, 0xFF}}},
};

Gfx tomato_segment_2_mesh_layer_1_tri_1[] = {
	gsSPVertex(tomato_segment_2_mesh_layer_1_vtx_1 + 0, 17, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
	gsSP2Triangles(3, 4, 0, 0, 5, 0, 4, 0),
	gsSP2Triangles(6, 5, 4, 0, 4, 7, 6, 0),
	gsSP2Triangles(8, 9, 10, 0, 9, 11, 10, 0),
	gsSP2Triangles(11, 12, 10, 0, 13, 12, 11, 0),
	gsSP2Triangles(14, 13, 11, 0, 11, 15, 14, 0),
	gsSP1Triangle(12, 16, 10, 0),
	gsSPEndDisplayList(),
};

Vtx tomato_segment_3_mesh_layer_1_vtx_0[18] = {
	{{{37, -18, 100}, 0, {817, 207}, {0x2B, 0xF9, 0x77, 0xFF}}},
	{{{33, 33, 90}, 0, {817, 207}, {0x25, 0x41, 0x67, 0xFF}}},
	{{{-33, 33, 90}, 0, {817, 207}, {0xDB, 0x41, 0x67, 0xFF}}},
	{{{92, -18, 53}, 0, {817, 207}, {0x6E, 0xF9, 0x3F, 0xFF}}},
	{{{83, 33, 48}, 0, {817, 207}, {0x5F, 0x41, 0x36, 0xFF}}},
	{{{105, -18, -19}, 0, {817, 207}, {0x7D, 0xF9, 0xEA, 0xFF}}},
	{{{95, 33, -17}, 0, {817, 207}, {0x6D, 0x3E, 0xEE, 0xFF}}},
	{{{69, -18, -82}, 0, {817, 207}, {0x52, 0xF9, 0x9F, 0xFF}}},
	{{{62, 33, -74}, 0, {817, 207}, {0x48, 0x3E, 0xAC, 0xFF}}},
	{{{0, -18, -107}, 0, {817, 207}, {0x00, 0xF9, 0x81, 0xFF}}},
	{{{0, 33, -96}, 0, {817, 207}, {0x00, 0x3D, 0x91, 0xFF}}},
	{{{-69, -18, -82}, 0, {817, 207}, {0xAE, 0xFE, 0x9F, 0xFF}}},
	{{{-62, 33, -74}, 0, {817, 207}, {0xB8, 0x3E, 0xAC, 0xFF}}},
	{{{-105, -18, -19}, 0, {817, 207}, {0x83, 0xF9, 0xEA, 0xFF}}},
	{{{-95, 33, -17}, 0, {817, 207}, {0x94, 0x40, 0xEE, 0xFF}}},
	{{{-92, -18, 53}, 0, {817, 207}, {0x92, 0xFE, 0x3F, 0xFF}}},
	{{{-83, 33, 48}, 0, {817, 207}, {0xA1, 0x41, 0x36, 0xFF}}},
	{{{-37, -18, 100}, 0, {817, 207}, {0xD5, 0xF9, 0x77, 0xFF}}},
};

Gfx tomato_segment_3_mesh_layer_1_tri_0[] = {
	gsSPVertex(tomato_segment_3_mesh_layer_1_vtx_0 + 0, 18, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(3, 4, 1, 0, 5, 4, 3, 0),
	gsSP2Triangles(5, 6, 4, 0, 7, 6, 5, 0),
	gsSP2Triangles(7, 8, 6, 0, 9, 8, 7, 0),
	gsSP2Triangles(9, 10, 8, 0, 11, 10, 9, 0),
	gsSP2Triangles(11, 12, 10, 0, 13, 12, 11, 0),
	gsSP2Triangles(13, 14, 12, 0, 15, 14, 13, 0),
	gsSP2Triangles(15, 16, 14, 0, 17, 16, 15, 0),
	gsSP2Triangles(17, 2, 16, 0, 0, 2, 17, 0),
	gsSPEndDisplayList(),
};

Vtx tomato_segment_3_mesh_layer_1_vtx_1[18] = {
	{{{-33, 33, 90}, 0, {322, 2004}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{33, 33, 90}, 0, {670, 2004}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{83, 33, 48}, 0, {937, 1549}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{62, 33, -74}, 0, {824, 239}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{95, 33, -17}, 0, {998, 852}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-62, 33, -74}, 0, {168, 239}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{0, 33, -96}, 0, {496, -3}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-95, 33, -17}, 0, {-6, 852}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-83, 33, 48}, 0, {55, 1549}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{69, -18, -82}, 0, {825, 232}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{105, -18, -19}, 0, {1000, 849}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{92, -18, 53}, 0, {939, 1549}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{0, -18, -107}, 0, {496, -11}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-69, -18, -82}, 0, {167, 232}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{37, -18, 100}, 0, {671, 2006}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-37, -18, 100}, 0, {321, 2006}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-92, -18, 53}, 0, {53, 1549}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-105, -18, -19}, 0, {-8, 849}, {0x00, 0x81, 0x00, 0xFF}}},
};

Gfx tomato_segment_3_mesh_layer_1_tri_1[] = {
	gsSPVertex(tomato_segment_3_mesh_layer_1_vtx_1 + 0, 18, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(2, 4, 3, 0, 0, 3, 5, 0),
	gsSP2Triangles(3, 6, 5, 0, 5, 7, 0, 0),
	gsSP2Triangles(7, 8, 0, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 9, 11, 0, 13, 12, 11, 0),
	gsSP2Triangles(11, 14, 13, 0, 14, 15, 13, 0),
	gsSP2Triangles(15, 16, 13, 0, 16, 17, 13, 0),
	gsSPEndDisplayList(),
};

Vtx tomato_segment_4_mesh_layer_1_vtx_0[18] = {
	{{{-32, -18, 87}, 0, {817, 207}, {0xDB, 0xC0, 0x67, 0xFF}}},
	{{{-37, 32, 100}, 0, {817, 207}, {0xD5, 0xF9, 0x77, 0xFF}}},
	{{{-92, 32, 53}, 0, {817, 207}, {0x92, 0xFE, 0x3F, 0xFF}}},
	{{{32, -18, 87}, 0, {817, 207}, {0x25, 0xC0, 0x67, 0xFF}}},
	{{{37, 32, 100}, 0, {817, 207}, {0x2B, 0xF9, 0x77, 0xFF}}},
	{{{80, -18, 46}, 0, {817, 207}, {0x5F, 0xBF, 0x36, 0xFF}}},
	{{{92, 32, 53}, 0, {817, 207}, {0x6E, 0xF9, 0x3F, 0xFF}}},
	{{{91, -18, -16}, 0, {817, 207}, {0x6D, 0xC1, 0xEE, 0xFF}}},
	{{{105, 32, -19}, 0, {817, 207}, {0x7D, 0xF9, 0xEA, 0xFF}}},
	{{{59, -18, -71}, 0, {817, 207}, {0x47, 0xC1, 0xAC, 0xFF}}},
	{{{69, 32, -82}, 0, {817, 207}, {0x52, 0xF9, 0x9F, 0xFF}}},
	{{{0, -18, -93}, 0, {817, 207}, {0x00, 0xBA, 0x96, 0xFF}}},
	{{{0, 32, -107}, 0, {817, 207}, {0x00, 0xF9, 0x81, 0xFF}}},
	{{{-59, -18, -71}, 0, {817, 207}, {0xB9, 0xC1, 0xAC, 0xFF}}},
	{{{-69, 32, -82}, 0, {817, 207}, {0xAE, 0xFE, 0x9F, 0xFF}}},
	{{{-91, -18, -16}, 0, {817, 207}, {0x93, 0xC1, 0xEE, 0xFF}}},
	{{{-105, 32, -19}, 0, {817, 207}, {0x83, 0xF9, 0xEA, 0xFF}}},
	{{{-80, -18, 46}, 0, {817, 207}, {0xA1, 0xBF, 0x36, 0xFF}}},
};

Gfx tomato_segment_4_mesh_layer_1_tri_0[] = {
	gsSPVertex(tomato_segment_4_mesh_layer_1_vtx_0 + 0, 18, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(3, 4, 1, 0, 5, 4, 3, 0),
	gsSP2Triangles(5, 6, 4, 0, 7, 6, 5, 0),
	gsSP2Triangles(7, 8, 6, 0, 9, 8, 7, 0),
	gsSP2Triangles(9, 10, 8, 0, 11, 10, 9, 0),
	gsSP2Triangles(11, 12, 10, 0, 13, 12, 11, 0),
	gsSP2Triangles(13, 14, 12, 0, 15, 14, 13, 0),
	gsSP2Triangles(15, 16, 14, 0, 17, 16, 15, 0),
	gsSP2Triangles(17, 2, 16, 0, 0, 2, 17, 0),
	gsSPEndDisplayList(),
};

Vtx tomato_segment_4_mesh_layer_1_vtx_1[18] = {
	{{{-105, 32, -19}, 0, {-21, 851}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-92, 32, 53}, 0, {41, 1565}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-37, 32, 100}, 0, {313, 2031}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-69, 32, -82}, 0, {157, 223}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{69, 32, -82}, 0, {825, 223}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{105, 32, -19}, 0, {1003, 851}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{92, 32, 53}, 0, {941, 1565}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{37, 32, 100}, 0, {669, 2031}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{0, 32, -107}, 0, {491, -25}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{32, -18, 87}, 0, {664, 32}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-32, -18, 87}, 0, {308, 32}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-80, -18, 46}, 0, {35, 484}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{80, -18, 46}, 0, {936, 484}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{59, -18, -71}, 0, {820, 1785}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-59, -18, -71}, 0, {152, 1785}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-91, -18, -16}, 0, {-26, 1176}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{0, -18, -93}, 0, {486, 2025}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{91, -18, -16}, 0, {998, 1176}, {0x00, 0x81, 0x00, 0xFF}}},
};

Gfx tomato_segment_4_mesh_layer_1_tri_1[] = {
	gsSPVertex(tomato_segment_4_mesh_layer_1_vtx_1 + 0, 18, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(2, 4, 3, 0, 5, 4, 2, 0),
	gsSP2Triangles(6, 5, 2, 0, 2, 7, 6, 0),
	gsSP2Triangles(4, 8, 3, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 9, 11, 0, 11, 13, 12, 0),
	gsSP2Triangles(11, 14, 13, 0, 11, 15, 14, 0),
	gsSP2Triangles(14, 16, 13, 0, 13, 17, 12, 0),
	gsSPEndDisplayList(),
};

Vtx tomato_segment_5_mesh_layer_1_vtx_0[17] = {
	{{{-20, -12, 54}, 0, {817, 207}, {0xEA, 0x92, 0x3B, 0xFF}}},
	{{{-32, 16, 87}, 0, {817, 207}, {0xDB, 0xBF, 0x67, 0xFF}}},
	{{{-80, 16, 46}, 0, {817, 207}, {0xA1, 0xBF, 0x36, 0xFF}}},
	{{{20, -12, 54}, 0, {817, 207}, {0x16, 0x92, 0x3B, 0xFF}}},
	{{{32, 16, 87}, 0, {817, 207}, {0x25, 0xBF, 0x67, 0xFF}}},
	{{{50, -12, 29}, 0, {817, 207}, {0x37, 0x92, 0x1F, 0xFF}}},
	{{{80, 16, 46}, 0, {817, 207}, {0x5F, 0xBF, 0x36, 0xFF}}},
	{{{57, -12, -18}, 0, {817, 207}, {0x3E, 0x92, 0xEF, 0xFF}}},
	{{{91, 16, -16}, 0, {817, 207}, {0x6D, 0xC1, 0xEE, 0xFF}}},
	{{{59, 16, -71}, 0, {817, 207}, {0x47, 0xC1, 0xAC, 0xFF}}},
	{{{27, -12, -52}, 0, {817, 207}, {0x1B, 0x91, 0xC7, 0xFF}}},
	{{{0, 16, -93}, 0, {817, 207}, {0x00, 0xC0, 0x92, 0xFF}}},
	{{{-27, -12, -52}, 0, {817, 207}, {0xE8, 0x8E, 0xCD, 0xFF}}},
	{{{-59, 16, -71}, 0, {817, 207}, {0xB9, 0xC1, 0xAC, 0xFF}}},
	{{{-57, -12, -18}, 0, {817, 207}, {0xC2, 0x92, 0xEF, 0xFF}}},
	{{{-91, 16, -16}, 0, {817, 207}, {0x93, 0xC1, 0xEE, 0xFF}}},
	{{{-50, -12, 29}, 0, {817, 207}, {0xC9, 0x92, 0x1F, 0xFF}}},
};

Gfx tomato_segment_5_mesh_layer_1_tri_0[] = {
	gsSPVertex(tomato_segment_5_mesh_layer_1_vtx_0 + 0, 17, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(3, 4, 1, 0, 5, 4, 3, 0),
	gsSP2Triangles(5, 6, 4, 0, 7, 6, 5, 0),
	gsSP2Triangles(7, 8, 6, 0, 9, 8, 7, 0),
	gsSP2Triangles(10, 9, 7, 0, 11, 9, 10, 0),
	gsSP2Triangles(12, 11, 10, 0, 12, 13, 11, 0),
	gsSP2Triangles(12, 14, 13, 0, 14, 15, 13, 0),
	gsSP2Triangles(16, 15, 14, 0, 16, 2, 15, 0),
	gsSP1Triangle(0, 2, 16, 0),
	gsSPEndDisplayList(),
};

Vtx tomato_segment_5_mesh_layer_1_vtx_1[17] = {
	{{{-80, 16, 46}, 0, {46, 1560}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-32, 16, 87}, 0, {318, 2018}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-91, 16, -16}, 0, {-16, 859}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{32, 16, 87}, 0, {674, 2018}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{0, 16, -93}, 0, {496, -2}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{91, 16, -16}, 0, {1008, 859}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{80, 16, 46}, 0, {946, 1560}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{59, 16, -71}, 0, {830, 241}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-59, 16, -71}, 0, {162, 241}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-20, -12, 54}, 0, {318, 42}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-50, -12, 29}, 0, {46, 502}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-57, -12, -18}, 0, {-16, 1353}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{27, -12, -52}, 0, {740, 1974}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-27, -12, -52}, 0, {252, 1974}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{50, -12, 29}, 0, {946, 502}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{57, -12, -18}, 0, {1008, 1353}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{20, -12, 54}, 0, {674, 42}, {0x00, 0x81, 0x00, 0xFF}}},
};

Gfx tomato_segment_5_mesh_layer_1_tri_1[] = {
	gsSPVertex(tomato_segment_5_mesh_layer_1_vtx_1 + 0, 17, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(3, 4, 2, 0, 3, 5, 4, 0),
	gsSP2Triangles(3, 6, 5, 0, 5, 7, 4, 0),
	gsSP2Triangles(4, 8, 2, 0, 9, 10, 11, 0),
	gsSP2Triangles(9, 11, 12, 0, 11, 13, 12, 0),
	gsSP2Triangles(12, 14, 9, 0, 12, 15, 14, 0),
	gsSP1Triangle(14, 16, 9, 0),
	gsSPEndDisplayList(),
};

Vtx tomato_segment_6_mesh_layer_1_vtx_0[9] = {
	{{{0, -7, 0}, 0, {817, 207}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{27, 5, -52}, 0, {817, 207}, {0x1B, 0x91, 0xC7, 0xFF}}},
	{{{57, 5, -18}, 0, {817, 207}, {0x3E, 0x92, 0xEF, 0xFF}}},
	{{{-27, 5, -52}, 0, {817, 207}, {0xE8, 0x8E, 0xCD, 0xFF}}},
	{{{-57, 5, -18}, 0, {817, 207}, {0xC2, 0x92, 0xEF, 0xFF}}},
	{{{-50, 5, 29}, 0, {817, 207}, {0xC9, 0x92, 0x1F, 0xFF}}},
	{{{-20, 5, 54}, 0, {817, 207}, {0xEA, 0x92, 0x3B, 0xFF}}},
	{{{20, 5, 54}, 0, {817, 207}, {0x16, 0x92, 0x3B, 0xFF}}},
	{{{50, 5, 29}, 0, {817, 207}, {0x37, 0x92, 0x1F, 0xFF}}},
};

Gfx tomato_segment_6_mesh_layer_1_tri_0[] = {
	gsSPVertex(tomato_segment_6_mesh_layer_1_vtx_0 + 0, 9, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
	gsSP2Triangles(0, 6, 5, 0, 0, 7, 6, 0),
	gsSP2Triangles(0, 8, 7, 0, 0, 2, 8, 0),
	gsSPEndDisplayList(),
};

Vtx tomato_segment_6_mesh_layer_1_vtx_1[8] = {
	{{{57, 5, -18}, 0, {1008, 664}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{27, 5, -52}, 0, {740, 44}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{50, 5, 29}, 0, {946, 1513}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-27, 5, -52}, 0, {252, 44}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-50, 5, 29}, 0, {46, 1513}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-57, 5, -18}, 0, {-16, 664}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{20, 5, 54}, 0, {674, 1972}, {0x00, 0x7F, 0x00, 0xFF}}},
	{{{-20, 5, 54}, 0, {318, 1972}, {0x00, 0x7F, 0x00, 0xFF}}},
};

Gfx tomato_segment_6_mesh_layer_1_tri_1[] = {
	gsSPVertex(tomato_segment_6_mesh_layer_1_vtx_1 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(4, 2, 3, 0, 3, 5, 4, 0),
	gsSP2Triangles(6, 2, 4, 0, 4, 7, 6, 0),
	gsSPEndDisplayList(),
};

Vtx tomato_tomato_whole_so_tomato_whole_mdl_mesh_layer_1_vtx_0[49] = {
	{{{37, 5, 100}, 0, {817, 207}, {0x2B, 0xFC, 0x77, 0xFF}}},
	{{{33, 56, 90}, 0, {817, 207}, {0x26, 0x40, 0x67, 0xFF}}},
	{{{-33, 56, 90}, 0, {817, 207}, {0xDA, 0x40, 0x67, 0xFF}}},
	{{{92, 5, 53}, 0, {817, 207}, {0x6E, 0xFC, 0x3F, 0xFF}}},
	{{{80, -45, 46}, 0, {817, 207}, {0x5D, 0xBD, 0x36, 0xFF}}},
	{{{32, -45, 87}, 0, {817, 207}, {0x25, 0xBD, 0x65, 0xFF}}},
	{{{-37, 5, 100}, 0, {817, 207}, {0xD5, 0xFC, 0x77, 0xFF}}},
	{{{-83, 56, 48}, 0, {817, 207}, {0xA1, 0x40, 0x37, 0xFF}}},
	{{{-51, 84, 30}, 0, {817, 207}, {0xCB, 0x70, 0x1D, 0xFF}}},
	{{{-20, 84, 56}, 0, {817, 207}, {0xED, 0x70, 0x38, 0xFF}}},
	{{{20, 84, 56}, 0, {817, 207}, {0x13, 0x70, 0x38, 0xFF}}},
	{{{83, 56, 48}, 0, {817, 207}, {0x5F, 0x40, 0x37, 0xFF}}},
	{{{105, 5, -19}, 0, {817, 207}, {0x7D, 0xFC, 0xEA, 0xFF}}},
	{{{91, -45, -16}, 0, {817, 207}, {0x6B, 0xBE, 0xEE, 0xFF}}},
	{{{57, -73, -18}, 0, {817, 207}, {0x3A, 0x90, 0xEF, 0xFF}}},
	{{{50, -73, 29}, 0, {817, 207}, {0x33, 0x90, 0x1D, 0xFF}}},
	{{{20, -73, 54}, 0, {817, 207}, {0x14, 0x90, 0x38, 0xFF}}},
	{{{-32, -45, 87}, 0, {817, 207}, {0xDB, 0xBD, 0x65, 0xFF}}},
	{{{-92, 5, 53}, 0, {817, 207}, {0x92, 0xFC, 0x3F, 0xFF}}},
	{{{-95, 56, -17}, 0, {817, 207}, {0x93, 0x3F, 0xEE, 0xFF}}},
	{{{-58, 84, -17}, 0, {817, 207}, {0xC4, 0x6F, 0xF1, 0xFF}}},
	{{{-28, 91, -26}, 0, {817, 207}, {0xBD, 0x6C, 0xF7, 0xFF}}},
	{{{-26, 91, 23}, 0, {817, 207}, {0xC1, 0x6E, 0x0A, 0xFF}}},
	{{{26, 91, 23}, 0, {817, 207}, {0xD2, 0x76, 0x09, 0xFF}}},
	{{{51, 84, 30}, 0, {817, 207}, {0x35, 0x70, 0x1D, 0xFF}}},
	{{{95, 56, -17}, 0, {817, 207}, {0x6D, 0x3F, 0xEE, 0xFF}}},
	{{{69, 5, -82}, 0, {817, 207}, {0x52, 0xFC, 0x9F, 0xFF}}},
	{{{59, -45, -71}, 0, {817, 207}, {0x46, 0xBF, 0xAD, 0xFF}}},
	{{{27, -73, -52}, 0, {817, 207}, {0x19, 0x8F, 0xCB, 0xFF}}},
	{{{0, -85, 0}, 0, {817, 207}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-20, -73, 54}, 0, {817, 207}, {0xEC, 0x90, 0x38, 0xFF}}},
	{{{-80, -45, 46}, 0, {817, 207}, {0xA3, 0xBD, 0x36, 0xFF}}},
	{{{-105, 5, -19}, 0, {817, 207}, {0x83, 0xFC, 0xEA, 0xFF}}},
	{{{-62, 56, -74}, 0, {817, 207}, {0xB8, 0x3E, 0xAC, 0xFF}}},
	{{{-25, 84, -59}, 0, {817, 207}, {0xE7, 0x6F, 0xC7, 0xFF}}},
	{{{27, 91, -26}, 0, {817, 207}, {0xD4, 0x77, 0xF6, 0xFF}}},
	{{{0, 86, -1}, 0, {817, 207}, {0x91, 0x3C, 0x0D, 0xFF}}},
	{{{58, 84, -17}, 0, {817, 207}, {0x3C, 0x6F, 0xF1, 0xFF}}},
	{{{62, 56, -74}, 0, {817, 207}, {0x48, 0x3E, 0xAC, 0xFF}}},
	{{{0, 5, -107}, 0, {817, 207}, {0x00, 0xFC, 0x81, 0xFF}}},
	{{{0, -45, -93}, 0, {817, 207}, {0x00, 0xBE, 0x94, 0xFF}}},
	{{{-27, -73, -52}, 0, {817, 207}, {0xE7, 0x8F, 0xCB, 0xFF}}},
	{{{-57, -73, -18}, 0, {817, 207}, {0xC6, 0x90, 0xEF, 0xFF}}},
	{{{-50, -73, 29}, 0, {817, 207}, {0xCD, 0x90, 0x1D, 0xFF}}},
	{{{-91, -45, -16}, 0, {817, 207}, {0x95, 0xBE, 0xEE, 0xFF}}},
	{{{-69, 5, -82}, 0, {817, 207}, {0xAE, 0xFC, 0x9F, 0xFF}}},
	{{{0, 56, -96}, 0, {817, 207}, {0x00, 0x3C, 0x90, 0xFF}}},
	{{{25, 84, -59}, 0, {817, 207}, {0x19, 0x6F, 0xC7, 0xFF}}},
	{{{-59, -45, -71}, 0, {817, 207}, {0xBA, 0xBF, 0xAD, 0xFF}}},
};

Gfx tomato_tomato_whole_so_tomato_whole_mdl_mesh_layer_1_tri_0[] = {
	gsSPVertex(tomato_tomato_whole_so_tomato_whole_mdl_mesh_layer_1_vtx_0 + 0, 49, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(4, 3, 0, 0, 4, 0, 5, 0),
	gsSP2Triangles(5, 0, 6, 0, 0, 2, 6, 0),
	gsSP2Triangles(6, 2, 7, 0, 2, 8, 7, 0),
	gsSP2Triangles(2, 9, 8, 0, 1, 9, 2, 0),
	gsSP2Triangles(1, 10, 9, 0, 11, 10, 1, 0),
	gsSP2Triangles(3, 11, 1, 0, 12, 11, 3, 0),
	gsSP2Triangles(13, 12, 3, 0, 13, 3, 4, 0),
	gsSP2Triangles(14, 13, 4, 0, 14, 4, 15, 0),
	gsSP2Triangles(15, 4, 5, 0, 15, 5, 16, 0),
	gsSP2Triangles(16, 5, 17, 0, 5, 6, 17, 0),
	gsSP2Triangles(17, 6, 18, 0, 6, 7, 18, 0),
	gsSP2Triangles(18, 7, 19, 0, 7, 20, 19, 0),
	gsSP2Triangles(7, 8, 20, 0, 8, 21, 20, 0),
	gsSP2Triangles(8, 22, 21, 0, 9, 22, 8, 0),
	gsSP2Triangles(10, 22, 9, 0, 10, 23, 22, 0),
	gsSP2Triangles(24, 23, 10, 0, 11, 24, 10, 0),
	gsSP2Triangles(25, 24, 11, 0, 12, 25, 11, 0),
	gsSP2Triangles(26, 25, 12, 0, 27, 26, 12, 0),
	gsSP2Triangles(27, 12, 13, 0, 27, 13, 14, 0),
	gsSP2Triangles(28, 27, 14, 0, 29, 28, 14, 0),
	gsSP2Triangles(29, 14, 15, 0, 29, 15, 16, 0),
	gsSP2Triangles(29, 16, 30, 0, 16, 17, 30, 0),
	gsSP2Triangles(30, 17, 31, 0, 17, 18, 31, 0),
	gsSP2Triangles(31, 18, 32, 0, 18, 19, 32, 0),
	gsSP2Triangles(32, 19, 33, 0, 19, 20, 33, 0),
	gsSP2Triangles(20, 34, 33, 0, 20, 21, 34, 0),
	gsSP2Triangles(34, 21, 35, 0, 35, 21, 36, 0),
	gsSP2Triangles(21, 22, 36, 0, 22, 23, 36, 0),
	gsSP2Triangles(23, 35, 36, 0, 37, 35, 23, 0),
	gsSP2Triangles(37, 23, 24, 0, 25, 37, 24, 0),
	gsSP2Triangles(25, 38, 37, 0, 26, 38, 25, 0),
	gsSP2Triangles(39, 38, 26, 0, 40, 39, 26, 0),
	gsSP2Triangles(40, 26, 27, 0, 40, 27, 28, 0),
	gsSP2Triangles(41, 40, 28, 0, 29, 41, 28, 0),
	gsSP2Triangles(29, 42, 41, 0, 29, 43, 42, 0),
	gsSP2Triangles(29, 30, 43, 0, 30, 31, 43, 0),
	gsSP2Triangles(43, 31, 44, 0, 31, 32, 44, 0),
	gsSP2Triangles(44, 32, 45, 0, 32, 33, 45, 0),
	gsSP2Triangles(45, 33, 46, 0, 33, 34, 46, 0),
	gsSP2Triangles(46, 34, 47, 0, 34, 35, 47, 0),
	gsSP2Triangles(47, 35, 37, 0, 38, 47, 37, 0),
	gsSP2Triangles(38, 46, 47, 0, 39, 46, 38, 0),
	gsSP2Triangles(45, 46, 39, 0, 48, 45, 39, 0),
	gsSP2Triangles(48, 39, 40, 0, 41, 48, 40, 0),
	gsSP2Triangles(41, 42, 48, 0, 42, 44, 48, 0),
	gsSP2Triangles(43, 44, 42, 0, 44, 45, 48, 0),
	gsSPEndDisplayList(),
};

Vtx tomato_tomato_whole_so_tomato_whole_mdl_mesh_layer_1_vtx_1[23] = {
	{{{-10, 108, -88}, 0, {224, -120}, {0xFE, 0x7D, 0x18, 0xFF}}},
	{{{-17, 95, -22}, 0, {195, 139}, {0x0E, 0x7D, 0x13, 0xFF}}},
	{{{19, 95, -20}, 0, {330, 150}, {0xEE, 0x7D, 0x10, 0xFF}}},
	{{{0, 88, 0}, 0, {259, 227}, {0xFE, 0x7F, 0xFE, 0xFF}}},
	{{{-25, 95, 8}, 0, {168, 258}, {0x18, 0x7C, 0xF7, 0xFF}}},
	{{{-82, 108, -25}, 0, {-47, 130}, {0x19, 0x7C, 0x06, 0xFF}}},
	{{{0, 95, 26}, 0, {259, 328}, {0xFE, 0x7D, 0xE8, 0xFF}}},
	{{{21, 95, 5}, 0, {336, 248}, {0xE4, 0x7B, 0xF6, 0xFF}}},
	{{{59, 108, 69}, 0, {480, 498}, {0xF0, 0x7D, 0xF0, 0xFF}}},
	{{{84, 108, -17}, 0, {571, 161}, {0xE7, 0x7D, 0x01, 0xFF}}},
	{{{-58, 108, 65}, 0, {44, 480}, {0x0F, 0x7D, 0xEC, 0xFF}}},
	{{{-1, 135, 0}, 0, {305, 12}, {0xCF, 0x75, 0x00, 0xFF}}},
	{{{-10, 131, -9}, 0, {230, 9}, {0xCF, 0x75, 0x00, 0xFF}}},
	{{{-18, 128, 0}, 0, {156, 7}, {0xCF, 0x75, 0x00, 0xFF}}},
	{{{-10, 131, 9}, 0, {230, 9}, {0xCF, 0x75, 0x00, 0xFF}}},
	{{{2, 91, 0}, 0, {258, 279}, {0x7F, 0x09, 0x00, 0xFF}}},
	{{{-1, 90, -3}, 0, {234, 280}, {0x0A, 0xEF, 0x83, 0xFF}}},
	{{{-10, 131, -9}, 0, {230, 9}, {0x10, 0xF0, 0x83, 0xFF}}},
	{{{-18, 128, 0}, 0, {156, 7}, {0x89, 0xD3, 0x00, 0xFF}}},
	{{{-4, 90, 0}, 0, {209, 281}, {0x89, 0xD3, 0x00, 0xFF}}},
	{{{-10, 131, 9}, 0, {230, 9}, {0x10, 0xF0, 0x7D, 0xFF}}},
	{{{-1, 90, 3}, 0, {234, 280}, {0x0A, 0xEF, 0x7D, 0xFF}}},
	{{{-1, 135, 0}, 0, {305, 12}, {0x7F, 0x09, 0x00, 0xFF}}},
};

Gfx tomato_tomato_whole_so_tomato_whole_mdl_mesh_layer_1_tri_1[] = {
	gsSPVertex(tomato_tomato_whole_so_tomato_whole_mdl_mesh_layer_1_vtx_1 + 0, 23, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(4, 3, 1, 0, 5, 4, 1, 0),
	gsSP2Triangles(6, 3, 4, 0, 7, 3, 6, 0),
	gsSP2Triangles(8, 7, 6, 0, 2, 3, 7, 0),
	gsSP2Triangles(9, 2, 7, 0, 10, 6, 4, 0),
	gsSP2Triangles(11, 12, 13, 0, 11, 13, 14, 0),
	gsSP2Triangles(15, 16, 17, 0, 16, 18, 17, 0),
	gsSP2Triangles(16, 19, 18, 0, 19, 20, 18, 0),
	gsSP2Triangles(19, 21, 20, 0, 21, 22, 20, 0),
	gsSP2Triangles(21, 15, 22, 0, 15, 17, 22, 0),
	gsSPEndDisplayList(),
};


Gfx mat_tomato_tomato_outer[] = {
	gsSPSetLights1(tomato_tomato_outer_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_tomato_tomato_outer[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_tomato_tomato_stem[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(tomato_tomato_stem_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, tomato_tomato_stem_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 9),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, tomato_tomato_stem_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 63, 2048),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 60),
	gsSPEndDisplayList(),
};

Gfx mat_revert_tomato_tomato_stem[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_tomato_tomato[] = {
	gsSPSetLights1(tomato_tomato_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, tomato_tomato_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 237),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, tomato_tomato_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 252),
	gsSPEndDisplayList(),
};

Gfx mat_revert_tomato_tomato[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx tomato_segment_1_mesh_layer_1[] = {
	gsSPDisplayList(mat_tomato_tomato_outer),
	gsSPDisplayList(tomato_segment_1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_tomato_tomato_outer),
	gsSPDisplayList(mat_tomato_tomato_stem),
	gsSPDisplayList(tomato_segment_1_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_tomato_tomato_stem),
	gsSPDisplayList(mat_tomato_tomato),
	gsSPDisplayList(tomato_segment_1_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_tomato_tomato),
	gsSPEndDisplayList(),
};

Gfx tomato_segment_2_mesh_layer_1[] = {
	gsSPDisplayList(mat_tomato_tomato_outer),
	gsSPDisplayList(tomato_segment_2_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_tomato_tomato_outer),
	gsSPDisplayList(mat_tomato_tomato),
	gsSPDisplayList(tomato_segment_2_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_tomato_tomato),
	gsSPEndDisplayList(),
};

Gfx tomato_segment_3_mesh_layer_1[] = {
	gsSPDisplayList(mat_tomato_tomato_outer),
	gsSPDisplayList(tomato_segment_3_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_tomato_tomato_outer),
	gsSPDisplayList(mat_tomato_tomato),
	gsSPDisplayList(tomato_segment_3_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_tomato_tomato),
	gsSPEndDisplayList(),
};

Gfx tomato_segment_4_mesh_layer_1[] = {
	gsSPDisplayList(mat_tomato_tomato_outer),
	gsSPDisplayList(tomato_segment_4_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_tomato_tomato_outer),
	gsSPDisplayList(mat_tomato_tomato),
	gsSPDisplayList(tomato_segment_4_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_tomato_tomato),
	gsSPEndDisplayList(),
};

Gfx tomato_segment_5_mesh_layer_1[] = {
	gsSPDisplayList(mat_tomato_tomato_outer),
	gsSPDisplayList(tomato_segment_5_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_tomato_tomato_outer),
	gsSPDisplayList(mat_tomato_tomato),
	gsSPDisplayList(tomato_segment_5_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_tomato_tomato),
	gsSPEndDisplayList(),
};

Gfx tomato_segment_6_mesh_layer_1[] = {
	gsSPDisplayList(mat_tomato_tomato_outer),
	gsSPDisplayList(tomato_segment_6_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_tomato_tomato_outer),
	gsSPDisplayList(mat_tomato_tomato),
	gsSPDisplayList(tomato_segment_6_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_tomato_tomato),
	gsSPEndDisplayList(),
};

Gfx tomato_tomato_whole_so_tomato_whole_mdl_mesh_layer_1[] = {
	gsSPDisplayList(mat_tomato_tomato_outer),
	gsSPDisplayList(tomato_tomato_whole_so_tomato_whole_mdl_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_tomato_tomato_outer),
	gsSPDisplayList(mat_tomato_tomato_stem),
	gsSPDisplayList(tomato_tomato_whole_so_tomato_whole_mdl_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_tomato_tomato_stem),
	gsSPEndDisplayList(),
};

Gfx tomato_material_revert_render_settings[] = {
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

