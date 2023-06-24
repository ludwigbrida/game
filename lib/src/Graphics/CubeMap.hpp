#ifndef ENGINE_CUBE_MAP_HPP
#define ENGINE_CUBE_MAP_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <string>
#include <vector>

namespace Engine {

class CubeMap {
public:
	explicit CubeMap(const std::vector<std::string>& textures);

private:
	UInt32 id{};
};

}

#endif
