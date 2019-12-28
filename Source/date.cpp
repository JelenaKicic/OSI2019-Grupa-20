#include <iostream>
#include "../Include/date.h"

Date::Date()
{
    day = 1;
    month = 1;
    year = 2020;
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

void Date::printDate()
{
    std::cout << day << "/" << month << "/" << year << std::endl;
}

int Date::setDate(int day, int month, int year)
{
    if (year >= 2020 && month <= 12 && month > 0) {
        this->month = month;
        this->year = year;
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            if (day <= 31 && day > 0)
            {
                this->day = day;
                return 1;
            }



            else if (month == 4 || month == 6 || month == 9 || month == 11)
                if (day <= 30 && day > 0)
                {
                    this->day = day;
                    return 1;
                }

                else if (month == 2)
                    if (year % 4 == 0)
                        if (day <= 29 && day > 0)
                        {
                            this->day = day;
                            return 1;
                        }
                        else
                            if (day <= 28 && day > 0)
                            {
                                this->day = day;
                                return 1;
                            }
    }

    else
    {
        std::cout << "Unesite datum u buducnosti." << std::endl;
        return 0;
    }
}
int Date::getDay()
{
    return day;
}
int Date::getMonth()
{
    return month;
}
int Date::getYear()
{
    return year;
}
