#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

class System {
public:
	virtual void setup() {}
	virtual void update(class Registry& registry, struct State& state,
											float deltaTime) = 0;
	virtual ~System() = default;
};

#endif