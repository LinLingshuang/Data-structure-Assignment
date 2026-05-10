/*1. 二叉树镜像翻转
一、问题描述
给定一棵二叉树，将其镜像翻转（左右子树交换），然后输出翻转后的先序遍历序列。

二、输入形式
一行若干个整数，表示二叉树的先序遍历序列，空节点用-1表示。

三、输出形式
输出镜像翻转后的二叉树的先序遍历序列，空节点不输出。

四、样例输入

1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
五、样例输出

1 3 6 2 5 4
六、样例说明
原二叉树：

    1
   / \
  2   3
 / \   \
4   5   6
镜像翻转后：

    1
   / \
  3   2
 /   / \
6   5   4
先序遍历：1 3 6 2 5 4

七、评分标准
共10个测试用例。

八、类库使用要求
必须手动实现二叉树结构。*/
#include<iostream>
using namespace std;

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    node(int val) {
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
    void creatTree(node*& p) {
        int input = -1;
        if (cin.peek() == EOF) {
            // 没有输入
        }
        else {
            cin >> input;
        }
        if (input == -1) {
            return;
        }
        else {
            p = new node(input);
            creatTree(p->left);
            creatTree(p->right);
        }
    }
    void getMirror(node* p) {
        if (p != NULL) {
            cout << p->data << ' ';
            getMirror(p->right);
            getMirror(p->left);
        }
        else {
            return;
        }
    }
};

int main() {
    tree myTree;
    myTree.creatTree(myTree.root);
    myTree.getMirror(myTree.root);
}