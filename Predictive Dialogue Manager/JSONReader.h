#ifndef _JSONREADER_H
#define _JSONREADER_H

#pragma once
#include "JSON.h"
#include <fstream>
#include <iostream>
#include "StoryDialogue.h"
#include <map>

class JSONReader
{
public:
	JSONReader();
	JSONReader(std::string const & filename);
	~JSONReader();
	StoryDialogue Dialogue();
	StoryAnswer Answer();
	StoryQuestion Question();

private:
	JSONValue *m_value;
	std::string m_JSONData;
	JSONObject m_object;
	std::map<std::map<std::string, std::string>, std::string> answerMap;
	void loadJSONData(std::string const & filename);
};

#endif
