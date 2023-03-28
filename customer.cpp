#include "customer.h"

//function to create a new customer and and add then to the user list
Customer createCustomer(std::string socialSecurity) {
	//necessary variables and objects
	std::string password = "";
	std::string newPassword = "temp";
	Customer newCustomer;
	//prompt to get customer name
	std::cout << "First name: ";
	std::cin >> newCustomer.firstName;
	std::cout << "Last name: ";
	std::cin >> newCustomer.lastName;
	//promt to let customer choose a password
	while (password != newPassword) {
		std::cout << "Choose a password: ";
		std::cin >> password;
		std::cout << "Confirm password: ";
		std::cin >> newPassword;
		//ask customer to re-enter password if chosen and confirmed password do not match
		if (password != newPassword) {
			std::cout << "Password and Confirmed password must match." << std::endl;
			continue;
		}	else {
			//if they do match: hash the password and store all customer information
			std::hash<std::string> hasher;
			newCustomer.password = std::to_string(hasher(password));
			newCustomer.socialSecurity = socialSecurity;
			newCustomer.balance = 0;
			//fix account number
			//store social security number and hashed password in file
			std::ofstream file("users.txt");
			file << newCustomer.socialSecurity << " " << newCustomer.password << "\n";
			file.close();
			//call first logged in page
			//customerPage(); //not yet created
		}
	}

	return newCustomer; //Save customer in file
}

//function to let customer create a new account
Customer signUp() {
	//necessary variables
	std::string socialSecurity;
	while (1) {
		//prompt customer for social security number
		std::cout << "Enter your social security number: ";
		std::cin >> socialSecurity;
		//ask customer to re-enter if social security is already registered
		if (matchSocialSecurity(socialSecurity) == true) {
			std::cout << "Social security already registered." << std::endl;
			continue;
		} else {
			//create a new customer if social security have not been registered before
			Customer newCustomer = createCustomer(socialSecurity);
			return newCustomer;
		}
	}
}

//fucntion to check if social security is registered
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

//fucntion to check if social security and password match
bool matchPassword(std::string socialSecurity, std::string password) {
	std::hash<std::string> hasher;
	std::string username, pass;
	std::ifstream file("users.txt");
	while (file >> username >> pass) {
		if (username == socialSecurity && pass == std::to_string(hasher(password))) {
			std::cout << pass;
			return true;
		}
	}
	return false;
}
