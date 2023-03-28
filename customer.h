#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <chrono>
#include <unistd.h>

typedef struct Customer {
	std::string socialSecurity;
	std::string password;
	std::string firstName;
	std::string lastName;
	unsigned int accountNumber;
	float balance;
} Customer;

Customer createCustomer(std::string socialSecurity);
Customer signUp();
bool matchSocialSecurity(std::string socialSecurity);
bool matchPassword(std::string socialSecurity, std::string password);
