//============================================================================
// Name        : Login.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <unistd.h>
#include "customer.h"

void login(){
	int loginTries = 3;
	while(loginTries >= 0){
		if(loginTries == 0){
			std::cout << "Account login has failed too many times, locked for 15 minutes";
			sleep(60*15);
			loginTries = 3;
			continue;
		}

		std::string personnummer;
		std::string password;
		std::hash<std::string> passwordHasher;

		std::cout << "Enter personnummer: " << std::endl;
		std::cin >> personnummer;
		std::cout << "Enter password: " << std::endl;
		std::cin >> password;
		passwordHasher(password);

		if (matchPassword(personnummer, password) == true){
			break;

		}

		else
		{
			std::cout << "Wrong personnummer and/or password. Tries left: " << --loginTries << std::endl;
			continue;
		}

	}
	// Kör customer-page
}
