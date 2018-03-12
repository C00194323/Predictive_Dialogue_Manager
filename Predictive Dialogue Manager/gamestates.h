#pragma once

class gameStates
{
public:
	enum states
	{
		MAINMENU,
		OPTIONSMENU,
		GAME,
		QUIT
	};

	bool transitioning = false;
	int currentState;
};