#pragma once

#include "./date.h"
#include "./location.h"
#include "./time.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
// #include <conio.h>

class Event
{
  private:
	std::string name;
	std::string description;
	Location location;
	std::string type;
	Date date;
	Time time;
	std::vector<std::string> comments;

  public:
	Event();
	Event(std::string name, std::string description, std::string city, std::string address, std::string type, int day, int month, int year, int hours, int minutes);

	void setName(std::string);
	void setDescription(std::string);
	void setType(std::string);
	void setLocation(std::string, std::string);
	void setTime(int, int);
	void setDate(int, int, int);
	void setDateRead(int, int, int);
	void setComment(const std::string &);

	static int getNumberOfEvents(std::ifstream &);
	void printEvent();
	int writeInFile(Event &);
	void addEvent();

	friend void geteventsByOrder(int, int);
	friend int checkOverviewCriteria(int, Event **, Event **, int *);
	friend void sortEvents(int, Event **, int);
	friend void sort(Event **, int, int (*cmp)(Event *, Event *));

	std::string getName();
	std::string getDescription();
	std::string getType();
	std::string getCity();
	std::string getAddress();
	int getHours();
	int getMinutes();
	int getDay();
	int getMonth();
	int getYear();
};
// void addEvent();

void eventOverviewCriteria();