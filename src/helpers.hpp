#pragma once

#include <array>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
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

	std::string exec (const char* cmd);
}