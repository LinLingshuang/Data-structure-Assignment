/*1. 第三章 R进制数值转换
【问题描述】设计一个算法，利用顺序栈将一个十进制正整数 d 转换为 r (2 ≤ r ≤ 16) 进制的数，要求 r 进制数采用字符串 string 表示。
【输入形式】d r
【输出形式】r 进制的数
【样例输入1】10 2
【样例输出1】1010
【样例输入2】255 16
【样例输出2】FF
【样例说明】r 进制数采用字符串 string 表示
【评分标准】
【类库使用要求】
不可以使用STL中的stack、queue等库函数，可以使用字符串STL处理输入。
【说明】
要求自己设计实现栈或队列类
*/
#include <iostream>
#include<string>
using namespace std;

struct stack {
	int top=0;
	int* s = new int[2000];
	string out;
	stack(int input,int r) {
		int sum = input;
		while (sum != 0) {
			s[top] = sum % r;
			sum = sum / r;
			top++;
		}
		top--;
	}
	void output() {
		while (top != -1) {
			if (s[top] >= 10) {
				char c = 'A' + s[top] - 10;
				out.push_back(c);
				//cout << c;
			}
			else {
				char c = '0' + s[top];
				out.push_back(c);
				//cout << s[top];
			}
			top--;
		}
		cout << out;
	}
};

int main()
{
	int input;
	cin >> input;
	int r;
	cin >> r;
	stack mystack(input, r);
	mystack.output();
}

