/*2. 第七章 求值为X的结点所在的最小层次
【问题描述】假设二叉树中的每个结点值为单个字符，采用二叉链存储结构存储。
二叉树bt可能有多个值为x的结点，每个这样的结点对应一个层次（根结点为第1层）。请设计一个算法，求值为 x 的结点所在的最小层次。
【输入形式】
第一行输入一个整数 n，表示二叉树的结点数（1 ≤ n ≤ 1000）。
接下来 n 行，每行输入一个结点的信息，格式为：
结点值 左子结点值 右子结点值
若左子结点或右子结点为空，则用字符 # 表示。
最后一行输入一个字符 x，表示要查找的目标结点值。
【输出形式】
输出一个整数，表示所有值为 x 的结点中，所处的最小层次。
若不存在则输出-1
【样例输入】
7
A B C
B D E
C # F
D # #
E # #
F G #
G # #
E
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
    void frontSearchTree(node* p, int layer,char target,int& findlayer) {
        if (p == NULL) {
           
            //cout << '#' << ' ';
            return;
        }
        //cout << p->data<<' ';
        if (p->data == target) {
            if (findlayer == -1) {
                findlayer = layer;
            }
            else if(layer<= findlayer){
                findlayer = layer;
            }
        }
        int nextlayer = layer + 1;
        frontSearchTree(p->left, nextlayer, target, findlayer);
        frontSearchTree(p->right, nextlayer, target, findlayer);
    }
};

int main() {
    tree myTree;

    int num;
    cin >> num;

    myTree.creatTree(num);

    char target;
    cin >> target;

    int findlayer = -1;
    myTree.frontSearchTree(myTree.root, 1, target, findlayer);

    cout << findlayer;
}