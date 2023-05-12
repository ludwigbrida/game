#include "color.hpp"

Color::Color() = default;

Color::Color(float r, float g, float b) : r(r), g(g), b(b) {}

Color Color::red = Color(1, 0, 0);

Color Color::green = Color(0, 1, 0);

Color Color::blue = Color(0, 0, 1);

Color Color::cyan = Color(0, 1, 1);

Color Color::magenta = Color(1, 0, 1);

Color Color::yellow = Color(1, 1, 0);

Color Color::white = Color(1, 1, 1);

Color Color::black = Color(0, 0, 0);
