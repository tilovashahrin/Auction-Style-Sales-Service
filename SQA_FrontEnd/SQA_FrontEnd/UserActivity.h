#pragma once
#include "Transaction.h"
#include <string>
using namespace std;
class UserActivity : public Transaction
{
private:
	string item_name;
	string sellers_username;
	string buyers_username;
	string credit_username;
	int num_days; //number of days until the auction ends
	float min_bid; //min amount of bidding ask from advertiser
	float bid_amount; //amount buyer bids for
	float transf_credit; //amount of credit transferred
	float refund_credit; //amount of credit refunded
	float previous_bid; //comapares current bid to previous one

public:
	UserActivity();
	void advertise(string user_type);
	void bid(string user_type);
	void addCredit(string user_type);
	void refund(string user_type);
	float getPreviousBid() { return previous_bid; }
};

