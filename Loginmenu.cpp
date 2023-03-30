//============================================================================
// Name        : Login.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "Loginmenu.h"
#include "customer.h"
#include "Menu.h"

void login(){
	int loginTries = 3;
	while(loginTries >= 0){
		if(loginTries == 0){
			std::cerr << "Account login has failed too many times, locked for 5 seconds" << std::endl;
			--loginTries;
			if(loginTries == -1){
			loginTries = 3;
			}
			sleep(5);
			std::cout << "\n";
			printMenu();
			continue;
		}

		Customer login;

		std::string personnummer;
		std::string password;


		std::cout << "Enter personnummer: " << std::endl;
//		std::cin >> personnummer;
		std::cin >> login.socialSecurity;
		std::cout << "Enter password: " << std::endl;
		std::cin >> login.password;


		if (matchPassword(login.socialSecurity, login.password) == true){
			customerPage(login.socialSecurity);
			break;

		}

		else
		{
			std::cerr << "Wrong personnummer and/or password. Tries left: " << --loginTries << std::endl;
			continue;
		}


	}
	// Kör customer-page
}
