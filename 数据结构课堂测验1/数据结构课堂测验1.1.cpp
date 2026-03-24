#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct student {
	string name;
	int number;
	string department;

};

struct book {
	string name;
	int number;
	string publish;

};

struct lendBook {
	int studentNum;
	int bookNum;
	int time;

};


void sortDepartment(vector<student>& myStudent, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = i; j < num - 1; j++) {
			if (myStudent[j].department >= myStudent[j + 1].department) {
				student temp = myStudent[j];
				myStudent[j] = myStudent[j + 1];
				myStudent[j + 1] = temp;
			}
		}
	}
}
void sortStudent(vector<student>& myStudent, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = i; j < num - 1; j++) {
			if (myStudent[j].department == myStudent[j + 1].department) {
				if (myStudent[j].number > myStudent[j + 1].number) {
					student temp = myStudent[j];
					myStudent[j] = myStudent[j + 1];
					myStudent[j + 1] = temp;
				}
			}
		}
	}
}
void sortBook(vector<lendBook>& myLendBook, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1; j++) {
			if (myLendBook[j].studentNum > myLendBook[j + 1].studentNum) {
				lendBook temp = myLendBook[j];
				myLendBook[j] = myLendBook[j + 1];
				myLendBook[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1; j++) {
			if (myLendBook[j].studentNum == myLendBook[j + 1].studentNum) {
				if (myLendBook[j].time > myLendBook[j + 1].time) {
					lendBook temp = myLendBook[j];
					myLendBook[j] = myLendBook[j + 1];
					myLendBook[j + 1] = temp;
				}
			}
		}
	}
}
void output(vector<student>myStudent, int n, vector<book>mybook, int m, vector<lendBook>myLendBook, int k) {
	bool changeDepartment = true;
	for (int i = 0; i < n; i++) {
		if (changeDepartment) {
			cout << "ѧԺ:" << myStudent[i].department << endl;
			changeDepartment = false;
		}
		cout << myStudent[i].number << "\t" << myStudent[i].name << "\t";
		for (int j = 0; j < k; j++) {
			bool findbook = false;
			if (myLendBook[j].studentNum == myStudent[i].number) {
				for (int f = 0; f < m; f++) {
					if (myLendBook[j].bookNum == mybook[f].number) {
						if (findbook) {
							cout << "\t\t\t";
						}
						cout << mybook[f].name << "\t" << mybook[f].publish << "\t" << myLendBook[j].time << endl;
					}
				}
			}
		}
		if (i != n - 1 && myStudent[i].department != myStudent[i + 1].department) {
			changeDepartment = true;
		}
	}
}



int main() {
	int  n, m, k;
	cin >> n;
	vector<student>myStudent(n);
	for (int i = 0; i < n; i++) {
		cin >> myStudent[i].number >> myStudent[i].name >> myStudent[i].department;
	}

	cin >> m;
	vector<book>mybook(m);
	for (int i = 0; i < m; i++) {
		cin >> mybook[i].number >> mybook[i].name >> mybook[i].publish;
	}


	cin >> k;
	vector<lendBook>myLendBook(k);
	for (int i = 0; i < k; i++) {
		cin >> myLendBook[i].studentNum >> myLendBook[i].bookNum >> myLendBook[i].time;
	}
	sortDepartment(myStudent, n);
	sortStudent(myStudent, n);
	sortBook(myLendBook, k);

	output(myStudent, n, mybook, m, myLendBook, k);
}