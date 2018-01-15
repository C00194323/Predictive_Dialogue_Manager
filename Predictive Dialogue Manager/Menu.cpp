#include "Menu.h"

Menu::Menu(Renderer & r){
	path = "Background.png";
	img = loadSurface(r);
	loadSurface(r, 0, 0, 800, 600);

	path = "button.png";
	img = loadSurface(r);
	loadSurface(r, 350, 200, 105, 60);

	path = "button.png";
	img = loadSurface(r);
	loadSurface(r, 350, 300, 100, 50);

	path = "button.png";
	img = loadSurface(r);
	loadSurface(r, 350, 400, 100, 50);

	loadFont(32, 255, 255, 255);
	generateFontSurface(r, Point2D(375, 210), "Play");
	generateFontSurface(r, Point2D(360, 300), "Options");
	generateFontSurface(r, Point2D(375, 400), "Quit");

	selectedItem = 1;
}

Menu::~Menu()
{
}


void Menu::MoveDown()
{
	if (selectedItem != 0 && selectedItem + 1 < 4)
	{
		TextureVector[selectedItem].rect->w = 100;
		TextureVector[selectedItem].rect->h = 50;
		textContainer[selectedItem - 1].rect->y = textContainer[selectedItem - 1].rect->y - 10;
		selectedItem++;
		textContainer[selectedItem - 1].rect->y = textContainer[selectedItem - 1].rect->y + 10;
		TextureVector[selectedItem].rect->w = 105;
		TextureVector[selectedItem].rect->h = 60;
	}
}

void Menu::MoveUp()
{

	if (selectedItem - 1 >= 1)
	{
		TextureVector[selectedItem].rect->w = 100;
		TextureVector[selectedItem].rect->h = 50;
		textContainer[selectedItem - 1].rect->y = textContainer[selectedItem - 1].rect->y - 10;
		selectedItem--;
		textContainer[selectedItem - 1].rect->y = textContainer[selectedItem - 1].rect->y + 10;
		TextureVector[selectedItem].rect->w = 105;
		TextureVector[selectedItem].rect->h = 60;
	}
}


void Menu::fix()
{
	int temp = 210;
	for (size_t i = 0; i < textContainer.size(); i++)
	{
		textContainer[i].rect->y = temp;
		temp += 95;
	}

	TextureVector[1].rect->w = 105;
	TextureVector[1].rect->h = 60;

	for (size_t i = 2; i < TextureVector.size(); i++)
	{
		TextureVector[i].rect->w = 100;
		TextureVector[i].rect->h = 50;
	}

}

void Menu::Render(Renderer &r)
{
	SDL_Rect* rect = new SDL_Rect{ 0,0,600,100 };
	for (size_t i = 0; i < TextureVector.size(); i++)
	{
		r.drawImage(TextureVector[i].texture, TextureVector[i].rect);
	}

	for (size_t i = 0; i < textContainer.size(); i++)
	{
		r.drawImage(textContainer[i].texture, textContainer[i].rect);
	}
}

void Menu::Update(unsigned int deltaTime)
{

}

void Menu::onEvent(EventListener::Event evt)
{
	//switch (evt)
	//{
	//case EventListener::DOWN:
	//	MoveDown();
	//	break;

	//case EventListener::UP:
	//	MoveUp();
	//	break;
	//}

}
////for loading only loading a texture and returning it
SDL_Texture * Menu::loadSurface(Renderer & r)
{
	SDL_Texture* optimizedSurface = NULL;
	SDL_Texture* loadedSurface = IMG_LoadTexture(r.getRenderer(), path.c_str());

	optimizedSurface = loadedSurface;
	return optimizedSurface;
}
////loads a texture with specified dimensions and position
void Menu::loadSurface(Renderer& r, int x, int y, int w, int h)
{
	TextureContainer textures;
	SDL_Rect* tempRect = new SDL_Rect{ x,y,w,h };
	SDL_Texture* loadedSurface = IMG_LoadTexture(r.getRenderer(), path.c_str());

	textures.texture = loadedSurface;
	textures.rect = tempRect;
	TextureVector.push_back(textures);
}
////loading a default font with colour and size
void Menu::loadFont()
{
	textFont = TTF_OpenFont("arial.ttf", 50);
	textCol.a = 255;
	textCol.b = 199;
	textCol.g = 160;
	textCol.r = 255;
}
//loading a font with colour and size
void Menu::loadFont(int fontSize, int r, int g, int b)
{
	textFont = TTF_OpenFont("arial.ttf", fontSize);
	textCol.a = 255;
	textCol.b = b;
	textCol.g = g;
	textCol.r = r;
}

////generates a texture with specified text
void Menu::generateFontSurface(Renderer & r, Point2D pos, std::string textToWrite)
{
	TextureContainer textures;
	std::string text = textToWrite;
	SDL_Texture* temp = NULL;
	SDL_Surface* tempSurf = NULL;
	tempSurf = TTF_RenderText_Solid(textFont, text.c_str(), textCol);

	temp = SDL_CreateTextureFromSurface(r.getRenderer(), tempSurf);
	textures.texture = temp;
	SDL_Rect* rectangle = new SDL_Rect{ (int)pos.x,(int)pos.y,(int)tempSurf->w, (int)tempSurf->h };
	textures.rect = rectangle;
	textContainer.push_back(textures);


}


