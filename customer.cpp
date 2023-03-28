#include "customer.h"

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
		   std::ofstream file("users.txt");
		   file << newCustomer.socialSecurity << " " << newCustomer.password << "\n";
		   file.close();
		}
	}

	return newCustomer; //Save customer in file
}

Customer signUp() {
	std::string socialSecurity;
	while (1) {
		std::cout << "Enter your social security number: ";
		std::cin >> socialSecurity;
		if (matchSocialSecurity(socialSecurity) == true) {
			std::cout << "Social security already registered." << std::endl;
			continue;
		} else {
			Customer newCustomer = createCustomer(socialSecurity);
			return newCustomer;
		}
	}
}

bool matchSocialSecurity(std::string socialSecurity) {
   std::string storedUsername, password;
   std::ifstream file("users.txt");
   while (file >> storedUsername >> password) {
      if (socialSecurity == storedUsername) {
         file.close();
         return true;
      }
   }
   file.close();
   return false;
}

bool matchPassword(std::string socialSecurity, std::string password) {
   std::string username, pass;
   std::ifstream file("users.txt");
   while (file >> username >> pass) {
      if (username == socialSecurity && pass == password) {
         return true;
      }
   }
   return false;
}
