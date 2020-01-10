#pragma once

#include "./date.h"
#include "./location.h"
#include "./time.h"
#include "./login.h"
#include "./menu.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <vector>
#include <iomanip>

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
	void printEventLine();
	int writeInFile(Event &);
	int search(std::vector<Event> &, std::vector<Event> &, int);
	// void addEvent();

	friend void geteventsByOrder(int, int);
	friend void checkOverviewCriteria(int, std::vector<Event> &, std::vector<Event> &);
	friend void sortEvents(int, std::vector<Event> &);
	friend void sort(std::vector<Event> &, int (*cmp)(Event &, Event &));
	friend void deleteEvent(std::vector<Event> &, std::vector<Event> &, int);
	friend void printEvent(std::vector<Event> &, std::vector<Event> &, int);

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
void addEvent();

int compareType(Event &, Event &);
int compareType(Event &, Event &);
int compareTime(Event &, Event &);
void eventOverviewCriteria();
int stringToInt(std::string);