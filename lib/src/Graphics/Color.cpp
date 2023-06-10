#include <Engine/Graphics/Color.hpp>

namespace ng {

Color::Color(UInt8 r, UInt8 g, UInt8 b): r{r}, g{g}, b{b} {}

Color::Color(UInt8 r, UInt8 g, UInt8 b, UInt8 a): r{r}, g{g}, b{b}, a{a} {}

const Color Color::Red{255, 0, 0};

const Color Color::Green{0, 255, 0};

const Color Color::Blue{0, 0, 255};

const Color Color::Yellow{255, 255, 0};

const Color Color::Magenta{255, 0, 255};

const Color Color::Cyan{0, 255, 255};

const Color Color::White{255, 255, 255};

const Color Color::Black{0, 0, 0};

const Color Color::Transparent{0, 0, 0, 0};

}
