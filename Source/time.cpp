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
	return stream << (time.hours / 10 == 0 ? "0" : "") << time.hours << ':' << (time.minutes / 10 == 0 ? "0" : "") << time.minutes;
}

int Time::getMinutes()
{
	return minutes;
}

int Time::getHours()
{
	return hours;
}
int Time::setHours(int hours)
{

	if (hours < 24 && hours >= 0)

	{
		this->hours = hours;
		return 1;
	}
	else if (hours == 24)
	{
		this->hours = 0;
		return 1;
	}
	else
	{
		this->hours = 0;
		return 0;
	}
}

int Time::setMinutes(int minutes)
{
	if (minutes < 60 && minutes >= 0)

	{

		this->minutes = minutes;
		return 1;
	}

	else
	{
		this->minutes = 0;
		return 0;
	}
}