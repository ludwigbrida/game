#include "../../lib/src/core/app.hpp"
#include <Engine/Graphics/Color.hpp>
#include <Engine/Maths/Vector3.hpp>
#include <iostream>

int main() {
	// App app;
	// app.run();

	ng::UInt32 var{0};

	ng::Vector3f vector{1, 2, 3};
	ng::Vector3f right{ng::Vector3f::Right};

	ng::Vector3f result1 = ng::Vector3f::Right + ng::Vector3f::Right;
	ng::Vector3f result2 = -result1;
	ng::Vector3f result = result2 += ng::Vector3f::Right;

	ng::Color red{1, 0, 0};

	std::cout << result.x << " " << result.y << " " << result.z << std::endl;
}
