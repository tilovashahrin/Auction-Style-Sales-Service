#pragma once
#include "Transaction.h"
#include <string>
using namespace std;
class UserActivity : public Transaction {
private:
	char item_name[25];
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
	Transaction daily_trans_file;
	UserActivity();
	void advertise(string user_type);
	void bid(string user_type);
	void addCredit(string user_type);
	void refund(string user_type);
	float getPreviousBid() { return previous_bid; }
};

