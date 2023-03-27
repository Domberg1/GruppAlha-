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

bool matchSocialSecurity(std::string socialSecurity) {
	//Loop through existing customers and see if socialSecurity has a match.
//	for (auto i : listOfSocialSecurity) {
//		if (socialSecurity == i) {
//			return true;
//		}
//	}
//	return false;
}

bool matchPassword(std::string socialSecurity, std::string password) {

	//Loop through existing customers and see if socialSecurity has a match.
//	for (auto i : listOfSocialSecurity) {
//		if (socialSecurity == i.socialSecurity) {
//			if (password == i.password) {
	//			return true;
	//		}
//		}
//	}
//	return false;
}
