/*6. 哈夫曼树与哈夫曼编码
哈夫曼树与哈夫曼编码
一、问题描述
给定n个字符及其出现频率，构建哈夫曼树并计算WPL（带权路径长度）。
WPL定义：所有叶子节点的带权路径长度之和，其中带权路径长度 = 权值 × 路径长度（从根到叶子的边数）。
二、输入形式
第一行输入一个正整数n（1 ≤ n ≤ 10000），表示字符数量。
第二行输入n个正整数，表示各字符的出现频率（权值）。
三、输出形式
输出一个整数，表示WPL值。
四、样例输入
4
5 29 7 8
五、样例输出
95
六、样例说明
频率：A=5, B=29, C=7, D=8
哈夫曼树构建过程：
排序：5, 7, 8, 29
合并5+7=12，排序：8, 12, 29
合并8+12=20，排序：20, 29
合并20+29=49
WPL = 5×3 + 7×3 + 8×2 + 29×1 = 15 + 21 + 16 + 29 = 81
（注：不同合并顺序可能产生不同树形，但WPL相同）
七、评分标准
共10个测试用例。
八、类库使用要求
可以使用priority_queue（小顶堆），禁止使用其他容器。*/
#include<iostream>
#include<queue>
using namespace std;

struct HFMnode {
	int data;
	int weight;

	int parent;
	int lchild;
	int rchild;

	bool atleft;

	HFMnode() {
		data = 0;
		weight = 0;
		parent = -1;
		lchild = -1;
		rchild = -1;
		atleft = true;
	}
	HFMnode(int d,int w) {
		data = d;
		weight = w;
		parent = -1;
		lchild = -1;
		rchild = -1;
		atleft = true;
	}
	
};

HFMnode ht[20000];

struct heapNode {
	int weight;
	int label;
	heapNode( int w,int l) {
		label = l;
		weight = w;
	}
	bool operator<(const heapNode& n)const {
		return weight > n.weight;
	}
};

void createHFMtree(int n) {
	priority_queue<heapNode>pq;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		ht[i] = HFMnode(i, temp);
		pq.push(heapNode(temp,i));
	}
	for (int i = n; i < 2 * n - 1; i++) {
		heapNode p1 = pq.top();
		pq.pop();
		heapNode p2 = pq.top();
		pq.pop();

		ht[i] = HFMnode();
		ht[i].weight = ht[p1.label].weight + ht[p2.label].weight;

		ht[p1.label].parent = i;
		ht[p1.label].atleft = true;
		ht[i].lchild = p1.label;

		ht[p2.label].parent = i;
		ht[p2.label].atleft = false;
		ht[i].rchild = p2.label;

		pq.push(heapNode(ht[i].weight, i));
	}
}

int getWPL(int n) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		int p = ht[i].parent;
		int cnt = 0;
		int w = ht[i].weight;
		while (p != -1) {
			cnt++;
			p = ht[p].parent;
		}
		result += w * cnt;
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	createHFMtree(n);
	cout << getWPL(n);
}