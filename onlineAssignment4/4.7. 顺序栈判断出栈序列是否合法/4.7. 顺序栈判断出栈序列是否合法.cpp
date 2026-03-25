/*
	7. 顺序栈判断出栈序列是否合法
	【问题描述】

	现有一个以英文字母组成的字符序列，序列的元素个数为N（3 < N < 26），该序列通过一个顺序栈可以得到多种出栈序列，
	设计一个算法判断输入的序列str是否为一个合适的出栈序列。
	【输入形式】

	第一行输入序列的元素个数N（3 < N < 26）

	第二行按顺序输入该序列的所有元素，输入顺序即为进栈的顺序

	第三行输入一个不知道是否正确的出栈序列
	【输出形式】

	判断第三行输入的是否为可能的出栈序列，如果是则输出true，如果不是则输出false。
	【样例输入】

	5

	a b c d e

	a b c d e
	【样例输出】

	true
	【样例说明】

	字符之间有空格	
	【评分标准】
*/
#include<iostream>
using namespace std;

struct stack {
	char* data = new char[100];
	int top = 0;
	int vepacity = 100;
	void check() {
		if (top == vepacity - 1) {
			vepacity += 100;
			char* newdata = new char[vepacity];
			for (int i = 0; i < top + 1; i++) {
				newdata[i] = data[i];
			}
			delete[]data;
			data = newdata;
		}
	}
	char peek() {
		if (top == 0) {
			return '0';
		}
		return data[top-1];
	}
	void push(char c) {
		check();
		data[top] = c;
		top++;
	}
	char pop() {
		if (top == 0) {
			return '0';
		}
		top--;
		return data[top];
	}

};

int main() {
	stack myStack;
	stack myStack1;
	stack myStack2;
	int n;
	cin >> n;
	for (int i = 0; i<n; i++) {
		char c;
		cin >> c;
		myStack.push(c);
	}
	for (int i = 0; i<n; i++) {
		
		myStack1.push(myStack.pop());
	}
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c != myStack2.peek()) {
			while (c != myStack1.peek() && myStack1.peek() != '0') {
				myStack2.push(myStack1.pop());
			}
			if (myStack1.peek() == '0') {
				cout << "false";
				return 0;
			}
			else {
				myStack1.pop();
			}
		}
		else {
			myStack2.pop();
		}
	}
	cout << "true";
}