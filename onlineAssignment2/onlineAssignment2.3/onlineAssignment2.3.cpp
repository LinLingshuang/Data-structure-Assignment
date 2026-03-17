
#include<iostream>
#include<string>
using namespace std;

int main() {
	string a;
	getline(cin, a);
	string *a1 = new string[1000];
	int aNum = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ' ') {
			aNum++;
		}
		else {
			a1[aNum].push_back(a[i]);
		}
	}
	string b;
	getline(cin, b);
	string* b1 = new string[1000];
	int bNum = 0;
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == ' ') {
			bNum++;
		}
		else {
			b1[bNum].push_back(b[i]);
		}
	}
	int cNum = 0;
	string* c = new string[10000];

	for (int i = 0; i < aNum+1; i++) {
		for (int j = 0; j < bNum+1; j++) {
			if (a1[i] == b1[j]) {
				c[cNum] = a1[i];
				cNum++;
			}
		}
	}
	if (cNum == 0) {
		cout << "error";
		return 0;
	}
	else {
		for (int i = cNum - 1; i >= 0; i--) {
			cout << c[i] << ' ';
		}
	}


}