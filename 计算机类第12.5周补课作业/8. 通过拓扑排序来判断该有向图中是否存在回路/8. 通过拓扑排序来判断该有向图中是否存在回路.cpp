/*8. 第八章第16题
【问题描述】
已知一个有向图采用邻接表的方式存储，图中节点编号从 1 到 N。
邻接表的每个节点包含一个顶点的编号以及一个指向其邻接顶点链表的指针。
设计一个算法，通过拓扑排序来判断该有向图中是否存在回路。
如果存在回路，说明图不是一个有向无环图（DAG）；如果不存在回路，则图是一个有向无环图。
【输入形式】
第一行输入两个整数 N 和 M（1 ≤ N ≤ 1000，0 ≤ M ≤ N * (N - 1)），分别表示图中顶点的数量和边的数量。
接下来 M 行，每行输入两个整数 u 和 v（1 ≤ u, v ≤ N），表示存在一条从顶点 u 到顶点 v 的有向边。
【输出形式】
如果图中存在回路，输出 "Yes"；如果图中不存在回路，输出 "No"。
【样例输入】
4 4
1 2
2 3
3 4
4 1
【样例输出】
Yes
【样例说明】
在这个样例中，输入的有向图包含 4 个顶点和 4 条边，
边的关系为从 1 到 2，从 2 到 3，从 3 到 4，从 4 到 1。
通过拓扑排序可以发现，该图中存在回路（1 -> 2 -> 3 -> 4 -> 1），所以输出 "Yes"。*/
#include<iostream>
#include<vector>
#include<stack>
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
	AdjGraph(int nn = 0, int ee = 0) {
		n = nn;
		e = ee;
		for (int i = 0; i < n; i++) {
			adjList.push_back(headNode());
		}
		cearteAdjGraph();
	}
	void cearteAdjGraph() {
		for (int i = 0; i < e; i++) {
			int u, v;
			cin >> u >> v;
			edgeNode* newNode = new edgeNode(v);
			edgeNode* p = adjList[u - 1].firstEdge;
			if (p == NULL) {
				adjList[u - 1].info = u;
				adjList[u - 1].firstEdge = newNode;
			}
			else {
				while (p->nextEdge != NULL) {
					p = p->nextEdge;
				}
				p->nextEdge = newNode;
			}

		}
	}
};

void topSort(AdjGraph g) {
	stack<int>st;
	vector<int>ind(g.n, 0);
	edgeNode* p;
	for (int i = 0; i < g.n; i++) {
		p = g.adjList[i].firstEdge;
		while (p != NULL) {
			int w = p->data-1;
			ind[w]++;
			p = p->nextEdge;
		}
	}
	for (int i = 0; i < g.n; i++) {
		if (ind[i] == 0) {
			st.push(i);
		}
	}
	int num = 0;
	while (!st.empty()) {
		int i = st.top(); st.pop();
		num++;
		p = g.adjList[i].firstEdge;
		while (p != NULL) {
			int w = p->data - 1;
			ind[w]--;
			if (ind[w] == 0)st.push(w);
			p = p->nextEdge;
		}
		
	}
	if (num==g.n) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
}


int main() {
	int n, m, s;
	cin >> n >> m;
	AdjGraph G(n, m);
	topSort(G);
}