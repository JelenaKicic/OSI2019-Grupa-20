#pragma once

#include <iostream>

class Date
{
private:
  int day;
  int month;
  int year;

public:
  Date();
  Date(int, int, int);

  void printDate();
  friend std::ostream &operator<<(std::ostream &, const Date &);

  int setDate(int, int, int);
  void setDateRead(int, int, int);

  int getDay();
  int getMonth();
  int getYear();
};
