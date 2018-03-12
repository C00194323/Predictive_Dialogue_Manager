#include "StoryManager.h"

StoryManager::StoryManager()
{

	JSONReader jsonStory("FYP_Json.json");
	dialogue = jsonStory.Dialogue();
	Question = new MenuSystem;
	Answers = new MenuSystem;
	currentPath = "Q3";
}

void StoryManager::PrintStory(SDL_Renderer* r)
{
	StoryQuestionAndAnswers temp = dialogue.getQuestionAnswer(currentPath);
	std::map<string, vector<StoryAnswer>>::iterator iter;
	iter = temp.QuestionAndAnswer.begin();
	
	Question->SetUsingImages(false);  
	Question->AddText("arial.ttf", iter->first, SDL_Rect{ 550, 200, 100,50 }, false,r, true, SDL_Color{ 249, 39, 74, 0 }, SDL_Color{ 249, 39, 74, 0 });

	Answers->SetUsingImages(false);
	Answers->SetUpdateType("KEYBOARD", SDL_Color{ 255, 0, 255, 255 });
	for (int i = 0; i < iter->second.size(); i++)
	{
		Answers->AddText("arial.ttf", iter->second.at(i).answer, SDL_Rect{ 550, 350 + (i*64), 100,50 }, false, r, true, SDL_Color{ 66, 232, 244, 0 }, SDL_Color{ 66, 232, 244, 0 });
	}
	


}

void StoryManager::Render(SDL_Renderer* r)
{
	Question->Render(r);
	Answers->Render(r);
}

void StoryManager::Event(SDL_Renderer * renderer, bool & gameRunning, SDL_Event * gameEvent)
{
	if (gameEvent->type == SDL_QUIT)
	{
		gameRunning = false;
	}

	if (gameEvent->type == SDL_KEYDOWN)
	{
		if (gameEvent->key.keysym.sym == SDLK_RETURN || gameEvent->key.keysym.sym == SDLK_KP_ENTER)
		{
			//onClick(Answers->onClick());
		}
	}

	Answers->SystemUpdate(gameEvent, renderer);
}



