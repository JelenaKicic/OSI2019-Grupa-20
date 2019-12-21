#pragma once
#include <iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time(int, int);
	friend std::ostream& operator<<(std::ostream&, const Time&);


};

