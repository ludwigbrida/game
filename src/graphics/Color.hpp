#ifndef GAME_COLOR_HPP
#define GAME_COLOR_HPP

struct Color {
	float r = 0;
	float g = 0;
	float b = 0;
	float a = 1;

	static Color red;
	static Color green;
	static Color blue;
	static Color cyan;
	static Color magenta;
	static Color yellow;
	static Color white;
	static Color black;
};

#endif
