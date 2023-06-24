#ifndef ENGINE_COMPONENT_HPP
#define ENGINE_COMPONENT_HPP

#include <type_traits>

namespace Engine {

struct Component {};

template <typename T>
concept IsComponent = std::is_base_of<Component, T>::value;

}

#endif
