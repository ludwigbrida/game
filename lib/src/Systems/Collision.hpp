#ifndef ENGINE_COLLISION_HPP
#define ENGINE_COLLISION_HPP

#include "Simplex.hpp"
#include <Engine/Components/Collider.hpp>
#include <Engine/Core/System.hpp>
#include <Engine/Maths/Matrix4.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace Engine {

class Collision: public System {
public:
	void run(NewRegistry& registry, State& state, const Clock& clock) override;

private:
	static bool gjk(
		const Collider& collider1,
		const Collider& collider2,
		const Matrix4<Float>& matrix1,
		const Matrix4<Float>& matrix2
	);

	static bool nextSimplex(Simplex& points, Vector3<Float>& direction);

	static bool line(Simplex& points, Vector3<Float>& direction);
	static bool triangle(Simplex& points, Vector3<Float>& direction);
	static bool tetrahedron(Simplex& points, Vector3<Float>& direction);

	static bool sameDirection(
		const Vector3<Float>& direction1,
		const Vector3<Float>& direction2
	);

	static Vector3<Float> supportPoint(
		const Collider& collider1,
		const Collider& collider2,
		const Matrix4<Float>& matrix1,
		const Matrix4<Float>& matrix2,
		Vector3<Float> direction
	);

	static Vector3<Float> furthestPoint(
		const Collider& collider,
		const Matrix4<Float>& matrix,
		Vector3<Float> direction
	);
};

}

#endif
