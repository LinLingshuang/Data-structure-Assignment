/*3. 图的存储-邻接矩阵与邻接表
一、问题描述
给定一个有n个节点、m条边的无向图，分别用邻接矩阵和邻接表存储，并输出两种存储形式。
二、输入形式
第一行输入两个正整数n和m（1 ≤ n ≤ 100, 1 ≤ m ≤ n(n-1)/2），表示节点数和边数。
接下来m行，每行两个整数u和v（1 ≤ u, v ≤ n），表示节点u和v之间有一条边。
三、输出形式
首先输出n行，每行n个整数，表示邻接矩阵（0表示无边，1表示有边）。
然后输出n行，每行格式为"i: v1 v2 ..."，表示节点i的邻接点列表（按升序排列）。
四、样例输入
4 4
1 2
1 3
2 4
3 4
五、样例输出
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
1: 2 3
2: 1 4
3: 1 4
4: 2 3
六、评分标准
共6个测试用例。
七、类库使用要求
可以使用vector。*/
#include<iostream>
#include<vector>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<vector<int>> creatGraphMartix() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> result(n, vector<int>(n,0));
	for (int i = 0; i < m; i++) {
		int f, s;
		cin >> f >> s;
		result[f - 1][s - 1] = 1;
		result[s - 1][f - 1] = 1;
	}
	return result;
}


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
	vector<vector<int>>graphMartix;
	vector<int>find;
	AdjGraph(int nn = 0, int ee = 0) {
		n = nn;
		e = ee;
		find = vector<int>(n, 0);
		for (int i = 0; i < n; i++) {
			adjList.push_back(headNode());
		}
		cearteAdjGraph();
	}
	
	AdjGraph(vector<vector<int>>GM) {
		graphMartix = GM;
		n = graphMartix.size();
		e = 0;
		find = vector<int>(n, 0);
		for (int i = 0; i < n; i++) {
			adjList.push_back(headNode());
		}
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (graphMartix[i][j] == 1) {
					edgeNode* node1 = new edgeNode(j + 1);
					edgeNode* node2 = new edgeNode(i + 1);
					edgeNode* p = adjList[i].firstEdge;
					edgeNode* q = adjList[j].firstEdge;
					if (p != NULL) {
						while (p->nextEdge != NULL) {
							p = p->nextEdge;
						}
						p->nextEdge = node1;
					}
					else {
						adjList[i].info = i + 1;
						adjList[i].firstEdge = node1;
					}
					if (q != NULL) {
						while (q->nextEdge != NULL) {
							q = q->nextEdge;
						}
						q->nextEdge = node2;
					}
					else {
						adjList[j].info = j + 1;
						adjList[j].firstEdge = node2;
					}
					e++;
				}
			}
		}

	}

	void cearteAdjGraph() {
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

	void displayGraphMartix() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << graphMartix[i][j] << ' ';
			}
			cout << endl;
		}
	}

	void displayAdjGraph() {
		for (int i = 0; i < n; i++) {
			cout << adjList[i].info << ':' << ' ';
			edgeNode* p = adjList[i].firstEdge;
			if (p != NULL) {
				cout << p->data << ' ';
				while (p->nextEdge != NULL) {
					p = p->nextEdge;
					cout << p->data << ' ';
				}
				
			}
			cout << endl;
		}
	}
};

int main() {
	vector<vector<int>> GM = creatGraphMartix();
	AdjGraph myGraph(GM);
	myGraph.displayGraphMartix();
	myGraph.displayAdjGraph();
}