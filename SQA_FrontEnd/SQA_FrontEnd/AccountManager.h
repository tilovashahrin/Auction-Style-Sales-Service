#pragma once
#include "UserActivity.h"
#include <string>
#include <iostream>
using namespace std;

class AccountManager : public UserActivity
{
private:
	bool logStatus; // true = logged in, false = logged out
	string user_type; // AA=admin, FS=full-standard, BS=buy-standard,SS=sell-standard
	string username;
	float credits;

public:
	AccountManager();

	AccountManager(bool _logStatus, string _user_type, string _username, float _credits); // For Testing Purposes

	int login(string _username); // 0 = Success, 1 = Already Logged In, 2 = No Account

	int logout(); // 0 = Success, 1 = Already Logged Out

	void createUser();

	void deleteUser() {};

	bool verifyLogin(string _username);

	string getUsername() { return username; };
	bool getLogStatus() { return logStatus; };
	string getUserType() { return user_type; };
	float getCredits() { return credits; }

	void setCredits(float _credits) { credits = _credits; };
};

