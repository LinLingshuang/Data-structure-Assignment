/*6. LeetCode52—N皇后II
【问题描述】
n皇后问题研究的是如何将n个皇后放置在n×n的棋盘上，
并且使皇后彼此之间不能相互攻击。给定一个整数n，返回n皇后不同的解决方案的数量。要求设计如下函数：
class Solution{
public:
 int totalNQueens(int n)
 {  … }
};
【输入形式】
 输入一个整数n。
【输出形式】
 输出n皇后问题的解决方案的数量。
【样例输入】
6
【样例输出】
4
【样例说明】
 6皇后问题有4个不同的求解方案。测试数据存放在in.txt文件中。
【评分标准】
 共10个测试用例，每通过一个测试得10分。
*/
#include<iostream>
#include<fstream>
using namespace std;

void clean(int* broad[],int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			broad[i][j] = 0;
		}
	}
}
void put(int* broad[], int n, int ii, int jj) {
	for (int i = 0; i < n; i++) {
		broad[i][jj] = 1;
		if ((jj - ii + i) >= 0 && (jj - ii + i) <= n - 1)
			broad[i][jj - ii + i] = 1;
	}
	for (int j = 0; j < n; j++) {
		broad[ii][j] = 1;
		if ((ii + jj - j) >= 0 && (ii + jj - j) <= n - 1)
			broad[ii + jj - j][j] = 1;
	}
}
int sol(int* broad[], int n, int label) {
	if (label > n) {
		return 1;
	}
	else {
		int sum = 0;
		int** copyBroad = new int* [n];
		for (int i = 0; i < n; i++) {
			copyBroad[i] = new int[n] {};
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				copyBroad[i][j] = broad[i][j];
			}
		}
		for (int j = 0; j < n; j++) {
			if (broad[label-1][j] == 0) {
				put(copyBroad, n, label-1, j);
				sum += sol(copyBroad, n, label + 1);
				for (int i = 0; i < n; i++) {
					delete[]copyBroad[i];
				}
				copyBroad = new int* [n];
				for (int i = 0; i < n; i++) {
					copyBroad[i] = new int[n] {};
				}
				for (int i = 0; i < n; i++) {
					for (int k = 0; k < n; k++) {
						copyBroad[i][k] = broad[i][k];
					}
				}
			}
		}
		if (sum == 0) {
			return 0;
		}
		else {
			return sum;
		}
	}
}


class Solution {
public:
	int totalNQueens(int n)	{
		int** broad = new int*[n];
		for (int i = 0; i < n; i++) {
			broad[i] = new int[n] {};
		}
		return sol(broad, n, 1);
	}
};


int main() {
	Solution s;
	ifstream in;
	in.open("in.txt");
	int n;
	in >> n;
	cin >> n;
	cout<<s.totalNQueens(n);
}