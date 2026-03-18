//4. 链表负整数原地前置
//【问题描述】
//有一个整数单链表L，设计一个算法将所有负整数的元素移到其他元素的前面，分别保持负数和正数的原始相对顺序，
// 要求在原始链表上操作，不额外新建链表。例如，L = (1, 2, -1, -2, 3, -3, 4)，移动后L = (-1, -2, -3, 1, 2, 3, 4)。
//【输入形式】
//第一行输入一个正整数N，表示链表的长度
//第二行输入N个整数A[i]，表示链表的元素
//【输出形式】
//输出一行整数，表示操作后的链表
//【样例输入】
//4
//1 - 3 - 5 7
//【样例输出】
//- 3 –5 1 7
//【样例说明】
//【评分标准】
//保证整数在int范围内
//N < 100000
//【类库使用要求】
//不可以使用STL库函数
//【说明】
//需要自行定义链表，完成链表的操作，不能使用STL库
#include<iostream>
using namespace std;


struct node {
	int data;
	node* next;
};
class list {
public:
	node* creatList(int n) {
		int num = 0;
		head = new node;
		node* p = head;
		for (int i = 0; i < n; i++) {
			cin >> num;
			if(i!=n-1)	{
				p->data = num;
				p->next = new node;
				p = p->next;
			}
			else {
				p->data = num;
				p->next = NULL;
			}
		}
		return head;
	}
	void soft(int n){
		bool changehead = false;
		bool m = false;
		if (head->data >= 0) {
			changehead = true;
		}
		node* p = head;
		node* q=NULL;
		while (p != NULL) {
			
			if (p->data >= 0) {
				q = p;
				m = true;
			}
			else {
				if (m) {
					q->next = p->next;
					p->next = head;
					node* s = head;
					node* t=NULL;
					while (s->data < 0) {
						t = s;
						s = s->next;
					}

					if (!changehead) {
						p->next = s;
						t->next = p;
					}
					else {
						p->next = s;
						head = p;
						changehead = false;
					}

					p = q;
					m = false;
					continue;
				}
			}
			p = p->next;
		}

		
	}
	void display() {
		node* p = head;
		while (p != NULL) {
			cout << p->data << ' ';
			p = p->next;
		}
	}

	node* head;

};

int main() {
	list my;
	int n;
	cin >> n;
	my.creatList(n);
	my.soft(n);
	my.display();
	

}