#pragma once

class Transaction {
private:
	int trans_code;
	float available_credit;

public:
	void logout_trans();
	void refund_trans();
	void adv_trans();
	void  bid_trans();
	void account_file();
	void items_file();
};
