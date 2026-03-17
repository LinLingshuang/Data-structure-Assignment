/*1. B2115 密码翻译
【题目描述】
在情报传递过程中，为了防止情报被截获，往往需要对情报用一定的方式加密。
我们给出一种最简单的加密方法，对给定的一个字符串，把其中从 a~y，A~Y 的字母用其后继字母替代，
把 z 和 Z 用 a 和 A 替代，其他非字母字符不变。请根据该加密规则将输入的密码进行解密。

【提示】这里需要进行解密操作，而不是加密。

【输入格式】
一行，加密后的字符串，长度不多于 10000 个字符。

【输出格式】
一行，将密码解密后的字符串。

【输入输出样例】
输入：

Ifmmp !  Ipx  bsf  zpv!
输出：

Hello !  How  are  you!
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	getline(cin,input);
	
	string output;
	for (int i = 0; i < input.length(); i++) {
		if (isalpha(input[i])) {
			if (input[i] == 'A') {
				output.push_back('Z');
			}
			else if (input[i] == 'a'){
				output.push_back('z');
			}
			else {
				output.push_back(input[i]-1);
			}
		}
		else {
			output.push_back(input[i]);
		}
	}
	cout << output;
}