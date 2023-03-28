//============================================================================
// Name        : Login.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "customer.h"


constexpr size_t bufferSize = 1024 * 1024;

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
			//login_success(loginAttempt.first, loginAttempt.second)
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



int main() {
	login();
	return 0;
}
