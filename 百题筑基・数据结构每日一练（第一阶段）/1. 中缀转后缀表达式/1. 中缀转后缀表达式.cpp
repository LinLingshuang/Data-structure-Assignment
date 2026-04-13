/*1. 中缀转后缀表达式
一、问题描述
给定一个中缀表达式，将其转换为后缀表达式（逆波兰表达式）。表达式只包含非负整数、+、-、*、/、括号。
注意：运算符优先级：*和/高于+和- 同级运算符从左到右计算
括号可以改变优先级
二、输入形式
一行一个字符串，表示中缀表达式，无空格，数字可能有多位。
三、输出形式
输出后缀表达式，数字和运算符之间用空格分隔。
四、样例输入
3+4*2/(1-5)
五、样例输出
3 4 2 * 1 5 - / +
六、样例说明
中缀表达式"3+4*2/(1-5)"的转换过程：
3直接输出
+入栈
4直接输出
* 优先级高于栈顶+，入栈
2直接输出
/优先级等于栈顶，*出栈输出，/入栈
(入栈
1直接输出
-入栈（栈顶是(，直接入栈）
5直接输出
)出栈直到(，-出栈输出，(出栈丢弃
表达式结束，栈中/和+依次出栈输出
结果：3 4 2 * 1 5 - / +
七、评分标准
共8个测试用例。
八、类库使用要求
可以使用栈，可以使用string、vector。*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct stack {
	int top = 0;
	vector<char>myOperator=vector<char>(1000);
	void intial() {
		for (int i = 0; i < 1000; i++) {
			myOperator[i] = '1';
		}
	}

	void pop() {
		top--;
		cout << ' '<< myOperator[top] ;
	}
	void push(char c) {
		myOperator[top] = c;
		top++;
	}
	void del() {
		top--;
	}

};

int main() {
	string a;
	stack myStack;
	myStack.intial();
	cin >> a;
	for (char c : a) {
		if (isalnum(c)) {
			cout << c ;
		}
		else if(c=='('){
			myStack.push(c);
		}
		else if (c == ')') {
			while (myStack.myOperator[myStack.top-1] != '(') {
				myStack.pop();
			}
			myStack.del();
		}
		else if (c == '*'||c=='/') {
			if (myStack.top != 0) {
				if (myStack.myOperator[myStack.top - 1] == '-' || myStack.myOperator[myStack.top - 1] == '+' || myStack.myOperator[myStack.top - 1] == '(') {
					cout << ' ';
					myStack.push(c);;
				}
				else {
					myStack.pop();
					cout << ' ';
					myStack.push(c);
				}
			}
			else {
				cout << ' ';
				myStack.push(c);
			}
		}
		else if (c == '+'||c=='-') {
			if (myStack.top != 0) {
				if (myStack.myOperator[myStack.top - 1] == '(') {
					cout << ' ';
					myStack.push(c);;
				}
				else {
					myStack.pop();
					cout << ' ';
					myStack.push(c);
				}
			}
			else {
				cout << ' ';
				myStack.push(c);
			}
		}
		/*
		else if (c == '+'||c=='-') {
			// 修改：循环弹出所有栈顶运算符（直到遇到'('或栈空），因为所有运算符优先级都 >= +和-
			while (myStack.top != 0 && myStack.myOperator[myStack.top-1] != '(') {
				myStack.pop();
			}
			cout << ' ';
			myStack.push(c);
		}*/
	}
	int b = myStack.top;
	for (int i = 0; i < b; i++) {
		myStack.pop();
	}

}
