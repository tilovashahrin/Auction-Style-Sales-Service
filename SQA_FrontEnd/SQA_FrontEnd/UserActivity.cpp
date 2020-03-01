#include "UserActivity.h"
#include "AccountManager.h"
#include "Transaction.h"
#include <string>
#include <iostream>
#include <limits>

using namespace std;

UserActivity::UserActivity() {
	item_name; //less than 25 characters
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

//have user create a bidding advertisement
void UserActivity::advertise(string sellers_username) {
	cout << "\nEnter the name of the item (in 25 characters or less): ";
	cin >> item_name;
	int item_size = sizeof(item_name);

	cout << "\nEnter minimum bid (eg 15.00): ";
	cin >> min_bid;
	cout << "\nEnter number of days available to bid: ";
	cin >> num_days;
	
	if (item_size >= 25) {
		cout << "\nERROR! item name exceeded limit. Please try again.";
		return;
	}
	if (!(min_bid)) {
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "\nERROR: Inavlid input. Please try again.\n";
		return;//return;
	}
	if (min_bid > 999.99) {
		cin.clear(); //clear bad input flag
		cout << "\nERROR: Maximum price exceeded for minimum bid. Minimum bid must be $999.99 or less.\n";
		return;
	}
	if (!(num_days)) {
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "\nERROR: Inavlid input. Please try again.\n";
		return;//return;
	}
	if (num_days > 100) {
		cin.clear(); //clear bad input flag
		cout << "\nERROR: Max number of days exceeded.\n";
		return;
	}
	
	cout << "\nAdvertisement Complete. Information saved into the daily transaction file.\n";
	daily_trans_file.adv_trans(item_name, sellers_username, num_days, min_bid);
	
}

void UserActivity::bid(string user_type) {
	float previous_bid = getPreviousBid();

	cout << "== Create a bid ==";
	cout << "\n Enter the item name: ";
	cin >> item_name;

	cout << "\nEnter seller's username: ";
	cin >> sellers_username;
		
	if (user_type != "AA") {
		cout << "\nOur last bidding is at " << previous_bid << ".\n You must bid at least 5% higher than the previous bid shown above.\nEnter here (eg. 230.00): ";
		if (!(cin >> bid_amount)) {
			cin.clear(); //clear bad input flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
			cout << "\nERROR: Inavlid input. Please try again.\n";
			exit(1);//return;
		}
		if (bid_amount < ((0.05 * previous_bid) + previous_bid)) {
			cout << "\nERROR: bid is less than the minimum amount.";
			return;
		}
		bid_amount = previous_bid;
	}
	else {
		cout << "\nEnter your bid amount here: ";
		if (!(cin >> bid_amount)) {
			cin.clear(); //clear bad input flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
			cout << "ERROR: Inavlid input. Please try again.\n";
			exit(1);//return;
		}
		bid_amount = previous_bid;
	}
	cout << "\nBid Complete. Information saved into the daily transaction file.\n";
	daily_trans_file.bid_trans(item_name, sellers_username, buyers_username, bid_amount);
}

void UserActivity::addCredit(string user_type) {
	cout << "\nIn a given session, you must enter a credit amount of less than $1000\n";
	if (user_type != "AA") {
		cout << "\nEnter amount: ";
		if (!(cin >> transf_credit)) {
			cin.clear(); //clear bad input flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
			cout << "\nERROR: Inavlid input. Please try again.\n";
			exit(1);//return;
		}
		if (transf_credit > 1000) {
			cout << "ERROR! Exceeded transfer limit. Please try again.";
			return;
		}
	}
	else {
		cout << "\nEnter username to which credit is being added: ";
		cin >> credit_username;
		cout << "\nEnter amount: ";
		if (!(cin >> transf_credit)) {
			cin.clear(); //clear bad input flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
			cout << "\nERROR: Inavlid input. Please try again.\n";
			exit(1);//return;
		}
		if (transf_credit > 1000) {
			cout << "ERROR! Exceeded transfer limit. Please try again.";
			return;
		}
		if (acc.verifyLogin(credit_username) != true) {
			cout << "ERROR: This user does not exist.\n";
			exit(1);//return;
		}
	}
	cout << "\nCredit transaction complete. Information saved into the daily transaction file.\n";
	daily_trans_file.logout_trans(06, buyers_username, user_type);
}

void UserActivity::refund(string user_type) {
	if (user_type == "AA") {
		cout << "\nEnter buyer's username: ";
		cin >> buyers_username;

		cout << "\nEnter seller's username: ";
		cin >> sellers_username;

		cout << "\nEnter the amount of credit you wish to transfer: ";
		if (!(cin >> refund_credit)) {
			cin.clear(); //clear bad input flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
			cout << "\nERROR: Inavlid input. Please try again.\n";
			exit(1);//return;
		}
	}
	else {
		cout << "\n ERROR! You do not have authorization to value refunds.\n";
		exit(1);
	}
	cout << "\nRefund Complete. Information saved into the daily transaction file.\n";
	daily_trans_file.refund_trans(buyers_username, sellers_username, refund_credit);
}
