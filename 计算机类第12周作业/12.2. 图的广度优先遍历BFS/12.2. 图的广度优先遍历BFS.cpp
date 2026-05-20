/*2. 图的广度优先遍历BFS
一、问题描述
给定一个无向图，从指定节点s开始进行广度优先搜索（BFS），输出遍历顺序。
二、输入形式
第一行输入两个正整数n和m（1 ≤ n ≤ 1000, 1 ≤ m ≤ 10000），表示节点数和边数。
接下来m行，每行两个整数u和v，表示节点u和v之间有一条边。
最后一行输入一个整数n，表示广度优先遍历的起点。
三、输出形式
输出BFS遍历顺序，节点编号用空格分隔。
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
1 2 3 4 5 6
六、样例说明
图结构：
1 -- 2 -- 4 -- 6
|    |    |
3 -- 5 --
BFS遍历（从1开始，邻接点按编号升序）：
访问1，队列[1]
弹出1，访问其邻接点2、3，队列[2,3]
弹出2，访问其未访问邻接点4、5，队列[3,4,5]
弹出3，其邻接点1、5都已访问，队列[4,5]
弹出4，访问其未访问邻接点6，队列[5,6]
弹出5，其邻接点都已访问，队列[6]
弹出6
七、评分标准
共6个测试用例。
八、类库使用要求
可以使用vector、queue。必须手动实现BFS。*/
#include<iostream>
#include<vector>
#include<queue>
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
			edgeNode* p = adjList[first - 1].firstEdge;
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
		cout << adjList[h - 1].info << ' ';
		edgeNode* p = adjList[h - 1].firstEdge;
		while (p != NULL) {
			if (find[p->data - 1] != 1) {
				DFS(p->data);
			}
			p = p->nextEdge;
		}
	}
	void BFS(int h) {
		find[h - 1] = 1;
		cout << adjList[h - 1].info << ' ';
		edgeNode* p = adjList[h - 1].firstEdge;

		queue<edgeNode*> qu;
		qu.push(p);	
		while (!qu.empty()) {
			p = qu.front();
			qu.pop();
			while (p != NULL) {
				if (find[p->data - 1] != 1) {
					find[p->data - 1] = 1;
					cout << p->data << ' ';
					qu.push(adjList[p->data - 1].firstEdge);
				}		
				p = p->nextEdge;
			}
		}
		
		
	}
};

int main() {
	int n, e;
	cin >> n >> e;
	AdjGraph myGraph(n, e);
	int start;
	cin >> start;
	myGraph.BFS(start);
}