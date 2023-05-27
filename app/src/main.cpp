#include "../../lib/src/core/app.hpp"
#include <Engine/Graphics/Color.hpp>
#include <Engine/Maths/Matrix4.hpp>
#include <Engine/Maths/Vector3.hpp>
#include <iostream>

int main() {
	// App app;
	// app.run();

	ng::UInt32 var{0};

	ng::Vector3f vector{1, 2, 3};
	ng::Vector3f right{ng::Vector3f::Right};

	ng::Vector3f result1 = ng::Vector3f::Right + ng::Vector3f::Right;
	ng::Vector3f result2 = ng::Vector3f::Up;

	ng::Float dotProduct = result1.dot(result2);
	ng::Vector3f crossProduct = result1.cross(result2);

	ng::Vector3f result = crossProduct;
	ng::Float length = crossProduct.length();
	ng::Vector3f normalized = crossProduct.normalized();

	ng::Color red{1, 0, 0};

	std::cout << result.x << " " << result.y << " " << result.z
						<< ", length: " << length << ", normalized: " << normalized.z
						<< std::endl;

	ng::Matrix4f matrix1{
		1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
	};
	ng::Matrix4f matrix2 = matrix1 * ng::Matrix4f::Identity;

	std::cout << "matrix2: " << matrix2.m00 << std::endl;
}
