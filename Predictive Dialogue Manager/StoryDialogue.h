#pragma once
#include <iostream>
#include "SDL2\include\SDL.h"
#include <map>



class StoryQuestion
{
public:
	StoryQuestion();
	~StoryQuestion();

	std::map <std::string, StoryAnswer> completeQuestion;
	void question(std::string);
};

class StoryAnswer
{
public:
	StoryAnswer();
	~StoryAnswer();

	std::map<std::string,std::map<std::string,std::string>> completeAnswer;
};

class StoryDialogue
{
public:
	StoryDialogue();
	~StoryDialogue();
	std::map <std::string, StoryQuestion> completeDialogue;
};