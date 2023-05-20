#ifndef GAME_COLOR_HPP
#define GAME_COLOR_HPP

struct Color {
	float r = 0;
	float g = 0;
	float b = 0;
	float a = 1;

	static const Color red;
	static const Color green;
	static const Color blue;
	static const Color cyan;
	static const Color magenta;
	static const Color yellow;
	static const Color white;
	static const Color black;
};

#endif
