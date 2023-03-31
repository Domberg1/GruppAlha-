#include "customer.h"
#include "Menu.h"
#include <thread>



void timer(){
	int counter = 5;
	while (counter != 0)
	{
		counter--;
		sleep(1);
		if (counter == 0){
			std::cerr << "Logging out due to inactivity" << std::endl;

			printMenu();
		}
	}
}
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
			file << newCustomer.socialSecurity << " " << newCustomer.password << " " << newCustomer.firstName << " " << newCustomer.lastName << " " << newCustomer.balance << "\n";
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
	std::string line;
	//	std::thread myThread(timer);
	std::ifstream file("users.txt", std::ios_base::app);
	// Read line and put input into customer.
	while(getline(file, line)){
		std::stringstream ss(line); // Convert the line to a stringstream
		getline(ss, customer.socialSecurity, ' '); // Extract the first variable separated by comma
		if(customer.socialSecurity == socialSecurity){

			std::string balance;
			getline(ss, customer.password, ' '); // Extract the second variable separated by comma
			getline(ss, customer.firstName, ' '); // Extract the second variable separated by comma
			getline(ss, customer.lastName, ' '); // Extract the third variable without any separator
			getline(ss, balance); // Extract the third variable without any separator
			customer.balance = stof(balance);


			file.close();
			break;
		}


	}


	//	customer.socialSecurity = socialSecurity;
	std::cout << "Welcome back "<< customer.firstName << std::endl;
	jump:
	std::cout << "What can we help you with today?\n" << std::endl;
	std::cout << "1. Balance" << std::endl;
	std::cout << "2. Transactions" << std::endl;
	std::cout << "3. Update customer info" << std::endl;
	std::cin >> choice;




	if (choice == 1){
		//		std::thread myThread(timer);
		std::cout << "Current balance is: " << customer.balance << "SEK" << std::endl;
		char alternative;
		std::cout << "Press y to return to customer page or n to logout" << std::endl;
		std::cin >> alternative;
		if (alternative == 'y'){
			goto jump;
		}
		else if (alternative == 'n')
		{
			printMenu();
		}
	}
	else if (choice == 2){
		double amount;
		std::string line2;
		std::string depositFirst, depositSecond;
		Customer customer2;
		jump2:
		std::cout << "To which account would you like to make a transaction? enter customer first and last name, separate with ENTER" << std::endl;
		std::cin >> depositFirst;
		std::cin >> depositSecond;
		std::ifstream file2("users.txt", std::ios_base::app);

		// Read line and put input into customer.
		while(getline(file2, line2)){
			std::stringstream ss2(line2); // Convert the line to a stringstream
			getline(ss2, customer2.socialSecurity, ' '); // Extract the first variable separated by comma

				std::string balance2;
				getline(ss2, customer2.password, ' '); // Extract the second variable separated by comma
				getline(ss2, customer2.firstName, ' '); // Extract the second variable separated by comma
				getline(ss2, customer2.lastName, ' '); // Extract the third variable without any separator
				getline(ss2, balance2); // Extract the third variable without any separator
				customer2.balance = stof(balance2);

			if(customer2.firstName == depositFirst && customer2.lastName == depositSecond){
				std::cout << "How much money would you like to transfer to " << customer2.firstName << " " << customer2.lastName << std::endl;
				std::cout << "Enter amount without currency: " << std::endl;
				std::cin >> amount;
				if(customer.balance > amount){
					customer.balance -= amount;
					customer2.balance += amount;
					std::cout << customer2.balance << std::endl;
					std::ofstream file2("users.txt", std::ios_base::app);
					file2 << customer2.socialSecurity << " " << customer2.password << " " << customer2.firstName << " " << customer2.lastName << " " << customer2.balance << "\n";


					std::cout << "Transfer successful!" << std::endl;
					break;
				}
				else if(customer.balance < amount){
					std::cout << "Insufficient funds" << std::endl;
				}
				else{
					std::cout << "User not found, try again? y/n" << std::endl;
					goto jump2;
				}


			}


		}
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
