#ifndef _JSONREADER_H
#define _JSONREADER_H

#pragma once
#include "JSON.h"
#include <fstream>
#include <iostream>

class JSONReader
{
public:
	JSONReader();
	JSONReader(std::string const & filename);
	~JSONReader();
	void Dialogue();


private:
	JSONValue *m_value;
	std::string m_JSONData;
	JSONObject m_object;

	void loadJSONData(std::string const & filename);
};

#endif
