//14. 判断链表是否有环
//判断链表是否有环
//一、问题描述
//给定一个单链表，判断链表中是否存在环。如果存在环，输出"YES"；否则输出"NO"。
//链表节点值为整数，输入格式特殊：每行输入两个整数val和next，val表示节点值，next表示下一个节点的位置索引（-1表示NULL）。
//二、输入形式
//第一行输入一个正整数n（1 ≤ n ≤ 100000），表示节点数量。
//接下来n行，每行两个整数val和next，表示第i个节点的值和下一个节点的索引（1-indexed）。
//三、输出形式
//输出"YES"或"NO"，表示链表是否有环。
//四、样例输入
//4
//1 2
//2 3
//3 4
//4 2
//五、样例输出
//YES
//六、样例说明
//链表结构：1 → 2 → 3 → 4 → 2（形成环：2→3→4→2）
//七、评分标准
//共6个测试用例。
//测试用例1-3：小规模数据，哈希法可过
//测试用例4-6：大规模数据，要求使用快慢指针法（Floyd判圈算法）
//八、类库使用要求
//可以使用iostream、vector。要求使用Floyd判圈算法，空间复杂度O(1)。
#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int data;
	int next;
};
int main() {
	int num;
	cin >> num;
	vector<Node>my(num + 1);
	for (int i = 1; i <= num; i++) {
		int a, b;
		cin >> a >> b;
		my[i].data = i;
		my[i].next = b;
	}
	for (int k = 1; k <= num; k++)
	{
		int slow = my[k].next;
		int fast = my[k].next;
		int dalay = 0;
		while (fast != -1) {
			fast = my[fast].next;
			if (fast == my[fast].next) {
				break;
			}
			if (fast == -1) {
				break;
			}
			fast = my[fast].next;
			slow = my[slow].next;
			if (fast == slow && fast != -1 && fast != my[fast].next) {
				cout << "YES";
				return 0;
			}
		}

	}
	cout << "NO";
	return 0;

}
/*
int main() {
	int num;
	cin >> num;
	vector<Node>my(10001000);
	vector<int>no(num);
	for (int i = 0; i < num; i++) {
		int a, b;
		cin >> a >> b;
		no[i] = a;
		my[a].data = a;
		my[a].next = b;
	}
	for (int k = 0; k < num; k++)
	{
		int slow = my[no[k]].next;
		int fast = my[no[k]].next;
		int dalay = 0;
		while (fast != -1) {
			fast = my[fast].next;
			if (fast == my[fast].next) {
				break;
			}
			if (fast == -1) {
				break;
			}
			fast = my[fast].next;
			slow = my[slow].next;
			if (fast == slow  && fast != -1 && fast != my[fast].next) {
				cout << "YES";
				return 0;
			}
		}

	}
	cout << "NO";
	return 0;

}
*/
/*
int main() {
	int num;
	cin >> num;
	vector<Node>myNode(num);
	for (int i = 0; i < num; i++) {
		cin >> myNode[i].data >> myNode[i].next;
	}
	for(int k=0;k<num;k++)
	{
		int slow = myNode[k].next;
		int fast = myNode[k].next;
		int dalay = 0;
		bool change = false;
		for (int i = 0; i < num; i++) {

			for (int j = 0; j < num; j++) {
				if (fast == myNode[j].data) {
					fast = myNode[j].next;
					dalay++;
					change = true;
					if (slow == fast && fast != -1 && change fast != myNode[k].next) {
						cout << "YES";
						return 0;
					}
					break;
				}

			}
			for (int j = 0; j < num; j++) {
				if (slow == myNode[j].data && dalay >= 10) {
					slow = myNode[j].next;
					dalay = 0;
					if (slow == fast && fast != -1 && change fast != myNode[k].next) {
						cout << "YES";
						return 0;
					}
					break;
				}
			}
			if (slow == fast&& fast!=-1 && change fast != myNode[k].next) {
				cout << "YES";
				return 0;
			}
		}

	}
	cout << "NO";
	return 0;
}
*/