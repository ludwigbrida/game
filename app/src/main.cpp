#include "../../lib/src/core/app.hpp"
#include <Engine/UInt.hpp>
#include <Engine/maths/Vector3.hpp>

int main() {
	App app;
	app.run();

	ng::UInt var{0};

	ng::Vector3f vector{1, 2, 3};
	auto right = ng::Vector3f::Right;
}
