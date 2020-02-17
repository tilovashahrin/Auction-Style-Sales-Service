#pragma once
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
	void advertise(string item_name, int num_days, float min_bid);
	void bid(string sellers_username, string item_name, float bid_amount, string user_type);
	void addCredit(string credit_username, string user_type, float transf_credit);
	void refund(string user_type, string buyers_username, string sellers_username, float refund_credit);
	float getPreviousBid() { return previous_bid; }
};

