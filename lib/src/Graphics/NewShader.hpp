#ifndef ENGINE_NEW_SHADER_HPP
#define ENGINE_NEW_SHADER_HPP

#include <Engine/Core/Arithmetic.hpp>

namespace ng {

class NewShader {
public:
	NewShader(const char* vertexSource, const char* fragmentSource);
	void bind() const;
	void unbind() const;
	~NewShader();

private:
	UInt32 programId;
};

}

#endif
