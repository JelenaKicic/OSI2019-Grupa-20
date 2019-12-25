#pragma once
class Answer
{
	std::string Answer;
	bool corect;
};
class QuizQuestion
{
	std::string question;
	std::string descripcion;
	Answer answers[3];
};
class Quiz
{
	static std::string city;
	QuizQuestion** array;
};