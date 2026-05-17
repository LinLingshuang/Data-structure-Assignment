/*3. 【实战7.1】POJ1330—求树中两个结点的最近公共祖先（LCA）
【问题描述】
 如图所示是一棵有根树，图中每个结点用1～16的整数标识，结点8是树根。如果结点x位于根结点到结点y之间的路径中，
 则结点x是结点y的祖先。如果结点x是结点y和结点z的祖先，则结点x称为两个不同结点y和z的公共祖先。
 如果x是y和z的共同祖先并且在所有共同祖先中最接近y和z，则结点x被称为结点y和z的最近公共祖先，
 如果y是z的祖先，那么y和z的最近共同祖先是y。例如结点16和7的最近公共祖先是结点4，
 结点2和3的最近公共祖先是结点10，结点4和12的最近公共祖先是结点4。编写一个程序，找到树中两个不同结点的最近公共祖先。
image.png
【输入形式】
每个测试用例的第一行为树中结点数n（2≤n≤10,000），所有结点用整数1～n标识，
接下来的n-1行中的每一行包含一对表示边的整数，第一个整数是第二个整数的父结点。
请注意，具有n个结点的树具有恰好n-1个边。每个测试用例的最后一行为两个不同整数，
需要计算它们的最近公共祖先。
【输出形式】
为每个测试用例输出一行，该行应包含最近公共祖先结点的编号。
【样例输入】
16                                                                         
1 14
8 5
10 16
5 9
4 6
8 4
4 10
1 13
6 15
10 11
6 7
10 2
16 3
8 1
16 12
16 7
【样例输出】
4
【样例说明】
测试数据的文件名为in.txt
【评分标准】
该题目有10个测试用例，每通过一个测试用例，得10分。*/
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<fstream>
using namespace std;

struct node {
	int data;
	int pareant;
	node() {
		data = 0;
		pareant = 0;
	}
	node(int d) {
		data = d;
		pareant = 0;
	}
	node(int d,int p) {
		data = d;
		pareant = p;
	}
};

node tree[10000];

void createTree(int& n1,int& n2) {
	int n;
	fstream in;
	in.open("in.txt");
	in >> n;
	int cnt=0;
	vector<int>check;
	while(cnt<n) {
		int p, c;
		in >> p >> c;
		bool findp = false;
		bool findc = false;
		for (int temp : check) {
			if (temp == p)findp = true;
			if (temp == c)findc = true;
		}
		if (!findp) {
			check.push_back(p);
			tree[p] = node(p);
			cnt++;
		}
		if (!findc) {
			check.push_back(c);
			cnt++;
		}
		
		tree[c] = node(c, p);
	}
	in >> n1 >> n2;
}

int getLCA(int n1, int n2) {
	node x = tree[n1];
	node y = tree[n2];

	stack<int>parentX;
	stack<int>parentY;

	int pX = x.data;
	while (pX != 0) {
		parentX.push(tree[pX].data);
		pX = tree[pX].pareant;
	}

	int pY = y.data;
	while (pY != 0) {
		parentY.push(tree[pY].data);
		pY = tree[pY].pareant;
	}

	int LCAX = parentX.top();
	int LCAY = parentY.top();
	int temp = 0;
	while (LCAX == LCAY) {
		temp = LCAX;
		parentX.pop();
		parentY.pop();

		if (!parentX.empty()) {
			LCAX = parentX.top();
		}
		else {
			return temp;
		}

		if (!parentY.empty()) {
			LCAY = parentY.top();
		}
		else {
			return temp;
		}
	}

	return temp;

}

int main() {
	int n1, n2;
	createTree(n1, n2);

	int result= getLCA(n1, n2);
	cout << result;
}