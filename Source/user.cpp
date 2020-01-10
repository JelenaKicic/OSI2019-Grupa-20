#include "../Include/user.h"
#include <iostream>

User::User(std::string userName, std::string password)
{
	this->userName = userName;
	this->password = password;
}