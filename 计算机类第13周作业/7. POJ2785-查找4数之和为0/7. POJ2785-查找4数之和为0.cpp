/*7. POJ2785-查找4数之和为0
【问题描述】
给定4个整数序列A、B、C、D，计算有多少个四元组（a,b,c,d）满足a+b+c+d=0，
其中a∈A，b∈B，c∈C，d∈D，假设4个序列中的元素个数均为n。
【输入形式】
输入文件的第一行为n（最大为4000），接下来的n行，
每行4个整数（整数的绝对值最大为228），分别为A、B、C、D中的一个整数。
【输出形式】
对于每个输入文件，输出一行表示满足条件的四元组个数。
【样例输入】
6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45
【样例输出】
5
【样例说明】
测试数据的文件名为in.txt
【评分标准】
该题目有5个测试用例，每通过一个测试用例，得20分。*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() {
	int n;
	ifstream in;
	in.open("in.txt");

	in >> n;
	vector<int>A(n);
	vector<int>B(n);
	vector<int>C(n);
	vector<int>D(n);
	for (int i = 0; i < n; i++) {
		in >> A[i] >> B[i] >> C[i] >> D[i];
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					if (A[i] + B[j] + C[x] + D[y] == 0)result++;
				}
			}
		}
	}
	cout << result;
}