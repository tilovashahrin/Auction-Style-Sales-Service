#include "AccountManager.h"
#include <string>
#include <iostream>
using namespace std;

AccountManager::AccountManager() {
	logStatus = false;
	username = "";
} 

AccountManager::AccountManager(bool _logStatus, char _user_type, string _username) {
	logStatus = _logStatus;
	user_type = _user_type;
	username = _username;
}
	
void AccountManager::login(string _username) {
	if (logStatus) {
		cout << username << " is already logged in.\n";
	}
	else {
		//Check data base for username would go first 
		username = _username;
		logStatus = true;
	}
}
void AccountManager::logout() {
	if (!logStatus) {
		cout << "User is already logged out.\n";
	}
	else {
		username = "";
		logStatus = false;
		user_type = 0;
		// needs to print transation file on logout
	}
}

