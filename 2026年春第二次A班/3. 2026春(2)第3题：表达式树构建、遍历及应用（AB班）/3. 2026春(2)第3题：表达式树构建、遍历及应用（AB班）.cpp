/*3. 2026春(2)第3题：表达式树构建、遍历及应用（A/B班）
【实验题目】从标准输入读取一个合法算术运算表达式（示例：(a + 3)*2/(b-A)），完成以下任务：
（1）根据输入表达式构建表达式二叉树。
（2）基于表达式树计算原表达式的值。
（3）对表达式树进行层次遍历，并输出遍历结果的倒序。
（4）按照层次遍历的倒序结果，重新计算表达式的值。
如表达式为(a + 3)*2/(b-A)，则生成的表达式树为如下图，通过表达式树计算的值为6，
层次遍历倒序为：3aAb2 + -* /，根据层次遍历倒序结果计算表达式的值为6。
【实验要求】
（1）输入限制：单个算术表达式长度不超过20个字符，表达式语法合法，圆括号正确匹配且支持嵌套，无错误表达式。
（2）表达式组成：①运算符： + （加）、 - （减）、 * （乘）、 / （除）；②运算数：一位十进制
数字、单个英文字母（A - Z / a - z），字母以其ASCII码值参与数值运算；③边界符：正确匹配的左圆括号"（"和右圆括号"）"。
（3）运算规则：除法运算采用整数除法，结果取整数部分（例：5 / 3 = 1）。
blob.png
【输入格式】从键盘输入一个合法的算术表达式字符串。
输入示例：(a+3)*2/(b-A)
【输出格式】在屏幕上依次输出以下三行内容：
第一行：基于表达式树计算得出的原表达式数值。
第二行：表达式树层次遍历结果的倒序序列。
第三行：依据层次遍历倒序结果计算得到的数值。
对于上述输入，输出一次为：
6
3aAb2 + -* /
6 */
#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct node {
    char data;
    node* left;
    node* right;
    node() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    node(char val) {
        data = val;
        left = NULL;
        right = NULL;
    }
    node(const node& n) {
        data = n.data;
        left = n.left;
        right = n.right;
    }
};



class tree {
public:
    node* root;
	int r;
    tree() {
        root = NULL;
    }
    void creatTree() {
        string input;
		cin >> input;
        vector<char>NPL;
        stack<char>op;
        for (char c : input) {
            if (isdigit(c) || isalpha(c)) {
                NPL.push_back(c);
            }
			else if (c == '(') {
				op.push(c);
			}
			else if (c == ')') {
				while (op.top() != '(') {
					NPL.push_back(op.top());
					op.pop();
				}
				op.pop();
			}
			else if (c == '*' || c == '/') {
				if (!op.empty()) {
					if (op.top() == '-' || op.top() == '+' || op.top() == '(') {
						op.push(c);
					}
					else {
						NPL.push_back(op.top());
						op.pop();
						op.push(c);
					}
				}
				else {
					op.push(c);
				}
			}
			else if (c == '+' || c == '-') {
				while (!op.empty() && op.top() != '(') {
					NPL.push_back(op.top());
					op.pop();
				}
				op.push(c);
			}
			else {
				continue;
			}
		}       
		while (!op.empty()) {	
			NPL.push_back(op.top());
			op.pop();
		}

		stack<node*>tree;
		stack<int>num;
		int result;
		for (char c : NPL) {
			if (isdigit(c) || isalpha(c)) {
				tree.push(new node(c));
				if (isdigit(c)) {
					num.push(c - '0');
				}
				else {
					num.push(c);
				}
			}
			else {
				node* right = tree.top();
				tree.pop();
				node* left = tree.top();
				tree.pop();
				node* parent = new node(c);
				parent->left = left;
				parent->right = right;
				tree.push(parent);
				int first = num.top();
				num.pop();
				int second = num.top();
				num.pop();
				if (c == '+') {
					num.push(second + first);
				}
				else if (c == '-') {
					num.push(second - first);
				}
				else if (c == '*') {
					num.push(second * first);
				}
				else if (c == '/') {
					num.push(second / first);
				}
				
			}
		}
		root = tree.top();
		result = num.top();
		r = result;
		cout << result << endl;
    }
	void getReverse() {
		vector<char>reNPL;
		queue<node*>layer;
		queue<node*>nextlayer;
		if (root != NULL) {
			reNPL.push_back(root->data);
			layer.push(root);
		}
		else {
			return;
		}
		do {
			while (!nextlayer.empty()) {
				nextlayer.pop();
			}
			while (!layer.empty()) {
				if (layer.front()->left != NULL) {
					nextlayer.push(layer.front()->left);
					reNPL.push_back(layer.front()->left->data);
				}
				if (layer.front()->right != NULL) {
					nextlayer.push(layer.front()->right);
					reNPL.push_back(layer.front()->right->data);
				}
				layer.pop();
			}
			layer = nextlayer;
		} while (!nextlayer.empty());

		
		for (int i = reNPL.size() - 1; i >= 0; i--) {
			cout << reNPL[i];
			
		}
		cout << endl;
		cout << r;
		return;
	}
};


int main() {
    tree myTree;
    myTree.creatTree();
	myTree.getReverse();
	string input;
	//getline(cin, input);
	//cout << endl<<input;
}