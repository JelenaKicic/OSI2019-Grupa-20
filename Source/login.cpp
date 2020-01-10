#include "../Include/login.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <conio.h>
bool isAdministrator = false;   

int login()
{
	
	std::string test1, test2, iName, inPass;
	std::string defName = "Username:";
	std::string defPass = "Password:";
	int pom1 = 0, pom2 = 0;
	std::ifstream file("./Database/user.txt");
	std::cout << "\nKorisnicko ime: ";
	getline(std::cin, iName);
	while (getline(file, test1, '|'))
	{
		std::string t;
		std::stringstream X(test1);
		getline(X, t, ' ');
		int a;
		a = t.compare(defName);
		if (a == 0)
		{
			getline(X, t, ' ');
			int b;
			b = t.compare(iName);
			if (b == 0)
			{
				pom1 += 1;
				break;
			}
		}
	}

	std::cout << "\nLozinka: ";
	int ch;
	while ((ch = getch()) != '\r')
	{
		if (ch == '\b')
		{
			if (inPass.size() > 0)
			{
				inPass.erase(inPass.size() - 1, 1);
				std::cout << "\b \b";
			}
		}
		else
		{
			inPass.push_back(ch);
			std::cout.put('*');
		}
	}
	getline(file, test2, '|');
	std::string k;
	std::stringstream Y(test2);
	getline(Y, k, ' ');
	int c;
	c = k.compare(defPass);
	if (c == 0)
	{
		getline(Y, k, ' ');
		int d;
		d = k.compare(inPass);
		if (d == 0)
			pom2 += 1;
	}

	if (pom1 == 1 && pom2 == 1)

	{
		isAdministrator = true;
		return 0;
	}
		
		
	
		
	else
		return 1;
}