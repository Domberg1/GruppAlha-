#include "customer.h"
#include "Menu.h"

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
			std::cerr << "Password and Confirmed password must match." << std::endl;
			continue;
		}	else {
			//if they do match: hash the password and store all customer information
			std::hash<std::string> hasher;
			newCustomer.password = std::to_string(hasher(password));
			newCustomer.socialSecurity = socialSecurity;
			newCustomer.balance = 0;
			//fix account number
			//store social security number and hashed password in file
			std::ofstream file("users.txt", std::ios_base::app);
			file << newCustomer.socialSecurity << " " << newCustomer.password << "\n";
			file.close();
			//call first logged in page
			//customerPage(); //not yet created
		}
	}

	return newCustomer; //Save customer in file
}

void customerPage(std::string socialSecurity){
	Customer customer;
	int choice;
	customer.socialSecurity = socialSecurity;
	std::cout << "Welcome back "<< customer.socialSecurity << std::endl;
	std::cout << "What can we help you with today?\n" << std::endl;
	std::cout << "1. Balance" << std::endl;
	std::cout << "2. Transactions" << std::endl;
	std::cout << "3. Update customer info" << std::endl;
	std::cin >> choice;


	if (choice == 1){
		std::cout << "Current balance is: " << customer.balance << "SEK";

	}


}

//function to let customer create a new account
Customer signUp() {
	//necessary variables
	std::string socialSecurity;
	while (1) {
		//prompt customer for social security number
		std::cout << "Enter your social security number: " << std::endl;
		std::cin >> socialSecurity;
		//ask customer to re-enter if social security is already registered
		if (matchSocialSecurity(socialSecurity) == true) {
			std::cerr << "Social security already registered." << std::endl;
//			std::cerr << "Going back to start menu..." << "\n" << std::endl;
//			printMenu();
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
			return true;
		}
	}
	return false;
}
