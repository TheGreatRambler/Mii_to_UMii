#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <fmt/core.h>
#include <fstream>
#include <string>

#include "third_party/cxxopts.hpp"

#include "ksy_gen/kaitai/kaitaistream.h"

#include "ksy_gen/gen1_wii.h"
#include "ksy_gen/gen2_wiiu_3ds_miitomo.h"
#include "ksy_gen/gen3_studio.h"
#include "ksy_gen/gen3_switch.h"
#include "ksy_gen/gen3_switchgame.h"

#include "helpers.hpp"
#include "mii_info.hpp"

int main (int argc, char* argv[]) {
	cxxopts::Options commandLineOptions ("Mii_to_UMii", "Convert Mii files to UMii files for use with BoTW");

	// clang-format off
	commandLineOptions.add_options()
		("i,input", "Input file", cxxopts::value<std::string>())
		("o,output", "Output file", cxxopts::value<std::string>()->default_value(NULL))
		("t,type", "Input Mii type (wii/3ds/wiiu/miitomo/switch/switchgame/studio)", cxxopts::value<std::string>()->default_value("wii"))
		("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"))
		("h,help", "Print usage");
	// clang-format on

	auto commandLineResult = commandLineOptions.parse (argc, argv);

	if (commandLineResult.count ("help")) {
		puts (commandLineOptions.help ().c_str ());
		return 0;
	}

	std::string inputType = commandLineResult["type"].as<std::string> ();
	std::string inputFile = commandLineResult["input"].as<std::string> ();
	std::string outputFile;
	if (commandLineResult.count ("output")) {
		outputFile = commandLineResult["output"].as<std::string> ();
	} else {
		// Using the YML format, because string formats are easier to deal with
		outputFile = HELPERS::splitString (inputFile, '.')[0] + ".umii.yml";
	}

	std::ifstream is (inputFile, std::ifstream::binary);
	kaitai::kstream ks (&is);

	Mii::MiiInfo info;

	if (inputType == "3ds" || inputType == "wiiu" || inputType == "miitomo") {
		Kaitai::gen2_wiiu_3ds_miitomo_t data (&ks);
		info.creator       = data.creator_name ();
		info.body_height   = data.body_height ();
		info.body_weight   = data.body_weight ();
		info.shape_make    = data.face_makeup ();
		info.shape_wrinkle = data.face_wrinkles ();
		info.hair_type     = data.hair_type ();
		info.hair_flip     = data.hair_flip ();
		info.hair_color    = data.hair_color ();
		info.eye_type      = data.eye ();
		info.eyebrow_type  = data.eyebrow ();
		info.nose_type     = data.nose ();
		info.mouth_type    = data.mouth ();
		info.beard_type    = data.beard ();
		info.glass_type    = data.glasses ();
	} else if (inputType == "switch") {
		Kaitai::gen3_switch_t data (&ks);
		info.name          = data.mii_name ();
		info.hair_type     = data.hair_type ();
		info.body_type     = data.body_height ();
		info.hair_flip     = data.hair_flip ();
		info.body_weight   = data.body_weight ();
		info.hair_color    = data.hair_color ();
		info.eye_color     = data.eye_color ();
		info.eyebrow_color = data.eyebrow_color ();
		info.mouth_color   = data.mouth_color ();
		info.hair_color    = data.facial_hair_color ();
		info.glass_color   = data.glasses_color ();
		info.eye_type      = data.eye_type ();
		info.mouth_type    = data.mouth_type ();
		// Need to figure this out
		//info.eye_trans_v = data.eye_vertical();
		info.beard_mustache = data.facial_hair_mustache ();
		info.eyebrow_type   = data.eyebrow_type ();
		info.beard_type     = data.facial_hair_beard ();
		info.nose_type      = data.nose_type ();
		//info.mouth_scale = data.mouth_stretch();
		//info.eye_rotate = data.eye_rotation();
		info.glass_type = data.glasses_type ();
		//info.shape_make = data.face_type();
		info.personal_fav_color = data.favorite_color ();
		info.shape_wrinkle      = data.face_wrinkles ();
		// ????????
		info.personal_head_fav_color = data.face_color ();
		info.shape_make              = data.face_makeup ();
	} else if (inputType == "switchgame") {
		Kaitai::gen3_switchgame_t data (&ks);
		info.name          = data.mii_name ();
		info.hair_type     = data.hair_type ();
		info.body_type     = data.body_height ();
		info.hair_flip     = data.hair_flip ();
		info.body_weight   = data.body_weight ();
		info.hair_color    = data.hair_color ();
		info.eye_color     = data.eye_color ();
		info.eyebrow_color = data.eyebrow_color ();
		info.mouth_color   = data.mouth_color ();
		info.hair_color    = data.facial_hair_color ();
		info.glass_color   = data.glasses_color ();
		info.eye_type      = data.eye_type ();
		info.mouth_type    = data.mouth_type ();
		// Need to figure this out
		//info.eye_trans_v = data.eye_vertical();
		info.beard_mustache = data.facial_hair_mustache ();
		info.eyebrow_type   = data.eyebrow_type ();
		info.beard_type     = data.facial_hair_beard ();
		info.nose_type      = data.nose_type ();
		//info.mouth_scale = data.mouth_stretch();
		//info.eye_rotate = data.eye_rotation();
		info.glass_type = data.glasses_type ();
		//info.shape_make = data.face_type();
		info.personal_fav_color = data.favorite_color ();
		info.shape_wrinkle      = data.face_wrinkles ();
		// ????????
		info.personal_head_fav_color = data.face_color ();
		info.shape_make              = data.face_makeup ();
	} else if (inputType == "studio") {
		Kaitai::gen3_studio_t data (&ks);
		info.hair_type     = data.hair_type ();
		info.body_type     = data.body_height ();
		info.hair_flip     = data.hair_flip ();
		info.body_weight   = data.body_weight ();
		info.hair_color    = data.hair_color ();
		info.eye_color     = data.eye_color ();
		info.eyebrow_color = data.eyebrow_color ();
		info.mouth_color   = data.mouth_color ();
		info.hair_color    = data.facial_hair_color ();
		info.glass_color   = data.glasses_color ();
		info.eye_type      = data.eye_type ();
		info.mouth_type    = data.mouth_type ();
		// Need to figure this out
		//info.eye_trans_v = data.eye_vertical();
		info.eyebrow_type = data.eyebrow_type ();
		info.beard_color  = data.facial_hair_color ();
		info.beard_type   = data.beard_goatee ();
		info.nose_type    = data.nose_type ();
		//info.mouth_scale = data.mouth_stretch();
		//info.eye_rotate = data.eye_rotation();
		info.glass_type = data.glasses_type ();
		//info.shape_make = data.face_type();
		info.personal_fav_color = data.favorite_color ();
		info.shape_wrinkle      = data.face_wrinkles ();
		// ????????
		info.personal_head_fav_color = data.face_color ();
		info.shape_make              = data.face_makeup ();
	} else {
		// Wii
		Kaitai::gen1_wii_t data (&ks);
		info.name               = data.mii_name ();
		info.creator            = data.creator_name ();
		info.personal_fav_color = data.favorite_color ();
		info.body_height        = data.body_height ();
		info.body_weight        = data.body_weight ();
		// ???????
		info.body_type        = data.face_type ();
		info.shape_skin_color = data.face_color ();
		// ??????
		info.beard_type    = data.facial_feature ();
		info.hair_type     = data.hair_type ();
		info.hair_color    = data.hair_color ();
		info.hair_flip     = data.hair_flip ();
		info.eyebrow_type  = data.eyebrow_type ();
		info.eyebrow_color = data.eyebrow_color ();
		info.eye_type      = data.eye_type ();
		info.eye_color     = data.eye_color ();
		info.nose_type     = data.nose_type ();
		info.mouth_type    = data.mouth_type ();
		info.mouth_color   = data.mouth_color ();
		info.glass_type    = data.glasses_type ();
		info.glass_color   = data.glasses_color ();
		// ?????!!!
		info.beard_type = data.facial_hair_mustache ();
		// !!!!!!!!
		info.beard_type  = data.facial_hair_beard ();
		info.beard_color = data.facial_hair_color ();
	}

	// clang-format off
	std::string generatedUMii = fmt::format(
		"!io\n"
		"version: 0\n"
		"type: xml\n"
		"param_root: !list\n"
		"  objects:\n"
		"    ffsd: !obj {{no_use_ffsd: {}, type: {}}}\n"
		"    body: !obj\n"
		"      race: {}\n"
		"      type: {}\n"
		"      number: {}\n"
		"      weight: {}\n"
		"      height: {}\n"
		"    personal: !obj\n"
		"      sex_age: {}\n"
		"      fav_color: {}\n"
		"      sub_color_1: {}\n"
		"      sub_color_2: {}\n"
		"      head_fav_color: {}\n"
		"      shoulder_fav_color: {}\n"
		"      shoulder_sub_color_1: {}\n"
		"      personality: {}\n"
		"      voice_type: {}\n"
		"    common: !obj\n"
		"      backpack: {}\n"
		"      hat: {}\n"
		"      no_hat_always: {}\n"
		"      body_correct: {}\n"
		"      is_mid_age: {}\n"
		"      rot_cravicle: {}\n"
		"      rot_arm: {}\n"
		"      rot_leg: {}\n"
		"      rot_crotch: {}\n"
		"    shape: !obj\n"
		"      jaw: {}\n"
		"      wrinkle: {}\n"
		"      make: {}\n"
		"      trans_v: {}\n"
		"      scale: {}\n"
		"      skin_color: {}\n"
		"    hair: !obj {{type: {}, color: {}, flip: {}}}\n"
		"    eye: !obj\n"
		"      type: {}\n"
		"      color: {}\n"
		"      trans_v: {}\n"
		"      trans_u: {}\n"
		"      rotate: {}\n"
		"      scale: {}\n"
		"      aspect: {}\n"
		"      eyeball_trans_u: {}\n"
		"      eyeball_trans_v: {}\n"
		"      eyeball_scale: {}\n"
		"      highlight_bright: {}\n"
		"    eye_ctrl: !obj\n"
		"      base_offset: !vec3 [{}, {}, {}]\n"
		"      translim_out: {}\n"
		"      translim_in: {}\n"
		"      translim_d: {}\n"
		"      translim_u: {}\n"
		"      neck_offset_ud: {}\n"
		"    eyebrow: !obj\n"
		"      type: {}\n"
		"      color: {}\n"
		"      trans_v: {}\n"
		"      trans_u: {}\n"
		"      rotate: {}\n"
		"      scale: {}\n"
		"      aspect: {}\n"
		"    nose: !obj {{type: {}, trans_v: {}, scale: {}}}\n"
		"    mouth: !obj\n"
		"      type: {}\n"
		"      color: {}\n"
		"      trans_v: {}\n"
		"      scale: {}\n"
		"      aspect: {}\n"
		"    beard: !obj {{mustache: {}, scale: {}, type: {}, color: {}}}\n"
		"    glass: !obj {{type: {}, color: {}}}\n"
		"    korog: !obj {{mask: {}, skin_color: {}, left_plant: {}, right_plant: {}}}\n"
		"    goron: !obj {{skin_color: {}}}\n"
		"    gerudo: !obj\n"
		"      hair: {}\n"
		"      hair_color: {}\n"
		"      glass: {}\n"
		"      glass_color: {}\n"
		"      skin_color: {}\n"
		"      lip_color: {}\n"
		"    rito: !obj {{body_color: {}, hair_color: {}}}\n"
		"    zora: !obj {{body_color: {}}}\n"
		"  lists: {}\n",

		// Ffsd
		info.ffsd_no_use_ffsd,
		info.ffsd_type,
		// Body
		info.body_race,
		info.body_type,
		info.body_number,
		info.body_weight,
		info.body_height,
		// Personal
		info.personal_sex_age,
		info.personal_fav_color,
		info.personal_sub_color_1,
		info.personal_sub_color_2,
		info.personal_head_fav_color,
		info.personal_shoulder_fav_color,
		info.personal_shoulder_sub_color1,
		info.personal_personality,
		info.personal_voice_type,
		// Common
		info.common_backpack,
		info.common_hat,
		info.common_no_hat_always,
		info.common_body_correct,
		info.common_is_mid_age,
		info.common_rot_cravicle,
		info.common_rot_arm,
		info.common_rot_leg,
		info.common_rot_crotch,
		// Shape
		info.shape_jaw,
		info.shape_wrinkle,
		info.shape_make,
		info.shape_trans_v,
		info.shape_scale,
		info.shape_skin_color,
		// Hair
		info.hair_type,
		info.hair_color,
		info.hair_flip,
		// Eye
		info.eye_type,
		info.eye_color,
		info.eye_trans_v,
		info.eye_trans_u,
		info.eye_rotate,
		info.eye_scale,
		info.eye_aspect,
		info.eye_eyeball_trans_u,
		info.eye_eyeball_trans_v,
		info.eye_eyeball_scale,
		info.eye_highlight_bright,
		info.eye_ctrl_base_offset_x,
		info.eye_ctrl_base_offset_y,
		info.eye_ctrl_base_offset_z,
		info.eye_ctrl_translim_out,
		info.eye_ctrl_translim_in,
		info.eye_ctrl_translim_d,
		info.eye_ctrl_translim_u,
		info.eye_ctrl_neck_offset_ud,
		// Eyebrow
		info.eyebrow_type,
		info.eyebrow_color,
		info.eyebrow_trans_v,
		info.eyebrow_trans_u,
		info.eyebrow_rotate,
		info.eyebrow_scale,
		info.eyebrow_aspect,
		// Nose
		info.nose_type,
		info.nose_trans_v,
		info.nose_scale,
		// Mouth
		info.mouth_type,
		info.mouth_color,
		info.mouth_trans_v,
		info.mouth_scale,
		info.mouth_aspect,
		// Beard
		info.beard_mustache,
		info.beard_scale,
		info.beard_type,
		info.beard_color,
		// Glass
		info.glass_type,
		info.glass_color,
		// Korog
		info.korog_mask,
		info.korog_skin_color,
		info.korog_left_plant,
		info.korog_right_plant,
		// Goron
		info.goron_skin_color,
		// Gerudo
		info.gerudo_hair,
		info.gerudo_hair_color,
		info.gerudo_glass,
		info.gerudo_glass_color,
		info.gerudo_skin_color,
		info.gerudo_lip_color,
		// Rito
		info.rito_body_color,
		info.rito_hair_color,
		// Zora
		info.zora_body_color
	);
	// clang-format on

	std::ofstream outfile (outputFile);
	outfile.write (generatedUMii.c_str (), generatedUMii.size ());
	outfile.close ();

	return 0;
}