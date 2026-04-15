/*1. 判断二叉树是否对称
一、问题描述
给定一棵二叉树，检查它是否是轴对称的（镜像对称）。
二、输入形式
一行若干个整数，表示二叉树的先序遍历序列，空节点用-1表示。
三、输出形式
输出"YES"表示对称，输出"NO"表示不对称。
四、样例输入
1 2 3 -1 -1 4 -1 -1 2 4 -1 -1 3 -1 -1
五、样例输出
YES
六、样例说明
对称二叉树：
    1
   / \
  2   2
 / \ / \
3  4 4  3
以根节点为轴，左右子树镜像对称。
七、评分标准
共8个测试用例。
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
    node(node &n) {
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
    void creatTree(node* &p) {
        int input;
        cin >> input;
        if (input == -1) {
            return;
        }
        else {
            p = new node(input);
            creatTree(p->left);
            creatTree(p->right);
        }
    }
   
};

int main() {
    tree myTree;
    myTree.creatTree(myTree.root);
    int a;
}