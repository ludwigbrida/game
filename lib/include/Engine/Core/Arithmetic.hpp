#ifndef ENGINE_ARITHMETIC_HPP
#define ENGINE_ARITHMETIC_HPP

#include <type_traits>

namespace ng {

using Int8 = char;

using Int16 = short;

using Int32 = int;

using Int64 = long long;

using UInt8 = unsigned char;

using UInt16 = unsigned short;

using UInt32 = unsigned int;

using UInt64 = unsigned long long;

using Float = float;

using Double = double;

template <typename T>
concept IsArithmetic = std::is_arithmetic<T>::value;

}

#endif
