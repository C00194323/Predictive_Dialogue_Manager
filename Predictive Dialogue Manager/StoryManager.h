#pragma once
#include "Story.h"
#include "JSONReader.h"
#include "EventListener.h"
#include <MenuComponentSystem.h>
using namespace std;

class StoryManager
{
public:
	StoryManager() ;
	~StoryManager() {};
	void LoadJSON(string language, SDL_Renderer* r);
	void PrintStory(SDL_Renderer* r);
	void Render(SDL_Renderer* r);
	void Event(SDL_Renderer* renderer, bool & gameRunning, SDL_Event * gameEvent);
	void onClick(string input, SDL_Renderer* renderer);

private:
	float timer;

	StoryDialogue dialogue;
	MenuSystem* Question;
	MenuSystem* Answers;
	string currentPath;
};

