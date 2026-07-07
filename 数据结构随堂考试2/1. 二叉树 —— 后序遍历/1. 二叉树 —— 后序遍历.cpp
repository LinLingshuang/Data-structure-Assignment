/*1. 二叉树 —— 后序遍历
问题描述
给定一棵二叉树的括号字符串表示，请编写程序输出该二叉树的后序遍历序列。
二叉树括号字符串的格式规则如下：
每个节点用一个字符表示其值
若节点至少有一个非空子树，在节点值后紧跟括号 (...)
括号内为 左子树,右子树，左右子树之间用逗号分隔
若左子树为空而右子树非空，左子树位置用空内容表示，即 节点值(,右子树)
若右子树为空而左子树非空，仅写左子树，即 节点值(左子树)
空树用空字符串表示
输入形式
输入一行，表示二叉树结构的括号字符串，长度不超过 1000 个字符。
输出形式
输出一行字符串，表示该二叉树的后序遍历序列（节点值按遍历顺序拼接，无空格）。
样例输入
A(B(D(,G)),C(E,F))
样例输出
GDBEFCA
样例说明
给定的二叉树结构如下：
        A
       / \
      B   C
     /   / \
    D   E   F
     \
      G
后序遍历顺序为：G → D → B → E → F → C → A，拼接为字符串 GDBEFCA。
评分标准
本题目共 10 个测试用例。
类库使用要求
允许使用标准输入输出库（如 iostream、cstdio 等）
允许使用字符串处理库（如 cstring、string 等）
允许使用vector、stack、queue容器库。
需自行实现二叉树的节点结构与遍历逻辑
未按题意进行编码求解，扣减得分的50%*/
#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct node {
    char data;
    node* lchild;
    node* rchild;
    node(char d) {
        data = d;
        lchild = rchild = NULL;
    }
};

struct tree {
    node* root=new node('#');
    tree() {
        string input;
        getline(cin, input);
        int position=0;
        creattree(root, input, position);
    }

    void creattree(node* &p,string input,int &position) {
        if (position >= input.length()) {
            p = NULL;
        }
        else {

            p = new node(input[position]);
            position++;
            if (position >= input.length() || input[position] == ')') {
                position++;
                return;
            }
            else if (input[position] == '(') {
                position++;
                if (input[position] == ',') {
                    position++;
                    creattree(p->rchild, input, position);
                }
                else {
                    creattree(p->lchild, input, position);

                    if (input[position] == ',') {
                        position++;
                        creattree(p->rchild, input, position);
                    }
                    //
                }
                if (input[position] == ')') {
                    position++;
                }
            }
        }
    }

    void backforward(node* p) {
        if (p == NULL || p->data == '#') {
            return;
        }
        else {
            backforward(p->lchild);
            backforward(p->rchild);
            cout << p->data;
        }
    }

};

int main() {
    tree t;
    t.backforward(t.root);
}