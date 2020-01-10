#pragma once

#include <string>

class User
{
	std::string userName;
	std::string password;

public:
	User();
	User(std::string, std::string);
};