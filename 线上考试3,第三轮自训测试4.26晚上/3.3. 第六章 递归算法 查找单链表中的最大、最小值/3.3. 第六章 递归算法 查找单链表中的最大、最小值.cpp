/*3. 第六章 递归算法 查找单链表中的最大、最小值
【问题描述】
设有一个不带表头结点的非空整数单链表 p，所有结点值不相同。请设计两个递归算法：
maxNode(p) 返回单链表 p 中的最大结点值。
minNode(p) 返回单链表 p 中的最小结点值。
要求用链表保存数据
【输入形式】
第一行输入一个整数 n，表示链表的长度（1 ≤ n ≤ 1000）。
第二行输入 n 个互不相同的整数，以空格分隔，表示链表中的结点值，按照链表顺序给出。
【输出形式】输出两行，第一行输出链表的最大结点值，第二行输出链表的最小结点值。
【样例输入】
5
3 1 4 2 5
【样例输出】
5
1
【样例说明】
【评分标准】
【说明】
要求用链表完成递归算法设计，可以使用STL库函数。
C++
(current)
草稿箱
1
*/
#include<iostream>
#include<list>
using namespace std;

int maxNode(const list<int>myList) {
	if (myList.size()==1) {
		return myList.front();
	}
	list<int>temp= myList;
	temp.pop_front();
	int tempNum = maxNode(temp);
	if (myList.front() < tempNum) {
		return tempNum;
	}
	else {
		return myList.front();
	}
}
int minNode(const list<int>myList) {
	if (myList.size() == 1) {
		return myList.front();
	}
	list<int>temp = myList;
	temp.pop_front();
	int tempNum = minNode(temp);
	if (myList.front() > tempNum) {
		return tempNum;
	}
	else {
		return myList.front();
	}
}

int main() {
	int n;
	list<int>myList;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		myList.push_back(temp);
	}
	cout << maxNode(myList) << endl;
	cout << minNode(myList) << endl;
}