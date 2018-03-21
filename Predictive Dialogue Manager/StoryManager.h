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
	void LoadJSON(EventListener* e);
	void PrintStory(SDL_Renderer* r, EventListener* e);
	void Render(SDL_Renderer* r);
	void Event(SDL_Renderer* renderer, bool & gameRunning, SDL_Event * gameEvent);

private:
	StoryDialogue dialogue;
	MenuSystem* Question;
	MenuSystem* Answers;
	string currentPath;
};

