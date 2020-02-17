#include "AccountManager.h"
#include <string>
#include <iostream>
using namespace std;

AccountManager::AccountManager() {
	logStatus = false;
	username = "";
} 

AccountManager::AccountManager(bool _logStatus, char _user_type, string _username) // Using for testing purposes
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
	//Check data base for username would go first 
	username = _username;
	logStatus = true;
	return 0;
}

int AccountManager::logout() // 0 = Success, 1 = Already Logged Out
{
	if (!logStatus) {
		return 1; // Already logged out
	}
	username = "";
	logStatus = false;
	user_type = 0;
	// needs to print transation file on logout
	return 0;
}

int AccountManager::createUser() {
	return 0;
}

