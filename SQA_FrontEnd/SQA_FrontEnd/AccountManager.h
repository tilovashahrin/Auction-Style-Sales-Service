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
	string accountFile;
	string itemFile;
	string transFile;

public:
	AccountManager();

	AccountManager(string _accountFile, string _itemFile, string _transFile);

	AccountManager(bool _logStatus, string _user_type, string _username, float _credits); // For Testing Purposes

	void login(string _username); // 0 = Success, 1 = Already Logged In, 2 = No Account

	void logout(); // 0 = Success, 1 = Already Logged Out

	void createUser();

	void deleteUser();

	bool verifyLogin(string _username);

	void advertise() { UserActivity::advertise(user_type); };
	void bid() { UserActivity::bid(user_type); };
	void addCredit() { UserActivity::addCredit(user_type); };
	void refund() { UserActivity::refund(user_type); };

	string getUsername() { return username; };
	bool getLogStatus() { return logStatus; };
	string getUserType() { return user_type; };
	float getCredits() { return credits; }

	void setCredits(float _credits) { credits = _credits; };

	void printFiles() // For testing purposes
	{
		cout << "Account Database File: " << accountFile << endl;
		cout << "Item Database File: " << itemFile << endl;
		cout << "Transaction File: " << transFile << endl;
	};
};

