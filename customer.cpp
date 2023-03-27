#include "test.h"

Customer createCustomer(std::string socialSecurity) {
	std::string password = "";
	std::string newPassword = "temp";
	Customer newCustomer;
	std::cout << "First name: ";
	std::cin >> newCustomer.firstName;
	std::cout << "Last name: ";
	std::cin >> newCustomer.lastName;
	while (password != newPassword) {
		std::cout << "Password: ";
		std::cin >> password;
		std::cout << "Confirm password: ";
		std::cin >> newPassword;

		if (password != newPassword) {
			std::cout << "Password and Confirmed password must match." << std::endl;
			continue;
		}	else {
			newCustomer.password = password; //need to be hashed
			newCustomer.socialSecurity = socialSecurity;
			newCustomer.balance = 0;
			//fix account number
			//customerPage(); //not yet created
		}
	}

	return newCustomer; //Save customer in file
}
