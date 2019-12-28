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

  public:
	Event();
	Event(std::string name, std::string description, std::string city, std::string address, std::string type, int day, int month, int year, int hours, int minutes); 
	void setName(std::string);
	void setDescription(std::string);
	void setType(std::string);
	void setLocation(std::string, std::string);
	void setTime(int, int);
	void setDate(int, int, int);
	friend void geteventsByOrder(int, int, int);
	friend void checkOverviewCriteria(int, Event **);
	friend void sortEvents(int , int , Event **);
	int writeInFile(Event&);
};
void addEvent();

void eventOverviewCriteria();