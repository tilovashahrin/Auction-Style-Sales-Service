#pragma once
#include "UserActivity.h"
#include <string>
#include <iostream>
using namespace std;

class AccountManager : public UserActivity
{
private:
	bool logStatus; // true = logged in, false = logged out
	char user_type; // ad = admin, fs = full-standard, bs = buy-standard, ss = sell-standard
	string username;

public:
	AccountManager();

	void login(string _username) ;

	void logout() {};

	string createUser() {};

	void deleteUser() {};

	bool verifyLogin() {};

	string getUsername() { return username; };
};

