#pragma once
#include <string>
using namespace std;
class Transaction {
private:
	int trans_code;
	float available_credit;
	
public:
	Transaction();
	void logout_trans(int trans_code, string username, string user_type);
	void refund_trans(string buyers_username, string sellers_username, float refund_credit);
	void adv_trans(string item_name, string sellers_username, int num_days, float min_bid);
	void  bid_trans(string item_name, string sellers_username, string buyers_username, float bid_amount);
	void account_file();
	void items_file();
};
