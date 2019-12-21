#pragma once
class Answer
{
	string Answer;
	bool corect;
};
class QuizQuestion
{
	string question;
	string descripcion;
	Answer answers[3];
};
class Quiz
{
	static string city;
	QuizQuestion** array;
};