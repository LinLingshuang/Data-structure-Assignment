#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Node {
	string Address;
	int	Data;
	string	Next;
	
};

int main() {
	string head;
	int num;
	int positionNum = 0;
	cin >> head >> num;
	vector<Node> myNode(num);
	vector<Node> output(num);
	for (int i = 0; i < num; i++) {
		cin >> myNode[i].Address >> myNode[i].Data >> myNode[i].Next;
	}
	bool getNull = false;
	while (!getNull)
	{
		for (int i = 0; i < num; i++) {
			if (myNode[i].Address == head) {
				output[positionNum] = myNode[i];
				positionNum++;
				head = myNode[i].Next;
			}
		}
		if (head == "-1") {
			getNull = true;
		}
	}

	int j = 0;
	for (int i = 0; i < num; i++) {
		if (i == num - 1) {
			if (num % 2 == 0) {
				cout << output[num /2-1].Address << ' ' << output[num /2-1].Data << ' ' << "-1" << endl;
			}
			else {
				cout << output[(num+1) / 2-1].Address << ' ' << output[(num + 1) / 2-1].Data << ' ' << "-1" << endl;
			}
		} 
		else{
			if (i % 2 == 0) {
				cout << output[num - 1 - j].Address << ' ' << output[num - 1 - j].Data << ' ' << output[j].Address << endl;
			}
			else {
				cout << output[j].Address << ' ' << output[j].Data << ' ' << output[num -2- j].Address << endl;
				j++;
			}
		}
	}


}