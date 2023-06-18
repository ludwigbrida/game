#ifndef GAME_TEXTURE_HPP
#define GAME_TEXTURE_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <string>

namespace ng {

class Texture {
public:
	explicit Texture(const std::string& source);

private:
	UInt32 id;
};

}

#endif
