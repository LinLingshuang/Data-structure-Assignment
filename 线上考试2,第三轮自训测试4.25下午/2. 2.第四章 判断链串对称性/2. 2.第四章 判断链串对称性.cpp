/*2. 第四章 判断链串对称性
【问题描述】假设字符串 s 采用链串存储（即使用链表存储字符串），
设计一个算法，判断它是否为 "x@x" 形式的字符串，其中 x 是不包含字符 '@' 的任意字符串。
【输入形式】输入一个字符串 s，其中 s 由字符串和 @ 组成（可能含有@）。
【输出形式】如果 s 为 "x@x" 形式，输出 true；否则输出 false。
【样例输入】
ab@ab
【样例输出】
true
【样例说明】
【评分标准】
【说明】
要求用链串设计，可以使用STL库函数。
*/
#include<iostream>
#include<string>
#include<list>

using namespace std;

int main() {
	string input;
	getline(cin,input);
	list<char>s;
	list<char>ss;

	bool finda = false;

	
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '@') {
			finda = true;
			continue;
		}
		if (!finda) {
			s.push_back(input[i]);
		}
		else {
			ss.push_back(input[i]);
		}
	}
	if (!finda) {
		cout << "false";
		return 0;
	}
	else if (s == ss) {
		cout << "true";
	}
	else {
		cout << "false";
	}
}
