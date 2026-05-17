/*5. 【实战7.2】LeetCode872—叶子相似的树
【问题描述】
请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个叶值序列。
例如如图所示的一棵二叉树的叶值序列为（6，7，4，9，8）。如果有两颗二叉树的叶值序列相同，
那么就认为它们是叶相似的。如果给定的两个根结点分别为root1和root2的树是叶相似的，则返回true，否则返回false。
image.png
假设给定的两棵二叉树可能会有1到200个结点，给定的两棵二叉树树上的值介于0到200之间。二叉树采用二叉链存储，结点类型TreeNode如下：
struct TreeNode
{    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x):val(x),left(NULL),right(NULL){}
};
设计如下成员函数：
class Solution {
public:
     bool leafSimilar(TreeNode* root1, TreeNode* root2)
     {  …  }
};
【输入形式】
每个测试用例为两行，每一行是一颗二叉树的括号表示法字符串
【输出形式】
true或false
【样例输入】
3（1,2）  
4（1,2）
【样例输出】
true
【样例说明】
如果某个节点没有右孩子节点，那么括号表示法中，该节点的子树括号内没有逗号，
例如 A(B,C(D))说明节点C只有一个左孩子为D，没有右孩子节点。
测试数据的文件名为in.txt
【评分标准】
该题目有10个测试用例，每通过一个测试用例，得10分。*/

#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node* parent;
    node() {
        data = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    node(const node& n) {
        data = n.data;
        left = n.left;
        right = n.right;
        parent = n.parent;
    }
};

bool isDigitChar(char c) {
    // 直接判断 ASCII 范围，完美兼容中文！
    return c >= '0' && c <= '9';
}

class tree {
public:
    node* root;
    tree() {
        root = NULL;
    }
    void creatTree(node*& p, string bt, int& position) {
        int num = 0;
        do {
            num = num * 10 + bt[position] - '0';
            position++;
        } while (position != bt.length() && isDigitChar(bt[position]));
        p = new node(num);

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
                    if (bt[position] != ')') {
                        creatTree(p->right, bt, position);
                    }
                }
            }
            position++;
        }
        else {
            return;
        }
    }
    void frontSearchTreeLeaves(node* p,vector<int>&leaves) {
        if (p == NULL) {
            return;
        }
        if (p->left == NULL&& p->right == NULL) {
            leaves.push_back(p->data);
            return;
        }
        frontSearchTreeLeaves(p->left, leaves);
        frontSearchTreeLeaves(p->right, leaves);
    }
};

bool leafSimilar(tree Tree1, tree Tree2){
    vector<int>leaves1;
    vector<int>leaves2;
    Tree1.frontSearchTreeLeaves(Tree1.root, leaves1);
    Tree2.frontSearchTreeLeaves(Tree2.root, leaves2);
    if (leaves1.size() != leaves2.size()) {
        return false;
    }
    else {
        for (int i = 0; i < leaves1.size(); i++) {
            if (leaves1[i] != leaves2[i]) {
                return false;
            }
        }
        return true;
    }
}


int main() {
    tree myTree1;
    tree myTree2;

    ifstream in;
    in.open("in.txt");
    string input1,input2;
    getline(in, input1);
    getline(in, input2);

    int position = 0;
    myTree1.creatTree(myTree1.root, input1, position);
    position = 0;
    myTree2.creatTree(myTree2.root, input2, position);

    if (leafSimilar(myTree1, myTree2)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}