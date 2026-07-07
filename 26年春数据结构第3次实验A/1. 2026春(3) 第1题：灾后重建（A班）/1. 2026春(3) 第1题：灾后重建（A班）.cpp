/*1. 2026春(3) 第1题：灾后重建（A班）
【问题描述】B地区现有编号为0～N-1的N个村庄及M条双向公路，地震后村庄需逐步重建，
公路保持完好。规则为：仅连接两个均已重建村庄的公路可通行，且仅能抵达已重建村庄。
现有Q次查询，每次询问：第t天时，从村庄x到村庄y的最短路径长度为多少。
规则如下：
① 村庄i在第ti天完成重建，重建当日即可通行；若t<ti，则该村庄未重建、不可通行。
仅连接两个均已重建村庄的公路可使用，每条公路长度不超过10000。 
②若起点x或终点y未重建，或二者在仅使用已重建村庄的前提下无通路，输出−1。 
③各村庄重建时间ti非递减（ti≥0，ti=0表示初始即可通车），查询时间t同样非递减。 
④数据范围：N≤100，M≤500，Q≤100。
【输入形式】键盘输入：
第一行输入两个正整数N、M，分别表示村庄总数与公路条数。
第二行输入N个非负整数ti，依次表示编号0～N−1村庄的重建完成时间，数据保证ti非递减。
接下来M行，每行输入三个非负整数i、j、w，表示村庄i与j之间存在一条长度为w的双向道路，
其中w≤10000，保证i≠j且任意两村庄间至多一条公路。
随后一行输入一个正整数Q，表示查询次数。
接下来Q行，每行输入三个非负整数x、y、t，表示询问第t天时从村庄x到y的最短路径长度，查询时间t非递减。
【输出形式】输出共 Q 行，对每一个询问(x,y,t)输出对应的答案，
即在第 t 天，从村庄 x 到村庄 y 的最短路径长度为多少。
如果经过若干个已重建完成的村庄，在第 t 天无法找到从 x 村庄到 y 村庄的路径，
或者村庄 x 或村庄 y 在第t 天仍未修复完成，则输出-1。
3 3
1
2
3
0 1 2
1 2 3
0 2 6
1
1 0 2

【样例输入】                        
4 5
1 2 3 4
0 2 1
2 3 1
3 1 2
2 1 4
0 3 5
4
2 0 2
0 1 2
0 1 3
0 1 4
【样例输出】 
-1
-1
5
4*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Qnode {
	int v;
	int dist;
	Qnode(int v, int d) {
		this->v = v; dist = d;
	}
	bool operator <(const Qnode& s)const {
		return dist > s.dist || (dist >= s.dist && v > s.v);
	}
};

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
	int rebuildTime=0;
	edgeNode* firstEdge;
	headNode() {
		info = 0;
		rebuildTime = 0;
		firstEdge = NULL;
	}
	headNode(int t) {
		info = 0;
		rebuildTime = t;
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
			int t;
			cin >> t;
			//cout << t << endl;
			adjList.push_back(headNode(t));
		}
		cearteAdjGrapha();
	}
	void cearteAdjGrapha() {
		for (int i = 0; i < e; i++) {
			int first, second,w;
			cin >> first >> second >> w;
			//cout << first << ' ' << second << ' ' << w << endl;
			edgeNode* firstNode = new edgeNode(second,w);
			edgeNode* p = adjList[first].firstEdge;
			if (p == NULL) {
				adjList[first].info = first;
				adjList[first].firstEdge = firstNode;
			}
			else {
				while (p->nextEdge != NULL) {
					p = p->nextEdge;
				}
				p->nextEdge = firstNode;
			}

			edgeNode* secondNode = new edgeNode(first,w);
			edgeNode* q = adjList[second].firstEdge;
			if (q == NULL) {
				adjList[second].info = second;
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
	void allSearch() {
		int Q;
		cin >> Q;
		for (int i = 0; i < Q; i++) {
			int x, y, t;
			cin >> x >> y >> t;
			//cout << x << ' ' << y << ' ' << t << endl;
			cout << search(x, y, t) << endl;
		}
	}
	int search(int x, int y, int t) {
		if (adjList[x].rebuildTime > t || adjList[y].rebuildTime > t) {
			return -1;
		}
		else {
			int result = DijkstraPlus(x, t, y);
			if (result == INF) {
				return -1;
			}
			else {
				return result;
			}
		}
	}
	int DijkstraPlus(int s, int t,int y) {
		priority_queue<Qnode> pq;
		vector<int> dist(this->n, INF);
		vector<int> S(this->n, 0);
		dist[s] = 0;
		pq.push(Qnode(s, dist[s]));

		while (!pq.empty()) {
			Qnode temp = pq.top(); pq.pop();
			int u = temp.v;
			if (S[u]) continue;   // 已确定最短路径，跳过
			S[u] = 1;

			edgeNode* p = this->adjList[u].firstEdge;
			while (p != NULL) {
				int w = p->data;
				if (!S[w] && dist[u] + p->weight < dist[w] && this->adjList[p->data].rebuildTime <= t) {
					dist[w] = dist[u] + p->weight;
					pq.push(Qnode(w, dist[w]));
				}
				p = p->nextEdge;
			}
		}
		return dist[y];
	}
};






int main() {
	int N, M;
	cin >> N >> M;
	//cout << N << ' ' << M << endl;
	AdjGraph myGraph(N, M);
	myGraph.allSearch();
}