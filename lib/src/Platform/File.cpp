#include "File.hpp"
#include <fstream>
#include <iostream>

namespace ng::File {

std::string Read(const std::string& path) {
	std::string content;
	std::ifstream file{path, std::ios::in};

	if (!file) {
		std::cerr << "Could not open file" << std::endl;
	}

	file.seekg(0, std::ios::end);
	content.resize(file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&content[0], content.size());
	file.close();

	return content;
}

}
