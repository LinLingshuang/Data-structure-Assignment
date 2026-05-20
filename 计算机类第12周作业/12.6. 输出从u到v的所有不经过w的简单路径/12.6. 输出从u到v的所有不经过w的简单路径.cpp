/*6. 第八章第11题
【问题描述】
假设一个有向图采用邻接表 G作为存储结构。设计一个算法，输出从顶点 u 到顶点 v 的所有不经过顶点 w 的简单路径。
所谓简单路径，是指路径中所有顶点不重复出现。
路径不能经过顶点 w，但允许从 u 到 v 是直接相连（只要不包含 w）。
【输入形式】
第一行输入四个整数：n m u v w
n 表示图中顶点个数（顶点编号为 0~n-1）
m 表示边数
u 表示起点
v 表示终点
w 表示不能经过的顶点编号
接下来 m 行，每行输入两个整数 a b，表示一条从 a 到 b 的有向边。
【输出形式】
每行输出一条路径，从起点 u 到终点 v，格式为：
 u1 u2 u3  ...  v 每个节点之间空一格
若没有路径，输出-1
【样例输入】
6 7 0 5 3
0 1
1 2
2 5
0 4
4 5
1 3
3 5
【样例输出】
0 1 2 5
0 4 5
【样例说明】
路径 0 → 1 → 3 → 5 被排除，因为中间包含禁止顶点 3
【评分标准】*/

#include<iostream>
#include<algorithm>
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
			adjList.push_back(headNode(i));
		}
		cearteAdjGrapha();
	}
	void cearteAdjGrapha() {
		for (int i = 0; i < e; i++) {
			int first, second;
			cin >> first >> second;
			edgeNode* firstNode = new edgeNode(second);
			edgeNode* p = adjList[first].firstEdge;
			if (p == NULL) {
				adjList[first].firstEdge = firstNode;
			}
			else {
				while (p->nextEdge != NULL) {
					p = p->nextEdge;
				}
				p->nextEdge = firstNode;
			}

			edgeNode* secondNode = new edgeNode(first);
			edgeNode* q = adjList[second].firstEdge;
			if (q == NULL) {
				adjList[second].firstEdge = secondNode;
			}
			else {
				while (q->nextEdge != NULL) {
					q = q->nextEdge;
				}
				q->nextEdge = secondNode;
			}
		}
	}

	bool getAllRoad(int search,int u,int v,int w, vector<int>selfFind, vector<int>road) {
		if (w == v || w == u) {
			return false;
		}
		edgeNode* p = adjList[search].firstEdge;
		selfFind[search] = 1;
		road.push_back(adjList[search].info);
		bool find = false;
		while (p != NULL) {
			if (adjList[p->data].info == v) {
				for (int i : road) {
					cout << i << ' ';
				}
				cout << v << endl;
				find = true;
			}
			else if (selfFind[p->data] != 1&& adjList[p->data].info!=w) {
				if (getAllRoad(p->data, u, v, w, selfFind, road)) {
					find = true;
				}
			}
			p = p->nextEdge;
		}
		return find;
	}

};

int main() {
	int n, e;
	cin >> n >> e;
	int u, v, w;
	cin >> u >> v >> w;
	//cout << endl << u << ' ' << v << ' ' << w << endl;
	AdjGraph myGraph(n, e);
	vector<int>selfFind(n,0);
	vector<int>road;
	if (!myGraph.getAllRoad(u, u, v, w, selfFind, road)) {
		cout << -1;
	}
	
}