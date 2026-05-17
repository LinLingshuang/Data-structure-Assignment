/*3. 第七章 先序遍历方法求出某个值的所有子孙
【问题描述】
在给定的二叉树结构中，每个结点值为单个字符。设计一个算法，
采用先序遍历方法求出某个值为x的结点的所有子孙。需先构建二叉链。
【输入形式】
输入由多行组成：
第一行为一个整数N，表示二叉树中结点的数量。
接下来N行，每行描述一个结点的信息，格式为：父节点值 左孩子值 右孩子值
如果某个孩子为空，则用‘#’表示。
最后一行为目标字符x。
【输出形式】
按先序遍历的顺序输出所有目标节点x的子孙结点值。
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
【样例输入】
6
A B C
B D E
C # F
D # #
E # #
F # #
B
【样例输出】
D E*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct node {
    char data;
    node* left;
    node* right;
    node() {
        data = '#';
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
    void creatTree(int num) {
        queue<node*>treeNode;
        root = new node('#');
        treeNode.push(root);
        for (int i = 0; i < num; i++) {
            char temp1, temp2, temp3;
            cin >> temp1;
            if (temp1 != '#') {
                treeNode.front()->data = temp1;
                cin >> temp2 >> temp3;
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
    void frontSearchTree(node* p,char target,bool find) {
        bool nextfind = false;
        if (p == NULL) {
           
            return;
        }
        if (find) {
            cout << p->data << ' ';
            nextfind = true;
        }

        if (p->data == target) {
            nextfind = true;
   
        }
        frontSearchTree(p->left, target, nextfind);
        frontSearchTree(p->right, target, nextfind);
    }
};

int main() {
    tree myTree;

    int num;
    cin >> num;
    myTree.creatTree(num);
    char target;
    cin >> target;

    bool find = false;
    myTree.frontSearchTree(myTree.root,target,find);
   
   
}