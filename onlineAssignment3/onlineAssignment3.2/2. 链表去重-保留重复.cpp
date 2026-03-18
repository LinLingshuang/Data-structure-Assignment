//2. 链表去重-保留重复
//链表去重-保留重复
//一、问题描述

// 给定一个已排序的链表，删除重复的元素，使得每个元素只出现一次，返回删除后链表的头节点。

//二、输入形式
//一行若干个整数，表示已排序链表节点值，以-1结束。

//三、输出形式
//输出去重后的链表节点值，用空格分隔。

//四、样例输入

//1 1 2 3 3 3 4 5 5 -1
//五、样例输出

//1 2 3 4 5
//六、样例说明
//原链表：1 → 1 → 2 → 3 → 3 → 3 → 4 → 5 → 5
//去重后：1 → 2 → 3 → 4 → 5

//七、评分标准
//共6个测试用例。

//八、类库使用要求
//必须手动实现链表结构。要求原地修改，空间复杂度O(1)。可以使用iostream。
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

				break;
			}
			p->data = num;
			p = p->next;
		} while (num != -1);
		return head;
	}
	void deleteList() {
		node* p = head;
		node* q = head;
		while (q != NULL) {
			if (p->data == q->data) {
				q = q->next;
				
			}
			else {
				p->next = q;
				p = q;
			}

		}
		p->next = q;
	}
	void display() {
		node* p = head;
		while (p->next != NULL) {
			cout << p->data << ' ';
			p = p->next;
		}
	}

	node* head;

};

int main() {
	list mylist;
	mylist.creatList();
	mylist.deleteList();
	mylist.display();
}
