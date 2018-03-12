#pragma once
#include "Story.h"
#include "JSONReader.h"
#include <MenuComponentSystem.h>
using namespace std;

class StoryManager
{
public:
	StoryManager();
	~StoryManager() {};
	void PrintStory(SDL_Renderer* r);
	void Render(SDL_Renderer* r);
	void Event(SDL_Renderer* renderer, bool & gameRunning, SDL_Event * gameEvent);

private:
	StoryDialogue dialogue;
	MenuSystem* Question;
	MenuSystem* Answers;
	string currentPath;
};

