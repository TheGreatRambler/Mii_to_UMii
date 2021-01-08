#pragma once

#include <array>
#include <cmath>
#include <codecvt>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <istream>
#include <locale>
#include <memory>
#include <numeric>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <unistd.h>
#include <vector>

namespace HELPERS {
	std::vector<std::string> splitString (const std::string s, char delim);
	std::string joinString (std::vector<std::string> strings, std::string delimiter);
	std::string bytesToHexString (unsigned char* info, unsigned int infoLength);

	std::string exec (const char* cmd);

	std::string wstringToString (std::wstring string);

	struct IMemBuf : std::streambuf {
		IMemBuf (uint8_t* base, size_t size) {
			char* p = (char*)base;
			this->setg (p, p, p + size);
		}
	};

	struct IMemStream : virtual IMemBuf, std::istream {
		IMemStream (uint8_t* mem, size_t size)
			: IMemBuf (mem, size)
			, std::istream (static_cast<std::streambuf*> (this)) {
			mem_ = mem;
		}
		~IMemStream () {
			free (mem_);
		}

	private:
		uint8_t* mem_;
	};
}