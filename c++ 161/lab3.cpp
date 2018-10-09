#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void genPass() {
	string s;
	char x;
	int upperC = 0;
	int lowerC = 0;
	int let = 0;
	int nums = 0;
	int length;
	int i = 0; //iterator for loop


	cout << "Would you like letters in your password? 0 for no and 1 for yes" << endl;
	cin >> let;

	if (let == 1) {
		cout << "Would you like upper case letters in your password? 0 for no, otherwise type your requested amount" << endl;
		cin >> upperC;
		cout << "Would you like lower case letters in your password? 0 for no, otherwise type your requested amount" << endl;
		cin >> lowerC;
	}

	cout << "Would you like numbers in your password? 0 for no, otherwise type your requested amount" << endl;
	cin >> nums;
	length = upperC + lowerC + nums;
	srand(time(NULL));
	while (i < length) {
		
		switch (rand() % 3) {

		case 0:
			if (upperC > 0) {
				s.push_back((rand() % 25) + 65);
				upperC--;
				i++;
				break;
			}
			
		case 1:
			if (lowerC > 0) {
				s.push_back((rand() % 25) + 97);
				lowerC--;
				i++;
				break;
			}
			
		case 2:
			if (nums > 0) {
				s.push_back((rand() % 9) + 48);
				nums--;
				i++;
				break;
			}
		}
	}
	int answer;
	do {
		cout << "Would you like to add special characters? 0 for no, 1 for yes" << endl;
		cin >> answer;
		if (answer == 1) {
			cin >> x;
			if (int(x) >= 33 && int(x) <= 47)
				s.push_back(x);
		}
		cout << "Add more special characters? 0 for no, 1 for yes" << endl;
		cin >> answer;
	} while (answer == 1);


	cout << "your password is " << s << endl;

	return;
}

int main() {

	genPass();
	int ans = 0;

	do {
		cout << "Generate a new password? 0 for no, 1 for yes" << endl;
		cin >> ans;
		if (ans == 1)
			genPass();
	} while (ans!=0);
	
	return 0;
}

