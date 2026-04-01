/*7. P2021 faebdc玩扑克
题目描述
zky 有 n 个扑克牌，编号从 1 到 n，zky 把它排成一个序列，每次把最上方的扑克牌放在牌堆底，
然后把下一张扑克牌拿出来输出，最终输出的序列恰好是从 1 到 n，faebdc 问你原序列是什么，
因为 faebdc 神犇早已在 O(1) 的时间得出结果，如果你在 1 s 内答不出来，faebdc 会吃了你。
输入格式
一个整数 n，表示扑克数目。
输出格式
n 个数，表示扑克序列。
输入输出样例
输入 #1
13
输出 #1
7 1 12 2 8 3 11 4 9 5 13 6 10
*/
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
public:
	listDeque() {
		end = new node;
		end->next = end;
		head = end;
	}
	listDeque(int num) {
		end = new node;
		end->next = end;
		head = end;
		PUSH_BACK(num);
		for (int i = 1; i < num; i++) {
			PUSH_FRONT(num - i);
			int temp = POP_BACK();
			PUSH_FRONT(temp);
		}
		display();
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
	int POP_FRONT() {
		if (head == end) {
			return -1;
		}
		else {
			int temp= head->next->data ;
			node* p = head->next;
			head->next = head->next->next;
			if (end == p) {
				end = head;
			}
			delete p;
			return temp;
		}
	}
	int POP_BACK() {
		if (head == end) {
			return -1;
		}
		else {
			int temp = end->data;
			node* p = end;
			node* q = head;
			while (q->next != end) {
				q = q->next;
			}
			end = q;
			end->next = head;
			delete p;
			return temp;
		}
	}
	void display() {
		node* p = head->next;
		while (p != head) {
			cout << p->data << ' ';
			p = p->next;
		}
	}
};
int main() {
	int n;
	cin >> n;
	listDeque my(n);
}