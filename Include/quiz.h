#pragma once
#include <iostream>
#include <bits/stdc++.h>

class Answer
{
	std::string answer;
	bool correct;

  public:
	void setAnswer(std::string);
	void setCorrect(bool);

	std::string getAnswer();
	bool getCorrect();
};

class QuizQuestion
{
	std::string question;
	std::string descripcion;
	Answer answers[3];
	bool answered;

  public:
	void setQuestion(std::string);
	void setDescription(std::string);
	void setAnswer(std::string, bool, int);
	void setAnswered(bool);

	std::string getQuestion();
	std::string getDescription();
	std::string getAnswer(int);
	bool getCorrect(int);
	bool getAnswered();

	void printCorrect();
};

class Quiz
{
	std::string city;
	QuizQuestion array[10];

  public:
	void setCity(std::string);

	std::string getCity();

	friend void readQuizData(std::vector<Quiz> &quiz);

	void printQuestion(int);
	void printAll(int, int &);
	void answerQuestion(int);
};

void startQuiz();
bool convertToBool(std::string str);