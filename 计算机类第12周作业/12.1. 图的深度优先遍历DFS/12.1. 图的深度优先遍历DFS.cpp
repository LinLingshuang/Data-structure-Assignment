/*1. 图的深度优先遍历DFS
一、问题描述
给定一个无向图，从给定节点开始进行深度优先搜索（DFS），输出遍历顺序。
二、输入形式
第一行输入两个正整数n和m（1 ≤ n ≤ 1000, 1 ≤ m ≤ 10000），表示节点数和边数。
接下来m行，每行两个整数u和v，表示节点u和v之间有一条边。
最后一行输入一个整数s，表示遍历开始的起点。
三、输出形式
输出DFS遍历顺序，节点编号用空格分隔。
四、样例输入
6 7
1 2
1 3
2 4
2 5
3 5
4 6
5 6
1
五、样例输出
1 2 4 6 5 3
六、样例说明
图结构：
1 -- 2 -- 4 -- 6
|    |		   |
3 -- 5 -- - --
DFS遍历（从1开始，邻接点按编号升序）：
访问1，标记为已访问
访问1的未访问邻接点中最小编号2
访问2的未访问邻接点中最小编号4
访问4的未访问邻接点中最小编号6
访问6的未访问邻接点中最小编号5（2和4已访问）
访问5的未访问邻接点中最小编号3
七、评分标准
共6个测试用例。
八、类库使用要求
可以使用vector。必须手动实现DFS递归或迭代。*/
#include<iostream>
#include<vector>
using namespace std;

const int INF = 0x3f3f3f3f;

struct edgeNode {
	int data;
	int weight;
	edgeNode* nextEdge;
	edgeNode() {
		data = 0;
		weight = INF;
		nextEdge = NULL;
	}
	edgeNode(int d, int w = 1) {
		data = d;
		weight = w;
		nextEdge = NULL;
	}
	edgeNode(const edgeNode& e) {
		data = e.data;
		weight = e.weight;
		nextEdge = e.nextEdge;
	}
};

struct headNode {
	int info;
	edgeNode* firstEdge;
	headNode() {
		info = 0;
		firstEdge = NULL;
	}
	headNode(int i) {
		info = i;
		firstEdge = NULL;
	}
};

class AdjGraph {
public:
	vector<headNode>adjList;
	int n, e;
	vector<int>find;
	AdjGraph(int nn = 0, int ee = 0) {
		n = nn;
		e = ee;
		find = vector<int>(n, 0);
		for (int i = 0; i < n; i++) {
			adjList.push_back(headNode());
		}
		cearteAdjGrapha();
	}
	void cearteAdjGrapha() {
		for (int i = 0; i < e; i++) {
			int first, second;
			cin >> first >> second;
			edgeNode* firstNode = new edgeNode(second);
			edgeNode *p= adjList[first - 1].firstEdge;
			if (p == NULL) {
				adjList[first - 1].info = first;
				adjList[first - 1].firstEdge = firstNode;
			}
			else {
				while (p->nextEdge != NULL) {
					p = p->nextEdge;
				}
				p->nextEdge = firstNode;
			}

			edgeNode* secondNode = new edgeNode(first);
			edgeNode* q = adjList[second - 1].firstEdge;
			if (q == NULL) {
				adjList[second - 1].info = second;
				adjList[second - 1].firstEdge = secondNode;
			}
			else {
				while (q->nextEdge != NULL) {
					q = q->nextEdge;
				}
				q->nextEdge = secondNode;
			}
		}
	}
	void DFS(int h) {
		find[h - 1] = 1;
		cout << adjList[h - 1].info<<' ';
		edgeNode* p= adjList[h - 1].firstEdge;
		while (p != NULL) {
			if (find[p->data-1] != 1) {
				DFS(p->data);
			}
			p = p->nextEdge;
		}
	}
};

int main() {
	int n, e;
	cin >> n >> e;
	AdjGraph myGraph(n, e);
	int start;
	cin >> start;
	myGraph.DFS(start);
}