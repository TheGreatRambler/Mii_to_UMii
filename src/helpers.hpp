#pragma once

#include <array>
#include <cmath>
#include <codecvt>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <locale>
#include <memory>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <vector>

namespace HELPERS {
	std::vector<std::string> splitString (const std::string s, char delim);
	std::string joinString (std::vector<std::string> strings, std::string delimiter);
	std::string bytesToHexString (unsigned char* info, unsigned int infoLength);

	std::string exec (const char* cmd);

	std::string wstringToString (std::wstring string);
}