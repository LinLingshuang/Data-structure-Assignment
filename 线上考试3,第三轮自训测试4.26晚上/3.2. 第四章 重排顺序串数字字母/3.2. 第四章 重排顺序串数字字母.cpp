/*2. 第四章 重排顺序串数字字母
【问题描述】
设有一个顺序串s，其字符仅由数字和小写字母组成。设计一个算法，将s中的所有数字字符放在前半部分，
将所有小写字母字符放在后半部分。
【输入形式】
输入为一个字符串 s ，仅包含数字（ 0-9 ）和小写字母（ a-z ），长度不超过 1000。
【输出形式】
输出处理后的字符串，满足：所有数字字符在前半部分，顺序与原字符串中的数字顺序一致。 
所有小写字母字符在后半部分，顺序与原字符串中的字母顺序一致。
【样例输入】
a1b2c3
【样例输出】
123abc
【样例说明】
在样例中，数字字符为 1, 2, 3 ，字母为 a, b, c ，处理后数字在前、字母在后，且各自顺序保持不变。
【评分标准】
【说明】
可以使用STL库函数，尽量用string类设计算法。*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string input;
	cin >> input;
	string outputNum;
	string outputAlpha;

	for (char c : input) {
		if (isalpha(c)) {
			outputAlpha.push_back(c);
		}
		else {
			outputNum.push_back(c);
		}
	}
	cout << outputNum << outputAlpha;
}