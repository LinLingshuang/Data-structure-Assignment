/*10. 后缀表达式求值
后缀表达式求值
一、问题描述
给定一个后缀表达式（逆波兰表达式），计算其结果。表达式中只包含非负整数和+、-、*、/四种运算符。
注意：除法为整数除法，向零取整。
二、输入形式
一行若干个token，表示后缀表达式，以空格分隔。每个token要么是整数（0-1000），要么是运算符（+、-、*、/）。
三、输出形式
输出一个整数，表示表达式的值。
四、样例输入
2 3 + 4 *
五、样例输出*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string input;
	getline(cin, input);
	bool inNum = false;
	stack<int>nums;
	int num;
	for (char c : input) {
		if (isdigit(c)&&!inNum) {
			num = 0;
			num = c - '0';
			inNum = true;
		}
		else if (isdigit(c) && inNum) {
			num = num * 10 + c - '0';
		}
		else if (c==' ' && inNum) {
			nums.push(num);
			inNum = false;
		}
		else if (c == ' ' && !inNum) {
			continue;
		}
		else if (c == '+') {
			int frist, second;
			frist = nums.top();
			nums.pop();
			second = nums.top();
			nums.pop();
			nums.push(second + frist);
		}
		else if (c == '-') {
			int frist, second;
			frist = nums.top();
			nums.pop();
			second = nums.top();
			nums.pop();
			nums.push(second - frist);
		}
		else if (c == '*') {
			int frist, second;
			frist = nums.top();
			nums.pop();
			second = nums.top();
			nums.pop();
			nums.push(second * frist);
		}
		else if (c == '/') {
			int frist, second;
			frist = nums.top();
			nums.pop();
			second = nums.top();
			nums.pop();
			nums.push((second - (second % frist)) / frist);
		}
	}
	cout << nums.top();
}