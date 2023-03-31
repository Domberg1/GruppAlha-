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
