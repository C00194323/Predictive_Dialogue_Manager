#include "SDL2\include\SDL.h"
#include "SDL2\include\SDL_image.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Menu.h"
#include "JSONReader.h"
#include <iostream>

using namespace std;
#undef main
int main(int argc, char* argv[])
{

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	SDL_Window* window = SDL_CreateWindow("Predictive Dialogue Manager", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
	SDL_Texture *image = nullptr;

	Renderer renderer;

	/*Menu* mainMenu;
	mainMenu=new Menu(renderer);
	mainMenu->Render(renderer);*/

	JSONReader jsonStory("FYP_Json.json");
	jsonStory.Answer();

	

	bool isRunning = true;
	
	while (isRunning)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				isRunning = false;
			}
		}
	}
	SDL_Quit();
	return 0;
}