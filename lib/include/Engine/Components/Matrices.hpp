#ifndef ENGINE_MATRICES_HPP
#define ENGINE_MATRICES_HPP

#include <Engine/Core/Component.hpp>
#include <Engine/Maths/Matrix4.hpp>

namespace ng {

struct Matrices : Component {
	Matrix4f local;
	Matrix4f world;
};

}

#endif