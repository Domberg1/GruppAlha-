#include <iostream>
#include <string>

class Customer {
public:
	std::string firstName;
	std::string lastName;
	std::string password;
	std::string socialSecurity;
	unsigned int accountNumber;
	float balance;
};

Customer createCustomer(std::string socialSecurity);
