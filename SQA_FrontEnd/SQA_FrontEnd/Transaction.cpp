#include "Transaction.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

Transaction::Transaction() {
	transFile = "DataFiles/Transout.atf";
	trans_code = 00;
	available_credit = 00.00;
}

Transaction::Transaction(string file) {
	transFile = file;
	trans_code = 00;
	available_credit = 00.00;
}

void Transaction::logout_trans(int trans_code, string username, string user_type, float credits) {
	//XX_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
	ofstream myfile(transFile);
	if (myfile.is_open()){
		string user = username.append(15 - username.length(), ' '); // Add Whitespace
		stringstream ss;
		ss << trans_code;
		string code = ss.str();
		code.insert(code.begin(), 2 - code.length(), '0');
		ss << fixed << setprecision(2) << credits;
		string credit = ss.str();
		credit.insert(credit.begin(), 9 - credit.length(), '0');
		//transactions.push_back(code + "_" + user + "_" + user_type + "_" + credit);
		myfile << code << "_" << user << "_" << user_type << "_" << credit;
		myfile.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void Transaction::refund_trans(string buyers_username, string sellers_username, float refund_credit) {
	//XX_UUUUUUUUUUUUUUU_SSSSSSSSSSSSSSS_CCCCCCCCC
	ofstream myfile(transFile);
	if (myfile.is_open()) {
		string buyer = buyers_username.append(15 - buyers_username.length(), ' '); // Add Whitespace
		string seller = sellers_username.append(15 - sellers_username.length(), ' '); // Add Whitespace
		stringstream ss;
		ss << fixed << setprecision(2) << refund_credit;
		string credit = ss.str();
		credit.insert(credit.begin(), 9 - credit.length(), '0');
		//transactions.push_back("05_" + buyer + "_" + seller + "_" + credit);
		myfile << "05_" << buyer << "_" << seller << "_" << credit;
	}
	else {
		cout << "Unable to open file";
	}
}

void Transaction::adv_trans(string item_name, string sellers_username, int num_days, float min_bid) {
	ofstream myfile(transFile);
	//XX_IIIIIIIIIIIIIIIIIII_SSSSSSSSSSSSS_DDD_PPPPPP
	if (myfile.is_open())
	{
		string item = item_name.append(19 - item_name.length(), ' '); // Add Whitespace
		string seller = sellers_username.append(15 - sellers_username.length(), ' '); // Add Whitespace
		stringstream ss;
		ss << num_days;
		string days = ss.str();
		days.insert(days.begin(), 3 - days.length(), '0');
		ss << fixed << setprecision(2) << min_bid;
		string bid = ss.str();
		bid.insert(bid.begin(), 6 - bid.length(), '0');
		myfile << "03_" << item << "_" << seller << "_" << days << "_" << bid;
		myfile.close();
	}
	else {
		cout << "Unable to open file"; 
	}
}

void  Transaction::bid_trans(string item_name, string sellers_username, string buyers_username, float bid_amount) {
	ofstream myfile(transFile);
	//XX_IIIIIIIIIIIIIIIIIII_SSSSSSSSSSSSSSS_UUUUUUUUUUUUUU_PPPPPP
	if (myfile.is_open())
	{
		string item = item_name.append(19 - item_name.length(), ' '); // Add Whitespace
		string seller = sellers_username.append(15 - sellers_username.length(), ' '); // Add Whitespace
		string buyer = buyers_username.append(15 - buyers_username.length(), ' '); // Add Whitespace
		stringstream ss;
		ss << fixed << setprecision(2) << bid_amount;
		string bid = ss.str();
		bid.insert(bid.begin(), 6 - bid.length(), '0');
		myfile << "04_" << item << "_" << seller << "_" << buyer << "_" << bid;
		myfile.close();
	}
	else { 
		cout << "Unable to open file"; 
	}
}

