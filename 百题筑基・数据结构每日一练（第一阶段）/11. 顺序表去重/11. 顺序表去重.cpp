/*11. 顺序表去重
一、问题描述
给定一个整数数组，删除其中的重复元素，使得每个元素只保留第一次出现的位置。保持原有元素的相对顺序不变。

二、输入形式
第一行输入一个正整数n（1 ≤ n ≤ 100000），表示数组长度。
第二行输入n个整数，表示数组元素。

三、输出形式
输出去重后的数组，元素之间用空格分隔。如果结果为空，输出空行。

四、样例输入

8
1 2 3 2 1 4 3 5
五、样例输出

1 2 3 4 5
六、样例说明
原数组：[1, 2, 3, 2, 1, 4, 3, 5]

1第一次出现在位置1，保留

2第一次出现在位置2，保留

3第一次出现在位置3，保留

2第二次出现，删除

1第二次出现，删除

4第一次出现，保留

3第二次出现，删除

5第一次出现，保留

去重后：[1, 2, 3, 4, 5]

七、评分标准
共6个测试用例。

测试用例1-2：小规模数据，双重循环解法可过

测试用例3-6：大规模数据，要求使用哈希优化

八、类库使用要求
可以使用vector、iostream、unordered_set。禁止使用unique函数。*/
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
		int i = 0;
		do {
			cin >> num;
			if (i == n) {
				p->next = new node;
			}
			else {
				p->next = NULL;
				(*p).next = NULL;

				break;
			}
			p->data = num;
			p = p->next;
			i++;
		} while (i <= n);
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
	int n;
	cin >> n;
	list mylist;
	mylist.creatList(n);
	mylist.deleteList();
	mylist.display();
}
