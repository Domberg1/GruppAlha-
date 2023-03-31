//============================================================================
// Name        : Login.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "Menu.h"
#include "customer.h"


void printMenu(){
	int choice;
	while (true) {
		std::cout << "What is your mission today?" << std::endl;
		std::cout << "1. Login in to your account. " << std::endl;
		std::cout << "2. Make an account on the bank." << std::endl;
		std::cout << "3. Check the stock exchange or exchange rates." << std::endl;
		std::cin >> choice;
		if (choice == 1){
			login();
			break;
		}
		else if (choice == 2){
			signUp();
			break;
		}
		else if (choice == 3){
			std::cerr << "Site is under construction" << std::endl;
			std::cerr << "Going back to start menu..." << "\n" << std::endl;
			printMenu();
			break;
		}
		else {
			std::cerr << "Invalid choice. Please enter a valid number." << "\n" << std::endl;
		}

	}
}

