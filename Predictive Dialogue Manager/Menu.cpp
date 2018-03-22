#include "Menu.h"

void Menu::Init(SDL_Renderer* renderer, TextureLoader* t)
{
	t->addTexture("MainMenu", "MenuBackground.jpg", renderer);

	//Set Default Language to English
	Language = "English";

	//Main Menu
	m_Menu->SetUsingImages(false);
	m_Menu->SetUpdateType("KEYBOARD", SDL_Color{ 255, 0, 255, 255 });
	m_Menu->AddText("arial.ttf", "Play", SDL_Rect{ 550, 200, 100,50 }, true, renderer, true, SDL_Color{ 0, 0, 0, 0 }, SDL_Color{ 249, 39, 74, 0 });
	m_Menu->AddText("arial.ttf", "Settings", SDL_Rect{ 550, 300, 100,50 }, true, renderer, true, SDL_Color{ 0, 0, 0, 0 }, SDL_Color{ 249, 39, 74, 0 });
	m_Menu->AddText("arial.ttf", "Quit", SDL_Rect{ 550, 400, 100,50 }, true, renderer, true, SDL_Color{ 0, 0, 0, 0 }, SDL_Color{ 249, 39, 74, 0 });

	m_LanguageMenu->SetUsingImages(false);
	m_LanguageMenu->SetUpdateType("KEYBOARD", SDL_Color{ 255, 0, 255, 255 });
	m_LanguageMenu->AddText("arial.ttf", "English", SDL_Rect{ 550, 200, 100,50 }, true, renderer, true, SDL_Color{ 0, 0, 0, 0 }, SDL_Color{ 249, 39, 74, 0 });
	m_LanguageMenu->AddText("arial.ttf", "French", SDL_Rect{ 550, 300, 100,50 }, true, renderer, true, SDL_Color{ 0, 0, 0, 0 }, SDL_Color{ 249, 39, 74, 0 });
	m_LanguageMenu->AddText("arial.ttf", "Spanish", SDL_Rect{ 550, 400, 100,50 }, true, renderer, true, SDL_Color{ 0, 0, 0, 0 }, SDL_Color{ 249, 39, 74, 0 });

	//background image
	m_background = new Sprite(t->getTexture("MainMenu"), SDL_Rect{ 0,0,1080,720 }, SDL_Rect{ 0,0,1080,720 });

	//Settings Menu
}

void Menu::Event(SDL_Renderer* renderer, gameStates::states & state,bool & gameRunning, SDL_Event * gameEvent, EventListener* e)
{
		if (gameEvent->type == SDL_QUIT)
		{
			gameRunning = false;
		}

		if (gameEvent->type == SDL_KEYDOWN)
		{
			if (gameEvent->key.keysym.sym == SDLK_RETURN || gameEvent->key.keysym.sym == SDLK_KP_ENTER)
			{
				if (state == gameStates::states::MAINMENU)
				{
					onClick(m_Menu->onClick(), state, e);
				}
				else if (state == gameStates::states::Language)
				{
					onClick(m_LanguageMenu->onClick(), state, e);
				}
			}
		}
		if (state == gameStates::states::MAINMENU)
		{
			m_Menu->SystemUpdate(gameEvent, renderer);
		}
		else if (state == gameStates::states::Language)
		{
			m_LanguageMenu->SystemUpdate(gameEvent, renderer);
		}
}

void Menu::Render(SDL_Renderer* renderer, gameStates::states & state)
{
	if (state == gameStates::states::MAINMENU)
	{
		m_background->Render(renderer);
		m_Menu->Render(renderer);
	}
	else if (state == gameStates::states::Language)
	{
		m_background->Render(renderer);
		m_LanguageMenu->Render(renderer);
	}
}

void Menu::onClick(string input, gameStates::states & state, EventListener* eListener)
{

	if (state == gameStates::states::MAINMENU)
	{
		if (input == "Options")
		{
			state = gameStates::states::OPTIONSMENU;
		}
		else if (input == "Play")
		{
			state = gameStates::states::Language;
		}
	}

	else if (state == gameStates::states::Language)
	{
		if (input == "English")
		{
			Language = input;
			state = gameStates::states::LOAD;
		}
		else if (input == "French")
		{
			Language = input;
			state = gameStates::states::LOAD;
		}
		else if (input == "Spanish")
		{
			Language = input;
			state = gameStates::states::LOAD;
		}
	}
}
