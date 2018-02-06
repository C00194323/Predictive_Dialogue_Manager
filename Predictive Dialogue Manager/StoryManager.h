#pragma once
#include "Story.h"
#include "JSONReader.h"
class StoryManager
{
public:
	StoryManager() {};
	StoryManager(JSONReader*);
	~StoryManager();
};

