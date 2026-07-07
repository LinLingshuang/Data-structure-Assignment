/*2. Dijkstra算法-单源最短路径
Dijkstra算法-单源最短路径
一、问题描述
给定一个带权有向图和一个源点，使用Dijkstra算法求从源点到所有其他节点的最短路径长度。如果无法到达，输出-1。
二、输入形式
第一行输入三个正整数n、m、s（1 ≤ n ≤ 1000, 1 ≤ m ≤ 100000），表示节点数、边数和源点。
接下来m行，每行三个整数u、v、w，表示从u到v有一条权重为w的有向边。
三、输出形式
输出n个整数，表示从源点到每个节点（1到n）的最短路径长度。如果无法到达，输出-1。
四、样例输入
5 6 1
1 2 2
1 3 4
2 3 1
2 4 7
3 4 3
4 5 1
五、样例输出
0 2 3 6 7
六、样例说明
从节点1出发：
到1：0
到2：2（1→2）
到3：3（1→2→3）
到4：6（1→2→3→4）
到5：7（1→2→3→4→5）
七、评分标准
共10个测试用例。
测试用例1-5：小图，朴素Dijkstra可过
测试用例6-10：大图，要求堆优化Dijkstra
八、类库使用要求
可以使用vector、priority_queue。必须使用堆优化的Dijkstra算法。*/
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
			int u, v, w;
			cin >> u >> v >> w;
			edgeNode* newNode = new edgeNode(v,w);
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

void DijkstraPlus(AdjGraph G, int s) {
	priority_queue<Qnode> pq;
	vector<int> dist(G.n, INF);
	vector<int> S(G.n, 0);
	dist[s - 1] = 0;
	pq.push(Qnode(s, dist[s - 1]));

	while (!pq.empty()) {
		Qnode temp = pq.top(); pq.pop();
		int u = temp.v;
		if (S[u - 1]) continue;   // 已确定最短路径，跳过
		S[u - 1] = 1;

		edgeNode* p = G.adjList[u - 1].firstEdge;
		while (p != NULL) {
			int w = p->data;
			if (!S[w - 1] && dist[u - 1] + p->weight < dist[w - 1]) {
				dist[w - 1] = dist[u - 1] + p->weight;
				pq.push(Qnode(w, dist[w - 1]));
			}
			p = p->nextEdge;
		}
	}

	// 输出（注意末尾无空格）
	for (int i = 0; i < G.n; i++) {
		if (dist[i] < INF) cout << dist[i];
		else cout << -1;
		if (i != G.n - 1) cout << ' ';
	}
	cout << endl;
}

int main() {
	int n, m, s;
	cin >> n >> m >> s;
	AdjGraph G(n,m);
	DijkstraPlus(G, s);
}

/*#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli; // (distance, node)

const ll INF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    // 邻接表: graph[u] = { (v, w) }
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    // 最短距离数组
    vector<ll> dist(n + 1, INF);
    dist[s] = 0;

    // 最小堆，存储 (距离, 节点)
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // 如果当前记录的距离已经不是最短距离，跳过
        if (d != dist[u]) continue;

        // 遍历邻边
        for (const auto& [v, w] : graph[u]) {
            ll nd = d + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.emplace(nd, v);
            }
        }
    }

    // 输出结果
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF)
            cout << "-1";
        else
            cout << dist[i];
        if (i < n) cout << ' ';
    }
    cout << '\n';

    return 0;
}*/