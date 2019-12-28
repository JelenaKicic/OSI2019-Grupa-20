#include "../Include/time.h"

Time::Time()
{
	hours = 0;
	minutes = 0;
}

Time::Time(int hour, int minute)
{
	this->hours = hour;
	this->minutes = minute;
}

std::ostream &operator<<(std::ostream &stream, const Time &time)
{
	return stream << time.hours << ':' << time.minutes;
}

void Time::setHours(int hours)
{
	if (hours == 24)
		hours = 0;

	if (hours < 24 && hours >= 0)
		this->hours = hours;
	else
		this->hours = 0;
}

void Time::setMinutes(int minutes)
{
	if (minutes < 60 && minutes >= 0)
		this->minutes = minutes;
	else
		this->minutes = 0;
}
int Time::getMinutes()
{
	return minutes;
}

int Time::getHours()
{
	return hours;
}