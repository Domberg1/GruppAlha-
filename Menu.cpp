//============================================================================
// Name        : Login.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

void printMenu(){
	int choice;
	while (true) {
		std::cout << "What is your mission today?" << std::endl;
		std::cout << "1. Login in on you account. " << std::endl;
		std::cout << "2. Make an account on the bank." << std::endl;
		std::cout << "3. Check the stock exchange or exchange rates." << std::endl;
		std::cin >> choice;
		if (choice == 1){
			// run // *GA-5 Customer page*
			break; // exit loop
		}
		else if (choice == 2){
			// run * GA -4 Login menu*
			break; // exit loop
		}
		else if (choice == 3){
			// If wee makit sow far. Other nothing.
			break; // exit loop
		}
		else {
			std::cout << "Invalid choice. Please enter a valid number." << std::endl;
		}

	}
}

