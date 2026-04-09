/*9. 括号匹配检查
括号匹配检查
一、问题描述
给定一个只包含'(', ')', '{', '}', '[', ']'的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合

左括号必须以正确的顺序闭合

空字符串可被认为是有效字符串

二、输入形式
输入一个字符串s（长度0 ≤ |s| ≤ 10000），只包含上述6种字符。

三、输出形式
输出"YES"表示有效，输出"NO"表示无效。

四、样例输入

(){[]}
五、样例输出

YES
六、样例说明
字符串"(){[]}"是有效的：

()是匹配的

{}是匹配的

[]是匹配的

嵌套顺序正确

七、评分标准
共6个测试用例。

八、类库使用要求
可以使用栈（手动实现或STL stack），可以使用string。*/
#include<iostream>
#include<string>
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
	string input;
	cin >> input;
	stack myStack;
	for (char c : input) {
		if (c == '(' || c == '[' || c == '{') {
			myStack.push(c);
		}
		else if (c == ')' || c == ']' || c == '}') {
			if (c == ')' && myStack.pop() == '(') {
				continue;
			}
			else if (c == ']' && myStack.pop() == '[') {
				continue;
			}
			else if (c == '}' && myStack.pop() == '{') {
				continue;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}