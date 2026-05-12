/*9. 最近公共祖先LCA
最近公共祖先LCA
一、问题描述
给定一棵二叉树和两个节点p、q，找到它们的最近公共祖先（LCA）。

LCA定义：对于有根树T的两个节点p、q，最近公共祖先表示为一个节点x，满足x是p、q的祖先且x的深度尽可能大（一个节点也可以是它自己的祖先）。

二、输入形式
第一行输入两个整数p和q，表示要查找LCA的两个节点值。
第二行输入若干个整数，表示二叉树的先序遍历序列，空节点用-1表示。

三、输出形式
输出一个整数，表示p和q的最近公共祖先的节点值。如果p或q不存在于树中，输出-1。

四、样例输入

5 1
3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1
五、样例输出

3
六、样例说明
二叉树结构：

      3
     / \
    5   1
   / \  / \
  6  2 0  8
    / \
   7   4
节点5和节点1的最近公共祖先是3。

七、评分标准
共10个测试用例。

八、类库使用要求
必须手动实现二叉树结构。*/
#include<iostream>
#include<vector>
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
    int getLCA(node* r, int p, int q, bool& find) {
        if (r == NULL) {
            return 0;
        }
        else if (r->data == p || r->data == q) {
            int result = getLCA(r->left, p, q, find) + getLCA(r->right, p, q, find);
            if (result == 1 && !find) {
                find = true;
                return r->data;
            }
            else {
                return result + 1;
            }
        }
        else {
            int result = getLCA(r->left, p, q, find) + getLCA(r->right, p, q, find);
            if (result == 2 && !find) {
                find = true;
                return r->data;
            }
            else {
                return result;
            }
        }
    }
};

int main() {
    int p, q;
    cin >> p >> q;
    tree myTree;
    myTree.creatTree(myTree.root);
    bool find = false;
    int result = myTree.getLCA(myTree.root, p, q, find);
    if (find) {
        cout << result;
    }
    else {
        if (p == q) {
            cout << p;
        }
        else {
            cout << -1;
        }
    }
}