#include<iostream>
#include<string>
using namespace std;

bool check_email(string Email) {
	bool flag_dog = false;
	int count_dog = 0;
	int count_I_after_dog = 0;
	for (int i = 0; i < Email.length(); i++) {
		if (i == 0 && (Email[i] == '@' || Email[i] == '.')){
			return false;
		}
		if (Email[Email.length()] == '.') {
			return false;
		}
		if (Email[i] == '.' && Email[i + 1] == '.') {
			return false;
		}

		if (Email[i] == '@') {
			flag_dog = true;
			count_dog++;
			if (i == Email.length() - 1) {
				return false;
			}
			if (count_dog > 1) {
				return false;
			}
		}
		if (flag_dog == true) {
			count_I_after_dog++;
		}
		if (count_I_after_dog > 63) {
			return false;
		}
		if (i > 64 && flag_dog == false) {
			return 0;
		}

		if (flag_dog == false) {
			if ((Email[i] < 'A' || Email[i]>'Z') && (Email[i] < 'a' || Email[i]>'z') && (Email[i] < '0' || Email[i]>'9')) {
				string Norm_sing = ".-@!#$%&'*+-/=?^_`{|}~";
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
		else {
			if ((Email[i] < 'A' || Email[i]>'Z') && (Email[i] < 'a' || Email[i]>'z') && (Email[i] < '0' || Email[i]>'9') && Email[i] != '.' && Email[i] != '-' && Email[i] != '@') {
				return false;
			}
		}
	}
	if (!flag_dog) {
		return false;
	}
	return true;
}
int main() {
	string email;
	do {
		cout << "Input your email: ";
		cin >> email;
		if (check_email(email)) {
			cout << "Yes";
		}
		else {
			cout << "Try again";
		}
	} while (!(check_email(email)));
}