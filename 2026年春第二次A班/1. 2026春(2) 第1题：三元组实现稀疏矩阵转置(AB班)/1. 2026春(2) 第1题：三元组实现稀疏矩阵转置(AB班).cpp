/*1. 2026春(2) 第1题：三元组实现稀疏矩阵转置(A/B班)
【问题描述】将稀疏矩阵进行转置，要求“按位就座”（对矩阵的三元组顺序表扫描一次）
【输入形式】从文件以三元组方式输入稀疏矩阵M
【输出形式】以文件形式输出M的转置矩阵，要求按照三元组形式输出
【要求】“按位就座”即只能对M的三元组顺序表扫描一次，就生成转置矩阵T
【样例输入】测试输入文件in.txt如下：                       
6 7 8
0 1 12
0 2 9
2 0 -3
2 5 14
3 2 24
4 1 18
5 0 15
5 3 -7
【样例输出】 输出到文件abc.out中，如下：
7 6 8
0 2 -3
0 5 15
1 0 12
1 4 18
2 0 9
2 3 24
3 5 -7
5 2 14
原矩阵 blob.png       转置后矩阵 blob.png
 矩阵的三元组存储        blob.png
 */
#include<iostream>
#include<fstream>
using namespace std;

struct matrix {
	int* x;
	int* y;
	int* data;
	matrix() {
		x = new int[0];
		y = new int[0];
		data = new int[0];
	}
	matrix(int n) {
		x = new int[n];
		y = new int[n];
		data = new int[n];
	}
};

int main() {
	int n, m, k;
	ifstream in;
	in.open("in.txt");
	in >> n >> m >> k;
	matrix result(k);
	for (int i = 0; i < k; i++) {
		int x, y, data;
		in >> x >> y >> data;
		result.x[i] = y;
		result.y[i] = x;
		result.data[i] = data;
		if (i > 0) {
			for (int j = i; j > 0; j--) {
				if (result.x[j] < result.x[j - 1]) {
					int tempx= result.x[j-1], tempy= result.y[j-1], tempdata= result.data[j-1];
					result.x[j - 1] = result.x[j];
					result.y[j - 1] = result.y[j];
					result.data[j - 1] = result.data[j];
					result.x[j] = tempx;
					result.y[j] = tempy;
					result.data[j] = tempdata;
				}
				else if (result.x[j] == result.x[j - 1] && result.y[j] < result.y[j - 1]) {
					int tempx = result.x[j - 1], tempy = result.y[j - 1], tempdata = result.data[j - 1];
					result.x[j - 1] = result.x[j];
					result.y[j - 1] = result.y[j];
					result.data[j - 1] = result.data[j];
					result.x[j] = tempx;
					result.y[j] = tempy;
					result.data[j] = tempdata;
				}
			}
		}
	}
	in.close();
	ofstream out;
	out.open("abc.out");
	out << m << ' ' << n << ' ' << k << endl;
	for (int i = 0; i < k; i++) {
		out << result.x[i] << ' ' << result.y[i] << ' ' << result.data[i] << endl;		
	}
}