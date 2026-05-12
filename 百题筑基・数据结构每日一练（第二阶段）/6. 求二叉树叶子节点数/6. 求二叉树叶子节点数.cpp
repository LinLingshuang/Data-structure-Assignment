/*6. 求二叉树叶子节点数
一、问题描述
给定一棵二叉树，计算树中叶子节点（度为0的节点）的数量。

二、输入形式
一行若干个整数，表示二叉树的先序遍历序列，空节点用-1表示。

三、输出形式
输出一个整数，表示二叉树的叶子节点数。

四、样例输入

1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
五、样例输出

3
六、样例说明
二叉树结构：

    1
   / \
  2   3
 / \   \
4   5   6
叶子节点为4、5、6，共3个。

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
    int getleaves(node* p) {
        if (p == NULL) {
            return 0;
        }
        if (p->left == NULL && p->right == NULL) {
            return 1;
        }
        else {
            return getleaves(p->left) + getleaves(p->right);
        }
    }

};

int main() {
    tree myTree;
    myTree.creatTree(myTree.root);
    cout << myTree.getleaves(myTree.root);
}