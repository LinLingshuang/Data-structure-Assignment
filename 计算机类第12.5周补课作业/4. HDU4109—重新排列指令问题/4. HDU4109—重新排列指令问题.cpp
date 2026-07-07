/*4. HDU4109—重新排列指令问题
【问题描述】
阿里本学期开设了计算机组织与架构课程，他了解到指令之间可能存在依赖关系，
如WAR（写入后读取），WAW，RAW。如果两个指令之间的距离小于安全距离（Safe Distances），
则会导致危险，这可能导致错误的结果，所以需要设计特殊的电路以消除危险。
然而，解决此问题的最简单方法是添加气泡（无用操作），
这意味着浪费时间以确保两条指令之间的距离不小于安全距离。
两条指令之间距离的定义是它们的开始时间之间的差异。
现在有很多指令，已知指令之间的依赖关系和安全距离。
我们有一个非常强大的CPU，具有无限数量的内核，
因此你可以根据需要同时运行多个指令，并且CPU速度非常快，
只需花费1ns即可完成任何指令。你的工作是重新排列指令，
以便CPU可以使用最短的时间完成所有指令。
【输入形式】
输入包含几个测试用例。每个测试用例的第一行是两个整数n，m（n≤1000，m≤10000），
表示有n个指令和m个依赖关系，以下m行，每行包含三个整数x，y，z，
表示x和y之间的安全距离为z，y应在x之后运行。指令编号从0到n-1。
【输出形式】
输出一个整数，即CPU运行所需的最短时间。
【样例输入】
5 2
1 2 1
3 4 1
【样例输出】
2
【样例说明】
7 4
1 3 2
3 5 4
0 3 3
2 5 1
输入样例有5个指令，2个依赖关系，CPU运行所需的最短时间为2。测试数据存放在in.txt文件中。
【评分标准】
共10个测试用例，每通过一个测试得10分。
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<vector<int>> creatGraphMartix() {
	int n, m;
	ifstream in;
	in.open("in.txt");
	in >> n >> m;
	vector<vector<int>> result(n, vector<int>(n, INF));
	vector<bool>depend(n, false);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		in >> u >> v >> w;
		result[u][v] = w;
		result[v][u] = -1;
		depend[v] = true;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!depend[i] && !depend[j]&& result[i][j]!=-1) {
				result[i][j] = 0;
			}
			if (result[i][j] == -1) {
				result[i][j] = INF;
			}
		}
	}

	return result;
}

void FloydButGetNecessaryTime(vector<vector<int>> g) {
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
				if ((A[i][j] < A[i][k] + A[k][j]|| A[i][j]==INF) && A[i][k] < INF && A[k][j]<INF) {
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] == INF) {
				cout << "INF" << " ";
			}
			else {
				cout << A[i][j] << " ";
			}
		}
		cout << endl;
	}
	*/
	bool haveSolution = false;
	int lowTime = INF;

	for (int i = 0; i < n; i++) {
		bool noINF = true;
		int thisSolutionMaxTime = 0;
		for (int j = 0; j < n; j++) {
			if (A[i][j] == INF) {
				noINF = false;
			}
			if (i != j && thisSolutionMaxTime < A[i][j]) {
				thisSolutionMaxTime = A[i][j];
			}
		}
		if (noINF) {
			if (lowTime > thisSolutionMaxTime) {
				lowTime = thisSolutionMaxTime;
				haveSolution = true;
			}
		}
	}
	if (haveSolution) {
		cout << lowTime+1;
	}
}

int main() {

	vector<vector<int>> g = creatGraphMartix();

	FloydButGetNecessaryTime(g);
}