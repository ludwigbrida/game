#ifndef ENGINE_TEXTURE_HPP
#define ENGINE_TEXTURE_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <string>

namespace Engine {

class Texture {
public:
	explicit Texture(const std::string& source);
	~Texture();

	void bind() const;
	void unbind() const;

private:
	UInt32 textureId;

	friend class Renderer;
};

}

#endif
