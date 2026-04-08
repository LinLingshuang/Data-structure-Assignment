/*5. 压缩矩阵相乘
【问题描述】
 两个n阶整型对称矩阵A和B采用压缩存储方式，均按行优先顺序存放其下三角和主对角线的各元素。
 设计一个算法求A和B的乘积C，要求C直接用二维数组表示。
【输入形式】
第一行：输入对称矩阵阶数N
第二行：输入压缩后矩阵A
第三行：输入压缩后矩阵B
【输出形式】
第i行：输出矩阵C的第i行
【样例输入】
2
1 1 1
2 2 2
【样例输出】
4 4
4 4
【样例说明】
测试点中会出现负数
【评分标准】
A,B矩阵只能使用一维数组存储，使用非压缩二维数组存储不得分*/
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	int** c = new int* [n];
	for (int i = 0; i < n*(n+1)/2; i++) {
		cin >> a[i];
		c[i] = new int[n];
	}
	for (int i = 0; i < n * (n + 1) / 2; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int value = 0;
			for (int k = 0; k < n; k++) {
				if (k <= i && k <= j) {
					value += a[i * (i + 1) / 2 + k] * b[j * (j + 1) / 2 + k];
				}
				else if (k <= i) {
					value += a[i * (i + 1) / 2 + k] * b[k * (k + 1) / 2 + j];
				}
				else if (k <= j) {
					value += a[k * (k + 1) / 2 + i] * b[j * (j + 1) / 2 + k];
				}
				else {
					value += a[k * (k + 1) / 2 + i] * b[k * (k + 1) / 2 + j];
				}
			}
			c[i][j] = value;

		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << c[j][i]<<' ';
		}
		cout << endl;
	}

}