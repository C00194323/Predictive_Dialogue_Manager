#pragma once

class EventListener
{
public:

	//list of possible events
	//add your own events here
	enum Event {
		PAUSE,
		QUIT,
		MOVERIGHT,
		MOVELEFT,
		STOPRIGHT,
		STOPLEFT,
		JUMPStart,
		JumpEnd,
		RECORD,
		JUMPHELD,
		JUMPRELEASED,
		RESTART,
		START,
		GAMEOVER,
		DOWN,
		UP,
		BOUNCESFX,
		SWITCHSFX,
		CHILLMUS,
		SELECT,
		BREAKMUS,
		LVLMUS,
		MUTEMUS,
		MUTESFX,
		FUEL
	};


	virtual void onEvent(Event) = 0;
};