/*2. 2026春(1)第2题：堆栈在表达式求值的应用（A班）
【问题描述】
数学老师需快速验证学生书写的算术表达式与标准答案是否等效，现要求编写C++程序，通过计算表达式结果的方式实现判断逻辑。
【实验要求】
（1）输入规则：第一行输入正整数n（表示需判断的算术表达式对数/测试用例数，1≤n≤20）；
后续输入n对算术表达式，每对表达式各占一行（无空行），单个表达式长度不超过20个字符。
（2）表达式构成：包含运算符（ + 、-、*、/）、运算数（一位数字或单个大小写区别的字母） 、输入表达式可能有语法错误，需要有效性验证。
（3）计算规则：除号“/”按整数除法规则计算（结果取整，例如5/3结果为1，分母为0表示表达式除0出错）；
必须通过逆波兰式（后缀表达式）完成表达式的计算逻辑。
【输入格式】in.txt文件输入n个测试用例
（1）第一行：正整数n（测试用例数量，1≤n≤20）。
（2）后续2n行：每2行对应1个测试用例，即每个测试用例包含两个算术表达式（各占一行）。
【输出格式】文件out.txt输出共n行，对应n个对表达式的判断结果：若第i对表达式计算结果等效，第i行输出：TRUE”；否则输出“FALSE”。
若第i对表达式的第j个表达式是无效表达式，第i行输出：表达式j无效！若第i对表达式的第j个表达式除0错误，第i行输出：表达式j除0出错。
【样例输入】输入文件in.txt内容如下：                        
4
3*(a+2*3/(2+1))-b*(5-2)
(b+1)*(5-3)+3-(6-4)*c
6+5+4+3+2
4*(2+6/3)+2
(a+b)*(-b)
a*a-b*b
5-4+8/(7-6/2-9/2)
2*3-8
【样例输出】输出文件out.txt如下:
测试用例1：TRUE
测试用例2：FALSE
测试用例3：表达式1无效！
测试用例4：表达式1除0出错！
【评分标准】
5组测试用例，每通过一个测试用例得20分
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

stack<string> getNPL(string input) {
	stack<char>myOperator;

	string tempNum;
	string tempOperator;

	stack<string>result;
	bool inNum = false;
	for (char c : input) {
		if (isdigit(c)) {
			tempNum.push_back(c);
			inNum = true;
		}
		else if (!inNum&&isalpha(c)) {
			tempNum.push_back(c);
			result.push(tempNum);
			tempNum.clear();
		}
		else if (c == '(') {
			if (inNum) {
				result.push(tempNum);
				tempNum.clear();
				inNum = false;
			}
			myOperator.push(c);
		}
		else if (c == ')') {
			if (inNum) {
				result.push(tempNum);
				tempNum.clear();
				inNum = false;
			}
			while (!myOperator.empty()&&myOperator.top() != '(') {
				tempOperator = myOperator.top();
				result.push(tempOperator);
				myOperator.pop();
			}
			if (!myOperator.empty()) {
				myOperator.pop();
			}
			else {
				result.push("$");
			}
		}
		else if (c == '*' || c == '/') {
			if (inNum) {
				result.push(tempNum);
				tempNum.clear();
				inNum = false;
			}
			if (!myOperator.empty()) {
				if (myOperator.top() == '-' || myOperator.top() == '+' || myOperator.top() == '(') {
					myOperator.push(c);
				}
				else {
					tempOperator = myOperator.top();
					result.push(tempOperator);
					myOperator.pop();
					myOperator.push(c);
				}
			}
			else {
				myOperator.push(c);
			}
		}
		/*
		else if (c == '+' || c == '-') {
			if (inNum) {
				result.push(tempNum);
				tempNum.clear();
				inNum = false;
			}
			if (!myOperator.empty()) {
				if (myOperator.top() == '(') {
					myOperator.push(c);;
				}
				else {
					tempOperator = myOperator.top();
					result.push(tempOperator);
					myOperator.pop();
					myOperator.push(c);
				}
			}
			else {
				myOperator.push(c);
			}
		}
		*/
		
		else if (c == '+' || c == '-') {
			if (inNum) {
				result.push(tempNum);
				tempNum.clear();
				inNum = false;
			}
			// 修改：循环弹出所有栈顶运算符（直到遇到'('或栈空），因为所有运算符优先级都 >= +和-
			while (!myOperator.empty() && myOperator.top() != '(') {
				tempOperator = myOperator.top();
				result.push(tempOperator);
				myOperator.pop();
			}
			myOperator.push(c);
		}
	}
	if (inNum) {
		result.push(tempNum);
		tempNum.clear();
		inNum = false;
	}
	while (!myOperator.empty()) {
		tempOperator = myOperator.top();
		result.push(tempOperator);
		myOperator.pop();
	}
	return result;
}

string check(stack<string>input, char label,bool &state) {
	stack<string>reverse;
	stack<int>num;
	string result;
	while (!input.empty()) {
		reverse.push(input.top());
		input.pop();
	}
	while (!reverse.empty()) {
		if (isdigit(reverse.top()[0])) {
			int temp = stoi(reverse.top());
			num.push(temp);
			reverse.pop();
		}
		else if (isalpha(reverse.top()[0])) {
			int temp = reverse.top()[0];
			num.push(temp);
			reverse.pop();
		}
		else {
			if (reverse.top() == "+") {
				int first, second;
				if (num.empty()) {
					result = "表达式";
					result.push_back(label);
					result += "无效！";
					state = false;
					return result;
				}
				first = num.top();
				num.pop();
				if (num.empty()) {
					result = "表达式";
					result.push_back(label);
					result += "无效！";
					state = false;
					return result;
				}
				second = num.top();
				num.pop();
				num.push(second + first);
				reverse.pop();
			}
			else if (reverse.top() == "-") {
				int first, second;
				if (num.empty()) {
					result = "表达式";
					result.push_back(label);
					result += "无效！";
					state = false;
					return result;
				}
				first = num.top();
				num.pop();
				if (num.empty()) {
					result = "表达式";
					result.push_back(label);
					result += "无效！";
					state = false;
					return result;
				}
				second = num.top();
				num.pop();
				num.push(second - first);
				reverse.pop();
			}
			else if (reverse.top() == "*") {
				int first, second;
				if (num.empty()) {
					result = "表达式";
					result.push_back(label);
					result += "无效！";
					state = false;
					return result;
				}
				first = num.top();
				num.pop();
				if (num.empty()) {
					result = "表达式";
					result.push_back(label);
					result += "无效！";
					state = false;
					return result;
				}
				second = num.top();
				num.pop();
				num.push(second * first);
				reverse.pop();
			}
			else if (reverse.top() == "/") {
				int first, second;
				if (num.empty()) {
					result = "表达式";
					result.push_back(label);
					result += "无效！";
					state = false;
					return result;
				}
				first = num.top();
				if (first == 0) {
					result = "表达式";
					result.push_back(label);
					result += "除0出错！";
					state = false;
					return result;
				}
				num.pop();
				if (num.empty()) {
					result = "表达式";
					result.push_back(label);
					result += "无效！";
					state = false;
					return result;
				}
				second = num.top();
				num.pop();
				num.push(second / first);
				reverse.pop();
			}
			else {
				result = "表达式";
				result.push_back(label);
				result += "无效！";
				state = false;
				return result;
			}
		}
	}
	result = to_string(num.top());
	num.pop();
	if (!num.empty()) {
		result = "表达式";
		result.push_back(label);
		result += "无效！";
		state = false;
		return result;
	}
	return result;
}

string compare(stack<string>first, stack<string>second,char label) {
	string result = "测试用例";
	result.push_back(label);
	result += "：";
	string firstResult, secondResult;
	bool state1=true, state2=true;
	firstResult=check(first, '1', state1);
	secondResult=check(second, '2', state2);
	if (!state1) {
		result += firstResult;
		if (!state2) {
			result += secondResult;
			return result;
		}
		return result;
	}
	if (!state2) {
		result += secondResult;
		return result;
	}

	if (firstResult == secondResult) {
		result += "TRUE";
		return result;
	}
	else {
		result += "FALSE";
		return result;
	}
	return result;
}


int main() {
	ifstream in;
	in.open("in.txt");
	ofstream out;
	out.open("out.txt");
	int n;
	in >> n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp1;
		string temp2;
		in >> temp1>> temp2;
		cin >> temp1 >> temp2;
		stack<string> op1=getNPL(temp1);
		stack<string> op2 = getNPL(temp2);
		out<< compare(op1, op2, i + '1') << endl;
		cout << compare(op1, op2, i + '1') << endl;
		
	}
}