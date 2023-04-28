#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

class System {
public:
	virtual void run(const float& deltaTime) = 0;
};

#endif
