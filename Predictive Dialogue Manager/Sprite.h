#pragma once
#include "TextureLoader.h"
class Sprite
{
public:
	Sprite() {};
	Sprite(TextureLoader * t, SDL_Renderer* r);
	~Sprite() {};
	void Attack();
	void Render();
private:

	SDL_Rect SpriteRect;
	SDL_Rect frameRect;
	SDL_Renderer *r;
	SDL_Texture * texture;
	TextureLoader * temp;
};

