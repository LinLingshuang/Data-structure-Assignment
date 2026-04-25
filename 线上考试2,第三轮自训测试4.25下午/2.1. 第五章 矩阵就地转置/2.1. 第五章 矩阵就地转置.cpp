/*1. 第五章 矩阵就地转置
【问题描述】设计一个算法,实现m行n列的二维数组a的就地转置,当m≠n时返回false,否则返回true。
“就地转置” 指的是在不额外开辟大量存储空间的前提下，直接对原数据结构进行操作以完成转置。
对于二维数组而言，就是直接在原数组的内存空间里进行元素位置的交换，从而实现数组的转置，
不使用和原数组规模相当的额外数组来存储转置后的结果。空间复杂度要求为O(1)。
【输入形式】
第一行输入两个整数 m 和 n，分别表示数组 a 的行数和列数。
接下来 m 行，每行 n 个整数，表示二维数组 a 的元素。
【输出形式】
若 m ≠ n，输出 false。
若 m = n，输出 true，并在接下来的 n 行中输出转置后的矩阵，每行 n 个整数。
【样例输入】
3 3
1 2 3
4 5 6
7 8 9
【样例输出】
true
1 4 7
2 5 8
3 6 9
【样例说明】
【评分标准】
【说明】
可以使用STL库函数*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int m,n;
	cin >> m >> n;
	if (m != n) {
		cout << "false";
		return 0;
	}
	else {
		cout << "true" << endl;
		vector<vector<int>>matrix(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << matrix[j][i] << ' ';
			}
			cout << endl;
		}
	}

}