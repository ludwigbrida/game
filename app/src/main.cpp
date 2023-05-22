#include "../../lib/src/core/app.hpp"
#include <Engine/Maths/Vector3.hpp>
#include <Engine/UInt.hpp>

int main() {
	App app;
	app.run();

	ng::UInt var{0};

	ng::Vector3f vector{1, 2, 3};
	ng::Vector3f right{ng::Vector3f::Right};
}
