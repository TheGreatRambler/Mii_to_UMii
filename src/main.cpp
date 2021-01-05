#include <cstdint>
#include <cstdio>
#include <cstdlib>
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

int main (int argc, char* argv[]) {
	cxxopts::Options commandLineOptions ("Mii_to_UMii", "Convert Mii files to UMii files for use with BoTW");

	// clang-format off
	commandLineOptions.add_options()
		("i,input", "Input file", cxxopts::value<std::string>())
		("o,output", "Output file", cxxopts::value<std::string>())
		("t,type", "Input Mii type (wii/3ds/wiiu/miitomo/switch/switchgame/studio)", cxxopts::value<std::string>())
		("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"));
	// clang-format on

	auto commandLineResult = commandLineOptions.parse (argc, argv);

	std::string inputType = commandLineResult["type"].as<std::string> ();
	std::string inputFile = commandLineResult["input"].as<std::string> ();
	std::string outputFile;
	if (commandLineResult.count ("output")) {
		outputFile = commandLineResult["output"].as<std::string> ();
	} else {
		// Convert to the YML format, because string formats are easier to deal with
		outputFile = HELPERS::splitString (inputFile, '.')[0] + "umii.yml";
	}

	std::ifstream is (inputFile, std::ifstream::binary);
	kaitai::kstream ks (&is);

	if (inputType == "3ds" || inputType == "wiiu" || inputType == "miitomo") {
		Kaitai::gen2_wiiu_3ds_miitomo_t data (&ks);
	} else if (inputType == "switch") {
		Kaitai::gen3_switch_t data (&ks);
	} else if (inputType == "switchgame") {
		Kaitai::gen3_switchgame_t data (&ks);
	} else if (inputType == "studio") {
		Kaitai::gen3_studio_t data (&ks);
	} else {
		// Wii
		Kaitai::gen1_wii_t data (&ks);
	}
}