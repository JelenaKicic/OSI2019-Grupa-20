#include <string>

class Location
{
private:
	std::string city;
	std::string adress;

public:
	Location();
	Location(std::string, std::string);
	void print_location();
	void setCity(std::string);
	void setAddress(std::string);
};