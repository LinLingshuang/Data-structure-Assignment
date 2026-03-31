/*1. 双端队列实现
双端队列实现
一、问题描述
实现一个双端队列（Deque），支持在队列两端进行插入和删除操作。
支持的操作：
PUSH_FRONT x：在队头插入元素x
PUSH_BACK x：在队尾插入元素x
POP_FRONT：移除队头元素，队空输出"EMPTY"
POP_BACK：移除队尾元素，队空输出"EMPTY"
FRONT：查看队头元素，队空输出"EMPTY"
BACK：查看队尾元素，队空输出"EMPTY"
二、输入形式
第一行输入一个正整数m（1 ≤ m ≤ 100000），表示操作数量。
接下来m行，每行一个操作，格式如上所述。
三、输出形式
对于需要输出的操作，输出对应的结果，每行一个。
四、样例输入
8
PUSH_BACK 1
PUSH_BACK 2
PUSH_FRONT 3
FRONT
BACK
POP_FRONT
POP_BACK
SIZE
五、样例输出
3
2
3
2
六、样例说明
操作过程：
PUSH_BACK 1：队列[1]
PUSH_BACK 2：队列[1,2]
PUSH_FRONT 3：队列[3,1,2]
FRONT：队头为3
BACK：队尾为2
POP_FRONT：弹出3，输出3
POP_BACK：弹出2，输出2
SIZE：大小为1
七、评分标准
共6个测试用例。
八、类库使用要求
可以使用deque或手动实现双向链表，可以使用STL deque。*/
#include<iostream>
#include<string>
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
		else{
			node* p = head->next;
			head->next = new node(val);
			head->next->next = p;
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
	bool POP_BACK() {
		if (head == end) {
			cout << "EMPTY" << endl;
			return false;
		}
		else {
			cout << end->data << endl;
			node* p = end;
			node* q = head;
			while (q->next != end) {
				q = q->next;
			}
			end = q;
			end->next = head;
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
	bool BACK() {
		if (head == end) {
			cout << "EMPTY" << endl;
			return false;
		}
		else {
			cout << end->data << endl;
			return true;
		}
	}
	int SIZE() {
		int size = 0;
		node* p = head;
		while (p->next != head) {
			p = p->next;
			size++;
		}
		return size;
	}
};

int main() {
	int op;
	cin >> op;
	listDeque myDeque;
	for (int i = 0; i < op; i++) {
		string temp;
		cin >> temp;
		if (temp == "PUSH_BACK"){
			int num;
			cin >> num;
			myDeque.PUSH_BACK(num);
		}
		else if (temp == "PUSH_FRONT") {
			int num;
			cin >> num;
			myDeque.PUSH_FRONT(num);
		}
		else if (temp == "POP_FRONT") {
			myDeque.POP_FRONT();
		}
		else if (temp == "POP_BACK") {
			myDeque.POP_BACK();
		}
		else if (temp == "FRONT") {
			myDeque.FRONT();
		}
		else if (temp == "BACK") {
			myDeque.BACK();
		}
		else if (temp == "SIZE") {
			cout<<myDeque.SIZE();
		}
	}



}

