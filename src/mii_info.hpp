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
		int body_type   = 2;
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
		std::string personal_voice_type  = "Hylia_Man_Young_Normal03";
		// Common
		int common_backpack       = -1;
		int common_hat            = -1;
		bool common_no_hat_always = false;
		int common_body_correct   = 0;
		bool common_is_mid_age    = false;
		float common_rot_cravicle = 0.0;
		float common_rot_arm      = 0.0;
		float common_rot_leg      = 0.0;
		float common_rot_crotch   = 0.0;
		// Shape
		int shape_jaw        = 5;
		int shape_wrinkle    = 0;
		int shape_make       = 0;
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
		float eye_aspect              = 3;
		float eye_eyeball_trans_u     = 0.0;
		float eye_eyeball_trans_v     = 0.0;
		float eye_eyeball_scale       = 0.031;
		int eye_highlight_bright      = 1;
		float eye_ctrl_base_offset_x  = 0.0;
		float eye_ctrl_base_offset_y  = 0.02;
		float eye_ctrl_base_offset_z  = 0.0;
		float eye_ctrl_translim_out   = 0.2;
		float eye_ctrl_translim_in    = 0.12;
		float eye_ctrl_translim_d     = 0.3;
		float eye_ctrl_translim_u     = 0.1;
		float eye_ctrl_neck_offset_ud = 0.0;
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

	static const std::unordered_map<int, int> SkinTone {
		{ 0, 0 },  //	Yellow, Light
		{ 1, 1 },  //	Yellow, Dark
		{ 7, 2 },  //	Yellow, Fair
		{ 3, 3 },  //	Pink, Fair
		{ 8, 4 },  //	Black, Fair
		{ 5, 5 },  //	Black, Dark
		{ 6, 6 },  //	Pink, Light
		{ 7, 7 },  //	White, Fair
		{ 0, 8 },  //	White, Light
		{ 4, 9 },  //	Brown, Fair
		{ 2, 10 }, //	Brown, Light
	};

	static const std::unordered_map<int, float> EyeRotBase {
		{ 0x02, 4.0 },
		{ 0x11, 4.0 },
		{ 0x01, 4.0 },
		{ 0x10, 4.0 },
		{ 0x0f, 4.0 },
		{ 0x1b, 4.0 },
		{ 0x14, 4.0 },
		{ 0x0b, 4.0 },
		{ 0x20, 4.0 },
		{ 0x09, 4.0 },
		{ 0x0c, 4.0 },
		{ 0x19, 4.0 },
		{ 0x05, 4.0 },
		{ 0x29, 4.0 },
		{ 0x24, 4.0 },
		{ 0x25, 4.0 },
		{ 0x06, 4.0 },
		{ 0x1e, 4.0 },
		{ 0x1f, 4.0 },
		{ 0x1c, 4.0 },
		{ 0x07, 4.0 },
		{ 0x2a, 4.0 },
		{ 0x03, 4.0 },
		{ 0x16, 4.0 },
		{ 0x0a, 4.0 },
		{ 0x35, 4.0 },
		{ 0x36, 4.0 },
		{ 0x3a, 4.0 },
		{ 0x39, 4.0 },
		{ 0x37, 4.0 },
		{ 0x34, 4.0 },
		{ 0x04, 3.0 },
		{ 0x00, 3.0 },
		{ 0x08, 3.0 },
		{ 0x27, 3.0 },
		{ 0x1a, 3.0 },
		{ 0x21, 3.0 },
		{ 0x13, 3.0 },
		{ 0x17, 3.0 },
		{ 0x22, 3.0 },
		{ 0x15, 3.0 },
		{ 0x28, 3.0 },
		{ 0x23, 3.0 },
		{ 0x0d, 3.0 },
		{ 0x18, 3.0 },
		{ 0x12, 3.0 },
		{ 0x2e, 3.0 },
		{ 0x2c, 3.0 },
		{ 0x26, 3.0 },
		{ 0x2d, 3.0 },
		{ 0x1d, 3.0 },
		{ 0x2b, 3.0 },
		{ 0x0e, 3.0 },
		{ 0x2f, 3.0 },
		{ 0x30, 3.0 },
		{ 0x31, 3.0 },
		{ 0x32, 3.0 },
		{ 0x3b, 3.0 },
		{ 0x38, 3.0 },
		{ 0x33, 3.0 },
	};

	static const std::unordered_map<int, float> EyebrowRotBase {
		{ 0x09, 7.0 },
		{ 0x07, 7.0 },
		{ 0x11, 7.0 },
		{ 0x05, 7.0 },
		{ 0x03, 7.0 },
		{ 0x16, 7.0 },
		{ 0x10, 7.0 },
		{ 0x0b, 8.0 },
		{ 0x06, 6.0 },
		{ 0x00, 6.0 },
		{ 0x01, 6.0 },
		{ 0x13, 6.0 },
		{ 0x15, 6.0 },
		{ 0x04, 6.0 },
		{ 0x0a, 6.0 },
		{ 0x0e, 6.0 },
		{ 0x0f, 6.0 },
		{ 0x12, 6.0 },
		{ 0x0c, 5.0 },
		{ 0x08, 5.0 },
		{ 0x02, 5.0 },
		{ 0x14, 5.0 },
		{ 0x0d, 5.0 },
		{ 0x17, 7.0 },
	};
};