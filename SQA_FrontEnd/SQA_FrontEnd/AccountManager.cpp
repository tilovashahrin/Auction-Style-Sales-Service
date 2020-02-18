#include "AccountManager.h"
#include "UserActivity.h"
#include "Transaction.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

AccountManager::AccountManager() {
	logStatus = false;
	username = "";
	credits = 00.00;
	user_type = "";
} 

AccountManager::AccountManager(bool _logStatus, string _user_type, string _username) // Using for testing purposes
{
	logStatus = _logStatus;
	user_type = _user_type;
	username = _username;
}

int AccountManager::login(string _username) // 0 = Success, 1 = Already Logged In, 2 = No Account
{
	if (logStatus) {
		return 1; // Already logged in
	}

	//UUUUUUUUUUUUUUU_TT_CCCCCCCCC
	//15_2_9
	_username = _username.append(15 - _username.length(), ' '); // Add Whitespace
	string line;
	ifstream myfile("DataFiles/UserDB.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (_username == line.substr(0, 15)) {
				username = line.substr(0, 15);
				// Remove White Space http://www.cplusplus.com/reference/string/string/find_last_not_of/
				username = username.erase(username.find_last_not_of(" \t\f\v\n\r") + 1);
				user_type = line.substr(16, 2);
				credits = stof(line.substr(19,9));
				logStatus = true;
				return 0;
			}
		}
		myfile.close();
	} else {cout << "Unable to open file"; }
	return 2;
}

int AccountManager::logout() // 0 = Success, 1 = Already Logged Out
{
	if (!logStatus) {
		return 1; // Already logged out
	}
	// needs to print transation file on logout and update user account info

	AccountManager();
	return 0;
}

// 0 = Success, 1 = Not Admin, 2 = Username Taken, 3 = Name to long, 4 = Exceeds max funds
int AccountManager::createUser() { 
	if (user_type != "AA" || !logStatus) {
		return 1; // Not logged in to a admin user
	}
	return 0;
}

bool getUser(string _username);
