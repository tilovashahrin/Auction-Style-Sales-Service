#include "UserActivity.h"
#include "AccountManager.h"
#include "Transaction.h"
#include <string>
#include <iostream>
#include <limits>
using namespace std;

UserActivity::UserActivity() {
	item_name = ""; //less than 25 characters
	num_days = 1; //less than 100 days
	min_bid = 00.00; //less than 999.99
	bid_amount = 00.00;
	transf_credit = 00.00;
	transf_credit = 00.00;
	refund_credit = 00.00;
	previous_bid = 00.00;
	sellers_username = "";
	buyers_username = "";
	credit_username = "";
}


void UserActivity::advertise(string user_type) {
	cout << "\nEnter the name of the item: ";
	cin >> item_name;

	cout << "\nEnter minimum bid (eg 15.00): ";
	if (!(cin >> min_bid)) {
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "ERROR: That is not even a number.\n";
		exit(1);//return;
	}

	cout << "\nEnter number of days available to bid: ";
	if (!(cin >> num_days)) {
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "ERROR: That is not even a number.\n";
		exit(1);//return;
	}

}

void UserActivity::bid(string user_type) {
	
	cout << "== Create a bid ==";
	cout << "\n Enter the item name: ";
	cin >> item_name;

	cout << "Enter seller's username: ";
	cin >> sellers_username;

	float previous_bid = getPreviousBid();
	if (user_type != "AA") {
		cout << "Our last bidding is at " << previous_bid << ".\n You must bid at least 5% higher than the previous bid shown above.\nEnter here (eg. 230.00): ";
		if (!(cin >> bid_amount)) {
			cin.clear(); //clear bad input flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
			cout << "ERROR: That is not even a number.\n";
			exit(1);//return;
		}
		bid_amount = previous_bid;
	}
	else {
		cout << "Enter your bid amount here: ";
		if (!(cin >> bid_amount)) {
			cin.clear(); //clear bad input flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
			cout << "ERROR: That is not even a number.\n";
			exit(1);//return;
		}
		bid_amount = previous_bid;
	}

}

void UserActivity::addCredit(string user_type) {
	cout << "In a given session, you must enter a credit amount of less than $1000\n";
	if (user_type != "AA") {
		cout << "\nEnter username to which credit is being added: ";
		
		cin >> credit_username;
		cout << "\nEnter amount: ";
		if (!(cin >> transf_credit)) {
			cin.clear(); //clear bad input flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
			cout << "ERROR: That is not even a number.\n";
			exit(1);//return;
		}
	}
	else {
		cout << "\nEnter amount: ";
		if (!(cin >> transf_credit)) {
			cin.clear(); //clear bad input flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
			cout << "ERROR: That is not even a number.\n";
			exit(1);//return;
		}
	}
}

void UserActivity::refund(string user_type) {
	if (user_type == "AA") {
		cout << "\nEnter buyer's username: ";
		cin >> buyers_username;

		cout << "\nEnter seller's username: ";
		cin >> sellers_username;

		cout << "Enter the amount of credit you wish to transfer: ";
		if (!(cin >> refund_credit)) {
			cin.clear(); //clear bad input flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
			cout << "ERROR: That is not even a number.\n";
			exit(1);//return;
		}
	}
	else {
		cout << "\n ERROR! You do not have authorization to value refunds.";
		exit(1);
	}
}
