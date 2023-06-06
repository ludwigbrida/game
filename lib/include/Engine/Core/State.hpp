#ifndef ENGINE_STATE_HPP
#define ENGINE_STATE_HPP

#include <Engine/Core/Entity.hpp>
#include <Engine/Input/Keyboard.hpp>
#include <memory>

namespace ng {

struct State {
	Entity activeCamera;
	std::unique_ptr<Keyboard> keyboard;
};

}

#endif
