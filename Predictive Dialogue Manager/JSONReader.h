#ifndef _JSONREADER_H
#define _JSONREADER_H

#pragma once
#include "JSON.h"
#include <fstream>
#include <iostream>
#include "Story.h"
#include <map>
#include <vector>

class JSONReader
{
public:
	JSONReader();
	JSONReader(std::string const & filename);
	~JSONReader();
	StoryDialogue Dialogue();
	std::vector<StoryAnswer> Answer(std::string question);
	StoryQuestionAndAnswers Question(int i);

private:
	JSONValue *m_value;
	std::string m_JSONData;
	JSONObject m_object;
	void loadJSONData(std::string const & filename);
};

#endif
