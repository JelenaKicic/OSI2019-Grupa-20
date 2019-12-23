#include "Time.h"

Time::Time(int hour, int minute)
{
	this->hours = hour;
	this->minutes = minute;
}

std::ostream &operator<<(std::ostream &stream, const Time &time)
{
	return stream << time.hours << ':' << time.minutes;
}
