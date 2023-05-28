#ifndef ENGINE_SYSTEM_HPP
#define ENGINE_SYSTEM_HPP

#include <type_traits>

namespace ng {

// TODO
class Registry;
class State;

struct System {
	virtual void setup();
	virtual void update(Registry& registry, State& state, float deltaTime) = 0;
	virtual ~System();
};

template <typename T>
concept IsSystem = std::is_base_of<System, T>::value;

}

#endif
