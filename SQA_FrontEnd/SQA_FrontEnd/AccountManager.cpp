#include "AccountManager.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <limits>
using namespace std;

AccountManager::AccountManager() {
	logStatus = false;
	username = "";
	credits = 00.00;
	user_type = "";
	accountFile = "DataFiles/UserDB.txt";
	itemFile = "DataFiles/ItemDB.txt";
	transFile = "DataFiles/Transout.atf";
} 

AccountManager::AccountManager(string _accountFile, string _itemFile, string _transFile){
	logStatus = false;
	//username = "";
	credits = 00.00;
	//user_type = "";
	accountFile = _accountFile;
	itemFile = _itemFile;
	transFile = _transFile;
}

AccountManager::AccountManager(bool _logStatus, string _user_type, string _username, float _credits) // Using for testing purposes
{
	logStatus = _logStatus;
	user_type = _user_type;
	username = _username;
	credits = _credits;
	accountFile = "DataFiles/UserDB.txt";
	itemFile = "DataFiles/ItemDB.txt";
	transFile = "DataFiles/Transout.atf";
}

void AccountManager::login(string _username) // 0 = Success, 1 = Already Logged In, 2 = No Account
{
	if (logStatus) {
		cout << "ERROR: Cannot log in, " << username << " is already logged in.\n";
		return; // Already logged in
	}

	//UUUUUUUUUUUUUUU_TT_CCCCCCCCC
	//15_2_9
	_username = _username.append(15 - _username.length(), ' '); // Add Whitespace
	string line;
	ifstream myfile(accountFile);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (_username == line.substr(0, 15)) {
				username = line.substr(0, 15);
				username = username.erase(username.find_last_not_of(" \t\f\v\n\r") + 1);
				user_type = line.substr(16, 2);
				credits = stof(line.substr(19,9));
				logStatus = true;
				myfile.close();
				cout << "Success! " << username << " is now logged in.\n";
				return;
			}
		}
		myfile.close();
	}
	else {
		cout << "Unable to open file.\n";
		return;
	}
	cout << "ERROR: Cannot log in, " << username << " was not found.\n";
}

void AccountManager::logout() // 0 = Success, 1 = Already Logged Out
{
	if (!logStatus) {
		cout << "User is already logged out.\n";
		return;
	}
	username = username.append(15 - username.length(), ' '); // Add Whitespace
	string line;
	ifstream infile(accountFile);
	ofstream outfile("temp.txt");
	if (infile.is_open())
	{
		while (getline(infile, line))
		{
			if (username == line.substr(0, 15)) {
				stringstream ss;
				ss << fixed << setprecision(2) << credits;
				string sFunds = ss.str();
				sFunds.insert(sFunds.begin(), 9 - sFunds.length(), '0');
				outfile << username << "_" << user_type << "_" << sFunds << endl;
				logStatus = false;
			}
			else {
				outfile << line << endl;
			}
		}
		if (logStatus) {
			stringstream ss;
			ss << fixed << setprecision(2) << credits;
			string sFunds = ss.str();
			sFunds.insert(sFunds.begin(), 9 - sFunds.length(), '0');
			outfile << username << "_" << user_type << "_" << sFunds << endl;
			logStatus = false;
		}
		infile.close();
		outfile.close();
		if (remove(accountFile.c_str()) != 0 || rename("temp.txt", accountFile.c_str()) != 0) {
			cout << "ERROR: There was an error saving the file\n";
		}
		
	}
	else { cout << "Could not save, unable to open file.\n"; }
	// needs to print transation file on logout and update user account info
	cout << "Success! User is now logged out.\n";
	logStatus = false;
	username = "";
	credits = 00.00;
	user_type = "";
}

void AccountManager::createUser() { 

	if (!logStatus) {
		cout << "ERROR: No account logged in.\n";
		return;
	}else if (user_type != "AA") {
		cout << "ERROR: Must be an admin to creat user.\n";
		return;
	}

	string _username, _utype;
	float _credit;

	cout << "Welcome! Please select a original username (15chr max): ";
	cin >> _username;

	if (verifyLogin(_username) == true) {
		cout << "ERROR: Username is already taken.\n";
		return;
	}else if(_username.length() > 15){
		cout << "ERROR: Username exceeds the 15 character max.\n";
		return;
	}

	cout << "What type user will " << _username << " be?\n" 
			<< "AA = Admin,\nFS = Full - Standard\nBS = Buy - Standard\nSS = Sell - Standard\nPlease select: ";
	cin >> _utype;

	if (_utype != "AA" && _utype != "FS" && _utype != "BS" && _utype != "SS") {
		cout << "ERROR: "<< _utype <<" is not user type.\n";
		return;
	}
	cout << "Please enter the funds for " << _username << " ($999999.99 max): ";
	if (!(cin >> _credit)) {
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "ERROR: That is not even a number.\n";
		return;
	}
	if (_credit > 999999.99f) {
		cout << "ERROR: " << _credit << " exceeds the $999999.99 max.\n";
		return;
	}

	string line;
	ifstream infile(accountFile);
	ofstream outfile("temp.txt");
	if (infile.is_open())
	{
		while (getline(infile, line)){
			outfile << line << endl;
		}
		_username = _username.append(15 - _username.length(), ' '); // Add Whitespace
		stringstream ss;
		ss << fixed << setprecision(2) << _credit;
		string sFunds = ss.str();
		sFunds.insert(sFunds.begin(), 9 - sFunds.length(), '0');
		outfile << _username << "_" << _utype << "_" << sFunds << endl;
		infile.close();
		outfile.close();
		if (remove("DataFiles/UserDB.txt") != 0 || rename("DataFiles/temp.txt", "DataFiles/UserDB.txt") != 0) {
			cout << "ERROR: There was an error saving the file\n";
			return;
		}

		cout << "\nSuccess! User " << _username.erase(_username.find_last_not_of(" \t\f\v\n\r") + 1)
			<< " Was Created! They are a " << _utype
			<< " type user, with $" << _credit << ".\n\n";
	}
	else { cout << "ERROR: Could not save, unable to open file"; }
}

void AccountManager::deleteUser() {
	if (!logStatus) {
		cout << "ERROR: No account logged in.\n";
		return;
	}
	else if (user_type != "AA") {
		cout << "ERROR: Must be an admin to creat user.\n";
		return;
	}

	string _username;

	cout << "Please select a user by their username: ";
	cin >> _username;

	if (verifyLogin(_username) != true) {
		cout << "ERROR: This user does not exist.\n";
		return;
	}
	_username = _username.append(15 - _username.length(), ' '); // Add Whitespace
	string line;
	ifstream infile(accountFile);
	ofstream outfile("temp.txt");
	if (infile.is_open())
	{
		while (getline(infile, line)) {
			if (_username != line.substr(0, 15)) {
				outfile << line << endl;
			}
		}
		infile.close();
		outfile.close();
		if (remove(accountFile.c_str()) != 0 || rename("temp.txt", accountFile.c_str()) != 0) {
			cout << "ERROR: There was an error saving the file\n";
			return;
		}
		cout << "\nSuccess! User " << _username.erase(_username.find_last_not_of(" \t\f\v\n\r") + 1) << " is no more!\n\n";
	}
	else { cout << "ERROR: Could not save, unable to open file\n"; }
}

bool AccountManager::verifyLogin(string _username)
{
	_username = _username.append(15 - _username.length(), ' '); // Add Whitespace
	string line;
	ifstream myfile(accountFile);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (_username == line.substr(0, 15)) {
				return true;
			}
		}
		myfile.close();
	}
	else { cout << "Unable to open file\n"; }
	return false;
}