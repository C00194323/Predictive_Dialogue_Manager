#pragma once

class gameStates
{
public:
	enum states
	{
		MAINMENU,
		OPTIONSMENU,
		Language,
		English,Spanish,French,
		GAME,
		LOAD,
		QUIT
	};

	bool transitioning = false;
	int currentState;
};