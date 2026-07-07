/*7. 第八章第15题
【问题描述】
给定一个带权无向图，采用邻接矩阵形式存储。设计并实现一个基于狄克斯特拉算法思想的程序，
求从顶点s到顶点t的最短路径长度。
【输入形式】
第一行为两个整数N和M（2 ≤ N ≤ 100），分别表示图中节点的数量以及边的数量。接下来N行，
每行包含N个非负整数，描述邻接矩阵中的权重，
其中0表示当前顶点与该列顶点没有直接相连或为同一顶点，
其它值表示从当前顶点到该列顶点的权重。最后两行为两个整数s和t（1 ≤ s, t ≤ N），分别代表起点和终点。
【输出形式】
一个整数，表示从顶点s到顶点t的最短路径长度。路径不存在时，输出-1。
【输入样例】
5 7
0 3 12 4 0
3 0 6 5 0
12 6 0 0 2
4 5 0 0 8
0 0 2 8 0
1
5
【输出样例】
9
*/
#include<iostream>
#include<vector>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<vector<int>> createMatrixGraphaa() {
	int n,e;
	cin >> n >> e;
	vector<vector<int>> result(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			if(temp==0&&i==j)
				result[i][j] = temp;
			else if (temp == 0) {

			}
			else {
				result[i][j] = temp;
			}
		}
	}
	return result;
}

void Dijkstra(vector<vector<int>> g,int u,int v) {
	int n = g.size();
	vector<int> dist(n);
	vector<int> path(n);
	vector<int> S(n);
	for (int i = 0; i < n; i++) {
		dist[i] = g[u][i];
		S[i] = 0;
		if (g[u][i] != 0 && g[u][i] < INF)
			path[i] = u;
		else
			path[i] = -1;
	}
	S[u] = 1;
	int minDist = INF, w = -1;
	for (int i = 0; i < n-1; i++) {
		minDist = INF;
		for (int j = 0; j < n; j++) {
			if (S[j] == 0 && dist[j] < minDist) {
				w = j;
				minDist = dist[j];
			}
		}
		S[w] = 1;
		for (int j = 0; j < n; j++) {
			if (S[j] == 0) {
				if (g[w][j] < INF && dist[w] + g[w][j] < dist[j]) {
					dist[j] = dist[w] + g[w][j];
					path[j] = w;
				}
			}
		}
	}
	if (dist[v] < INF)
		cout << dist[v];
	else
		cout << -1;
}

int main(){
	vector<vector<int>> g = createMatrixGraphaa();
	int u, v;
	cin >> u >> v;
	Dijkstra(g, u-1, v-1);
}