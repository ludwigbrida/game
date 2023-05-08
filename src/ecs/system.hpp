#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

class Registry;

class System {
public:
	virtual void run(Registry& registry, float deltaTime) = 0;
	virtual ~System() = default;
};

#endif
