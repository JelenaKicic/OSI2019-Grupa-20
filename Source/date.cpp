#include <iostream>
#include "date.h"

Date::Date()
{
    day = month = year = 0;
}
Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDate()
{

    return month, day, year;
}

void Date::print_date()
{
    cout << day << "/" << month << "/" << year << endl;
}