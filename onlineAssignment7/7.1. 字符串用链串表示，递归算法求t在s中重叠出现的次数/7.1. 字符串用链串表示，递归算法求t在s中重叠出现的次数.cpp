/*1. 第六章第3题
【问题描述】
假设一个字符串采用链串表示，设计一个递归算法求t在s中重叠出现的次数。
【输入形式】
第一行输入串s，第二行输入串t。(空格也可以作为串中的一个字符)
【输出形式】
仅一行，输出t在s中重叠出现的次数
【样例输入】
aababad
aba
【样例输出】
2
【样例说明】
aba在aababad重复出现了两次
【评分标准】
题目强调了使用递归算法，仅是普通的遍历会扣分；
题目强调了该串采用链串表示，使用其他形式的会酌情扣分。*/
#include<iostream>
using namespace std;

struct node {
	char data;
	node* next;
	node() {
		data = 0;
		next = NULL;
	}
};
class listSring {
public:
	node* head;
	
	listSring() {
		head = new node;
	}
	listSring(listSring &l) {
		head = l.head;
	}
	void createList() {
		node* p = head;
		char c;
		cin.get(c);
		while (c != '\n') {
			p->next = new node;
			p = p->next;
			p->data = c;
			cin.get(c);
			
		}
		
	}
};

int getSum(listSring s, listSring t) {
	bool isSubstr = true;
	node* p = s.head;
	node* q = t.head;
	if (p == NULL) {
		return 0;
	}
	while (p->next != NULL && q->next != NULL) {
		p = p->next;
		q = q->next;
		if (p->data != q->data) {
			isSubstr = false;
		}
	}
	if (q->next != NULL &&p->next == NULL) {
		isSubstr = false;
	}
	listSring subS = s;
	subS.head = subS.head->next;
	if (isSubstr) {
		return getSum(subS,t)+1;
	}
	else {
		return getSum(subS,t);
	}
}

int main() {
	listSring s, t;
	s.createList();
	t.createList();
	cout << getSum(s, t);
}