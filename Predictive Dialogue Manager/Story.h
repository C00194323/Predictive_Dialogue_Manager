#pragma once
#include <iostream>
#include "SDL2\include\SDL.h"
#include <map>

class StoryQuestion
{
public:
	StoryQuestion() {};
	~StoryQuestion() {};


	void question(std::string tempquestion)
	{
		Question = tempquestion;
		std::cout << Question.c_str() << std::endl;
	}
	std::string Question;	
	

};

class StoryAnswer
{
public:
	StoryAnswer() {};
	~StoryAnswer() {};

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

	std::map<std::string, std::map<std::string, std::string>> completeAnswer;
};

class StoryDialogue
{
public:
	StoryDialogue() {};
	~StoryDialogue() {};
	StoryQuestion question;
	StoryAnswer answer;

	void addQuestion()
	{

	}
	void addAnswer()
	{

	}
	std::map <std::string, StoryQuestion> completeDialogue;
};