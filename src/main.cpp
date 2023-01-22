#include "models/Vector.hpp"
#include <iostream>

int main() {
  auto vec1 = ng::Vector3f(1, 2, 3);
  auto vec2 = ng::Vector3f(3, 2, 1);
  auto dot = vec1.dot(vec2);
  auto length = vec1.length();

  std::cout << "Hello, World! " << dot << ", " << length << std::endl;
}
