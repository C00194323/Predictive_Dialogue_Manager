#pragma once
#include "GameObject.h"
#include "EventListener.h"
#include <vector>

class Menu
{
public:
	Menu(Renderer & r);
	~Menu();

	void Render(Renderer& r);

	int getPressedItem() { return selectedItem; }

	void onEvent(EventListener::Event evt);

	SDL_Texture* loadSurface(Renderer& r);

	void loadSurface(Renderer& r, int x, int y, int h, int w);

	void loadFont();

	void loadFont(int fontSize, int r, int g, int b);

	void generateFontSurface(Renderer& r, Point2D pos, std::string textToWrite);

	void MoveDown();

	void MoveUp();

	std::string path;

	void Update(unsigned int deltaTime);

	int selectedItem;

	void fix();

private:


	std::vector<TextureContainer> TextureVector;
	std::vector<TextureContainer> textContainer;
	SDL_Texture* img = NULL;
	SDL_Texture* textImg = NULL;
	TTF_Font* textFont = NULL;

	SDL_Color textCol = { 0,0,0 };

};

