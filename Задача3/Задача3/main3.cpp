#include<iostream>
#include<string>
using namespace std;

string get_address_part(string address, int number_ockted) {
	bool flag = false;
	int count = 0;
	string final = "";
	for (int i = 0; i < address.length(); i++) {
		if (count == number_ockted && address[i] != '.') {
			final += address[i];
		}
		if (!flag) {
			flag = (address[i] == '.') ? true : false;
			if(flag){
				count++;
				if (address[i + 1] == '.') {
					final = "Error";
					return final;
				}
				flag = false;
			}
		}
	}
	if (count > 3) {
		final = "Error";
	}
	return final;
}
bool check_valid(string Ockted) {
	if (Ockted.length() > 3 || Ockted.length() == 0) {
		return false;
	}
	if (Ockted[0] == '0' && Ockted.length() != 1) {
		return false;
	}
	for (int i = 0; i < Ockted.length(); i++) {
		if (Ockted[i] < '0' || Ockted[i]>'9') {
			return false;
		}
	}
	int OCkted = 0;
	if (Ockted.length() == 1) {
		OCkted += Ockted[0] - '0';
	}
	else if (Ockted.length() == 2) {
		OCkted += (Ockted[0] - '0') * 10;
		OCkted += Ockted[1] - '0';
	}
	else if (Ockted.length() == 3) {
		OCkted += (Ockted[0] - '0') * 100;
		OCkted += (Ockted[1] - '0') * 10;
		OCkted += Ockted[2] - '0';
	}
	if (OCkted > 255) {
		return false;
	}
	return true;
}
bool check_valid_F(string address) {
	for (int g = 0; g < 4; g++) {
		string ockted = get_address_part(address, g);
		if (ockted == "Error") {
			return 0;
		}
		if (!(check_valid(ockted))) {
			return 0;
		}
	}
	return true;
}
int main() {
	string Adress;
	do {
		cout << "Input adress: ";
		cin >> Adress;
		if (check_valid_F(Adress)) {
			cout << "Valid\n";
		}
		else {
			cout << "Invalid\n";
		}
	} while (!(check_valid_F(Adress)));
}