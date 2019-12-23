#pragma once
#include "date.h"
#include "location.h"
#include "time.h"
#include <string>

class Event
{
	std::string nameEvent;
	std::string descriptionEvent;
	Location location;
	std::string typeEvent;
	Date date;
	Time time;
};