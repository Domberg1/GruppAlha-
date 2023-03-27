//============================================================================
// Name        : Login.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <chrono>
#include <thread>
#include <unistd.h>

int loginTries = 3;

template <typename Map>
bool map_compare (Map const &lhs, Map const &rhs) {
	// No predicate needed because there is operator== for pairs already.
	return lhs.size() == rhs.size()
			&& std::equal(lhs.begin(), lhs.end(),
					rhs.begin());
}


void login(int tries){

	if(tries != 0){

		std::map<std::string, std::string> loginAttempt;


		std::string personnummer;
		std::string password;

		std::map<std::string, std::string> userList;


		userList["Temp"] = "Temp2";


		// Read userlist from file TBA

//		std::ifstream ifs("userList.txt");


		std::cout << "Enter personnummer: " << std::endl;
		std::cin >> personnummer;
		std::cout << "Enter password: " << std::endl;
		std::cin >> password;

		loginAttempt.insert({personnummer, password});

		if (map_compare(loginAttempt, userList) == 1){
			//login_success(loginAttempt.first, loginAttempt.second)
		}
		else
		{
			std::cout << "Wrong personummer and/or password. Tries left: " << tries - 1 << std::endl;
			login(tries - 1);
		}
	}
	else
	{
		std::cout << "Account login has failed too many times, locked for 15 minutes";
		sleep(60*15);
	}
}


int main() {
	login(loginTries);
	return 0;
}
