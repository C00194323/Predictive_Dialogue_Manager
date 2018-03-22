#pragma once
#include <MenuComponentSystem.h>
#include "gamestates.h"
#include <string>
#include "TextureLoader.h"
#include "EventListener.h"

class Menu
{
public:
	Menu() { m_Menu = new MenuSystem; m_LanguageMenu = new MenuSystem; };
	~Menu() {};
	void Init(SDL_Renderer * renderer, TextureLoader* t);
	void Event(SDL_Renderer* renderer, gameStates::states & state, bool & gameRunning, SDL_Event * gameEvent, EventListener* e);
	void Render(SDL_Renderer* renderer, gameStates::states & state);
	void onClick(string input, gameStates::states & state,EventListener* eListener);
	int getSelected() { return selected; }

	string Language;

private:
	MenuSystem * m_Menu;
	MenuSystem * m_LanguageMenu;
	Sprite * m_background;
	SDL_Renderer* tempRenderer;
	SDL_Event* tempEvent;
	int selected;
};

