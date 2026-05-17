/*1. 第七章 先序遍历计算二叉树的宽度
【问题描述】假设二叉树中的每个结点值为单个字符，采用二叉链存储结构存储。
请设计一个算法，采用先序遍历的方法计算二叉树 bt 的宽度（即具有最多结点的层的结点数）。
【输入形式】
第一行输入一个整数 n，表示二叉树的结点数（1 ≤ n ≤ 1000）。
接下来 n 行，每行输入一个结点的信息，格式为：
结点值 左子结点值 右子结点值
若左子结点或右子结点为空，则用字符 # 表示。
【输出形式】
输出一个整数，表示二叉树的最大宽度（即具有最多结点的层的结点数）。
【样例输入】
7
A B C
B D E
C # F
D # #
E # #
F G #
G # #

14
A B C
B 1 2
C 3 4
1 F #
2 # #
3 R T
4 # 5
F L #
R ( )
T # #
5 # #
L # #
( # #
) # #
【样例输出】
3
【样例说明】
【评分标准】
【说明】
需要用二叉链存储结构实现
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct node {
    char data;
    node* left;
    node* right;
    node* parent;
    node() {
        data = '#';
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    node(char val) {
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

class tree {
public:
    node* root;
    tree() {
        root = NULL;
    }
    void creatTree(int num) {
        queue<node*>treeNode;
        root = new node('#');
        treeNode.push(root);
        for (int i = 0; i < num; i++) {
            char temp1, temp2, temp3;
            cin >> temp1;
            if (temp1 != '#') {
                treeNode.front()->data = temp1;
                cin>> temp2 >> temp3;
                if (temp2 != '#') {
                    treeNode.front()->left = new node(temp2);
                    treeNode.push(treeNode.front()->left);
                }
             
                if (temp3 != '#') {
                    treeNode.front()->right = new node(temp3);
                    treeNode.push(treeNode.front()->right);
                }
              
                treeNode.pop();
            }
           
        }

    }
    void frontSearchTree(node* p,int layer, vector<int>&width) {
        if (p == NULL) {
            width.push_back(0);
            //cout << '#' << ' ';
            return;
        }
        //cout << p->data<<' ';
        if (width.size() <= layer) {
            width.push_back(0);
        
        }
        int nextlayer = layer + 1;
        width[layer]++;
        frontSearchTree(p->left, nextlayer, width);
        frontSearchTree(p->right, nextlayer, width);
    }
};

int main() {
    tree myTree;

    int num;
    cin >> num;

    myTree.creatTree(num);
    vector<int>width;
    myTree.frontSearchTree(myTree.root,0,width);
    int max = 0;
    for (int num : width) {
        if (num >= max)max = num;
    }
    cout << max;
}