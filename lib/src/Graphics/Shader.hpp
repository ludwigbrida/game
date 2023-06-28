#ifndef ENGINE_SHADER_HPP
#define ENGINE_SHADER_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Maths/Matrix4.hpp>
#include <Engine/Maths/Vector3.hpp>
#include <string>

namespace Engine {

class Shader {
public:
	explicit Shader(const std::string& path);
	Shader(const char* vertexSource, const char* fragmentSource);

	void compile(const char* vertexSource, const char* fragmentSource);

	void bind() const;
	void unbind() const;

	void use(const char* name, UInt32 value) const;
	void use(const char* name, const Vector3<Float>& value) const;
	void use(const char* name, const Matrix4<Float>& value) const;

	~Shader();

private:
	UInt32 programId;
};

}

#endif
