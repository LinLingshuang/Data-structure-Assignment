/*8. 队列-超市模拟(1)
【问题描述】
模拟超市排队的行为。最初，有n个队列（1，2，…，n），每个队列都有一些顾客。之后可能会发生两个事件：
ENTERS：顾客到达队列。如果队列在1到n之间，则顾客到达该队列的末尾。否则，该事件将被忽略；
LEAVES：顾客离开队列。如果队列在1到n之间，并且该队列不为空，则该队列的第一个顾客将离开该队列。否则，该事件将被忽略。
【类库使用要求】可以使用STL类库
【输入形式】
1.     输入从队列的数量n（严格意义上为正的自然数）开始。
2.     按照n行，每个队列一行，每个行按照顾客到达队列的顺序，列出顾客名字。
3.     然后空一行。
4.     事件描述（ENTERS 或者LEAVES）后面，跟着顾客名字和和队列序号（正整数）。
【输出形式】
1.     首先，按离开的顺序打印离开队列的顾客姓名。
2.     然后，按顺序打印n个队列的最终内容。
【样例输入】
5
Lisa Tom
John
Jerry Mary

Eric
 
LEAVES 1
LEAVES 2
ENTERS Harry 2
【样例输出】
DEPARTS
Lisa
John
 
FINAL CONTENTS
queue 1: Tom
queue 2: Harry
queue 3: Jerry Mary
queue 4:
queue 5: Eric

【样例说明】
【评分标准】*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;


struct node {
	string name;
	node* next;
	node() {
		name = "";
		next = NULL;
	}
	node(string n) {
		name = n;
		next = NULL;
	}
};

class listDeque {
private:
	node* head;
	node* end;
public:
	listDeque() {
		end = new node;
		end->next = end;
		head = end;
	}
	void PUSH_BACK(string name) {
		end->next = new node(name);
		end = end->next;
		end->next = head;
	}
	string POP_FRONT() {
		if (head == end) {
			
			return "false";
		}
		else {
			string temp= head->next->name;
			node* p = head->next;
			head->next = head->next->next;
			if (end == p) {
				end = head;
			}
			delete p;
			return temp;
		}
	}
	void display() {
		node* p = head->next;
		while (p != head) {
			cout << p->name << ' ';
			p = p->next;
		}
	}
	
};

int main() {
	int num;
	cin >> num;
	vector<listDeque>qeque(num);
	string cleanEmpty1;
	getline(cin, cleanEmpty1);
	for (int i = 0; i < num; i++) {
		string c;
		getline(cin, c);
		int cNum=0;
		string name;
		bool empty = true;
		while (c[cNum] != '\0') {
			empty = false;
			if (c[cNum] != ' ') {
				name.push_back(c[cNum]);
			}
			else {
				qeque[i].PUSH_BACK(name);
				name.clear();
			}
			cNum++;
		}
		if (!empty) {
			qeque[i].PUSH_BACK(name);
			name.clear();
		}
	}
	string cleanEmpty2;
	getline(cin,cleanEmpty2);
	string op;
	vector<string>outpeople;
	int outnum = 0;
	while (getline(cin, op)) {
		if (op[0] == 'L') {
			int lineNum = 0;
			for (int i = 7; i < op.length(); i++) {
				lineNum = lineNum * 10 + (op[i] - '0');
			}
			if (lineNum > num)continue;
			string tempName;
			tempName = qeque[lineNum - 1].POP_FRONT();
			if (tempName == "false")continue;
			outpeople.push_back(tempName);
			outnum++;
		}
		else if (op[0] == 'E') {
			string tempName;
			int i = 7;
			while (op[i] != ' ') {
				tempName.push_back(op[i]);
				i++;
			}
			i++;
			int lineNum = 0;
			for (; i < op.length(); i++) {
				lineNum = lineNum * 10 + (op[i] - '0');
			}
			if (lineNum > num)continue;
			qeque[lineNum - 1].PUSH_BACK(tempName);
		}
	}

	cout << "DEPARTS" << endl;
	for (int i = 0; i < outnum; i++) {
		cout << outpeople[i] << endl;
	}
	cout << endl;
	cout << "FINAL CONTENTS" << endl;
	for (int i = 0; i < num; i++) {
		cout << "queue " << i + 1<<": ";
		qeque[i].display();
		cout << endl;
	}

}