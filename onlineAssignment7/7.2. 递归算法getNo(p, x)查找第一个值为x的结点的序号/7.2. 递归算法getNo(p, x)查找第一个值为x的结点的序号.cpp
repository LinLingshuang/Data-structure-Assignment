/*2. 第六章 第6题
【问题描述】
设有一个不带表头结点的整数单链表p，
设计一个递归算法getNo(p, x)查找第一个值为x的结点的序号（假设首结点的序号为0），没有找到时返回一1。
【输入形式】
第一行：链表长度
第二行：链表 元素以空格隔开
第三行：查找的值x
【输出形式】
结点序号
【样例输入】
3 
10 20 30 
10
【样例输出】
0
【样例说明】
【评分标准】*/
#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node() {
		data = 0; 
		next = NULL;
	}
	node(int val) {
		data = val;
		next = NULL;
	}
};

class list {
public:
	node* first;
	list() {
		first = new node();
	}
	list(list &l) {
		first = l.first;
	}
	void create() {
		int n;
		cin >> n;
		node* p = first;
		int temp;
		for (int i = 0; i < n-1; i++) {
			cin >> temp;
			p->data = temp;
			p->next = new node;
			p = p->next;
		}
		cin >> temp;
		p->data = temp;
		p->next = NULL;
	}
};

int getNo(list p, int x) {
	node* temp = p.first;
	if (temp == NULL) {
		return -1;
	}
	else if (temp->data == x) {
		return 0;
	}
	else {
		list subList = p;
		subList.first = subList.first->next;
		if (getNo(subList, x) == -1) {
			return -1;
		}
		else {
			return getNo(subList, x) + 1;
		}
	}
}
int main() {
	list myList;
	myList.create();
	int num;
	cin >> num;
	cout << getNo(myList, num);
}