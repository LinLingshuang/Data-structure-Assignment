//3. 查找倒数第k个节点
//查找倒数第k个节点
//一、问题描述
//给定一个单链表，查找并输出倒数第k个节点的值。如果k大于链表长度，输出 - 1。

//输入为先序遍历的链表节点值， - 1表示链表结束。

//二、输入形式
//第一行输入一个正整数k（1 ≤ k ≤ 100000）。
//第二行输入若干个整数，表示链表节点值，以 - 1结束。

//三、输出形式
//输出倒数第k个节点的值。如果不存在，输出 - 1。

//四、样例输入

//2
//1 2 3 4 5 - 1
//五、样例输出

//4
//六、样例说明
//链表：1 → 2 → 3 → 4 → 5 → NULL
//倒数第1个是5，倒数第2个是4，输出4。

//七、评分标准
//共6个测试用例。

//八、类库使用要求
//必须手动实现链表结构。要求使用双指针法（快慢指针），只遍历链表一次。可以使用iostream。
#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};
class list {
public:
	node* creatList() {
		int num = 0;
		head = new node;
		node* p = head;
		do {
			cin >> num;
			if (num != -1) {
				p->next = new node;
			}
			else {
				p->next = NULL;
				(*p).next = NULL;
				p = NULL;

				break;
			}
			p->data = num;
			p = p->next;
		} while (num != -1);
		return head;
	}
	void findNum(int k) {
		node* p = head;
		node* q = head;
		bool error = false;
		for (int i = 0; i < k; i++) {
			if (q->next == NULL) {
				cout << -1;
				error = true;
				break;
			}
			else {
				q = q->next;
			}
		}
		while (q->next != NULL) {
			q = q->next;
			p = p->next;
		}
		if(!error)	{
			cout << p->data;
		}
	}

	node* head;

};

int main() {
	list myList;
	int k;
	cin >> k;
	myList.creatList();
	myList.findNum(k);

}