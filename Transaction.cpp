//============================================================================
// Name        : Transaction.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "Transaction.h"

// A struct that you use when you want to transfer money from one account to the others.
struct bankTransaction {
protected:
	std::string firstName;
	std::string lastName;
	double balance;
	int date;
	int toAccount;
	int fromAccount;
};

// A struct to use. When we want to compare a new member whit the current wan.
struct transactions: public bankTransaction{
protected:
	int personalNumber;
//	You can also you all in the "bankTransaction".
	};


void transactionsPage(){
	int choice;
	while(true){
		std::cout << "You transactions page, chose you mission four today. " << std::endl << std::endl;
		std::cout << "1. Add transaction. " << std::endl;
		std::cout << "2. View transaction. " << std::endl;
		std::cout << "3. Go back to your main profile. " << std::endl;
		std >> choice;

//		if (choice == 1){
//			run //*GA 17 add transaction*
//			break; // exit loop
//		}
//		else if (choice == 2){
//			run * GA-20 View transaction *
//			break; //exit loop 	}
//		else if (choice == 3){
//			run * GA-21 Go back option*
//			break; // exit loop		}
//		else {
//		std::cout << "Invalid choice. Please enter a valid number." << std::endl; }
	}
}
/
