/*8. 二叉树遍历
【问题描述】假设二叉树中每个结点值均为单个字符，采用链式的存储结构。分别输出该二叉树先序遍历中序遍历和后序遍历的结果。
【输入形式】
第一行：以括号表示法输入该二叉树的所有结点
【输出形式】
第一行：输出先序遍历的结果
第二行：输出中序遍历的结果
第三行：输出后序遍历的结果
【样例输入】
a(c,b)
【样例输出】
acb
cab
cba
【样例说明】
符号均为半角符号，中间无空格，输入字符串的长度不超过N（N<=100）
【提示】
如果不知道如何根据输入生成二叉链树，可看本提示(仅供参考，算法有多样，以下只有核心思路，具体请自行完善)。
可以先将输入存入到一维数组中，之后顺序扫描:
    若扫描到非括号且非逗号，存入当前结点，继续扫描；
    若扫描到左括号，继续：
        若扫描到非逗号非右括号，生成当前结点左子结点，递归扫描；
        若扫描到逗号，生成当前结点右子结点，递归扫描；
        若扫描到右括号，结束；
    若扫描到逗号或右括号，结束；
    */
#include<iostream>
#include<string>
#include<vector>
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
    tree() {
        root = NULL;
    }
    void creatTree(node*& p, string bt, int& position) {
        p = new node(bt[position]);
        position++;
        if (bt[position] == '(') {
            position++;
            if (bt[position] == ',') {
                position++;
                creatTree(p->right, bt, position);

            }
            else {
                creatTree(p->left, bt, position);
                if (bt[position] == ',') {
                    position++;
                    creatTree(p->right, bt, position);
                }
            }
            position++;
        }
        else {
            return;
        }
        
    }
  
    void frontSearchTree(node* p) {
        if (p == NULL) {
            return;
        }
        cout << p->data;
        frontSearchTree(p->left);
        frontSearchTree(p->right);
    }
    //中序
    void middleSearchTree(node* p) {
        if (p == NULL) {
            return;
        }
        middleSearchTree(p->left);
        cout << p->data;
        middleSearchTree(p->right);
    }
    void backSearchTree(node* p) {
        if (p == NULL) {
            return;
        }
        backSearchTree(p->left);
        backSearchTree(p->right);
        cout << p->data;
    }
};


int main() {
    tree bt;
    string myTree;
    getline(cin, myTree);
    int position = 0;

    bt.creatTree(bt.root, myTree, position);
    bt.frontSearchTree(bt.root);
    cout << endl;
    bt.middleSearchTree(bt.root);
    cout << endl;
    bt.backSearchTree(bt.root);
    cout << endl;
}
