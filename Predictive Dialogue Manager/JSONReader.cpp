#include "JSONReader.h"



JSONReader::JSONReader() {}

JSONReader::JSONReader(std::string const & filename)
{

	loadJSONData(filename);
	m_value = JSON::Parse(m_JSONData.c_str());
	if (NULL == m_value)
	{
		std::string s("Could not parse json in " + filename);
		throw std::exception(s.c_str());
	}
	m_object = m_value->AsObject();
}

JSONReader::~JSONReader() {
	//delete m_value;
}

void JSONReader::loadJSONData(std::string const & filename)
{
	m_JSONData.clear();
	std::ifstream myfile(filename);
	std::string line;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			m_JSONData.append(line);
		}
		myfile.close();
	}
	else
	{
		std::string errorMessage = "Could not open " + filename + " exiting!";
		std::cout << "Could not open " + filename + " exiting!" << std::endl;
		throw std::exception(errorMessage.c_str());
	}
}