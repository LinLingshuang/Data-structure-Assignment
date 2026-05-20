/*4. 判断图的连通性
一、问题描述
给定一个无向图，判断该图是否是连通图。如果是连通图，输出"YES"；否则输出"NO"，并输出连通分量的数量。
二、输入形式
第一行输入两个正整数n和m（1 ≤ n ≤ 1000, 0 ≤ m ≤ 10000），表示节点数和边数。
接下来m行，每行两个整数u和v，表示节点u和v之间有一条边。
三、输出形式
如果是连通图，输出"YES"。
如果不是连通图，输出"NO"和连通分量数量，用空格分隔。
四、样例输入1
6 7
1 2
1 3
2 4
2 5
3 5
4 6
5 6
五、样例输出1
YES
六、样例输入2
5 2
1 2
3 4
七、样例输出2
NO 3
八、样例说明
样例1：所有节点都连通，是连通图。
样例2：连通分量有{1,2}、{3,4}、{5}，共3个，不是连通图。
九、评分标准
共6个测试用例。
十、类库使用要求
可以使用vector、queue。使用DFS或BFS遍历。*/
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
			adjList.push_back(headNode(i + 1));
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
		//cout << adjList[h - 1].info << ' ';
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
		//cout << adjList[h - 1].info << ' ';
		edgeNode* p = adjList[h - 1].firstEdge;
		queue<edgeNode*> qu;
		qu.push(p);
		while (!qu.empty()) {
			p = qu.front();
			qu.pop();
			while (p != NULL) {
				if (find[p->data - 1] != 1) {
					find[p->data - 1] = 1;
					//cout << p->data << ' ';
					qu.push(adjList[p->data - 1].firstEdge);
				}
				p = p->nextEdge;
			}
		}
	}

	int DFSA() {
		int result = 0;
		for (int i = 0; i < n; i++) {
			if (find[i] == 0) {
				DFS(i + 1);
				result++;
			}
		}
		return result;
	}
};

int main() {
	int n, e;
	cin >> n >> e;
	AdjGraph myGraph(n, e);
	int start;
	int cnt=myGraph.DFSA();
	if (cnt == 1) {
		cout << "YES";
	}
	else {
		cout << "NO " << cnt;
	}
}