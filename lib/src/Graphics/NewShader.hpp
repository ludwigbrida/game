#ifndef ENGINE_NEW_SHADER_HPP
#define ENGINE_NEW_SHADER_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Maths/Matrix4.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace ng {

class NewShader {
public:
	NewShader(const char* vertexSource, const char* fragmentSource);

	void bind() const;
	void unbind() const;

	void upload(const char* name, const Vector3<Float>& value) const;
	void upload(const char* name, const Matrix4<Float>& value) const;

	~NewShader();

private:
	UInt32 programId;
};

}

#endif
