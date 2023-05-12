#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

class System {
public:
	virtual void run(class Registry& registry, float deltaTime) const = 0;
	virtual ~System() = default;
};

#endif
