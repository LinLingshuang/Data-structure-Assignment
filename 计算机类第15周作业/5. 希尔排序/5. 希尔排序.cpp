/*5. 希尔排序
【问题描述】
有一个含n（n<=200000）个整数的无序序列，采用希尔排序实现递增排序
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

	int d = num.size() / 2;
	while (d > 0) {
		for (int i = d; i < num.size(); i++) {
			if (num[i] < num[i - d]) {
				int temp = num[i];
				int j = i - d;
				do {
					num[j + d] = num[j];
					j = j - d;
				} while (j >= 0 && num[j] > temp);
				num[j + d] = temp;
			}
		}
		d = d / 2;
	}

	ofstream out;
	out.open("out.txt");

	for (int i = 0; i < num.size(); i++) {
		out << num[i] << ' ';
	}


}