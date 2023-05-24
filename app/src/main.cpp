#include "../../lib/src/core/app.hpp"
#include <Engine/Graphics/Color.hpp>
#include <Engine/Maths/Vector3.hpp>

int main() {
	App app;
	app.run();

	ng::UInt32 var{0};

	ng::Vector3f vector{1, 2, 3};
	ng::Vector3f right{ng::Vector3f::Right};

	ng::Vector3f result = ng::Vector3f::Forward + ng::Vector3f::Right;

	ng::Color red{1, 0, 0};
}
