/*3. 2026春(1)第3题：好串枚举(A班）
【问题描述】
 对于一个长度为n的字符串 s=s0s1⋯sn−1来说，子串的定义是从中选出两个下标l,r(0≤l≤r≤n−1)，
 这之间所有的字符组合起来的一个新的字符串：s′=slsl+1⋯sr 就是其中一个子串。
 给出一个数字字符0∼9或字母字符组成的字符串，输出子串是好串的数目。一个子串是好串，当且仅当它满足以下两个条件之一：
单字符子串一定是好串，即当子串长度为1时，它总是好串；
长度大于1时，可以拆分为两个单字符子串、一个单字符子串和一个连续非递减子串或者两个连续非递减子串，
一个串p=p0p1…pk−1 为连续非递减子串是指：对于所有1≤i<k，满足pi=pi−1或 pi=pi−1+1，
即字符串中的每一个字符，要么等于上一个字符，要么等于上一个字符加1，例如122、456是连续非递减子串。
例如：12258的好串个数为12，分别为：1、2、2、5、8、12、22、25、58、122、225、1225；18967的好串个数为13，
分别为：1、8、9、6、7、18、89、96、67、189、896、967、8967。
【输入形式】从键盘输入一行数字字符串S。
【输出形式】在屏幕上输出S的好串数目m并列举这m个好串。
【样例输入】12258
【样例输出】12258有12个好串：1 12 122 1225 2 22 225 2 25 5 58 8 
【评分标准】该题目有10个测试用例，每通过一个测试用例，得10分。
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isGoodStirng(string input) {
	if (input.length() == 1|| input.length() == 0) {
		return true;
	}
	else {
		bool good = true;
		for (int i = 0; i < input.length() - 1; i++) {
			if (input[i] == input[i + 1] || input[i] == input[i + 1] - 1) continue;
			else {
				good = false;
				break;
			}
		}
		return good;
	}
}
bool subSringisGoodStirng(string input) {
	bool good = false;
	for (int i = 1; i < input.length(); i++) {
		string subString1 = input.substr(0, i);
		string subString2 = input.substr(i, input.length()-i);
		good = (isGoodStirng(subString1) && isGoodStirng(subString2));
		if (good)break;
	}
	if (input.length() == 1)good = true;
	return good;
}

int main() {
	string input;
	cin >> input;
	int num = 0;
	vector<string>output;

	for (int i = 0; i < input.length(); i++) {
		for (int j = 1; j <= input.length() - i; j++) {
			string subString = input.substr(i, j);
			if (subSringisGoodStirng(subString)) {
				output.push_back(subString);
				num++;
			}
		}
	}

	cout << input << "有" << num << "个好串：";
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << ' ';
	}
}