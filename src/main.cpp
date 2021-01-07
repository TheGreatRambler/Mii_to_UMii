#define STB_IMAGE_IMPLEMENTATION

#include <ZXing/ReadBarcode.h>
#include <ZXing/TextUtfEncoding.h>
#include <cryptopp/aes.h>
#include <cryptopp/ccm.h>
#include <cryptopp/filters.h>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fstream>
#include <memory>
#include <stb_image.h>
#include <string>

#include "third_party/cxxopts.hpp"

#include "ksy_gen/kaitai/exceptions.h"
#include "ksy_gen/kaitai/kaitaistream.h"

// All generated from the KSY files here:
// https://github.com/RiiConnect24/mii2studio
#include "ksy_gen/gen1_wii.h"
#include "ksy_gen/gen2_wiiu_3ds_miitomo.h"
#include "ksy_gen/gen3_studio.h"
#include "ksy_gen/gen3_switch.h"
#include "ksy_gen/gen3_switchgame.h"

#include "helpers.hpp"
#include "mii_info.hpp"

static const std::string programVersion = "0.0.1";

std::string getStringifiedUmii (Mii::MiiInfo& info) {
	// clang-format off
	return fmt::format(
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
		"      rot_cravicle: {:.1f}\n"
		"      rot_arm: {:.1f}\n"
		"      rot_leg: {:.1f}\n"
		"      rot_crotch: {:.1f}\n"
		"    shape: !obj\n"
		"      jaw: {}\n"
		"      wrinkle: {}\n"
		"      make: {}\n"
		"      trans_v: {:.1f}\n"
		"      scale: {:.1f}\n"
		"      skin_color: {}\n"
		"    hair: !obj {{type: {}, color: {}, flip: {}}}\n"
		"    eye: !obj\n"
		"      type: {}\n"
		"      color: {}\n"
		"      trans_v: {:.1f}\n"
		"      trans_u: {:.1f}\n"
		"      rotate: {:.1f}\n"
		"      scale: {:.1f}\n"
		"      aspect: {:.1f}\n"
		"      eyeball_trans_u: {:.1f}\n"
		"      eyeball_trans_v: {:.1f}\n"
		"      eyeball_scale: {:.1f}\n"
		"      highlight_bright: {}\n"
		"    eye_ctrl: !obj\n"
		"      base_offset: !vec3 [{:.1f}, {:.2f}, {:.1f}]\n"
		"      translim_out: {:.1f}\n"
		"      translim_in: {:.2f}\n"
		"      translim_d: {:.1f}\n"
		"      translim_u: {:.1f}\n"
		"      neck_offset_ud: {:.1f}\n"
		"    eyebrow: !obj\n"
		"      type: {}\n"
		"      color: {}\n"
		"      trans_v: {:.1f}\n"
		"      trans_u: {:.1f}\n"
		"      rotate: {:.1f}\n"
		"      scale: {:.1f}\n"
		"      aspect: {:.1f}\n"
		"    nose: !obj {{type: {}, trans_v: {:.1f}, scale: {:.1f}}}\n"
		"    mouth: !obj\n"
		"      type: {}\n"
		"      color: {}\n"
		"      trans_v: {:.1f}\n"
		"      scale: {:.1f}\n"
		"      aspect: {:.1f}\n"
		"    beard: !obj {{mustache: {}, scale: {:.1f}, type: {}, color: {}}}\n"
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
		"  lists: {{}}",

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
}

int main (int argc, char* argv[]) {
	cxxopts::Options commandLineOptions ("Mii_to_UMii", "Convert Mii files to UMii files for use with BoTW");

	// clang-format off
	commandLineOptions.add_options()
		("i,input", "Input file", cxxopts::value<std::string>())
		("o,output", "Output file", cxxopts::value<std::string>())
		("t,type", "Input Mii type (wii/3ds/wiiu/miitomo/switch/switchgame/studio)", cxxopts::value<std::string>()->default_value("wii"))
		("x,verbose", "Verbose output")
		("b,binary", "Output binary file")
		("v,version", "Print verson")
		("h,help", "Print usage");
	// clang-format on

	auto commandLineResult = commandLineOptions.parse (argc, argv);

	bool isVerbose      = commandLineResult["verbose"].as<bool> ();
	bool outputAsBinary = commandLineResult["binary"].as<bool> ();

	if (commandLineResult.count ("help") || commandLineResult.arguments ().size () == 0) {
		puts (commandLineOptions.help ().c_str ());
		return 0;
	}

	if (commandLineResult.count ("version")) {
		puts (fmt::format ("MIITOUMII v{} copyright TheGreatRambler", programVersion).c_str ());
		return 0;
	}

	std::string inputType = commandLineResult["type"].as<std::string> ();
	std::string inputFile = commandLineResult["input"].as<std::string> ();
	std::string outputFile;
	std::filesystem::path inputPath (inputFile);
	if (commandLineResult.count ("output")) {
		outputFile = commandLineResult["output"].as<std::string> ();
	} else {
		outputFile = fmt::format ("{}{}", inputPath.stem ().string (), outputAsBinary ? ".bumii" : ".umii.yml");
	}

	if (!std::filesystem::exists (inputPath)) {
		// clang-format off
		puts (fmt::format (
			"| Input file {} does not exist, aborting",
		inputFile).c_str ());
		// clang-format on
		return 3;
	}

	if (isVerbose) {
		// clang-format off
		puts (fmt::format (
			"| MIITOUMII v{} copyright TheGreatRambler\n"
			"| Input type: {}\n"
			"| Input file: {}\n"
			"| Input file size: {}\n"
			"| Output file: {}",
		programVersion, inputType, inputFile, std::filesystem::file_size(inputPath), outputFile).c_str ());
		// clang-format on
	}

	std::ifstream* is;

	std::string inputFileExtension = std::filesystem::path (inputFile).extension ().string ();
	if (inputFileExtension == ".png" || inputFileExtension == ".jpg" || inputFileExtension == ".jpeg") {
		if (inputType == "3ds" || inputType == "wiiu" || inputType == "miitomo") {
			// Unsupported for now
			// puts ("| QR codes are unsupported for now");
			// return 0;

			ZXing::DecodeHints qrHints;
			qrHints.setFormats (ZXing::BarcodeFormat::QR_CODE);

			int width, height, channels;
			std::unique_ptr<stbi_uc, void (*) (void*)> buffer (stbi_load (inputFile.c_str (), &width, &height, &channels, 4), stbi_image_free);

			ZXing::Result result         = ZXing::ReadBarcode ({ buffer.get (), width, height, ZXing::ImageFormat::RGBX }, qrHints);
			ZXing::ByteArray bin         = result.metadata ().getByteArrayList (ZXing::ResultMetadata::BYTE_SEGMENTS).front ();
			ZXing::DecodeStatus qrStatus = result.status ();

			std::string qrCodeCountry = HELPERS::wstringToString (result.metadata ().getString (ZXing::ResultMetadata::POSSIBLE_COUNTRY));

			uint8_t* binPtr = bin.data ();

			if (isVerbose) {
				// clang-format off
				puts (fmt::format (
					"| QR size: {}\n"
					"| QR status: {}\n"
					"| QR country: {}\n"
					"| QR in hex:",
				bin.size(), ZXing::ToString(qrStatus), qrCodeCountry).c_str ());
				// clang-format on

				static const int charactersPerLine = 50;

				std::string hexString = HELPERS::bytesToHexString (bin.data (), bin.size ());
				size_t stringLength   = hexString.length ();
				for (int index = 0; index < stringLength; index += charactersPerLine) {
					bool atEnd = index + charactersPerLine > stringLength;
					// clang-format off
					puts (fmt::format (
						"     {}",
					hexString.substr(index, atEnd ? std::string::npos : charactersPerLine)).c_str ());
					// clang-format on
				}
			}

			static uint8_t aesKey[16] = {
				0x59,
				0xFC,
				0x81,
				0x7E,
				0x64,
				0x46,
				0xEA,
				0x61,
				0x90,
				0x34,
				0x7B,
				0x20,
				0xE9,
				0xBD,
				0xCE,
				0x52,
			};

			uint8_t nonce[8];
			memcpy (nonce, binPtr, sizeof (nonce));

			uint8_t nonceExtended[12];
			memcpy (nonceExtended, nonce, sizeof (nonce));
			memset (&nonceExtended[8], 0, 4);

			//AES_ctx ctx;
			//AES_init_ctx_iv (&ctx, aesKey, nonceExtended);
			//AES_CBC_decrypt_buffer (&ctx, &binPtr[8], 88);

			// populate key and iv with the correct values

			CryptoPP::CCM<CryptoPP::AES, 2>::Decryption d;
			d.SetKeyWithIV (aesKey, sizeof (aesKey), nonceExtended, sizeof (nonceExtended));
			d.SpecifyDataLengths (0, 86, 0);

			CryptoPP::ArraySource (&binPtr[8], 88, true,
				new CryptoPP::AuthenticatedDecryptionFilter (d, new CryptoPP::ArraySink (&binPtr[8], 88), CryptoPP::AuthenticatedDecryptionFilter::Flags::MAC_AT_END));

			std::string tempName = fmt::format ("{}.temp", inputFile);

			if (isVerbose) {
				// clang-format off
				puts (fmt::format (
					"| Temporary name: {}",
				tempName).c_str ());
				// clang-format on
			}

			uint8_t decodedMii[96];

			memcpy (decodedMii, &binPtr[8], 12);
			memcpy (&decodedMii[12], nonce, sizeof (nonce));
			memcpy (&decodedMii[20], &binPtr[20], 76);

			FILE* output = fopen (tempName.c_str (), "wb");
			fwrite (decodedMii, sizeof (decodedMii), 1, output);
			fclose (output);

			if (isVerbose) {
				// clang-format off
				puts (fmt::format (
					"| File size: {}\n"
					"| Decoded QR in hex:",
				sizeof(decodedMii)).c_str ());
				// clang-format on

				static const int charactersPerLine = 50;

				std::string hexString = HELPERS::bytesToHexString (decodedMii, sizeof (decodedMii));
				size_t stringLength   = hexString.length ();
				for (int index = 0; index < stringLength; index += charactersPerLine) {
					bool atEnd = index + charactersPerLine > stringLength;
					// clang-format off
					puts (fmt::format (
						"     {}",
					hexString.substr(index, atEnd ? std::string::npos : charactersPerLine)).c_str ());
					// clang-format on
				}
			}

			is = new std::ifstream (tempName, std::ifstream::binary);
		} else {
			puts ("| QR codes are only supported in the wiiu/wiiu/miitomo types");
			return -1;
		}
	} else {
		is = new std::ifstream (inputFile, std::ifstream::binary);
	}

	kaitai::kstream* ks;

	try {
		ks = new kaitai::kstream (is);
	} catch (kaitai::kstruct_error& e) {
		// clang-format off
		puts (fmt::format (
			"| Kaitai exception: {}",
		e.what()).c_str ());
		// clang-format on
	}

	Mii::MiiInfo info;

	if (inputType == "3ds" || inputType == "wiiu" || inputType == "miitomo") {
		Kaitai::gen2_wiiu_3ds_miitomo_t data (ks);
		info.name        = data.mii_name ();
		info.creator     = data.creator_name ();
		info.body_height = (int)(data.body_height () / 42.33);
		info.body_weight = (int)(data.body_weight () / 42.33);

		try {
			info.shape_skin_color = Mii::SkinTone.at (data.face_color ());
		} catch (std::out_of_range& e) {
			// clang-format off
			puts (fmt::format (
				"| Skin color is ill formed: {}",
			data.face_color ()).c_str ());
			// clang-format on
			if (isVerbose) {
				puts (fmt::format ("| UMii output so far: \n\n{}\n", getStringifiedUmii (info)).c_str ());
			}
			return 0;
		}

		info.shape_make       = data.face_makeup ();
		info.shape_wrinkle    = data.face_wrinkles ();
		info.hair_type        = data.hair_type ();
		info.hair_flip        = data.hair_flip ();
		info.hair_color       = data.hair_color ();
		info.eye_type         = data.eye_type ();
		info.eyebrow_type     = data.eyebrow_type ();
		info.nose_type        = data.nose_type ();
		info.mouth_type       = data.mouth_type ();
		info.beard_type       = data.facial_hair_beard ();
		info.glass_type       = data.glasses_type ();
		info.personal_sex_age = data.gender () == 0 ? 1 : 4;
		info.shape_jaw        = data.face_type ();

		try {
			info.eye_rotate = (float)data.eye_rotation () - Mii::EyeRotBase.at (info.eye_type);
		} catch (std::out_of_range& e) {
			// clang-format off
			puts (fmt::format (
				"| Eye type is ill formed: {}",
			info.eye_type).c_str ());
			// clang-format on
			if (isVerbose) {
				puts (fmt::format ("| UMii output so far: \n\n{}\n", getStringifiedUmii (info)).c_str ());
			}
			return 0;
		}

		try {
			info.eyebrow_rotate = (float)data.eyebrow_rotation () - Mii::EyebrowRotBase.at (info.eyebrow_type);
		} catch (std::out_of_range& e) {
			// clang-format off
			puts (fmt::format (
				"| Eyebrow type is ill formed: {}",
			info.eyebrow_type).c_str ());
			// clang-format on
			if (isVerbose) {
				puts (fmt::format ("| UMii output so far: \n\n{}\n", getStringifiedUmii (info)).c_str ());
			}
			return 0;
		}

		info.personal_personality = data.gender () == 0 ? "Man_Normal" : "Woman_Normal";
		info.personal_voice_type  = data.gender () == 0 ? "Hylia_Man_Young_Normal03" : "Hylia_Woman_Young_Normal04";
	} else if (inputType == "switch") {
		Kaitai::gen3_switch_t data (ks);
		info.name                 = data.mii_name ();
		info.hair_type            = data.hair_type ();
		info.body_height          = (int)(data.body_height () / 42.33);
		info.body_weight          = (int)(data.body_weight () / 42.33);
		info.hair_flip            = data.hair_flip ();
		info.hair_color           = data.hair_color ();
		info.eye_color            = data.eye_color ();
		info.eyebrow_color        = data.eyebrow_color ();
		info.mouth_color          = data.mouth_color ();
		info.hair_color           = data.facial_hair_color ();
		info.glass_color          = data.glasses_color ();
		info.eye_type             = data.eye_type ();
		info.mouth_type           = data.mouth_type ();
		info.eye_trans_v          = (float)data.eye_vertical ();
		info.beard_mustache       = data.facial_hair_mustache ();
		info.eyebrow_type         = data.eyebrow_type ();
		info.beard_type           = data.facial_hair_beard ();
		info.nose_type            = data.nose_type ();
		info.mouth_scale          = (float)data.mouth_stretch ();
		info.nose_trans_v         = (float)data.nose_vertical ();
		info.eyebrow_scale        = (float)data.eyebrow_stretch ();
		info.mouth_trans_v        = (float)data.mouth_vertical ();
		info.eye_rotate           = (float)data.eye_rotation ();
		info.eye_scale            = (float)data.eye_stretch ();
		info.eye_scale            = (float)data.eye_size ();
		info.glass_type           = data.glasses_type ();
		info.personal_fav_color   = data.favorite_color ();
		info.shape_wrinkle        = data.face_wrinkles ();
		info.shape_skin_color     = Mii::SkinTone.at (data.face_color ());
		info.eye_trans_u          = (float)data.eye_horizontal ();
		info.shape_make           = data.face_makeup ();
		info.eyebrow_scale        = (float)data.eyebrow_size ();
		info.eyebrow_trans_v      = (float)data.eyebrow_vertical () - 3.0;
		info.eyebrow_trans_u      = (float)data.eyebrow_horizontal ();
		info.mouth_scale          = (float)data.mouth_size ();
		info.nose_scale           = (float)data.nose_size ();
		info.beard_scale          = (float)data.facial_hair_size ();
		info.shape_jaw            = data.face_type ();
		info.eye_rotate           = (float)data.eye_rotation () - Mii::EyeRotBase.at (info.eye_type);
		info.eyebrow_rotate       = (float)data.eyebrow_rotation () - Mii::EyebrowRotBase.at (info.eyebrow_type);
		info.personal_personality = data.gender () == 0 ? "Man_Normal" : "Woman_Normal";
		info.personal_voice_type  = data.gender () == 0 ? "Hylia_Man_Young_Normal03" : "Hylia_Woman_Young_Normal04";
	} else if (inputType == "switchgame") {
		Kaitai::gen3_switchgame_t data (ks);
		info.name                 = data.mii_name ();
		info.personal_fav_color   = data.favorite_color ();
		info.personal_sex_age     = data.gender () == 0 ? 1 : 4;
		info.body_height          = (int)(data.body_height () / 42.33);
		info.body_weight          = (int)(data.body_weight () / 42.33);
		info.shape_skin_color     = Mii::SkinTone.at (data.face_color ());
		info.shape_wrinkle        = data.face_wrinkles ();
		info.shape_make           = data.face_makeup ();
		info.hair_type            = data.hair_type ();
		info.hair_flip            = data.hair_flip ();
		info.hair_color           = data.hair_color ();
		info.eye_color            = data.eye_color ();
		info.eyebrow_color        = data.eyebrow_color ();
		info.mouth_color          = data.mouth_color ();
		info.beard_color          = data.facial_hair_color ();
		info.glass_color          = data.glasses_color ();
		info.eye_type             = data.eye_type ();
		info.mouth_type           = data.mouth_type ();
		info.eye_scale            = (float)data.eye_size ();
		info.eye_aspect           = (float)data.eye_stretch ();
		info.eye_trans_u          = (float)data.eye_horizontal ();
		info.eye_trans_v          = (float)data.eye_vertical ();
		info.eyebrow_scale        = (float)data.eyebrow_size ();
		info.eyebrow_aspect       = (float)data.eyebrow_stretch ();
		info.eyebrow_trans_u      = (float)data.eyebrow_horizontal ();
		info.eyebrow_trans_v      = (float)data.eyebrow_vertical () - 3.0;
		info.nose_scale           = (float)data.nose_size ();
		info.nose_trans_v         = (float)data.nose_vertical ();
		info.mouth_scale          = (float)data.mouth_size ();
		info.mouth_aspect         = (float)data.mouth_stretch ();
		info.mouth_trans_v        = (float)data.mouth_vertical ();
		info.beard_scale          = (float)data.facial_hair_size ();
		info.beard_mustache       = data.facial_hair_mustache ();
		info.eyebrow_type         = data.eyebrow_type ();
		info.beard_type           = data.facial_hair_beard ();
		info.nose_type            = data.nose_type ();
		info.glass_type           = data.glasses_type ();
		info.personal_fav_color   = data.favorite_color ();
		info.shape_wrinkle        = data.face_wrinkles ();
		info.shape_make           = data.face_makeup ();
		info.shape_jaw            = data.face_type ();
		info.eye_rotate           = (float)data.eye_rotation () - Mii::EyeRotBase.at (info.eye_type);
		info.eyebrow_rotate       = (float)data.eyebrow_rotation () - Mii::EyebrowRotBase.at (info.eyebrow_type);
		info.personal_personality = data.gender () == 0 ? "Man_Normal" : "Woman_Normal";
		info.personal_voice_type  = data.gender () == 0 ? "Hylia_Man_Young_Normal03" : "Hylia_Woman_Young_Normal04";
	} else if (inputType == "studio") {
		Kaitai::gen3_studio_t data (ks);
		info.personal_fav_color   = data.favorite_color ();
		info.personal_sex_age     = data.gender () == 0 ? 1 : 4;
		info.body_height          = (int)(data.body_height () / 42.33);
		info.body_weight          = (int)(data.body_weight () / 42.33);
		info.shape_skin_color     = Mii::SkinTone.at (data.face_color ());
		info.shape_wrinkle        = data.face_wrinkles ();
		info.shape_make           = data.face_makeup ();
		info.hair_type            = data.hair_type ();
		info.hair_flip            = data.hair_flip ();
		info.hair_color           = data.hair_color ();
		info.eye_color            = data.eye_color ();
		info.eyebrow_color        = data.eyebrow_color ();
		info.mouth_color          = data.mouth_color ();
		info.beard_color          = data.facial_hair_color ();
		info.glass_color          = data.glasses_color ();
		info.eye_type             = data.eye_type ();
		info.mouth_type           = data.mouth_type ();
		info.eye_scale            = (float)data.eye_size ();
		info.eye_aspect           = (float)data.eye_stretch ();
		info.eye_trans_u          = (float)data.eye_horizontal ();
		info.eye_trans_v          = (float)data.eye_vertical ();
		info.eyebrow_scale        = (float)data.eyebrow_size ();
		info.eyebrow_aspect       = (float)data.eyebrow_stretch ();
		info.eyebrow_trans_u      = (float)data.eyebrow_horizontal ();
		info.eyebrow_trans_v      = (float)data.eyebrow_vertical () - 3.0;
		info.nose_scale           = (float)data.nose_size ();
		info.nose_trans_v         = (float)data.nose_vertical ();
		info.mouth_scale          = (float)data.mouth_size ();
		info.mouth_aspect         = (float)data.mouth_stretch ();
		info.mouth_trans_v        = (float)data.mouth_vertical ();
		info.beard_scale          = (float)data.beard_size ();
		info.beard_mustache       = data.beard_mustache ();
		info.eyebrow_type         = data.eyebrow_type ();
		info.beard_type           = data.beard_goatee ();
		info.nose_type            = data.nose_type ();
		info.glass_type           = data.glasses_type ();
		info.personal_fav_color   = data.favorite_color ();
		info.shape_wrinkle        = data.face_wrinkles ();
		info.shape_make           = data.face_makeup ();
		info.shape_jaw            = data.face_type ();
		info.eye_rotate           = (float)data.eye_rotation () - Mii::EyeRotBase.at (info.eye_type);
		info.eyebrow_rotate       = (float)data.eyebrow_rotation () - Mii::EyebrowRotBase.at (info.eyebrow_type);
		info.personal_personality = data.gender () == 0 ? "Man_Normal" : "Woman_Normal";
		info.personal_voice_type  = data.gender () == 0 ? "Hylia_Man_Young_Normal03" : "Hylia_Woman_Young_Normal04";
	} else {
		// Wii
		Kaitai::gen1_wii_t data (ks);
		info.name                 = data.mii_name ();
		info.creator              = data.creator_name ();
		info.personal_sex_age     = data.gender () == 0 ? 1 : 4;
		info.creator              = data.creator_name ();
		info.personal_fav_color   = data.favorite_color ();
		info.body_height          = (int)(data.body_height () / 42.33);
		info.body_weight          = (int)(data.body_weight () / 42.33);
		info.shape_skin_color     = Mii::SkinTone.at (data.face_color ());
		info.beard_type           = data.facial_feature ();
		info.hair_type            = data.hair_type ();
		info.hair_color           = data.hair_color ();
		info.hair_flip            = data.hair_flip ();
		info.eyebrow_type         = data.eyebrow_type ();
		info.eyebrow_color        = data.eyebrow_color ();
		info.eye_type             = data.eye_type ();
		info.eye_color            = data.eye_color ();
		info.nose_type            = data.nose_type ();
		info.mouth_type           = data.mouth_type ();
		info.mouth_color          = data.mouth_color ();
		info.glass_type           = data.glasses_type ();
		info.glass_color          = data.glasses_color ();
		info.eyebrow_trans_v      = (float)data.eyebrow_vertical () - 3.0;
		info.eyebrow_scale        = (float)data.eyebrow_size ();
		info.eyebrow_trans_u      = (float)data.eyebrow_horizontal ();
		info.eye_trans_v          = (float)data.eye_vertical ();
		info.eye_scale            = (float)data.eye_size ();
		info.eye_trans_u          = (float)data.eye_horizontal ();
		info.nose_scale           = (float)data.nose_size ();
		info.nose_trans_v         = (float)data.nose_vertical ();
		info.mouth_scale          = (float)data.mouth_size ();
		info.mouth_trans_v        = (float)data.mouth_vertical ();
		info.beard_mustache       = data.facial_hair_mustache ();
		info.beard_type           = data.facial_hair_beard ();
		info.beard_color          = data.facial_hair_color ();
		info.beard_scale          = (float)data.facial_hair_size ();
		info.shape_jaw            = data.face_type ();
		info.eye_rotate           = (float)data.eye_rotation () - Mii::EyeRotBase.at (info.eye_type);
		info.eyebrow_rotate       = (float)data.eyebrow_rotation () - Mii::EyebrowRotBase.at (info.eyebrow_type);
		info.personal_personality = data.gender () == 0 ? "Man_Normal" : "Woman_Normal";
		info.personal_voice_type  = data.gender () == 0 ? "Hylia_Man_Young_Normal03" : "Hylia_Woman_Young_Normal04";
	}

	delete ks;
	delete is;

	std::string generatedUmii = getStringifiedUmii (info);

	if (isVerbose) {
		puts (fmt::format ("| UMii output: \n\n{}\n", generatedUmii).c_str ());
	}

	std::ofstream outfile (outputFile);

	if (!outfile.is_open ()) {
		puts (fmt::format ("Output file {} did not open\n", outputFile).c_str ());
	}

	outfile.write (generatedUmii.c_str (), generatedUmii.size ());
	outfile.close ();

	if (outputAsBinary) {
		std::string commandLine = fmt::format ("yml_to_aamp {} {}", outputFile, outputFile);

		if (isVerbose) {
			puts ("| Generating UMii as Binary AAMP");
			puts (fmt::format ("| {}", commandLine).c_str ());
		}

		HELPERS::exec (commandLine.c_str ());
	}

	return 0;
}