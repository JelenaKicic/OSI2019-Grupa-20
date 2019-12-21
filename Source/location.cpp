#include<iostream>
#include<string>
#include"location.h"



Location::Location() {
	city ="";
	adress = "";


	}


Location::Location(std::string c,std::string a) {
	city = c;
	adress = a;
	

	}



void Location::print_location() {
	cout << city << ", " << adress << endl;
	}




