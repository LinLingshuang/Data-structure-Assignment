/*6. 第七章第6题
【问题描述】
假设二叉树采用二叉链存储结构存储，设计一个算法将二叉树bt1复制到二叉树bt2.
【输入形式】
输入为一棵二叉树的先序遍历序列（带空指针标记），其中：
非空结点用单个字符表示；
空指针（空子树）用 # 表示。
【输出形式】
输出复制后的二叉树的中序遍历结果（字符间用空格隔开，开头与末尾无多余空格）。若原树为空，输出为空。
【样例输入】
AB##C##
【样例输出】
B A C
【样例说明】
构建出原始二叉树 bt1；
将其完整复制为新的树 bt2；
对 bt2 进行中序遍历输出结果 B A C；
确保 bt1 与 bt2 是两个不同的内存树（复制而非引用）。
【评分标准】*/
#include<iostream>
#include<string>
#include<vector>
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
    void copyTree(node* bt1, node*& bt2) {
        if (bt1==NULL) {
            return;
        }
        bt2 = new node(bt1->data);
        copyTree(bt1->left,bt2->left);
        copyTree(bt1->right,bt2->right);
    }
    //中序
    void middleSearchTree(node* p) {
        if (p == NULL) {
            return;
        }
        middleSearchTree(p->left);
        cout << p->data << ' ';
        middleSearchTree(p->right);
    }

};


int main() {
    tree bt1;
    string myTree;
    getline(cin, myTree);
    int position = 0;

    bt1.creatTree(bt1.root, myTree, position);

    tree bt2;
    bt2.copyTree(bt1.root, bt2.root); 
    bt2.middleSearchTree(bt2.root);
}