/*7. 第七章第4题
【问题描述】
假设二叉树中的每个结点值为单个字符，采用二叉链存储结构存储。
设计一个算法按从右到左的次序输出一棵二叉树bt中的所有叶子结点。
【输入形式】
输入为二叉树的先序遍历序列（带空指针标记），其中空子树用 # 表示，非空结点用单个字符表示。
【输出形式】
从右到左输出所有叶子结点的值，空格分隔；若树为空，则无输出。
【样例输入】
ABD##E##CF###
【样例输出】
F E D
【样例说明】
叶子结点为 D, E, F ，从右到左的次序为 F→E→D
【评分标准】*/
#include<iostream>
#include<vector>
#include<string>
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
        if (bt[position] == '#') {
            return;
        }
        p = new node(bt[position]);
        position++;
        creatTree(p->left, bt, position);
        position++;
        creatTree(p->right, bt, position);

    }
   

    void getleaves(node* p) {
        if (p == NULL) {
            return ;
        }
        if (p->left == NULL && p->right == NULL) {
            cout << p->data << ' ';
            return ;
        }
        else {
            getleaves(p->right);
            getleaves(p->left); 
        }
    }
};


int main() {
    tree bt;
    string myTree;
    getline(cin, myTree);
    int position = 0;

    bt.creatTree(bt.root, myTree, position);
    bt.getleaves(bt.root);
}