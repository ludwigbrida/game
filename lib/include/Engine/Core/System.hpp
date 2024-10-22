#ifndef ENGINE_SYSTEM_HPP
#define ENGINE_SYSTEM_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Core/Clock.hpp>
#include <type_traits>

namespace Engine {

// TODO
class Registry;
class State;

struct System {
public:
	virtual void run(Registry& registry, State& state, const Clock& clock) = 0;
	virtual ~System();
};

template <typename T>
concept IsSystem = std::is_base_of<System, T>::value;

}

#endif
