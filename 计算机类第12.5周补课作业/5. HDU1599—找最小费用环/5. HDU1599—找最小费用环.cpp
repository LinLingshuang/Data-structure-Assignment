/*5. HDU1599—找最小费用环
【问题描述】
杭州有n个景区，景区之间有一些双向的路来连接，现在万先生想找一条旅游路线，
这个路线从A点出发并且最后回到A点，假设经过的路线为v1，v2，…，vk，v1，那么必须满足k>2，
就是说至除了出发点以外至少要经过两个其他不同的景区，而且不能重复经过同一个景区。
现在万先生需要你帮他找一条这样的路线，并且花费越少越好。
【输入形式】
 第一行是两个整数n和m（n≤100，m≤1000)，代表景区的个数和道路的条数。
 接下来的m行每行包括3个整数a，b，c，代表a和b之间有一条通路，并且需要花费c元（c≤100）。
【输出形式】
对于每个测试用例，如果能找到这样一条路线的话，输出花费的最小值。如果找不到的话，输出"It's impossible."。
【样例输入】
3 3
1 2 1
2 3 1
1 3 1
【样例输出】
 3
【样例说明】
输入的数据包含3个景区和3条道路，可以找到一条旅游路线，其最小代价为3。测试数据存放在in.txt文件中。
【评分标准】
共10个测试用例，每通过一个测试得10分。*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<vector<int>> creatGraphMartix() {
	int n, m;
	ifstream in;
	in.open("in.txt");
	in >> n >> m;
	vector<vector<int>> result(n, vector<int>(n, INF));
	for (int i = 0; i < m; i++) {
		int u, v, w;
		in >> u >> v >> w;
		if (w < result[u - 1][v - 1]) { // 取最小权边（可能有重边）
			result[u - 1][v - 1] = w;
			result[v - 1][u - 1] = w;
		}
	}
	return result;
}

int ans; // 全局最小环权值

// DFS 搜索环
// u: 当前节点, start: 起始节点, depth: 已访问节点数, cost: 当前路径总权值
// prev: 上一个节点（避免直接回头）, visited: 访问标记
void dfs(const vector<vector<int>>& g, int u, int start, int depth, int cost, int prev, vector<bool>& visited) {
	int n = g.size();
	// 当深度 >= 3 且 能回到起点时，更新答案
	if (depth >= 3 && g[u][start] != INF) {
		ans = min(ans, cost + g[u][start]);
	}
	// 继续扩展路径
	for (int v = 0; v < n; ++v) {
		if (v == prev) continue;               // 不走回头路
		if (visited[v]) continue;              // 每个节点只经过一次
		if (g[u][v] == INF) continue;          // 无边
		if (cost + g[u][v] >= ans) continue;   // 剪枝：已经不可能更优

		visited[v] = true;
		dfs(g, v, start, depth + 1, cost + g[u][v], u, visited);
		visited[v] = false;
	}
}

void solution(vector<vector<int>> g) {
	int n = g.size();
	ans = INF;
	// 每个节点作为起点尝试
	for (int s = 0; s < n; ++s) {
		vector<bool> visited(n, false);
		visited[s] = true;
		dfs(g, s, s, 1, 0, -1, visited);
	}
	if (ans < INF)
		cout << ans << endl;
	else
		cout << "It's impossible." << endl;
}

int main() {
	vector<vector<int>> g = creatGraphMartix();
	solution(g);
	return 0;
}
/*#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<vector<int>> creatGraphMartix() {
	int n, m;
	ifstream in;
	in.open("in.txt");
	in >> n >> m;
	vector<vector<int>> result(n, vector<int>(n, INF));
	for (int i = 0; i < m; i++) {
		int u, v, w;
		in >> u >> v >> w;
		if (w <= result[u - 1][v - 1]) {
			result[u - 1][v - 1] = w;
			result[v - 1][u - 1] = w;
		}
		
	}
	return result;
}


vector<int> getRing(vector<vector<int>> g, int recent, int edgeNum, int start, vector<bool>haveWalk) {
	vector<int> cost(pow(g.size(), g.size() - (edgeNum + 1)), INF);
	if (edgeNum == g.size() - 1) {
		vector<int> nextCost(1, g[recent - 1][start - 1]);
		return nextCost;
	}
	for (int i = 0; i < g.size(); i++) {
		vector<int> nextCost(pow(g.size(), g.size() - (edgeNum + 1) - 1), INF);
		if (!haveWalk[i]) {
			vector<bool>nextHaveWalk = haveWalk;
			nextHaveWalk[i] = true;
			nextCost = getRing(g, i + 1, edgeNum + 1, start, nextHaveWalk);
		}
		for (int j = 0; j < pow(g.size(), g.size() - (edgeNum + 1) - 1); j++) {
			if (nextCost[j] != INF && g[recent - 1][i] != INF)
				cost[i + j] = nextCost[j] + g[recent - 1][i];
		}
	}
	return cost;
}

void solution(vector<vector<int>> g) {
	int n = g.size();
	int cost = INF;
	for (int k = 0; k < n; k++) {
		vector<bool>haveWalk(n, false);
		haveWalk[k] = true;
		vector<int> tempCost = getRing(g, k + 1, 0, k + 1, haveWalk);
		int min = tempCost[0];
		for (int j = 0; j < tempCost.size(); j++) {
			if (tempCost[j] < min)min = tempCost[j];
		}
		if (min < cost) {
			cost = min;
		}
	}
	if (cost < INF) {
		cout << cost;
	}
	else {
		cout << "It's impossible.";
	}
}



int main() {

	vector<vector<int>> g = creatGraphMartix();

	solution(g);
}
*/