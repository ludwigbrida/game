#ifndef ENGINE_KEYBOARD2_HPP
#define ENGINE_KEYBOARD2_HPP

namespace ng {

class Keyboard2 {
public:
	enum Key { W, A, S, D };

	static bool isKeyPressed(Key key);
};

auto key = Keyboard2::A;

}

#endif
