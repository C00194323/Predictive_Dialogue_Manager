#include "Game.h"

Game::Game()
{
	gameRunning = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		exit(0);
	}
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0)
	{
		printf("SDL_Image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		exit(0);
	}
	if (TTF_Init() < 0)
	{
		printf("SDL_Image could not initialize! SDL_TTF Error: %s\n", TTF_GetError());
		exit(0);
	}
	window = SDL_CreateWindow("Argo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);

	gameRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawBlendMode(gameRenderer, SDL_BLENDMODE_BLEND);

	m_textureLoader = TextureLoader::Instance();
	eventListener = new EventListener();

	menu = new Menu;
	menu->Init(gameRenderer, m_textureLoader);
	m_state = gameStates::states::MAINMENU;
}


Game::~Game() {}

void Game::Run()
{
	while (gameRunning)
	{
		if (m_state == gameStates::states::MAINMENU || m_state == gameStates::states::Language || m_state == gameStates::states::GAME)
		{
			Event();
		}
		SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 255);
		SDL_RenderClear(gameRenderer);
		if (m_state == gameStates::states::MAINMENU|| m_state == gameStates::states::Language)
		{
			menu->Render(gameRenderer, m_state);
		}

		if (m_state == gameStates::states::GAME)
		{
			story.Render(gameRenderer);
		}
		SDL_RenderPresent(gameRenderer);
	}
	
}


void Game::Event()
{
	SDL_Event pollevent;

	while (SDL_PollEvent(&pollevent))
	{
		if (m_state == gameStates::states::MAINMENU || m_state == gameStates::states::Language)
		{
			menu->Event(gameRenderer, m_state, gameRunning, &pollevent, eventListener);
		}

		if (m_state == gameStates::states::LOAD)
		{
			story.LoadJSON(menu->Language, gameRenderer);
			story.PrintStory(gameRenderer);
			m_state = gameStates::states::GAME;
		}

		if (m_state == gameStates::states::GAME)
		{
			story.Event(gameRenderer, gameRunning, &pollevent);
		}
	}
}
