#pragma once
#include <string>
using namespace std;
class UserActivity
{
private:
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
	void advertise();
	void bid(string user_type);
	void addCredit(string user_type);
	void refund(string user_type);
	float getPreviousBid() { return previous_bid; }
};

