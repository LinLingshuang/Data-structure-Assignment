/*1. 哈希查找
【问题描述】
对一个含n（n<=200）个正整数的无序序列构建一个长为200的哈希表，
其哈希函数为h（key）=key%199，采用线性探测法解决冲突，输出查找成功或失败，并输出每次的查找序列。
【输入形式】
两行字符串，第一行为需要查找的数，第二行为无序正整数序列，每个数之间用空格分开。
【输出形式】
第一行：查找成功输出”True”，查找失败输出”False”
第二行：输出查找序列，每个数之间用空格分开
【样例输入一】
1
1 2 3 4 5 6 7 8 9 10
【样例输出一】
True
1
【样例输入二】
200
1 2 3 4 5 6 7 8 9 10
【样例输出二】
False
1 2 3 4 5 6 7 8 9 10
【样例说明】
测试数据的文件名为in.txt，输出文件名为out.txt
【评分标准】
该题目有10个测试用例，每通过一个测试用例得10分*/
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;



int main() {
	vector<int>h(200, -1);

	ifstream in;
	in.open("in.txt");

	int target;
	string input;

	in >> target;
	getline(in, input);
	getline(in,input);

	in.close();

	int temp = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ') {
			int d = 0;
			while (h[(temp % 199 + d) % 200] != -1) {
				d++;
			}
			h[(temp % 199 + d) % 200] = temp;
			temp = 0;
		}
		else {
			temp = temp * 10 + input[i] - '0';
		}
	}
	int d = 0;
	while (h[(temp % 199 + d) % 200] != -1) {
		d++;
	}
	h[(temp % 199 + d) % 200] = temp;
	temp = 0;


	int t= 0;
	bool find = false;
	vector<int>result;
	while (h[(target % 199 + t) % 200] != -1) {
		if (h[(target % 199 + t) % 200] == target) {
			find = true;
			result.push_back(h[(target % 199 + t) % 200]);
			break;
		}
		else {
			result.push_back(h[(target % 199 + t) % 200]);
		}
		t++;
	}

	ofstream out;
	out.open("out.txt");

	if (find) {
		out << "True" << endl;
	}
	else {
		out << "False" << endl;
	}
	for (int i = 0; i < result.size(); i++) {
		out << result[i] << ' ';
	}
}

