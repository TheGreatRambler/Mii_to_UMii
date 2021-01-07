#include "helpers.hpp"

std::vector<std::string> HELPERS::splitString (const std::string s, char delim) {
	std::vector<std::string> result;
	std::stringstream ss (s);
	std::string item;

	while (std::getline (ss, item, delim)) {
		result.push_back (item);
	}

	return result;
}

std::string HELPERS::joinString (std::vector<std::string> vec, std::string delimiter) {
	if (vec.size () != 0) {
		// https://stackoverflow.com/a/40052831
		// clang-format off
		return std::accumulate(std::next(vec.begin()), vec.end(),
			vec[0],
		[&delimiter](std::string& a, std::string& b) {
			return a + delimiter + b;
		});
		// clang-format on
	} else {
		return "";
	}
}

// https://stackoverflow.com/a/478960/9329945
std::string HELPERS::exec (const char* cmd) {
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype (&pclose)> pipe (popen (cmd, "r"), pclose);
	if (!pipe) {
		throw std::runtime_error ("popen() failed!");
	}
	while (fgets (buffer.data (), buffer.size (), pipe.get ()) != nullptr) {
		result += buffer.data ();
	}
	return result;
}

std::string HELPERS::bytesToHexString (unsigned char* info, unsigned int infoLength) {
	char* buffer;
	const char* pszNibbleToHex = { "0123456789ABCDEF" };
	int nNibble, i;
	if (infoLength > 0) {
		if (info != NULL) {
			buffer                   = (char*)malloc ((infoLength * 2) + 1);
			buffer[(infoLength * 2)] = 0;
			for (i = 0; i < infoLength; i++) {
				nNibble           = info[i] >> 4;
				buffer[2 * i]     = pszNibbleToHex[nNibble];
				nNibble           = info[i] & 0x0F;
				buffer[2 * i + 1] = pszNibbleToHex[nNibble];
			}

		} else {
			*buffer = NULL;
		}
	} else {
		*buffer = NULL;
	}

	if (buffer != NULL) {
		return std::string (buffer);
	} else {
		return "";
	}
}

std::string HELPERS::wstringToString (std::wstring string) {
	using convert_type = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> converter;
	return converter.to_bytes (string);
}