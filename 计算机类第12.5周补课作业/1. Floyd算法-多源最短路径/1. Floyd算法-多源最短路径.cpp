/*1. Floyd算法-多源最短路径
Floyd算法-多源最短路径
一、问题描述
给定一个带权有向图，使用Floyd算法求任意两点之间的最短路径长度。
二、输入形式
第一行输入两个正整数n和m（1 ≤ n ≤ 200, 1 ≤ m ≤ 10000），表示节点数和边数。
接下来m行，每行三个整数u、v、w，表示从u到v有一条权重为w的有向边。
三、输出形式
输出n行n列的矩阵，第i行第j列表示从节点i到节点j的最短路径长度。如果无法到达，输出"INF"。
四、样例输入
4 4
1 2 1
2 3 2
1 3 5
3 4 1
五、样例输出
0 1 3 4
INF 0 2 3
INF INF 0 1
INF INF INF 0
六、样例说明
Floyd算法计算所有点对之间的最短距离。
七、评分标准
共10个测试用例。
八、类库使用要求
只能使用数组，必须实现Floyd算法。*/
#include<iostream>
#include<vector>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<vector<int>> creatGraphMartix() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> result(n, vector<int>(n, INF));
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		result[u - 1][v - 1] = w;
	}
	for (int i = 0; i < n; i++) {
		result[i][i] = 0;
	}
	return result;
}

void Floyd(vector<vector<int>> g) {
	int n = g.size();
	vector<vector<int>> A(n, vector<int>(n, INF));
	vector<vector<int>> path(n, vector<int>(n, INF));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = g[i][j];
			if (i != j && g[i][j] < INF) {
				path[i][j] = i;
			}
			else {
				path[i][j] = -1;
			}
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (A[i][j] > A[i][k] + A[k][j]) {
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] == INF) {
				cout << "INF" << " ";
			}
			else {
				cout<< A[i][j] << " ";
			}
		}
		cout << endl;
	}

}

int main() {

	vector<vector<int>> g = creatGraphMartix();

	Floyd(g);
}