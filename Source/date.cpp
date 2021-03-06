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

std::ostream &operator<<(std::ostream &stream, const Date &date)
{
    return stream << date.day << "/" << date.month << "/" << date.year;
}

// void Date::printDate()
// {
//     std::cout << day << "/" << month << "/" << year << std::endl;
// }

int Date::setDate(int day, int month, int year)
{
    if (year >= 2020 && month <= 12 && month > 0 && day <= 31 && day > 0)
    {

        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {

            this->day = day;
            this->month = month;
            this->year = year;
            return 1;
        }

        if ((month == 4 || month == 6 || month == 9 || month == 11) && (day <= 30))

        {
            this->day = day;
            this->month = month;
            this->year = year;
            return 1;
        }

        if (month == 2 && day <= 28)

        {
            this->day = day;
            this->month = month;
            this->year = year;
            return 1;
        }

        if (month == 2 && day == 29 && year % 4 == 0)
        {
            this->day = day;
            this->month = month;
            this->year = year;
            return 1;
        }
        if (((month == 4 || month == 6 || month == 9 || month == 11) && (day == 31)) || (month == 2 && day >= 29))
        {
            std::cout << "Unesite datum u buducnosti." << std::endl;
            return 0;
        }
    }

    std::cout << "Unesite datum u buducnosti." << std::endl;
    return 0;
}

void Date::setDateRead(int day, int month, int year)
{

    this->day = day;

    this->month = month;

    this->year = year;
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
