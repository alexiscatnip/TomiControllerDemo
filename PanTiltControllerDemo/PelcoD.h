#pragma once
#include <iostream>

class PelcoD
{
public:

	enum class PelcoDCommand { Up, Down, Left, Right, SetPreset, GoToPreset };
	enum class PelcoDSpeed { Slow, Mid, Fast, Max };
	static void getCommandBytes(PelcoDCommand cmd, PelcoDSpeed speed, char* message);
};

