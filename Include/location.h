#pragma once
#include <string>

class Location
{
  private:
	std::string city;
	std::string adress;

  public:
	Location();
	Location(std::string, std::string);
	void printLocation();
	void setCity(std::string);
	void setAddress(std::string);
	std::string getCity();
	std::string getAddress();
};