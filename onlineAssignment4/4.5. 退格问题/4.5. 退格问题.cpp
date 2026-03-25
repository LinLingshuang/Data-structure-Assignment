//5. 退格问题
//【问题描述】
//小明的键盘坏了，每次按下字符时会随机多输入一个退格符 #（例如输入 a#b 实际显示为 b）。
//现给定一个字符串 s，其中 # 表示退格符，它会删除其前一个有效字符。请编写程序，模拟键盘输出最终显示的字符串。
//【输入形式】
//输入一行字符串 s（仅包含小写字母和 # 符号）。
//【输出形式】
//输出处理后的字符串。若结果为空，则输出空行。
//【样例输入1】
//a#b#c
//【样例输出1】
//c
//【样例输入2】
//ab#c##
//【样例输出2】（说明：空行）
// 
//【评分标准】
//10个测试用例，按通过比例评分。
//【评分标准】
//10个测试用例，按通过比例评分。
//【样例说明】
//样例的输入只有1行，样例输出只有1行，请忽略为阅读方便而插入的空白行。
//【类库使用要求】
//不可以使用STL中的stack、queue、deque、vector等库函数，可以使用字符串STL处理输入。
//【说明】
//要求自己设计实现栈或队列类
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
	void popOne() {
		if (top == 0) {
			return ;
		}
		top--;
		return ;
	}
	void popAll() {
		for (int i = 0; i < top; i++) {
			cout << data[i];
		}
	}

};

int main() {
	string input;
	cin >> input;
	stack myStack;
	for (char c : input) {
		if (c == '#') {
			myStack.popOne();
		}
		else {
			myStack.push(c);
		}
	}
	myStack.popAll();
}