/*5. 二叉树的创建与遍历
一、问题描述
根据给定的先序遍历序列创建二叉树（空节点用-1表示），然后输出中序、后序和层序遍历序列。
二、输入形式
一行若干个整数，表示二叉树的先序遍历序列，空节点用-1表示。
三、输出形式
输出三行，分别是中序、后序和层序遍历序列，节点值用空格分隔。
四、样例输入
1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
五、样例输出
4 2 5 1 3 6
4 5 2 6 3 1
1 2 3 4 5 6
六、样例说明
二叉树结构：
    1
   / \
  2   3
 / \   \
4   5   6
七、评分标准
共8个测试用例。
八、类库使用要求
必须手动实现二叉树结构和遍历算法，可以使用queue。*/
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
    //中序
    void middleSearchTree(node* p) {
        if (p == NULL) {
            return;
        }
        middleSearchTree(p->left);
        cout << p->data << ' ';
        middleSearchTree(p->right);
    }
    //后序
    void backSearchTree(node* p) {
        if (p == NULL) {
            return;
        }
        backSearchTree(p->left);
        backSearchTree(p->right);
        cout << p->data << ' ';
    }
    //层序
    void lyarSearchTree(vector<node*>lyar) {
        vector<node*>nextlyar;
        for (node* p : lyar) {
            if (p != NULL) {
                cout << p->data << ' ';
                nextlyar.push_back(p->left);
                nextlyar.push_back(p->right);
            }
        }
        if (!nextlyar.empty()) {
            lyarSearchTree(nextlyar);
        }
    }
};

int main() {
    tree myTree;
    myTree.creatTree(myTree.root);
    myTree.middleSearchTree(myTree.root);
    cout << endl;
    myTree.backSearchTree(myTree.root);
    cout << endl;
    vector<node*>lyar;
    lyar.push_back(myTree.root);
    myTree.lyarSearchTree(lyar);
}