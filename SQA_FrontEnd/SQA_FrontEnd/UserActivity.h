#pragma once
#include "Transaction.h"

#include <string>
#include <iostream>

using namespace std;
class UserActivity : public Transaction {
private:
	string itemFile;
	string item_name;
	string sellers_username;
	string buyers_username;
	string credit_username;
	int num_days; //number of days until the auction ends
	float min_bid; //min amount of bidding ask from advertiser
	float bid_amount; //amount buyer bids for
	float transf_credit;
	float refund_credit;
	float previous_bid;

public:

	UserActivity();
	UserActivity(string file);
	void advertise(string user_type);
	void bid(string user_type);
	void addCredit(string user_type);
	void refund(string user_type);
	float getPreviousBid() { return previous_bid; }

	void setItemFile(string file) { itemFile = file; };
	string getItemFile() { return itemFile; };
	virtual bool verifyLogin(string _username) = 0;
	virtual string getUser (string _username) = 0;
};

