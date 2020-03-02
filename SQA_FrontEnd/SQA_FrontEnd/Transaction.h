#pragma once
#include <string>
#include <vector>
using namespace std;
class Transaction {
private:
	int trans_code;
	float available_credit;
	string transFile;
	vector<string> transactions;
	
public:
	Transaction();
	Transaction(string file);
	void logout_trans(int trans_code, string username, string user_type, float credits);
	void refund_trans(string buyers_username, string sellers_username, float refund_credit);
	void adv_trans(string item_name, string sellers_username, int num_days, float min_bid);
	void  bid_trans(string item_name, string sellers_username, string buyers_username, float bid_amount);

	void setTransFile(string file) {transFile = file;};
	string getTransFile() {return transFile;};

};
