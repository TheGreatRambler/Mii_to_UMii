#include <cstdint>
#include <string>
#include <unordered_map>

namespace Mii {
	// As reference
	// https://github.com/leoetlino/botw/blob/master/Actor/UMii/AncientAssistant001.umii.yml
	// Assigned with defaults from the above
	struct MiiInfo {
		std::string name    = "UNDEFINED";
		std::string creator = "UNDEFINED";
		// Ffsd
		bool ffsd_no_use_ffsd = false;
		int ffsd_type         = 0;
		// Body
		int body_race   = 0;
		int body_type   = 4;
		int body_number = 0;
		int body_weight = 1;
		int body_height = 0;
		// Personal
		int personal_sex_age             = 1;
		int personal_fav_color           = 0;
		int personal_sub_color_1         = -1;
		int personal_sub_color_2         = -1;
		int personal_head_fav_color      = -1;
		int personal_shoulder_fav_color  = -1;
		int personal_shoulder_sub_color1 = -1;
		std::string personal_personality = "Man_Normal";
		std::string personal_voice_type  = "Hylia_Man_Old_Normal02";
		// Common
		int common_backpack       = -1;
		int common_hat            = 0;
		bool common_no_hat_always = true;
		int common_body_correct   = 0;
		bool common_is_mid_age    = false;
		float common_rot_cravicle = 0.0;
		float common_rot_arm      = 0.0;
		float common_rot_leg      = 0.0;
		float common_rot_crotch   = 0.0;
		// Shape
		int shape_jaw        = 5;
		int shape_wrinkle    = 11;
		int shape_make       = 10;
		float shape_trans_v  = 0.0;
		float shape_scale    = 1.0;
		int shape_skin_color = 3;
		// Hair
		int hair_type  = 56;
		int hair_color = 4;
		bool hair_flip = false;
		// Eye
		int eye_type                  = 52;
		int eye_color                 = 2;
		float eye_trans_v             = 10.8;
		float eye_trans_u             = 2.24;
		float eye_rotate              = -1.0;
		float eye_scale               = 4.62;
		float eye_aspect              = 1.775;
		float eye_eyeball_trans_u     = -0.0712;
		float eye_eyeball_trans_v     = -0.0692;
		float eye_eyeball_scale       = 0.031;
		int eye_highlight_bright      = 1;
		float eye_ctrl_base_offset_x  = 0.0;
		float eye_ctrl_base_offset_y  = 0.03;
		float eye_ctrl_base_offset_z  = 0.0;
		float eye_ctrl_translim_out   = 0.2;
		float eye_ctrl_translim_in    = 0.12;
		float eye_ctrl_translim_d     = 0.027;
		float eye_ctrl_translim_u     = 0.09;
		float eye_ctrl_neck_offset_ud = -1.8;
		// Eyebrow
		int eyebrow_type      = 5;
		int eyebrow_color     = 4;
		float eyebrow_trans_v = 3.0;
		float eyebrow_trans_u = 3.0;
		float eyebrow_rotate  = 0.0;
		float eyebrow_scale   = 3.0;
		float eyebrow_aspect  = 3.0;
		// Nose
		int nose_type      = 11;
		float nose_trans_v = 9.0;
		float nose_scale   = 4.0;
		// Mouth
		int mouth_type      = 23;
		int mouth_color     = 0;
		float mouth_trans_v = 15.0;
		float mouth_scale   = 4.0;
		float mouth_aspect  = 3.0;
		// Beard
		int beard_mustache = 5;
		float beard_scale  = 8.0;
		int beard_type     = 0;
		int beard_color    = 4;
		// Glass
		int glass_type  = 2;
		int glass_color = 1;
		// Korog
		int korog_mask        = 0;
		int korog_skin_color  = 0;
		int korog_left_plant  = 0;
		int korog_right_plant = 0;
		// Goron
		int goron_skin_color = 0;
		// Gerudo
		int gerudo_hair        = 0;
		int gerudo_hair_color  = 0;
		int gerudo_glass       = 0;
		int gerudo_glass_color = 0;
		int gerudo_skin_color  = 0;
		int gerudo_lip_color   = 0;
		// Rito
		int rito_body_color = 0;
		int rito_hair_color = -1;
		// Zora
		int zora_body_color = 0;
	};

	static const std::unordered_map<int, std::string> FavoriteColors {
		{ 0, "Red" },
		{ 1, "Orange" },
		{ 2, "Yellow" },
		{ 3, "Light Green" },
		{ 4, "Green" },
		{ 5, "Blue" },
		{ 6, "Light Blue" },
		{ 7, "Pink" },
		{ 8, "Purple" },
		{ 9, "Brown" },
		{ 10, "White" },
		{ 11, "Black" },
	};

	static const std::unordered_map<int, std::string> Types {
		{ 0x00, "Special Mii - Gold Pants" },
		{ 0x20, "Normal Mii - Black Pants" },
		{ 0x40, "Special Mii - Gold Pants" },
		{ 0x60, "Normal Mii - Black Pants" },
		{ 0xC0, "Foreign Mii - Blue Pants (uneditable)" },
		{ 0xE0, "Normal Mii - Black Pants" },
		{ 0x100, "???" },
	};

	static const std::unordered_map<int, int> Makeup {
		{ 1, 1 },
		{ 2, 6 },
		{ 3, 9 },
		{ 9, 10 },
	};

	static const std::unordered_map<int, int> Wrinkles {
		{ 4, 5 },
		{ 5, 2 },
		{ 6, 3 },
		{ 7, 7 },
		{ 8, 8 },
		{ 10, 9 },
		{ 11, 1 },
	};
};