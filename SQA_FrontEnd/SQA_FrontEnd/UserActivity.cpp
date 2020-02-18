#include "UserActivity.h"
#include "AccountManager.h"
#include "Transaction.h"
#include <string>
#include <iostream>
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


void UserActivity::advertise() {
	cout << "\nEnter the name of the item: ";
	cin >> item_name;

	cout << "\nEnter minimum bid (eg 15.00): ";
	cin >> min_bid;

	cout << "\nEnter number of days available to bid: ";
	cin >> num_days;
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
		cin >> bid_amount;
		bid_amount = previous_bid;
	}
	else {
		cout << "Enter your bid amount here: ";
		cin >> bid_amount;
		bid_amount = previous_bid;
	}

}

void UserActivity::addCredit(string user_type) {
	cout << "In a given session, you must enter a credit amount of less than $1000\n";
	if (user_type != "AA") {
		cout << "\nEnter username to which credit is being added: ";
		cin >> credit_username;
		cout << "\nEnter amount: ";
		cin >> transf_credit;
	}
	else {
		cout << "\nEnter amount: ";
		cin >> transf_credit;
	}
}

void UserActivity::refund(string user_type) {
	if (user_type == "AA") {
		cout << "\nEnter buyer's username: ";
		cin >> buyers_username;

		cout << "\nEnter seller's username: ";
		cin >> sellers_username;

		cout << "Enter the amount of credit you wish to transfer: ";
		cin >> refund_credit;
	}
	else {
		cout << "\n ERROR! You do not have authorization to value refunds.";
		system("pause");
	}
}
