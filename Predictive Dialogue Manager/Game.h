#pragma once
#include "SDL2\include\SDL.h"
#include "SDL2\include\SDL_image.h"
#include "SDL2\include\SDL_ttf.h"
#include "JSONReader.h"
#include "StoryManager.h"
#include "TextureLoader.h"
#include "gamestates.h"
#include "EventListener.h"
#include "InputManager.h"
#include "Menu.h"
#include <iostream>

using namespace std;

class Game
{
public:
	Game();
	~Game();
	void Run();
	void Event();

private:
	SDL_Window* window = nullptr;
	SDL_Renderer* gameRenderer = nullptr;
	SDL_Event m_event;

	Menu* menu;
	bool gameRunning;
	TextureLoader* m_textureLoader;

	EventListener * eventListener;
	InputHandler * input;
	gameStates::states m_state;
	MenuSystem* m_Menu;
	StoryManager story;
};

