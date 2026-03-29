/*4. 用队列实现栈
用队列实现栈
一、问题描述
仅使用队列实现栈的功能，支持以下操作：

PUSH x：将元素x压入栈顶

POP：弹出栈顶元素，栈空时输出"EMPTY"

TOP：查看栈顶元素，栈空时输出"EMPTY"

要求：所有操作的时间复杂度为O(n)。

二、输入形式
第一行输入一个正整数m（1 ≤ m ≤ 100000），表示操作数量。
接下来m行，每行一个操作，格式如上所述。

三、输出形式
对于POP、TOP操作，输出对应的值或错误信息，每行一个。

四、样例输入

6
PUSH 1
PUSH 2
TOP
POP
PUSH 3
POP
五、样例输出

2
2
3
六、样例说明
使用两个队列：q1（主队列）和q2（辅助队列）

PUSH：直接入队q1

POP/TOP：将q1中除最后一个元素外的所有元素移入q2，最后一个元素即为栈顶，操作完成后交换q1和q2

操作过程：

PUSH 1：q1=[1]

PUSH 2：q1=[1,2]

TOP：将1移入q2，查看2，将2移回q1，交换后q1=[1,2]，输出2

POP：将1移入q2，弹出2，交换后q1=[1]，输出2

PUSH 3：q1=[1,3]

POP：将1移入q2，弹出3，交换后q1=[1]，输出3

七、评分标准
共8个测试用例。

八、类库使用要求
只能使用队列（可以手动实现或使用STL queue），禁止使用栈。*/





#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;

};

struct list {
	node* head;
	void out() {
		node* p=head->next;
		while (p != NULL) {
			cout << p->data << " ";
		}
	}
};

int main() {
	int n; 
	cin >>n;
	list a,b;
	node* p = a.head;
	node* q = b.head;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp < 0) {
			cout << temp << " ";
		}
		else {
			p->next = new node;
			p->next->data = temp;
			p->next->next = NULL;
			p = p->next;
		}
	}
	a.out();
}