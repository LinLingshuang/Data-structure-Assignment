/*3. 第六章 递归算法 删除指定值节点
[问题描述]
设计一个递归算法，在不带表头结点的整数单链表中删除所有值等于给定值x的节点。链表中的元素由用户输入确定。
要求用链表保存数据，并删除指定节点。
[输入形式]
第一行是一个整数n，表示链表的长度；
第二行是n个用空格分隔的整数，表示链表中的值；
第三行是一个整数x，表示需要删除节点的值。
[输出形式]
按修改后的链表顺序输出所有剩余节点的值。如果链表为空，则只输出"-1"。
[输入样例]
5
1 2 3 2 4
2
[输出样例]
1 3 4
[样例说明]
删除值为2的所有节点后，链表中剩余的元素是{1, 3, 4}。
[说明]
要求用链表完成算法设计，可以使用STL库函数。*/
#include<iostream>
#include<list>
using namespace std;

list<int> cleanX(list<int>myList,int x) {
	if (myList.empty()) {
		return myList;
	}
	else {
		if (myList.front() != x) {
			list<int> head;
			head.push_back(myList.front());

			myList.pop_front();
			list<int> back = cleanX(myList, x);

			for (int temp : back) {
				head.push_back(temp);
			}

			return head;
		}
		else {
			myList.pop_front();
			list<int> head = cleanX(myList, x);
			return head;
		}
	}
}

int main() {
	int n;
	cin >> n;
	list<int>myList;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		myList.push_back(temp);
	}
	int x;
	cin >> x;
	myList = cleanX(myList, x);
	if (myList.empty()) {
		cout << -1;
		return 0;
	}
	else {
		for (int temp : myList) {
			cout << temp;
		}
	}
}