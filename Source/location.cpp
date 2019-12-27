#include "../Include/location.h"

#include <iostream>
#include <string>

Location::Location()
{
	city = "";
	adress = "";
}

Location::Location(std::string c, std::string a)
{
	city = c;
	adress = a;
}

void Location::print_location()
{
	std::cout << city << ", " << adress << std::endl;
}

void Location::setCity(std::string city)
{
	this->city = city;
}

void Location::setAddress(std::string adress)
{
	this->adress = adress;
}
std::string Location::getCity()
{
	return city;
}

std::string Location::getAddress()
{
	return adress;
}