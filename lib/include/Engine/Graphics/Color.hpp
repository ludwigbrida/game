#ifndef ENGINE_COLOR_HPP
#define ENGINE_COLOR_HPP

#include <Engine/Types/Scalar.hpp>

namespace ng {

class Color {
public:
	UInt8 r{};
	UInt8 g{};
	UInt8 b{};
	UInt8 a{255};

	Color(UInt8 r, UInt8 g, UInt8 b);
	Color(UInt8 r, UInt8 g, UInt8 b, UInt8 a);

	static const Color Red;
	static const Color Green;
	static const Color Blue;
	static const Color Yellow;
	static const Color Magenta;
	static const Color Cyan;
	static const Color White;
	static const Color Black;
	static const Color Transparent;
};

}

#endif
