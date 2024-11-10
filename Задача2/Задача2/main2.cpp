#include<iostream>
#include<string>
using namespace std;

string check_email_F(string Email) { //разбитие на первую часть
	string Email_check;
	for (int i = 0; i < Email.length(); i++) {
		if (Email[i] == '@') {
			return Email_check;
		}
		else {
			Email_check += Email[i];
		}
	}
	return Email_check;
}
string check_email_S(string Email) { // разбитие на 2 часть
	bool flag = false;
	string Email_check;
	for (int i = 0; i < Email.length(); i++) {
		if (flag == true) {
			Email_check += Email[i];
		}
		if (Email[i] == '@') {
			flag = true;
		}
	}
	return Email_check;
}
bool check_emails_F_full(string Email) { //проверка на коректность первой части
	for (int i = 0; i < Email.length(); i++) {
		if (i == 0 && (Email[i] == '@' || Email[i] == '.')) {
			return false;
		}
		if (Email[i] == '.' && Email[i + 1] == '.') {
			return false;
		}
		if (Email[i] == '@') {
			return false;
		}
		if (i > 64) {
			return false;
		}
		if ((Email[i] < 'A' || Email[i]>'Z') && (Email[i] < 'a' || Email[i]>'z') && (Email[i] < '0' || Email[i]>'9')) {
			string Norm_sing = ".-!#$%&'*+-/=?^_`{|}~";
			bool flag = false;
			for (int g = 0; g < Norm_sing.length(); g++) {
				if (Email[i] == Norm_sing[g]) {
					flag = true;
					break;
				}
			}
			if (flag == false) {
				return false;
			}
		}
	}
	return true;
}
bool check_email_S_full(string Email) { // проверка на коректность второй части
	if (Email == "") {
		return false;
	}
	for (int i = 0; i < Email.length(); i++) {
		if (Email[i] == '@') {
			return false;
		}
		if (Email[Email.length()] == '.') {
			return false;
		}
		if (Email[i] == '.' && Email[i + 1] == '.') {
			return false;
		}
		if (i > 63) {
			return false;
		}
		if ((Email[i] < 'A' || Email[i]>'Z') && (Email[i] < 'a' || Email[i]>'z') && (Email[i] < '0' || Email[i]>'9') && Email[i] != '.' && Email[i] != '-' && Email[i] != '@') {
			return false;
		}
	}
	return true;
}
bool check_email_All(string Email) { // общая проверка на коректность
	string part_1 = check_email_F(Email);
	string part_2 = check_email_S(Email);
	if (check_emails_F_full(part_1)) {
		if (check_email_S_full(part_2)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
int main() {
	string email;
	do {
		cout << "Input your email: ";
		cin >> email;
		if (check_email_All(email)) {
			cout << "Yes";
		}
		else {
			cout << "Try again";
		}
	} while (!(check_email_All(email)));
}