//4. 偶数出栈
//【问题描述】
//假设有一个整数链栈st，设计一个算法，出栈从栈顶开始的所有偶数结点。
//【输入形式】
//1.程序首先会读取一个整数n，表示链栈中初始的元素个数。
//2.接下来读取n个整数，表示链栈中的元素（从栈顶到栈底依次输入）。
//【输出形式】
//1.按出栈顺序（从栈顶到栈底）输出出栈的偶数结点，用空格分隔。
//2.输出出栈操作后剩余的链栈内容（从栈顶到栈底），结点间用空格分隔。
//3.若无需要出栈的结点，则只输出原始链栈；若所有结点全部出栈，则只输出出栈的结点。
//【样例输入1】
//6
//1 6 3 4 5 2
//【样例输出1】
//6 4 2
//1 3 5
//【样例说明1】
//1.构造初始链栈内容为 1 -> 6 -> 3 -> 4 -> 5 -> 2（栈顶为 1，栈底为4）。
//2.删除值为6、4、2的结点.
//3.删除后链栈内容为1->3->5，并输出删除的节点值6、4、2。
//【样例输入2】
//3
//1 3 5
//【样例输出2】
//1 3 5
//【样例说明2】
//1.构造初始链栈内容为 1 -> 3 -> 5（栈顶为 1，栈底为 5）。
//2.没有需要出栈的节点，输出链栈内容为 1 3 5。
//【样例输入3】
//3
//6 4 2
//【样例输出3】
//6 4 2
//【样例说明2】
//1.构造初始链栈内容为 6 -> 4 -> 2（栈顶为 6，栈底为 2）。
//2.6、4、2节点均出栈输出，原始链栈变空无输出。
//【类库使用要求】
//不可以使用STL中的stack、queue、vector等库函数，可以使用字符串STL处理输入。
//【说明】
//要求自己设计实现栈或队列类
#include<iostream>
#include<string>
using namespace std;

struct node {
	node(int d, node* n) {
		data = d;
		next = n;
	}
	int data;
	node* next;
};

struct listStack {
	node* head = new node(NULL, NULL);
	void add(int x) {
		node* p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = new node(x, NULL);
	}
	void output() {
		node* p = head;
		while (p->next != NULL) {
			if ((p->next->data) % 2 == 0) {
				cout << p->next->data<<' ';
				node* temp = p->next;
				p->next = p->next->next;
				delete temp;
				continue;
			}
			else {
				p = p->next;
			}
		}
		cout << endl;
		p = head;
		p = p->next;
		while (p != NULL) {
			cout << p->data << ' ';
			p = p->next;
		}
	}
};


int main() {
	int n;
	cin >> n;
	listStack myLS;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		myLS.add(temp);
	}
	myLS.output();

}