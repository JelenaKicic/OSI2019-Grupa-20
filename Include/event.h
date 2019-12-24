#pragma once
#include "date.h"
#include "location.h"
#include "time.h"
#include <string>

class Event
{
  private:
	std::string nameEvent;
	std::string descriptionEvent;
	Location location;
	std::string typeEvent;
	Date date;
	Time time;

  public:
	friend void geteventsByOrder(int, int, int);
	friend void checkOverviewCriteria(int, Event **);
};

void eventOverviewCriteria();