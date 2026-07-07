/*6. 快速排序
【问题描述】
有一个含n（n<=200000）个整数的无序序列，采用快速排序实现递增排序
【输入形式】
一行字符串，包含多个整数，每个数之间用空格分开。
【输出形式】
递增排序的结果，每个数之间用空格分开。
【样例输入】
9 4 7 6 2 5 8 1 3
【样例输出】
1 2 3 4 5 6 7 8 9
【样例说明】
测试数据的文件名为in.txt，输出文件名为out.txt
【评分标准】
该题目有10个测试用例，每通过一个测试用例得10分*/
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;


int Partition(vector<int>& num, int s, int t) {
	int base = num[s];
	int i = s, j = t + 1;
	while (i < j) {
		j--;
		while (num[j] > base && i < j)j--;
		i++;
		while (num[i] <= base && i < j)i++;
		if (i < j) {
			swap(num[i], num[j]);
		}
	}
	swap(num[s], num[j]);
	return j;
}

void _QuickSort(vector<int>& num, int s, int t) {
	if (s < t) {
		int i = Partition(num, s, t);
		_QuickSort(num, s, i - 1);
		_QuickSort(num, i + 1, t);
	}
}

void QuickSort(vector<int>& num, int n) {
	_QuickSort(num, 0, n - 1);
}

int main() {
	ifstream in;
	in.open("in.txt");

	int input;
	vector<int> num;
	while (in.peek() != EOF) {
		in >> input;
		num.push_back(input);
	}
	in.close();

	QuickSort(num, num.size());

	ofstream out;
	out.open("out.txt");

	for (int i = 0; i < num.size(); i++) {
		out << num[i] << ' ';
	}


}