#include <Engine/Components/Mesh.hpp>
#include <Engine/Graphics/Color.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace ng {

Mesh Mesh::createTriangle(Float size) {
	auto radius = size / 2;
	return {{}, {}};
	/*return {{{
						 Vector3f(0, radius, 0),
						 Vector3f::Backward,
						 Color::Red,
					 },
					 {
						 Vector3f(-radius, -radius, 0),
						 Vector3f::Backward,
						 Color::Green,
					 },
					 {
						 Vector3f(radius, -radius, 0),
						 Vector3f::Backward,
						 Color::Blue,
					 }},
					{0, 1, 2}};*/
}

}
