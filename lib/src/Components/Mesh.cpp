#include <Engine/Components/Mesh.hpp>
#include <Engine/Graphics/Color.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace ng {

Mesh Mesh::createTriangle(Float size) {
	auto radius = size / 2;
	return Mesh{.vertices{
								// vertex 1
								0, radius, 0, // position
								0, 0, 1,			// normal
								1, 0, 0,			// color

								// vertex 2
								-radius, -radius, 0, // position
								0, 0, 1,						 // normal
								0, 1, 0,						 // color

								// vertex 3
								radius, -radius, 0, // position
								0, 0, 1,						// normal
								0, 0, 1,						// color
							},
							.indices{0, 1, 2}};
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
