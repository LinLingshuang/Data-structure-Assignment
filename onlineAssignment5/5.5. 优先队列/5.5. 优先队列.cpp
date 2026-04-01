/*5. 优先队列
题目描述
给定一个数列，初始为空，请支持下面三种操作：
1.给定一个整数 x请将 x 加入到数列中。
2.输出数列中最小的数。
3.删除数列中最小的数（如果有多个数最小，只删除1个）。
输入格式
第一行是一个整数，表示操作的次数 n。接下来 n 行，每行表示一次操作。每行首先有一个整数 op 表示操作类型。
若 op=1，则后面有一个整数 x，表示要将 x 加入数列。
若 op=2，则表示要求输出数列中的最小数。
若 op=3，则表示删除数列中的最小数。如果有多个数最小，只删除 1 个。
输出格式
对于每个操作 2，输出一行一个整数表示答案。
输入输出样例 #1
输入 #1
5
1 2
1 5
2
3
2
输出 #1
2
5
说明/提示
【数据规模与约定】
对于30% 的数据，保证 n≤15。
对于 70% 的数据，保证 n≤10^4。
对于 100% 的数据，保证 1≤n≤10^6，1≤x<2^31，op∈{1,2,3}。*/
#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node() {
		data = NULL;
		next = NULL;
	}
	node(int val) {
		data = val;
		next = NULL;
	}
};

class listDeque {
private:
	node* head;
	node* end;
	int min = 0, max = 0;
public:
	listDeque() {
		end = new node;
		end->next = end;
		head = end;
	}
	listDeque(int num) {

	}
	void PUSH_BACK(int val) {
		end->next = new node(val);
		end = end->next;
		end->next = head;
	}
	void PUSH_FRONT(int val) {
		if (head == end) {
			end->next = new node(val);
			end = end->next;
			end->next = head;
		}
		else {
			node* p = head->next;
			head->next = new node(val);
			head->next->next = p;
		}
	}
	void insert(int num) {
		if (min == max&& min!=0) {
			if (num >= max) {
				PUSH_BACK(num);
				max = num;
			}
			else {
				PUSH_FRONT(num);
				min = num;
			}
		}
		else if (min == max) {
			PUSH_BACK(num);
			min = num;
			max = num;
		}
		else {
			if (num >= max) {
				PUSH_BACK(num);
				max = num;
			}
			else if (num <= min) {
				PUSH_FRONT(num);
				min = num;
			}
			else {
				node* p=head->next;
				node* q=head;
				while (p->data < num) {
					p = p->next;
					q = q->next;
				}
				node* t = q->next;
				q->next = new node(num);
				q->next->next = t;
			}
		}
	}
	bool POP_FRONT() {
		if (head == end) {
			cout << "EMPTY" << endl;
			return false;
		}
		else {
			cout << head->next->data << endl;
			node* p = head->next;
			head->next = head->next->next;
			if (end == p) {
				end = head;
			}
			delete p;
			return true;
		}
	}
	bool FRONT() {
		if (head == end) {
			cout << "EMPTY" << endl;
			return false;
		}
		else {
			cout << head->next->data << endl;
			return true;
		}
	}
};

int main() {
	int n;
	cin >> n;
	listDeque mLD;
	for (int i = 0; i < n; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			int num;
			cin >> num;
			mLD.insert(num);
		}
		else if (op == 2) {
			mLD.FRONT();
		}
		else if (op == 3) {
			mLD.POP_FRONT();
		}
	}


}