#include "Sprite.h"

Sprite::Sprite(TextureLoader * t, SDL_Renderer* r)
{
	
	t->addTexture("ZombieAttack", "../Resources/Attack.png", r);

	SDL_SetRenderDrawColor(r, 0xFF, 0, 0, 0xFF);
	SDL_RenderClear(r);

	SpriteRect.x = 0;
	SpriteRect.y = 0;
	SpriteRect.w =512;
	SpriteRect.h =512;

	frameRect.x = 0;
	frameRect.y = 0;
	frameRect.w = 192;
	frameRect.h = 192;
}

void Sprite::Attack()
{
	texture = temp->getTexture("ZombieAttack");
	SpriteRect.x += 512;
	if (SpriteRect.y == 0 && SpriteRect.x >= 4092)
	{
		SpriteRect.x = 0;

	}
}
void Sprite::Render()
{
	
	SDL_RenderClear(r);
	SDL_RenderCopy(r, texture, &SpriteRect, &frameRect);
	SDL_RenderPresent(r);
}