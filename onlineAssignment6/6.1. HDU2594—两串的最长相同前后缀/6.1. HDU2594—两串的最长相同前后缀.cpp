/*1. HDU2594—两串的最长相同前后缀
【问题描述】
给定两个字符串s1和s2，求最长的s1前缀ss使得ss为s2的最长后缀，输出该字符串和其长度。
【输入形式】
  输入的每个测试用例由两行构成，第一行为s1，第二行为s2。假设所有输入的数据均为小写字母。
【输出形式】
每个测试用例的输出由单行组成，其中包含最长的字符串，该字符串是s1的前缀和s2的后缀，后面跟着该前缀的长度。
如果最长的此类字符串是空字符串，则输出应为0。s1和s2的长度最多为50000。
【样例输入】
 aaariemann
 marjorieaaa
【样例输出】
 aaa 3
【样例说明】
 输入的第一行字符串s1=‘aaariemann’，第二行字符串s2=‘marjorieaaa’。s1的前缀和s2的后缀最长相等字符串为aaa，
 因此输出aaa 3，而不是a 1。测试数据存放在in.txt文件中。
【评分标准】
 共10个测试用例，每通过一个测试得10分。*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main() {
	fstream input;
	input.open("in.txt");
	string s1, s2;
	input >> s1 >> s2;
	//cin >> s1 >> s2;
	input.close();

	string ss;
	int sum = 0;
	for (int i = 0;i<s2.length();i++) {
		char c2 = s2[i];
		if (c2 == s1[sum]) {
			sum++;
			ss.push_back(c2);
		}
		else {
			i -= sum;
			sum = 0;
			ss.clear();
		}
	}
	cout << ss << ' ' << sum;

}