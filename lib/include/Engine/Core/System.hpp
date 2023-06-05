#ifndef ENGINE_SYSTEM_HPP
#define ENGINE_SYSTEM_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <type_traits>

namespace ng {

// TODO
class Registry;
class State;

class System {
public:
	virtual void setup();
	virtual void update(Registry& registry, State& state, Float deltaTime,
											Float elapsedTime) = 0;
	virtual ~System();
};

template <typename T>
concept IsSystem = std::is_base_of<System, T>::value;

}

#endif
