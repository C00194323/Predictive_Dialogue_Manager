#pragma once
#include <iostream>
#include "SDL2\include\SDL.h"
#include <map>
#include <vector>



class StoryAnswer
{
public:
	StoryAnswer() {};
	~StoryAnswer() {};

	StoryAnswer(std::string tempans, std::string temppath, std::string tempCategory)
	{
		answer = tempans;
		Path = temppath;
		Category = tempCategory;
	}

	void AnswerSet(std::string tempans, std::string temppath, std::string tempCategory)
	{
		answer = tempans;
		Path = temppath;
		Category = tempCategory;

		std::cout << answer.c_str() << std::endl;
		std::cout << Path.c_str() << std::endl;
		std::cout << Category.c_str() << std::endl;
		
	}

	std::string answer;
	std::string Path;
	std::string Category;

};

class StoryQuestionAndAnswers
{
public:
	StoryQuestionAndAnswers() {};
	~StoryQuestionAndAnswers() {};


	void question(std::string tempquestion)
	{
		Question = tempquestion;
		std::cout << Question.c_str() << std::endl;
	}

	void answer(std::string Q, std::vector<StoryAnswer> A)
	{
		QuestionAndAnswer[Q] = A;
	}

	std::string getPath(std::string A, std::string cp)
	{
		std::map <std::string, std::vector<StoryAnswer>>::iterator iter;
		for (iter = QuestionAndAnswer.begin(); iter != QuestionAndAnswer.end(); iter++)
		{
			for (int i = 0; i < iter->second.size(); i++)
			{
				StoryAnswer temp = iter->second.at(i);
				if (A == temp.answer)
				{
					return temp.Path;
				}
			}
		}

		return cp;
	}

	std::string Question;	
	std::map <std::string, std::vector<StoryAnswer>> QuestionAndAnswer;
};

class StoryDialogue
{
public:
	StoryDialogue() {};
	~StoryDialogue() {};

	void addStoryPath(std::string ID, StoryQuestionAndAnswers dialogue)
	{
		completeDialogue[ID] = dialogue;
	}

	StoryQuestionAndAnswers getQuestionAnswer(std::string ID)
	{
		return completeDialogue[ID];
	}

	std::map <std::string, StoryQuestionAndAnswers> completeDialogue;
};