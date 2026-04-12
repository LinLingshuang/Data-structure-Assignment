/*3. 第三章 杨辉三角
【问题描述】
对于给定的正整数 n (n>2)，利用一个队列输出 n 阶杨辉三角形（帕斯卡三角形）。
第n阶杨辉三角形的规则如下：
第一行只有一个数字 1；
每行的第一个和最后一个数都是 1；
其余每个数等于上一行相邻两个数之和。
示例：当 n=5 时，杨辉三角形的生成过程如下：
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
【输入形式】输入一个整数 n（n>2），表示杨辉三角形的阶数。
【输出形式】输出 n 阶杨辉三角形，每行的数字以空格分隔。
【样例输入】5
【样例输出】
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
【样例说明】
【评分标准】
【类库使用要求】
可以使用STL中的queue、vector等库函数，可以使用字符串STL处理输入。
*/
#include<iostream>
using namespace std;


struct queue {
	int* head;
	queue(int n) {
		head = new int[n];
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			head[n - 1 - i] = temp;
		}
	}
	void output(int n) {
		for (int i = 0; i < n; i++) {
			cout << head[i] << ' ';
		}
	}

};

int main() {


}
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
	node* head = new node(0);
	node* end = new node(0);
public:
	listDeque(int n) {
		head->next = new node(1);
		head->next->next = end;
		display();
		for (int i = 1; i < n; i++) {
			int temp = 0;
			node* p = head;
			for (int j = 0; j < i; j++) {
				p->next->data = temp + p->next->data;
				temp = p->next->data - temp;
				p = p->next;
			}
			end->data = 1;
			end->next = new node(0);
			end = end->next;
			display();
		}
	}
	void display() {
		node* p = head->next;
		while (p->next != NULL) {
			cout << p->data << ' ';
			p = p->next;
		}
		cout << endl;
	}
};
int main() {
	int n;
	cin >> n;
	listDeque mLD(n);
}
