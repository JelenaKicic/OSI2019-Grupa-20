#pragma once
#include <iostream>

class Time
{
  private:
	int hours;
	int minutes;

  public:
	Time();
	Time(int, int);
	friend std::ostream &operator<<(std::ostream &, const Time &);

	int setHours(int);
	int setMinutes(int);
	
	int getHours();
	int getMinutes();
};
