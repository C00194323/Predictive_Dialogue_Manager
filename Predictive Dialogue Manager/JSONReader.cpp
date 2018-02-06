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

StoryAnswer JSONReader::Answer()
{
	StoryAnswer completeAnswer;
	std::string dialogue("Story");
	std::wstring wDialogue;
	wDialogue.assign(dialogue.begin(), dialogue.end());
	JSONObject dialogueObject = m_object[wDialogue]->AsObject();

	for (int i = 0; i < dialogueObject.size(); i++)
	{
		std::string Question("Q" + std::to_string(i));
		std::wstring w_Question;
		w_Question.assign(Question.begin(), Question.end());
		JSONObject questionObject = dialogueObject[w_Question]->AsObject();

		std::string questionText("Question");
		std::wstring w_QuestionText;
		w_QuestionText.assign(questionText.begin(), questionText.end());
		std::string questionString(questionObject[w_QuestionText]->AsString().begin(), questionObject[w_QuestionText]->AsString().end());

		std::string answer("Answers");
		std::wstring w_Answer;
		w_Answer.assign(answer.begin(), answer.end());

		JSONObject answerObject = questionObject[w_Answer]->AsObject();

		for (int j = 0; j < answerObject.size(); j++)
		{
			// Answer
			std::string ans("Answer" + std::to_string(j));
			std::wstring w_ans;
			w_ans.assign(ans.begin(), ans.end());
			JSONObject ansObj = answerObject[w_ans]->AsObject();

			std::string ansText("text");
			std::wstring w_ansText;
			w_ansText.assign(ansText.begin(), ansText.end());
			std::string answerString(ansObj[w_ansText]->AsString().begin(), ansObj[w_ansText]->AsString().end());
			std::cout << "Answer : " + answerString << std::endl;

			// Path
			std::string Path("Path");
			std::wstring w_Path;
			w_Path.assign(Path.begin(), Path.end());
			std::string PathString(ansObj[w_Path]->AsString().begin(), ansObj[w_Path]->AsString().end());
			std::cout << "Path : " + PathString << std::endl;

			// Category
			std::string Category("Category");
			std::wstring w_Category;
			w_Category.assign(Category.begin(), Category.end());
			std::string CategoryString(ansObj[w_Category]->AsString().begin(), ansObj[w_Category]->AsString().end());
			std::cout << "Category : " + CategoryString << std::endl;

			completeAnswer.AnswerSet(answerString, PathString, CategoryString);
			
		}
	}
	return completeAnswer;
}

// Returns a Storyquestion object
StoryQuestion JSONReader::Question()
{
	StoryQuestion m_Storyquestion;
	std::string dialogue("Story");
	std::wstring wDialogue;
	wDialogue.assign(dialogue.begin(), dialogue.end());
	JSONObject dialogueObject = m_object[wDialogue]->AsObject();

	for (int i = 0; i < dialogueObject.size(); i++)
	{
		std::string Question("Q" + std::to_string(i));
		std::wstring w_Question;
		w_Question.assign(Question.begin(), Question.end());
		JSONObject questionObject = dialogueObject[w_Question]->AsObject();


		std::string questionText("Question");
		std::wstring w_QuestionText;
		w_QuestionText.assign(questionText.begin(), questionText.end());
		std::string questionString(questionObject[w_QuestionText]->AsString().begin(), questionObject[w_QuestionText]->AsString().end());
		m_Storyquestion.question(questionString);
	}
	return m_Storyquestion;
}

StoryDialogue JSONReader::Dialogue()
{
	StoryDialogue completeDialogue;
	std::string dialogue("Story");
	std::wstring wDialogue;
	wDialogue.assign(dialogue.begin(), dialogue.end());
	JSONObject dialogueObject = m_object[wDialogue]->AsObject();

	for (int i = 0; i < dialogueObject.size(); i++)
	{
		std::string Question("Q" + std::to_string(i));
		std::wstring w_Question;
		w_Question.assign(Question.begin(), Question.end());
		JSONObject questionObject = dialogueObject[w_Question]->AsObject();

		std::string questionText("Question");
		std::wstring w_QuestionText;
		w_QuestionText.assign(questionText.begin(), questionText.end());
		std::string questionString(questionObject[w_QuestionText]->AsString().begin(), questionObject[w_QuestionText]->AsString().end());

		std::string answer("Answers");
		std::wstring w_Answer;
		w_Answer.assign(answer.begin(), answer.end());

		JSONObject answerObject = questionObject[w_Answer]->AsObject();
	
		for (int j = 0; j < answerObject.size(); j++)
		{
			// Answer
			std::string ans("Answer" + std::to_string(j));
			std::wstring w_ans;
			w_ans.assign(ans.begin(), ans.end());
			JSONObject ansObj = answerObject[w_ans]->AsObject();

			std::string ansText("text");
			std::wstring w_ansText;
			w_ansText.assign(ansText.begin(), ansText.end());
			std::string answerString(ansObj[w_ansText]->AsString().begin(), ansObj[w_ansText]->AsString().end());
			std::cout <<"Answer : " + answerString << std::endl;
			
			// Path
			std::string Path("Path");
			std::wstring w_Path;
			w_Path.assign(Path.begin(), Path.end());
			std::string PathString(ansObj[w_Path]->AsString().begin(), ansObj[w_Path]->AsString().end());
			std::cout << "Path : " + PathString << std::endl;

			// Category
			std::string Category("Category");
			std::wstring w_Category;
			w_Category.assign(Category.begin(), Category.end());
			std::string CategoryString(ansObj[w_Category]->AsString().begin(), ansObj[w_Category]->AsString().end());
			std::cout << "Category : " + CategoryString << std::endl;
		}		
	}
	return completeDialogue;
}