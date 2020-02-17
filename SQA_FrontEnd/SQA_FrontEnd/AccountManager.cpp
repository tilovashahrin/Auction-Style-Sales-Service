#include "AccountManager.h"
#include <string>
#include <iostream>
using namespace std;

AccountManager::AccountManager() {
		logStatus = false;
		username = "";
} 
	
void AccountManager::login(string _username) {
	//Check data base for username would go first 

	username = _username;
	logStatus = true;
}

