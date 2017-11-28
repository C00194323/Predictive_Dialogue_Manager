#pragma once

#pragma once
#define SDL_MAIN_HANDLED
#ifdef __APPLE__
#include "SDL2\include\SDL.h"
#elif defined(_WIN64) || defined(_WIN32)
#include "SDL2\include\SDL.h"
#endif


#include "BasicTypes.h"
#include "SDL2\include\SDL_image.h"
#include "SDL2\include\SDL_ttf.h"

// ------------------------------------------------------------------ 
//
// PLATFORM : ALL
// PRODUCT : RWM_1718_P1
// VISIBILITY : PUBLIC
//
// ------------------------------------------------------------------ 
// PURPOSE : Responsible for all drawing operations
// abstracts away specfic SDL specific drawing functions
class Renderer {

	// size of window in pixels
	Size2D windowSize;

	//position of window in world coordinates
	//change these if you want to zoom or pan

	Point2D viewportBottomLeft;
	Size2D viewportSize;
	SDL_Surface* renderSurface = NULL;

	SDL_Window *window;
	SDL_Renderer *sdl_renderer;

public:
	Renderer();
	bool init(const Size2D&, const char*);
	void drawRect(const Rect&, const Colour&);

	void drawImage(SDL_Texture* surface);
	void drawPortal(const Rect&, const Colour&);

	void drawImage(SDL_Texture* surface, SDL_Rect* textureRect);

	void drawRotateableImage(SDL_Texture* surface, double rotation, SDL_Point* origin, bool flip);
	void drawRotateableImage(SDL_Texture* surface, SDL_Rect* rect, double rotation, SDL_Point* origin, bool flip);

	SDL_Window* getWindow();

	void drawAnimation(SDL_Texture* surface, SDL_Rect* sRect, SDL_Rect* dRect);
	void drawWorldRect(const Rect&, const Colour&);
	void drawPortalRect(const Rect&, const Colour&);
	void present();
	void clear(const Colour&);
	Point2D worldToScreen(const Point2D&);
	Rect worldToScreen(const Rect&);
	SDL_Renderer* getRenderer();
	void setViewPort(const Rect&);

	void destroy();
	~Renderer();
};

