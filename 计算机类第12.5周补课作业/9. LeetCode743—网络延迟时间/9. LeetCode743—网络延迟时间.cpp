/*9. LeetCode743—网络延迟时间
【问题描述】
有N个网络结点，标记为1到N。给定一个列表times，表示信号经过有向边的传递时间，
times[i]=(u，v，w)，其中u是源结点，v是目标结点，w是一个信号从源结点传递到目标结点的时间。
现在我们向当前的结点K发送了一个信号，需要多久才能使所有结点都收到信号？
如果不能使所有结点收到信号，返回-1。这里N的范围在[1，100]之间，
K的范围在[1，N]之间，times的长度在[1，6000]之间，所有的边times[i]=(u，v，w)都有1≤u，v≤N且0≤w≤100。
要求设计满足题目要求的函数：
class Solution {
public:
 int networkDelayTime(vector<vector<int>>& times,int N,int K)
 {  …  }
};
【输入形式】
输入网络结点的总个数N，以及信号发送的起始结点K。 
然后输入时间列表，其中每一行给出了源结点、目标结点以及信号从源结点到目标结点锁需要的时间。
【输出形式】
输出所有结点都收到信号需要花费的时间。
【样例输入】
4 2
2 1 1
2 3 1
3 4 1
【样例输出】
2
【样例说明】
时间列表对应的带权有向图如下图所示。网络有4个结点，
信号从结点2开始传播，需要2个单位时间即可传递到所有的结点。
测试数据存放在in.txt文件中。
【评分标准】
共10个测试用例，每通过一个测试得10分。*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

const int INF = 0x3f3f3f3f;


void Floyd(vector<vector<int>> g, int s) {
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



	int maxTime = 0;
	for (int j = 0; j < n; j++) {
		if (maxTime < A[s][j]) {
			maxTime = A[s][j];
		}
	}

	if (maxTime < INF) {
		cout << maxTime;
	}
	else {
		cout << -1;
	}

}

int main() {
	ifstream in;
	in.open("in.txt");

	int n,s;
	in >> n >> s;
	string clean;
	getline(in, clean);

	vector<vector<int>> result(n, vector<int>(n, INF));
	string temp;
	int i = 0;
	while (getline(in, temp)) {
		int flag = 0;
		int u = 0, v = 0, w = 0;
		for (int i = 0; i < temp.length(); i++) {
			if (flag == 0) {
				if (temp[i] == ' ') {
					flag++;
				}
				else {
					u = u * 10 + temp[i] - '0';
				}
			}
			else if (flag == 1) {
				if (temp[i] == ' ') {
					flag++;
				}
				else {
					v = v * 10 + temp[i] - '0';
				}
			}
			else if (flag == 2) {
				w = w * 10 + temp[i] - '0';
			}

		}
		result[u - 1][v - 1] = w;
		i++;
	}
	for (int i = 0; i < n; i++) {
		result[i][i] = 0;
	}
	

	Floyd(result,s-1);
}