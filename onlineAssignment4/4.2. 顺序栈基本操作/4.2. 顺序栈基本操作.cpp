//2. 顺序栈基本操作
//顺序栈基本操作
//一、问题描述
//实现一个顺序栈（固定容量），支持以下操作：
//PUSH x：将元素x压入栈顶，栈满时输出"FULL"
//POP：弹出栈顶元素，栈空时输出"EMPTY"
//TOP：查看栈顶元素，栈空时输出"EMPTY"
//SIZE：输出栈中元素个数
//二、输入形式
//第一行输入两个正整数n和m（1 ≤ n ≤ 100000, 1 ≤ m ≤ 100000），分别表示栈的最大容量和操作数量。
//接下来m行，每行一个操作，格式如上所述。
//三、输出形式
//对于POP、TOP操作，输出对应的值或错误信息。
//对于PUSH操作，栈满时输出"FULL"。
//每个输出占一行。
//四、样例输入
//3 8
//PUSH 1
//PUSH 2
//TOP
//POP
//SIZE
//PUSH 3
//PUSH 4
//PUSH 5
//五、样例输出
//2
//2
//1
//FULL
//六、样例说明
//操作过程：
//PUSH 1：栈[1]
//PUSH 2：栈[1, 2]
//TOP：栈顶为2
//POP：弹出2，栈[1]
//SIZE：大小为1
//PUSH 3：栈[1, 3]
//PUSH 4：栈[1, 3, 4]
//PUSH 5：栈满，输出FULL
//七、评分标准
//共6个测试用例。
//八、类库使用要求
//可以使用数组或vector实现，禁止使用STL stack。
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct stack {
	stack(int v) {
		vepacity = v;
		size = 0;
		data = vector<int>(vepacity);
	}

	int vepacity;
	int size;
	vector<int> data;


	void PUSH(int x) {
		if (size == vepacity) {
			cout << "FULL" << endl;
			return;
		}
		else {
			data[size] = x;
			size++;
		}
	}
	void POP() {
		if (size == 0) {
			cout << "EMPTY" << endl;
			return;
		}
		else {
			size--;
			cout << data[size] << endl;
		}
	}
	void TOP() {
		if (size == 0) {
			cout << "EMPTY" << endl;
			return;
		}
		else {
			cout << data[size - 1] << endl;
		}
	}
	void SIZE() {
		cout << size << endl;
	}

};


int main() {
	int n, m;
	cin >> n >> m;
	stack myStack(n);
	for (int i = 0; i < m; i++) {
		string op;
		cin >> op;
		if (op=="PUSH") {
			int x;
			cin >> x;
			myStack.PUSH(x);
		}
		else if (op=="POP") {
			myStack.POP();
		}
		else if (op == "TOP") {
			myStack.TOP();
		}
		else if (op == "SIZE") {
			myStack.SIZE();
		}

	}




}