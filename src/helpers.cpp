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