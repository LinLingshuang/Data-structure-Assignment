/*8. 9.2.10 POJ3579—求中位数
【问题描述】
给定n个整数x1，x2，…，xn，计算每对整数的差值|xi-xj|（1≤i＜j≤n），
可以得到C(n，2)个差值，现在你的任务是尽快找到这些差值的中位数。
注意在此问题中，如果差值的个数m为偶数，则中位数定义为第m/2个最小数，
例如m=6时需要求第3个最小数。
【输入形式】
在每个测试用例中，第一行给出n，然后给出n个整数，分别代表x1，x2，…，xn（xi≤1，000，000，000，3≤n≤1，00，000）。
【输出形式】
 在单独的行中输出中位数
【样例输入】
4
1 3 2 4
【样例输出】
1
【样例说明】
测试数据的文件名为in.txt
【评分标准】
该题目有10个测试用例，每通过一个测试用例，得10分。
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main() {
	int n;
	ifstream in;
	in.open("in.txt");
	in >> n;
	vector<int>input(n);
	for (int i = 0; i < n; i++) {
		in>>input[i];
	}
	vector<int>mid;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			mid.push_back(abs(input[i] - input[j]));
		}
	}
	sort(mid.rbegin(), mid.rend());
	cout << mid[mid.size() / 2];
}