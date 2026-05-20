/*5. 第八章第9题
【问题描述】
一个无向图采用邻接表存储，设计一个算法在存在经过顶点v的简单回路时输出其中任意一条简单回路
【输入形式】
n m（点数、边数）
u1 v1(一条边连接u1和v1)
…
um vm
v(询问的顶点)
【输出形式】
将经过v的简单回路上的点按编号从小到大排序，并顺序输出，如
v1 v2 … vk (k为环长)
若没有经过v的简单回路，输出-1
【样例输入】
3 3
1 2
2 3
3 1
1
【样例输出】
1 2 3
【评分标准】
n<=200，无重边自环
*/
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
	bool getRing(int search, int target, vector<int>selfFind, vector<int>ring, vector<int>&resultring) {
		edgeNode* p = adjList[search - 1].firstEdge;
		selfFind[search - 1] = 1;
		bool result = false;
		ring.push_back(adjList[search - 1].info);
		while (p != NULL) {
			if (selfFind[p->data - 1] != 1) {
				
				if (getRing(p->data, target, selfFind, ring, resultring)) {
					result = true;
				}
			}
			else if (adjList[p->data - 1].info == target && ring.size() > 2) {
				resultring = ring;
				return true;
			}
			p = p->nextEdge;
		}
		return result;
	}


	
};

int main() {
	int n, e;
	cin >> n >> e;
	AdjGraph myGraph(n, e);
	int target;
	cin >> target;
	vector<int>selfFind(n,0);
	vector<int>ring;
	vector<int>resultring;
	if (myGraph.getRing(target, target, selfFind, ring, resultring)) {
		sort(resultring.begin(), resultring.end());
		for (int i : resultring) {
			cout << i << ' ';
		}
	}
	else {
		cout << -1;
	}
}