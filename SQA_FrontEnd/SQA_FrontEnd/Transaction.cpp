#include "AccountManager.h"
#include "UserActivity.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Transaction::Transaction() {
	available_credit = 00.00;
}

void Transaction::logout_trans(int trans_code, string username, string user_type) {

	ofstream myfile("Transaction_File.txt");
	//XX_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
	if (myfile.is_open())
	{
		myfile << trans_code << "_" << username << "_" << user_type << "_" << available_credit;
		myfile.close();
	}
	else { cout << "Unable to open file"; }
}

void Transaction::refund_trans(string buyers_username, string sellers_username, float refund_credit) {

	ofstream myfile("Transaction_File.txt");
	//XX_UUUUUUUUUUUUUUU_SSSSSSSSSSSSSSS_CCCCCCCCC
	if (myfile.is_open())
	{
		myfile << "05" << "_" << buyers_username << "_" << sellers_username << "_" << refund_credit;
		myfile.close();
	}
	else { cout << "Unable to open file"; }
}

void Transaction::adv_trans(string item_name, string sellers_username, int num_days, float min_bid) {
	ofstream myfile("Transaction_File.txt");
	//XX_IIIIIIIIIIIIIIIIIII_SSSSSSSSSSSSS_DDD_PPPPPP
	if (myfile.is_open())
	{
		myfile << "03" << "_" << item_name << "_" << sellers_username << "_" << num_days << "_" << min_bid;
		myfile.close();
	}
	else { cout << "Unable to open file"; }
}

void  Transaction::bid_trans(string item_name, string sellers_username, string buyers_username, float bid_amount) {
	ofstream myfile("Transaction_File.txt");
	//XX_IIIIIIIIIIIIIIIIIII_SSSSSSSSSSSSSSS_UUUUUUUUUUUUUU_PPPPPP

	if (myfile.is_open())
	{
		myfile << "03" << "_" << item_name << "_" << sellers_username << "_" << buyers_username << "_" << bid_amount;
		myfile.close();
	}
	else { cout << "Unable to open file"; }
}

void Transaction::account_file() {

}

void Transaction::items_file() {

}
