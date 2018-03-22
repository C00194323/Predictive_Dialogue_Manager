#include "StoryManager.h"

StoryManager::StoryManager()
{
	Question = new MenuSystem;
	Answers = new MenuSystem;

	Question->SetUsingImages(false);
	Answers->SetUsingImages(false);
	Answers->SetUpdateType("KEYBOARD", SDL_Color{ 255, 0, 255, 255 });

	timer = 0.5f;

	currentPath = "Q0";
}

void StoryManager::LoadJSON(EventListener* e)
{
	/*if (e->English == true)
	{
		JSONReader jsonStory("English.json");
		dialogue = jsonStory.Dialogue();
	}
	if (e->French == true)
	{
		JSONReader jsonStory("French.json");
		dialogue = jsonStory.Dialogue();
	}
	if (e->Spanish == true)
	{
		JSONReader jsonStory("Spanish.json");
		dialogue = jsonStory.Dialogue();  
	}*/
}

void StoryManager::LoadJSON(string language, SDL_Renderer* r)
{
	string filepath = language + ".json";

	JSONReader jsonStory(filepath);
	dialogue = jsonStory.Dialogue();
}

void StoryManager::PrintStory(SDL_Renderer* r)
{
	StoryQuestionAndAnswers temp = dialogue.getQuestionAnswer(currentPath);
	std::map<string, vector<StoryAnswer>>::iterator iter;
	iter = temp.QuestionAndAnswer.begin();

	Question->clear();
	Answers->clear();

	Question->AddText("arial.ttf", iter->first, SDL_Rect{ 550, 200, 100,50 }, false,r, true, SDL_Color{ 249, 39, 74, 0 }, SDL_Color{ 249, 39, 74, 0 });

	for (int i = 0; i < iter->second.size(); i++)
	{
		Answers->AddText("arial.ttf", iter->second.at(i).answer, SDL_Rect{ 550, 350 + (i * 64), 100,50 }, false, r, true, SDL_Color{ 66, 232, 244, 0 }, SDL_Color{ 66, 232, 244, 0 });	
	}
}



void StoryManager::Event(SDL_Renderer * renderer, bool & gameRunning, SDL_Event * gameEvent)
{
	if (timer <= 0.0f)
	{
		if (gameEvent->type == SDL_QUIT)
		{
			gameRunning = false;
		}

		if (gameEvent->type == SDL_KEYDOWN)
		{
			if (gameEvent->key.keysym.sym == SDLK_RETURN || gameEvent->key.keysym.sym == SDLK_KP_ENTER)
			{
				onClick(Answers->onClick(), renderer);
			}
		}
		Answers->SystemUpdate(gameEvent, renderer);
	}
	else
	{
		timer -= 1.0f / 60.0f;
	}
}

void StoryManager::Render(SDL_Renderer* r)
{
	Question->Render(r);
	Answers->Render(r);
}

void StoryManager::onClick(string input, SDL_Renderer* renderer)
{
	currentPath = dialogue.getQuestionAnswer(currentPath).getPath(input, currentPath);
	PrintStory(renderer);
}


