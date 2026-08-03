void scroll_gfx_mat_jrb_dl_water_moving() {
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_water_moving);

	shift_s(mat, 9, PACK_TILESIZE(0, 1));
	shift_t(mat, 9, PACK_TILESIZE(0, 1));

};

void scroll_jrb() {
	scroll_gfx_mat_jrb_dl_water_moving();
};
