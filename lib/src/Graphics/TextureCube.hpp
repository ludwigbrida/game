#ifndef ENGINE_TEXTURE_CUBE_HPP
#define ENGINE_TEXTURE_CUBE_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <string>

namespace Engine {

class TextureCube {
public:
	explicit TextureCube(const std::string& path);
	~TextureCube();

	void bind() const;
	void unbind() const;

private:
	UInt32 textureId;

	friend class Renderer;
};

}

#endif
