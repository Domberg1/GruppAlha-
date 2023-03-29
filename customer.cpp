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
			std::hash<std::string> hasher;
			newCustomer.password = hasher(password);
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
	std::hash<std::string> hasher;
	std::string username, pass;
	std::ifstream file("users.txt");
	while (file >> username >> pass) {
		if (username == socialSecurity && pass == hasher(password)) {
			return true;
		}
	}
	return false;
}

void custeromerPage(std::string bankTransaction){
	int choicee;
	while (true){

	std::string  firstName, lastName, balance, fromAccount;

	std::cout << "This is menu of your account." << std::endl << std::endl;
	std::cout << "1. Update your name. " << std::endl;
	std::cout << "2. Change passport." << std::endl;
	std::cout << "3. Make a transactions." << std::endl;
	std::cout << "4. Log out." << std::endl;
	if (choicee == 1){
		//run // GA-15 Update name
		// break // exit loop
	}
//	else if (choice == 2){
	//			// run * GA -16 Chaning passport*
	//			break; // exit loop
	//		}
	//		else if (choice == 3){
	//			// run *GA - 10 Transetion.
	//			break; // exit loop
	//		}
	//		else if (choice == 4){
		//			// run *GA - 19 logout.
		//			break; // exit loop

//Make one more opption to make sore. You whant to log out. Make a new loop.
	//		else {
	//			std::cout << "Invalid choice. Please enter a valid number." << std::endl;
	//		}

	}
}
