#ifndef GAME_CUBE_MAP_HPP
#define GAME_CUBE_MAP_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <string>
#include <vector>

namespace ng {

class CubeMap {
public:
	explicit CubeMap(const std::vector<std::string>& textures);

private:
	UInt32 id{};
};

}

#endif
