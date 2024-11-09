#include<iostream>
#include<string>
using namespace std;

string encrypt_caesar(string text, int code) {
	string Code_Text = "";
	for (int i = 0; i < text.length(); i++) {
		if (text[i] >= 'A' && text[i] <= 'Z') {
			int Code_char = (int)text[i] - (int)'A';
			Code_char = (Code_char + code) % 26;
			Code_char += (int)'A';
			Code_Text += (char)Code_char;
		}
		else if (text[i] >= 'a' && text[i] <= 'z') {
			int Code_char = (int)text[i] - (int)'a';
			Code_char = (Code_char + code) % 26;
			Code_char += (int)'a';
			Code_Text += (char)Code_char;
		}
		else {
			Code_Text += text[i];
		}
	}
	return Code_Text;
}
int main() {
	string Text;
	cout << "Input text: ";
	getline(cin, Text);
	int Code;
	cout << "Input Code: ";
	cin >> Code;
	string Final_Text = encrypt_caesar(Text, Code);
	cout << Final_Text;
}