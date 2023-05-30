#ifndef ENGINE_TRANSFORM_MATRIX_HPP
#define ENGINE_TRANSFORM_MATRIX_HPP

#include <Engine/Core/Component.hpp>
#include <Engine/Maths/Matrix4.hpp>

namespace ng {

struct TransformMatrix : Component {
	Matrix4f local;
	Matrix4f global;
};

}

#endif
